#include "operationspec_manager.h"
#include "general_functions.h"
#include "main_application.h"
#include <stdio.h>
#include "systick.h"
#include "key_exit.h"
#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "read_manage.h"
#include "EN25Q256.h"
#include "buzzer_led.h"
OperationSpec_Manager::OperationSpec_Manager()
{
//    m_pIDToSelectSpec = new map<llrp_u32_t,Tag_SelectSpec *>;
//    m_pIDToAccessSpec = new map<llrp_u32_t,Tag_AccessSpec *>;
    m_pSelectSpecList = new list<Tag_SelectSpec*>;
    m_pAccessSpecList = new list<Tag_AccessSpec*>;

    m_SelectSpecList_IT = m_pSelectSpecList->begin();

    //读取磁盘中的持久化规则文件

		//为手持机新加一默认的读卡规则。
		initDefaultSelectSpec(); 
	
		this->addSelectSpec(m_pCurrentSelectSpec,false);
}

//void OperationSpec_Manager::activeGPISelectSpec(){
//	m_pCurrentSelectSpec->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
//}
//初始化时 默认 配置的 selectSpec
void OperationSpec_Manager::initDefaultSelectSpec(){
	
	m_pCurrentSelectSpec = (CAddSelectSpec *)HbFrame_Operation::genMessage(AddSelectSpec,0);

	CSelectSpec* paraseletespec = (CSelectSpec*)HbFrame_Operation::genParam(SelectSpec, 0, NULL);
	paraseletespec->setSelectSpecID(3001);
	paraseletespec->setPriority(0);
	paraseletespec->setSelectCurrentState(SelectCurrentState_Inactive);
	paraseletespec->setPersistence(Persistence_Noneed);

	CSelectSpecStartTrigger* paraselectspecstarttrigger = (CSelectSpecStartTrigger*)HbFrame_Operation::genParam(SelectSpecStartTrigger, 0, NULL);
	paraselectspecstarttrigger->setSelectSpecStartTriggerType(SelectSpecStartTriggerType_GPI);

	CGPITrigger* paragpitrigger = (CGPITrigger*)HbFrame_Operation::genParam(GPITrigger, 0, NULL);
	paragpitrigger->setGPIEvent(GPIEvent_DOWN);
	paragpitrigger->setGPIPortNum(0);//这里暂无关，随便设置
	paragpitrigger->setTimeout(0);//这里暂不起作用，随便设置
	HbFrame_Operation::addParamToParameter(paragpitrigger, paraselectspecstarttrigger);

	HbFrame_Operation::addParamToParameter(paraselectspecstarttrigger, paraseletespec);


	CSelectSpecStopTrigger* paraselectspecstoptrigger = (CSelectSpecStopTrigger*)HbFrame_Operation::genParam(SelectSpecStopTrigger, 0, NULL);
	paraselectspecstoptrigger->setSelectSpecStopTriggerType(SelectSpecStopTriggerType_GPI);
	paraselectspecstoptrigger->setDurationValue(0);
	CGPITrigger* paragpistoptri = (CGPITrigger*)HbFrame_Operation::genParam(GPITrigger, 0, NULL);
	paragpistoptri->setGPIEvent(GPIEvent_UP);
	paragpistoptri->setGPIPortNum(0);
	paragpistoptri->setTimeout(0);
	HbFrame_Operation::addParamToParameter(paragpistoptri, paraselectspecstoptrigger);

	HbFrame_Operation::addParamToParameter(paraselectspecstoptrigger, paraseletespec);

	CAntennaSpec* paraantennaspec = (CAntennaSpec*)HbFrame_Operation::genParam(AntennaSpec, 0, NULL);

	llrp_u8v_t antennaids = llrp_u8v_t(1);
	antennaids.m_pValue[0] = 4; //手持机默认4号天线
	paraantennaspec->setAntennaIDs(antennaids);


	CAntennaSpecStopTrigger* paraantennaspecstoptrigger = (CAntennaSpecStopTrigger*)HbFrame_Operation::genParam(AntennaSpecStopTrigger, 0, NULL);
	paraantennaspecstoptrigger->setAntennaSpecStopTriggerType(AntennaSpecStopTriggerType_SelectSpecStop);
	paraantennaspecstoptrigger->setDurationValue(0);
	HbFrame_Operation::addParamToParameter(paraantennaspecstoptrigger, paraantennaspec);
	
	CRfSpec* pararfspec = (CRfSpec*)HbFrame_Operation::genParam(RfSpec, 0, NULL);
	pararfspec->setRfSpecID(1000);
	pararfspec->setProtocolID(ProtocolID_HangBiao);
	pararfspec->setSelectType(SelectType_Read);

	CMemoryBank* paramemorybank = (CMemoryBank*)HbFrame_Operation::genParam(MemoryBank, 0, NULL);
	paramemorybank->setMemoryBankID(0);
	paramemorybank->setReadType(1); //按分区读
	paramemorybank->setPointer(4);
	paramemorybank->setCount(10);
	paramemorybank->setBankType(2);
	HbFrame_Operation::addParamToParameter(paramemorybank, pararfspec);

	CAntennaConfiguration * paraantennaconfiguration = (CAntennaConfiguration *)HbFrame_Operation::genParam(AntennaConfiguration, 0, NULL);
	paraantennaconfiguration->setAntennaID(4);
	paraantennaconfiguration->setTransmitPowerIndex(15);
	
	llrp_u16v_t chanel = llrp_u16v_t(1);  //用于获取20个频道复选框的内容
	int current = 0;
	chanel.m_pValue[0] = 0;
	
	paraantennaconfiguration->setFrequencyIndexes(chanel);
	paraantennaconfiguration->setForDataRateIndex(0);
	paraantennaconfiguration->setRevDataRateIndex(5);
	paraantennaconfiguration->setForModulationIndex(0);
	paraantennaconfiguration->setRevDataEncodingIndex(1);
	HbFrame_Operation::addParamToParameter(paraantennaconfiguration, pararfspec);

	HbFrame_Operation::addParamToParameter(pararfspec, paraantennaspec);

	
	
	HbFrame_Operation::addParamToParameter(paraantennaspec, paraseletespec);
	
	HbFrame_Operation::addParamToMessage(paraseletespec, m_pCurrentSelectSpec);
	
	m_pCurrentSelectSpec->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Disabled);
	
	//HbFrame_Operation::printMessage(m_pCurrentSelectSpec);
	
}

OperationSpec_Manager::~OperationSpec_Manager(){
    delete m_pSelectSpecList;
    delete m_pAccessSpecList;
}

/*
 * 在未标志要删除的selectspec中，查找相应ID的TagSelect，返回Select的集合
 */
vector<Tag_SelectSpec*> OperationSpec_Manager::findValidSelectByID(llrp_u32_t selectid){
    vector<Tag_SelectSpec*> Tag_SelectSpecs;
    for(list<Tag_SelectSpec*>::iterator it=m_pSelectSpecList->begin();
            it!=m_pSelectSpecList->end();it++){
        Tag_SelectSpec *ptagselect = *it;
        if((ptagselect->getSelectSpec()->getSelectSpecID()==selectid||selectid==0)&&ptagselect->isValid==true){
            //printf("findValidSelectByID:find select by id=%d\n",selectid);
            Tag_SelectSpecs.push_back(ptagselect);
        }
    }
    return Tag_SelectSpecs;
}

/*
 * 查找相应AccessID返回的是TagAccess的集合。没有找到，则集合为空
 */
vector<Tag_AccessSpec*> OperationSpec_Manager::findValidAccessByID(llrp_u32_t id){
    vector<Tag_AccessSpec*> accessspecs;
    for(list<Tag_AccessSpec*>::iterator it=m_pAccessSpecList->begin();
                                    it!=m_pAccessSpecList->end();it++){
        Tag_AccessSpec *accessspec = *it;
        //Access的selectID相符或等于0（即所有Select）
        if((accessspec->getAccessSpec()->getAccessSpecID()==id||
                id==0)&&accessspec->isValid==true){
            accessspecs.push_back(accessspec);
        }
    }
    return accessspecs;
}

/*
 * 将所有符合条件的有效的Access加入到指定的Select中
 */
void OperationSpec_Manager::setSelectFromAccess(Tag_SelectSpec *pSpec){
    llrp_u32_t selectid = pSpec->getSelectSpec()->getSelectSpecID();
    vector<Tag_AccessSpec*> tagaccessspecs ;
    for(list<Tag_AccessSpec*>::iterator it=m_pAccessSpecList->begin();
                                    it!=m_pAccessSpecList->end();it++){
        Tag_AccessSpec *paccessspec = *it;
        //Access的selectID相符或等于0（即所有Select）
        if((paccessspec->getAccessSpec()->getAccessSpecID()==selectid||
                paccessspec->getAccessSpec()->getAccessSpecID()==0)&&paccessspec->isValid==true){
            paccessspec->retain();
            tagaccessspecs.push_back(paccessspec);
        }
    }
    pSpec->tagAccessSpecs = tagaccessspecs;
}

/*
 * 将Access加入到所有符合条件的Select中
 */
void OperationSpec_Manager::pushAccessToSelect(Tag_AccessSpec *pSpec){

    vector<Tag_SelectSpec*> Tag_SelectSpecs = this->findValidSelectByID(pSpec->getAccessSpec()->getSelectSpecID());
    //printf("Tag_SelectSpecs.size()=%d\n",Tag_SelectSpecs.size());
    for(int i=0;i<Tag_SelectSpecs.size();i++){
        Tag_SelectSpecs.at(i)->pushTagAccess(pSpec);
    }
}

/*
 * 从Select中移除Access，但并未删除该Access
 */
void OperationSpec_Manager::removeAccessFromSelect(Tag_AccessSpec *pSpec){
    vector<Tag_SelectSpec*> Tag_SelectSpecs = this->findValidSelectByID(pSpec->getAccessSpec()->getSelectSpecID());
    for(int i=0;i<Tag_SelectSpecs.size();i++){
        Tag_SelectSpecs.at(i)->eraseTagAccess(pSpec);
    }
}

/**
 * @brief OperationSpec_Manager::addSelectSpec
 * @param pAddSelectSpec
 * @param isNeedSave，是否需要保存持久化规则
 * @return
 */
bool OperationSpec_Manager::addSelectSpec(CAddSelectSpec *pAddSelectSpec,bool isNeedSave){
//    HbFrame_Operation::printMessage(pAddSelectSpec);
//    Delay_ms(2000);
		llrp_u32_t specid = pAddSelectSpec->getSelectSpec()->getSelectSpecID();
    if(this->findValidSelectByID(specid).size()<=0){
        printf("addSelectSpec:not find specid!\n");
        Tag_SelectSpec *ptagspec = new Tag_SelectSpec(pAddSelectSpec);
        this->setSelectFromAccess(ptagspec);
        m_pSelectSpecList->push_back(ptagspec);
        m_SelectSpecList_IT = m_pSelectSpecList->begin();//每次添加规则后，都把迭代器归为begin;
        if(ptagspec->getSelectSpec()->getPersistence()==Persistence_Need&&isNeedSave==true){//如当前配置的规则需要持久化，则保存该规则
           				
					this->writePersisSelect(pAddSelectSpec);
        }
        printf("addSelectSpec success!specID=%d and status is %d\n",ptagspec->selectSpecID,ptagspec->getSelectSpec()->getSelectCurrentState());
        return true;
    }else{
        printf("addSelectSpec:find specid!\n");
        printf("addSelectSpec fail!specid=%d \n",specid);
        return false;
    }

}

bool OperationSpec_Manager::disableSelectSpec(llrp_u32_t specid){
    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(specid);
    if(specs.size()<=0){
        printf("disableSelectSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
        printf("disableSelectSpec success!specID=%d\n",specid);
        //这里应进行disable操作
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Disabled);
        }
        return true;
    }
}

bool OperationSpec_Manager::enableSelectSpec(llrp_u32_t specid){
    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(specid);
    if(specs.size()<=0){
        printf("enableSelectSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
        printf("enableSelectSpec success!specID=%d\n",specid);
        //这里应进行disable操作
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Inactive);
        }
        return true;
    }
}

/**
 * @brief OperationSpec_Manager::deleteSelectSpec
 * @param specid
 * @return
 * 删除操作仅是将要删除的SelectSpec置为无效，对其本身的删除在autorelease中进行
 */
bool OperationSpec_Manager::deleteSelectSpec(llrp_u32_t specid){

    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(specid);
    if(specs.size()<=0){
        printf("deleteSelectSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return true; //没有发该规则，也认为删除成功
    }else{
        printf("deleteSelectSpec success!specID=%d\n",specid);
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->isValid = false;
            specs.at(i)->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Disabled);
            this->deletePersisSelect(specs.at(i)->getSelectSpec()->getSelectSpecID()); //先删除可能记在磁盘上的规则
        }
				//停止底层设备	
				g_pMainApplication->getOpProcess()->getOpExecute()->m_SelectStep =  0;
				g_pMainApplication->m_read_manage->stop();		
        return true;
    }
}

bool OperationSpec_Manager::startSelectSpec(llrp_u32_t specid){
    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(specid);
    if(specs.size()<=0){
        printf("startSelectSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
			  KEY_TYPE = read_start;
		      //MCU_To_MCU(Device_cpu,StartReadCard,0);	//开始当前节点
        printf("startSelectSpec success!specID=%d\n",specid);
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Active);
        }
        return true;
    }
}

bool OperationSpec_Manager::stopSelectSpec(llrp_u32_t specid){
    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(specid);
    if(specs.size()<=0){
        printf("stopSelectSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
				//停止底层设备
				g_pMainApplication->m_read_manage->stop();	
        printf("stopSelectSpec success!specID=%d\n",specid);
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getSelectSpec()->setSelectCurrentState(SelectCurrentState_Inactive);
        }
        return true;
    }
}

/**
 * @brief OperationSpec_Manager::addAccessSpec
 * @param pAddAccessSpec
 * @param isNeedSave， 是否需要保存，如为真，则会保存持久规则。
 * @return
 */
bool OperationSpec_Manager::addAccessSpec(CAddAccessSpec *pAddAccessSpec,bool isNeedSave){

    llrp_u32_t specid = pAddAccessSpec->getAccessSpec()->getAccessSpecID();
    if(this->findValidAccessByID(specid).size()<=0){
        printf("addAccessSpec:not find specid!\n");
        HbFrame_Operation::printMessage(pAddAccessSpec);
        Tag_AccessSpec *ptagspec = new Tag_AccessSpec(pAddAccessSpec);
        this->pushAccessToSelect(ptagspec);

        m_pAccessSpecList->push_back(ptagspec);

        if(ptagspec->getAccessSpec()->getPersistence()==Persistence_Need&&isNeedSave==true){
            this->writePersisAccess(ptagspec->getAccessSpec()->getAccessSpecID(),ptagspec->getAccessSpec());
        }
        printf("addAccessSpec success!specID=%d and status is %d\n",ptagspec->accessSpecID,ptagspec->getAccessSpec()->getAccessCurrentState());
        return true;
    }else{
        printf("addAccessSpec:find specid!\n");
        printf("addSelectSpec fail!specid=%d \n",specid);
        return false;
    }

}

bool OperationSpec_Manager::disableAccessSpec(llrp_u32_t specid){

    vector<Tag_AccessSpec*> specs = this->findValidAccessByID(specid);
    if(specs.size()<=0){
        printf("disableAccessSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
        printf("disableAccessSpec success!specID=%d\n",specid);
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getAccessSpec()->setAccessCurrentState(AccessCurrentState_Disabled);
        }
        return true;
    }
}

bool OperationSpec_Manager::enableAccessSpec(llrp_u32_t specid){
    vector<Tag_AccessSpec*> specs = this->findValidAccessByID(specid);
    if(specs.size()<=0){
        printf("enableAccessSpec:not find specid!\n");
        printf("specid=%d\n",specid);
        return false;
    }else{
        printf("enableAccessSpec success!specID=%d\n",specid);
        //这里应进行disable操作
        //==================================================================//
        for(int i=0;i<specs.size();i++){
            specs.at(i)->getAccessSpec()->setAccessCurrentState(AccessCurrentState_Active);
        }
        return true;
    }
}

bool OperationSpec_Manager::deleteAccessSpec(llrp_u32_t specid){

        vector<Tag_AccessSpec*> specs = this->findValidAccessByID(specid);
        if(specs.size()<=0){
            printf("deleteAccessSpec:not find specid!\n");
            printf("specid=%d\n",specid);
            return true; //没有发现该规则，也认为删除成功
        }else{
            printf("deleteAccessSpec success!specID=%d\n",specid);
            //这里应进行disable操作
            //==================================================================//
            for(int i=0;i<specs.size();i++){
                specs.at(i)->isValid =false;
                specs.at(i)->getAccessSpec()->setAccessCurrentState(AccessCurrentState_Disabled);
                this->removeAccessFromSelect(specs.at(i));
                this->deletePersisAccess(specs.at(i)->getAccessSpec()->getAccessSpecID());//先删除可能存在磁盘上的规则文件

            }
            return true;
    }
}

/**
 * @brief OperationSpec_Manager::requestValidSelectSpec
 * @return
 * 通过SelectID申请一个有效的SelectSpec
 */
Tag_SelectSpec *OperationSpec_Manager::requestValidSelectSpec(llrp_u32_t selectid){
    vector<Tag_SelectSpec*> specs = this->findValidSelectByID(selectid);
    if(specs.size()<=0){
        return NULL;
    }else{//对于可能的多个查询结果只返回第一个。（所有有效的SelectSpec的SelectID应不相同，所以只可能有一个）
        specs.at(0)->retain(); //所有SPEC类，每申请一次均应保留一次。
        return specs.at(0);
    }
}

/**
 * @brief OperationSpec_Manager::releaseInvalidSpecs
 * 释放无效规则所占用的空间
 */
void OperationSpec_Manager::releaseInvalidSpecs(){
    bool haserase = false;
    for(list<Tag_SelectSpec*>::iterator it=m_pSelectSpecList->begin();
        it!=m_pSelectSpecList->end();){
        //printf("b0.................................\n");
        list<Tag_SelectSpec*>::iterator tempit = it;
        it++;
        Tag_SelectSpec *pspec = *tempit;
        //printf("spec->isValid=%d,pspec->retaincount=%d\n",pspec->isValid,pspec->getRetainCount());

        if(pspec->isValid==false&&pspec->isRetainZero()){
            printf("real delete select spec,retain count = %d......................!\n",pspec->getRetainCount());
            m_pSelectSpecList->erase(tempit);
            printf("select spec id=%d....................\n",pspec->getSelectSpec()->getSelectSpecID());
            //printf("A0..............................\n");
            delete pspec;
            haserase = true;
            //printf("A1.....................\n");
        }
    }
    if(haserase==true){
        m_SelectSpecList_IT = m_pSelectSpecList->begin(); //每次有删除操作后，将迭代器归为begin;
    }

    for(list<Tag_AccessSpec*>::iterator it=m_pAccessSpecList->begin();
        it!=m_pAccessSpecList->end();){
        list<Tag_AccessSpec*>::iterator tempit = it;
        it++;
        Tag_AccessSpec *pspec = *tempit;
        //printf("spec->isValid=%d,pspec->retaincount=%d\n",pspec->isValid,pspec->getRetainCount());
        if(pspec->isValid==false&&pspec->isRetainZero()){
            printf("real delete access spec,retain count = %d......................!\n",pspec->getRetainCount());
            delete pspec;
            m_pAccessSpecList->erase(tempit);
        }
    }

}

Tag_SelectSpec* OperationSpec_Manager::nextTagSelectSpec(){
    Tag_SelectSpec* pspec = NULL;

    //printf("m_pSelectSpecList->size()=%d\n",m_pSelectSpecList->size());
    while(true){
        if(m_pSelectSpecList->begin()==m_pSelectSpecList->end()){//如列表为空，直接返回空指针
            //printf("a0......................\n");
            pspec = NULL;
            break;
        }

        pspec = *m_SelectSpecList_IT;
        if(pspec->isValid==true){ //如果是有效的规则，则退出，并指向下一个
            m_SelectSpecList_IT++;
            if(m_SelectSpecList_IT==m_pSelectSpecList->end()){ //如果已超出范围，则回到最初
                //printf("a2......................\n");
                m_SelectSpecList_IT = m_pSelectSpecList->begin();
            }
            break;
        }

        m_SelectSpecList_IT++; //这里的m_SelectList_IT因为其它地方的限制，肯定不会超出end的范围
        if(m_SelectSpecList_IT==m_pSelectSpecList->end()){ //如果没找到，就复位迭代器，并跳出循环，结束查找
            //printf("a2......................\n");
            m_SelectSpecList_IT = m_pSelectSpecList->begin();
            break;
        }

    }

    return pspec;
}

vector<CSelectSpec*> OperationSpec_Manager::getSelectSpecs(){
    vector<CSelectSpec*> specs;
    for(list<Tag_SelectSpec*>::iterator it=m_pSelectSpecList->begin();
        it!=m_pSelectSpecList->end();it++){
        Tag_SelectSpec *tagselectspec = *it;
        CAddSelectSpec *addselectspec = (CAddSelectSpec*)HbFrame_Operation::copyMessage(tagselectspec->getAddSelectSpec());
        specs.push_back(addselectspec->getSelectSpec());
        addselectspec->m_listAllSubParameters.clear();//打断CAddSelectSpec对象与CSelectSpec对象的联系。
        delete addselectspec;//将之删除
    }
    return specs;
}

vector<CAccessSpec*> OperationSpec_Manager::getAccessSpecs(){
    vector<CAccessSpec*> specs;
    for(list<Tag_AccessSpec*>::iterator it=m_pAccessSpecList->begin();
        it!=m_pAccessSpecList->end();it++){
        Tag_AccessSpec *tagaccessspec = *it;
        CAddAccessSpec *addaccessspec = (CAddAccessSpec*)HbFrame_Operation::copyMessage(tagaccessspec->getAddAccessSpec());
        specs.push_back(addaccessspec->getAccessSpec());
        addaccessspec->m_listAllSubParameters.clear();
        delete addaccessspec;
    }
    return specs;
}

void OperationSpec_Manager::writePersisSelect(CAddSelectSpec *pAddSelectSpec){    
   printf("A0..........................\n");
	if(pAddSelectSpec!=NULL){
    unsigned char buf[MAX_TX_LEN];
		memset(buf,0,sizeof(buf));
		HbFrame_Operation::printMessage(pAddSelectSpec);
    int msglen = HbFrame_Operation::putMessageToBuf(pAddSelectSpec,buf,MAX_TX_LEN);
		printf("msglen :%d \n",msglen);
		//写入持久化规则到flash continueSpc_start启示地址
		EN25Q256_Write((u8*)buf,continueSelectSSpc_start,msglen);	
		//数据比对
		
		//写入flash标志位读卡规则存储成功			
		unsigned char tmp = flash_Isok;
		EN25Q256_Write(&tmp,continueSelectSpc_flag,1);		
		
		printf("write current select spec file success!\n");
//		for(int i = 0;i<msglen;i++)
//		{
//			printf("%x",buf[i]);
//		}
//		printf("\n");
//		printf("read .............................................\n");
//    memset(buf,0,sizeof(buf));
//		//写入持久化规则到flash continueSpc_start启示地址
//		EN25Q256_Read((u8* )buf,continueSelectSSpc_start,msglen);	
//		for(int i = 0;i<msglen;i++)
//		{
//			printf("%x",buf[i]);
//		}
//    CMessage *pmsg = HbFrame_Operation::getMessageFromBuf(buf,msglen);		
//		HbFrame_Operation::printMessage(pmsg);	
//	  printf("read current access spec file success!\n");			
	}
	
    //先判断文件夹是否存在，不存在则建立一个。
    //printf("A0..........................\n");
//		if(NULL==opendir(WORK_DIR)){
//				mkdir(WORK_DIR,S_IRUSR|S_IWUSR);
//		}
//		chmod(WORK_DIR, S_IRUSR|S_IWUSR); //修改权限
//		//printf("A1..........................\n");
//		//先写入selectspec的xml字串
//		if(pSelectSpec!=NULL){
//				//printf("get select spec xml..............\n");
//				string xmlstring = HbFrame_Operation::getXmlFromParameter(pSelectSpec);
//				//printf("xml is %s\n",xmlstring.c_str());

//				string filename = "SelectSpec";
//				filename = filename + std::to_string(selectid) + ".xml";
//				filename = WORK_DIR + filename;
//				int fd = open(filename.c_str(),O_WRONLY|O_CREAT|O_TRUNC);
//				if(fd<0){
//						printf("open current select spec file fail!\n");
//				}else{
//						fchmod(fd, S_IRUSR|S_IWUSR);
//						int len = xmlstring.length();
//						int res = write(fd,xmlstring.c_str(),len);
//						if(res!=len){
//								printf("write current select spec file fail!\n");
//								close(fd);
//						}else{
//								printf("write current select spec file success!\n");
//								close(fd);
//						}
//						sync();
//				}
//		}	
	
}

void OperationSpec_Manager::writePersisAccess(llrp_u32_t accessid,CAccessSpec *pAccessSpec){
//   printf("A1..........................\n");
//	//先写入selectspec的xml字串
//	if(pAccessSpec!=NULL){
//			//printf("get select spec xml..............\n");
//			string xmlstring = HbFrame_Operation::getXmlFromParameter(pAccessSpec);
//			printf("xml is %s\n",xmlstring.c_str());
//			int len = xmlstring.length();
//		  printf("len :%d \n",len);
//		  //写入持久化规则到flash continueSpc_start启示地址
//			EN25Q256_Write((u8*)xmlstring.c_str(),continueAccessSpc_start,len);
//			printf("write current access spec file success!\n");	
//	}
}

CSelectSpec* OperationSpec_Manager::ReadPersisSelect(llrp_u32_t selectid){
	
	
	
	
	
	
//    CSelectSpec * pselectspec = NULL;
//    //先读selectspec
//    string filename = "SelectSpec";
//    filename = filename + std::to_string(selectid) + ".xml";
//    //注意文件名应是全路径。
//    filename = WORK_DIR + filename;
//    //以下取得配置文件的长度
//    long filesize = 0;
//    struct stat statbuff;
//    if(stat(filename.c_str(), &statbuff) < 0){
//        printf("Get current select file size fail!\n");
//        pselectspec = NULL;
//    }else{
//       filesize = statbuff.st_size;
//        int fd=open(filename.c_str(),O_RDONLY);
//        if(fd<0){
//            printf("Open current select file fail!\n");
//            pselectspec = NULL;
//        }else{
//            printf("Open current select file success!\n");
//            char buf[filesize+1];
//            memset(buf,0x00,filesize+1);
//            int ret = 0;
//            ret = read(fd,buf,filesize);
//            if(ret==filesize){
//                printf("Read current select file success!\n");
//                string xmlstring(buf);
//                close(fd);
//                pselectspec = (CSelectSpec*)HbFrame_Operation::getParameterFromXml(xmlstring);
//            }else{
//                printf("Read current select file fail!\n");
//                close(fd);
//                pselectspec = NULL;
//            }
//        }
//    }
//    return pselectspec;
	return NULL;
}

CAccessSpec* OperationSpec_Manager::ReadPersisAccess(llrp_u32_t accessid){

//    CAccessSpec *paccessspec = NULL;
//    //读Accessspec
//    string filename = "AccessSpec";
//    filename = filename + std::to_string(accessid) + ".xml";
//    //注意文件名应是全路径。
//    filename = WORK_DIR + filename;
//    //以下取得配置文件的长度
//    long filesize = 0;
//    struct stat statbuff;
//    if(stat(filename.c_str(), &statbuff) < 0){
//        printf("Get current access file size fail!\n");
//        paccessspec = NULL;
//    }else{
//        filesize = statbuff.st_size;
//        int fd=open(filename.c_str(),O_RDONLY);
//        if(fd<0){
//            printf("Open current access file fail!\n");
//            paccessspec = NULL;
//        }else{
//            printf("Open current access file success!\n");
//            char buf[filesize+1];
//            memset(buf,0x00,filesize+1);
//            int ret = 0;
//            ret = read(fd,buf,filesize);
//            if(ret==filesize){
//                printf("Read current access file success!\n");
//                string xmlstring(buf);
//                //printf("%s\n",xmlstring.c_str());
//                close(fd);
//                paccessspec = (CAccessSpec*)HbFrame_Operation::getParameterFromXml(xmlstring);
//            }else{
//                printf("Read current select file fail!\n");
//                close(fd);
//                paccessspec = NULL;
//            }

//        }
//    }
//    return paccessspec;
	return NULL;
}

bool OperationSpec_Manager::deletePersisSelect(llrp_u32_t selectid){
			//写入flash标志位读卡规则存储成功			
		unsigned char tmp = flash_Notok;
		EN25Q256_Write(&tmp,continueSelectSpc_flag,1);	
	
	  return true;
	
//    bool success = true;

//    string filename = "SelectSpec";
//    filename = filename + std::to_string(selectid) + ".xml";
//    filename = WORK_DIR + filename;
//    if(remove(filename.c_str())==0){
//        printf("remove select spec %d file success!\n",selectid);
//    }else{
//        success = false;
//        printf("remove  select spec %d file fail!\n",selectid);
//    }

//    return success;
}

bool OperationSpec_Manager::deletePersisAccess(llrp_u32_t accessid){
//    bool success = true;
//    string filename = "AccessSpec";
//    filename = filename + std::to_string(accessid) + ".xml";
//    filename = WORK_DIR + filename;
//    if(remove(filename.c_str())==0){
//        printf("remove access spec %d file success!\n",accessid);
//    }else{
//        success = false;
//        printf("remove access spec %d file fail!\n",accessid);
//    }
//    return success;
}

/**
 * @brief OperationSpec_Manager::readAllPersisSelect
 * @return
 * 从磁盘上读取所有持久化规则
 */
vector<CAddSelectSpec*> OperationSpec_Manager::readAllPersisSelect(){
    unsigned char buf[MAX_TX_LEN];
    vector<CAddSelectSpec*> addselectspecs;		
		printf("\n");
		printf("read .............................................\n");
		//读取flash 判断是否存储有持久化规则 没有直接退出
		unsigned char tmp = 0;
		EN25Q256_Read(&tmp,continueSelectSpc_flag,1);		
		if(tmp != flash_Isok) return addselectspecs;
	
    memset(buf,0,sizeof(buf));
	  //暂时检测到是读用户区0 105，读取6个用户区 200
	  //为保证后期存入指令加长扩大读取长度 
	  int msglen = 120;//暂时检测到是105，为保证后期存入指令加长扩大读取长度
		//写入持久化规则到flash continueSpc_start启示地址
		EN25Q256_Read((u8* )buf,continueSelectSSpc_start,msglen);	
//		for(int i = 0;i<msglen;i++)
//		{
//			printf("%x",buf[i]);
//		}
    //CMessage *pmsg = HbFrame_Operation::getMessageFromBuf(buf,msglen);		
		CAddSelectSpec *pmsg = (CAddSelectSpec *)HbFrame_Operation::getMessageFromBuf(buf,msglen);	
		HbFrame_Operation::printMessage(pmsg);	
	  printf("read current access spec file success!\n");

	   addselectspecs.push_back(pmsg);
	 return addselectspecs;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//    vector<CAddSelectSpec*> addselectspecs;
//    //遍历工作目录下的所有SelectSpec*.xml文件
//    DIR *dir;
//    struct dirent *ptr;
//    string path = WORK_DIR;
//    if ((dir=opendir(path.c_str())) == NULL)
//    {
//        perror("readAllPersisSelect:Open dir error...");
//        return addselectspecs;
//    }
//    while ((ptr=readdir(dir)) != NULL)
//    {
//        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
//            continue;
//        else if(ptr->d_type == 8)    ///file
//        {
//            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
//            string filename = ptr->d_name;

//            vector<string> splitstr =  General_Functions::splitString(filename,".");
//            if(splitstr.size()==2){
//                if(splitstr.at(0).compare(0,10,"SelectSpec")==0&&splitstr.at(1).compare("xml")==0){
//                    printf("filename is %s\n",filename.c_str());
//                    string idstr = splitstr.at(0).substr(10);
//                    int specid = stoul(idstr);
//                    printf("specid is %d\n",specid);
//                    CSelectSpec* pselectspec = this->ReadPersisSelect(specid);
//                    if(pselectspec!=NULL){
//                        CAddSelectSpec *pspec = (CAddSelectSpec*)HbFrame_Operation::genMessage(AddSelectSpec,0);
//                        pspec->setSelectSpec(pselectspec);
//                        addselectspecs.push_back(pspec);
//                    }
//                    //printf("addselectspecs.size()=%d\n",addselectspecs.size());
//                }
//            }
//        }
//        else if(ptr->d_type == 10)    ///link file
//        {
//        }
//        else if(ptr->d_type == 4)    ///dir
//        {
//        }
//    }
//    closedir(dir);
//    return addselectspecs;
//	return vector<CAddSelectSpec*>();
}

/**
 * @brief OperationSpec_Manager::readAllPersisAccess
 * @return
 * 从磁盘上读取所有持久化规则
 */
vector<CAddAccessSpec*> OperationSpec_Manager::readAllPersisAccess(){
//    vector<CAddAccessSpec*> addaccessspecs;
//    //遍历工作目录下的所有SelectSpec*.xml文件
//    DIR *dir;
//    struct dirent *ptr;
//    string path = WORK_DIR;
//    if ((dir=opendir(path.c_str())) == NULL)
//    {
//        perror("readAllPersisSelect:Open dir error...");
//        return addaccessspecs;
//    }
//    while ((ptr=readdir(dir)) != NULL)
//    {
//        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
//            continue;
//        else if(ptr->d_type == 8)    ///file
//        {
//            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
//            string filename = ptr->d_name;

//            vector<string> splitstr =  General_Functions::splitString(filename,".");
//            if(splitstr.size()==2){
//                if(splitstr.at(0).compare(0,10,"AccessSpec")==0&&splitstr.at(1).compare("xml")==0){
//                    printf("filename is %s\n",filename.c_str());
//                    string idstr = splitstr.at(0).substr(10);
//                    int specid = stoul(idstr);
//                    printf("specid is %d\n",specid);
//                    CAccessSpec* paccessspec = this->ReadPersisAccess(specid);
//                    if(paccessspec!=NULL){
//                        CAddAccessSpec *pspec = (CAddAccessSpec*)HbFrame_Operation::genMessage(AddAccessSpec,0);
//                        pspec->setAccessSpec(paccessspec);
//                        addaccessspecs.push_back(pspec);
//                    }
//                    //printf("addaccessspecs.size()=%d\n",addaccessspecs.size());
//                }
//            }
//        }
//        else if(ptr->d_type == 10)    ///link file
//        {
//        }
//        else if(ptr->d_type == 4)    ///dir
//        {
//        }
//    }
//    closedir(dir);
//    return addaccessspecs;
	return vector<CAddAccessSpec*>();
}
