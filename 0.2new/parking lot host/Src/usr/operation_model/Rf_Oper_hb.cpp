#include "Rf_Oper_hb.h"
#include "main_application.h"
#include "XML_Operation.h"
#include "general_functions.h"

Rf_Oper_HB::Rf_Oper_HB() {
	// TODO Auto-generated constructor stub
		// TODO Auto-generated constructor stub
	AA_ConfigParam = 0xAA00000000000000;
	AB_ConfigParam = 0xAB01000000000000; //0次，表示无限次读取
	//AB_ConfigParam = 0xAB01E80300000000; //1000
	//AB_ConfigParam = 0xAB01640000000000; //100
	//AB_ConfigParam = 0xAB01881300000000; //5000
    //this->setRf_Oper_NewCount(1000);

	AC_ConfigParam = 0xAC00000000000000;
	//AD_ConfigParam = 0xAD00025000010003; //频道0，天线2
	AD_ConfigParam = 0xAD00015000010003;
	//AD_ConfigParam = 0xAD00018002010003;

	
	
	 this->isRfOperStart = false;
	isSkippingAnt = false;
	ADRetryCount = 5;
    needSendParam = false;
    m_pCurrentSelectSpec = NULL;
    m_pCurrentAccessSpec = NULL;
    m_pCurrentRfSpec = NULL;
    m_pCurrentAntSpec = NULL;

    m_Filterms = 0;
    /////////////////////////////////////////////////////
    m_CurrentAntIDIndex = 0;
    m_AntChangeDelay = 0;
    m_FreqChangeDelay = 0;
	
//	this->powerToCalibration.clear();
//	currentPowerID = DEFAULT_POWERID;
	
	this->m_AntChangeDelay = SWITCHANT_DELAY*3;

}

Rf_Oper_HB::~Rf_Oper_HB() {
	// TODO Auto-generated destructor stub

}


/**
 * @brief Rf_Oper_HB::setSelectAccessParam
 * @param pSpec
 * @param accessIndex
 * @return
 * 配置select和access的参数
 * 并产生实际参数并向安全模块发送工作参数
 */
bool Rf_Oper_HB::setSelectAccessParam(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec){
    //如果要设置的参数与当前参数一至，什么也不做，直接返回真
    if(pTagSelectSpec==m_pCurrentSelectSpec&&pTagAccessSpec==m_pCurrentAccessSpec&&pRfSpec==m_pCurrentRfSpec){
        return true;
    }

//    printf("do set SelectAccessParam!\n");
    m_pCurrentSelectSpec = pTagSelectSpec;
    m_pCurrentAccessSpec = pTagAccessSpec;
    m_pCurrentRfSpec = pRfSpec;
    needSendParam = true;

    AB_ConfigParam = 0xAB01000000000000; //0次，表示无限次读取

    //设置当前Select的相关参数
    pTagSelectSpec->currentpTagAccessSpec = pTagAccessSpec;
    pTagSelectSpec->currentAntSpecIndex = antSpecIndex;
    if(pRfSpec!=NULL){
        pTagSelectSpec->currentRfSpecID = pRfSpec->getRfSpecID();
    }else{
        pTagSelectSpec->currentRfSpecID = 0; //因为RfSpecID规定必须是非0值。故用0表示是无效
    }
    pTagSelectSpec->currentOperBankIDs.clear();

    //2017.06.09新增，by lijin。用以配置安全模块是否过滤数据
    if(pTagSelectSpec->currentpTagAccessSpec==NULL){//没有Access，则取默认值进行配置
        //this->setSecReadMode(this->getDefaultReadMode());
        setTagDataFilter(this->getDefaultReadMode());
    }else{ //有Access，则检查是否有相关配置，没有则取默认值进行配置
        //printf("a0.......................\n");
        CAccessCommand *pcmd = pTagSelectSpec->currentpTagAccessSpec->getAccessSpec()->getAccessCommand();
        if(pcmd!=NULL){
            //printf("a1.......................\n");
            CSecurityModuleSpec *psecspec = pcmd->getSecurityModuleSpec();
            if(psecspec!=NULL){//有指定
                //printf("a3.......................\n");
                //this->setSecReadMode(psecspec->getReadMode());
                setTagDataFilter(psecspec->getReadMode());
            }else{
                //printf("a4.......................\n");
                //accesscommd中没有指定，则取默认值进行配置
                //this->setSecReadMode(this->getDefaultReadMode());
                setTagDataFilter((this->getDefaultReadMode()));
            }
        }else{
            //printf("a2.......................\n");
            //this->setSecReadMode(this->getDefaultReadMode());
            setTagDataFilter(this->getDefaultReadMode());
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////

    if(pTagSelectSpec->currentpTagAccessSpec==NULL){//没有Access操作
//        printf("no access\n");
        if(pRfSpec!=NULL){//这里同样不会为空指针，
//            printf("AccessSpec is NULL!use no continue mode!\n");
            pTagSelectSpec->hasContinueOperation = false; //没有Ａccess，肯定没有continue操作
            return this->setNoContinueOpParam(pRfSpec,NULL,pTagSelectSpec);
        }
        //return false;
    }else{ //有Access操作。
 //       printf("has access\n");

        CAccessCommand *paccesscmd = pTagSelectSpec->currentpTagAccessSpec->getAccessSpec()->getAccessCommand();

        //如果AccessCommand有匹配条件，则只进行Select设置，没有，则根据所有Op配置成读多分区模式。
        CHbTargetTag *ptargettag = *(paccesscmd->getHbMatchSpec()->beginHbTargetTag());//这里简化为只取第一个匹配规则
        bool needmatch = false;
        /*llrp_u1v_t mask = ptargettag->getTagMask();

        printf("mask is:");
        for(int i=0;i<(mask.m_nBit+7u)/8u;i++){
            printf("0x%02x,",mask.m_pValue[i]);
        }
        printf("\n");

        //mask为非零值，即表示要匹配
        for(int i=0;i<(mask.m_nBit+7u)/8u;i++){
            if(mask.m_pValue[i]>0){
                needmatch = true;
                break;
            }
        }*/

        //判断是否有写操作
        bool haswriteop = false;
        for(list<CParameter*>::iterator it=paccesscmd->beginOpSpec();
                it!=paccesscmd->endOpSpec();it++){
            CParameter *popspec = *it;
            if(popspec->m_pType->m_TypeNum+PARAM_BASE==HbWriteSpec){
                haswriteop = true;
                break;
            }
        }
//        printf("needmatch==%d,haswriteop=%d\n",needmatch,haswriteop);
        if(needmatch==true||haswriteop==true){//要匹配或有写操作，则采用continue操作模式
            if(pRfSpec!=NULL){
//                printf("AccessSpec is not NULL!use continue mode!\n");
                pTagSelectSpec->hasContinueOperation = true;
                return this->setContinueOpParam(pRfSpec,pTagSelectSpec);
                //return false;
            }
        }else{//无匹配及无写操作，则配置成非continue操作
            if(pRfSpec!=NULL){//这里同样不会为空指针，
//                printf("AccessSpec is not NULL!use no continue mode!\n");
                pTagSelectSpec->hasContinueOperation = false;
                return this->setNoContinueOpParam(pRfSpec,pTagAccessSpec->getAccessSpec(),pTagSelectSpec);
            }
        }

    }

}

/*
 * 传入的是一对SelectSpec和AccessSpec
 * 如果pAccessSpec为NULL，即等同于setSelectMemParam函数的作用
 * 如不为NULL,则等同于不对AccessSpec做匹配选择，直接读AccessSpec所指定的分区信息，可为单分区，可为多分区。
 * 此时，selecSpec中传入的参数不起作用。
 */
bool Rf_Oper_HB::setNoContinueOpParam(CRfSpec *pRfSpec, CAccessSpec *pAccessSpec, Tag_SelectSpec *pTagSelectSpec){

		if(pRfSpec==NULL){
			printf("Rf_Oper_New:warnning,pRfSpec is null!\n");
			return false;
		}
	
		/*if(pAccessSpec==NULL){
			//printf("AccessSpec is NULL!use select mode!\n");
			return false;
		}*/
	   //==============================================//
			pTagSelectSpec->hasReadRepeat = false; //复位有重复读标志
	
			//这里对AB的配置必须加，否则会读卡失败
			llrp_u8_t selecttype = pRfSpec->getSelectType();
	
			AB_ConfigParam &= 0xFFFFFFFFFFFFFF00;
	
			STRUCT_M2SEC_FRAME *pframe = NULL;
	
	
			if(pAccessSpec==NULL){ //无AccessSpec
				printf("selecttype=%d\n",selecttype);
				if(selecttype==0){//是盘点
					AB_ConfigParam |= 0x00;
					pframe = this->genSecReadSetFrame(NULL,0);
				}else{//是读
					AB_ConfigParam |= 0x01;
					Struct_TagBank_RWInfo bankinfos[6]; //最多6个分区。规范中分区5不能读，故最多5个分区
					int bankcount = 0;
					CMemoryBank *pbank = pRfSpec->getMemoryBank();
					if(pbank==NULL){
						printf("Memory bank is NULL，use default!\n");
						pbank = this->getDefaultMemoryBank();
						pRfSpec->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
					}
					bankinfos[bankcount++] = this->getBankinfoFromMemBank(pbank);
	
					//pTagSelectSpec->currentReadUserCount = bankcount;
					pframe = this->genSecReadSetFrame(bankinfos,bankcount);
				}
	
			}else{//有AccessSpec
				//AB_ConfigParam |= 0x01;
	
	
				AB_ConfigParam |= 0x01;
	
				///////////////////////////////////////////////////////////
				Struct_TagBank_RWInfo bankinfos[6]; //最多6个分区。规范中分区5不能读，故最多5个分区
				int bankcount = 0;
				//如果Select有读，则将Select中的读分区加入。
				int selectuserid = -1;
				if(selecttype==1){ //有Select读
					CMemoryBank *pbank = pRfSpec->getMemoryBank();
					if(pbank==NULL){
						printf("Memory bank is NULL，use default!\n");
						pbank = this->getDefaultMemoryBank();
						pRfSpec->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
					}
					 selectuserid = pbank->getMemoryBankID();
					 bankinfos[bankcount++] = this->getBankinfoFromMemBank(pbank);
	
				}
				//将AccessSpec中的读分区信息全部取出，构成读多分区的配置，发给安全模块
				this->currentUserIDtoSpecID.clear();
				this->currentReadSpecIDs.clear();
				this->currentUserIDToReadReslt.clear();
				CAccessCommand *pcommand = pAccessSpec->getAccessCommand();
				for(list<CParameter*>::iterator it= pcommand->beginOpSpec();it!=pcommand->endOpSpec();it++){
					//printf("zzzzzzzzzzzzzzzzzzzzzz\n");
					CParameter *popspec= *it;
					switch(popspec->m_pType->m_TypeNum+PARAM_BASE)
					{
					case HbReadSpec:
						{
							if(bankcount<5){ //目前规范规定分区5不能读，故最多只能有5个分区。即0～4分区
								CHbReadSpec *preadspec = (CHbReadSpec *)popspec;
								CMemoryBank *pbank = preadspec->getMemoryBank();
								if(pbank==NULL){
									printf("Memory bank is NULL，use default!\n");
									pbank = this->getDefaultMemoryBank();
									preadspec->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
								}
								if(pbank->getMemoryBankID()==selectuserid){//分区已在select中读过，则不再读该分区，并将原分区读改为读全区
									bankinfos[0].BankReadFlag = 2;
									printf("pTagSelectSpec->hasReadRepeat = true\n");
									pTagSelectSpec->hasReadRepeat = true;
									break;
								}
								Struct_TagBank_RWInfo bankinfo = this->getBankinfoFromMemBank(pbank);
								bankinfos[bankcount++] = bankinfo;
								this->currentUserIDtoSpecID.insert(pair<int,int>(bankinfo.BankNum,preadspec->getOpSpecID()));
								currentReadSpecIDs.push_back(preadspec->getOpSpecID());
	
								this->currentUserIDToReadReslt.insert(pair<int,CHbReadSpec*>(bankinfo.BankNum,preadspec));
							}
	
						}
						break;
					case HbWriteSpec://在非continue操作中，不能进行写操作。故不处理写op
						break;
					case ClientRequestSpec:
						break;
	
					}//end of switch
				}//end of for
				printf("setNoContinueParam	end .......................................\n");
				printf("bankcount=%d\n",bankcount);
				currentAccessBankCount = bankcount; //保存要读取的分区数，以确保单次操作时，获取所有的分区数据。
				//pTagSelectSpec->currentReadUserCount = bankcount;
				pframe = this->genSecReadSetFrame(bankinfos,bankcount);
			}
			//AB_ConfigParam = 0xAB01000000000001;
			printf("SetAccessParam:AB_ConfigParam = %llx\n",AB_ConfigParam);
			//==============================================//
			if(pframe==NULL){
				printf("Rf_Oper_New:gen set frame fail!\n");
				return false;
			}
	
			//////////////////////////////////////
			int c = pframe->DataBuf[0];
			for(int i=0;i<c;i++){
				pTagSelectSpec->currentOperBankIDs.push_back(pframe->DataBuf[1+i*7]);
			}
	
			/*for(int i=0;i<c;i++){
				printf("pTagSelectSpec->currentOperBankIDs.at(%d)=%d,",i,pTagSelectSpec->currentOperBankIDs.at(i));
			}
			printf("\n");*/
			//////////////////////////////////////
	
			//发送配置帧
			printf("Access Sec module set frame is ");
			MCUToSecureComm::printfSecFrame(pframe);
	
			if(m_pM2SecComm->sendFrameToSecure(pframe)){
				printf("Rf_Oper_New:send access set secure module workmode frame success!\n");
			}else{
				printf("Rf_Oper_New:send access set secure module workmode frame fail!\n");
			}
			m_pM2SecComm->removeFrame(pframe);
			pframe = NULL;
	
			if(m_pM2SecComm->waitSecReadyForComm()<0){
				printf("Rf_Oper_New:wait set frame overtime!\n");
				return false;
			}
	
			pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_SETACK_FRAME);
			if(pframe==NULL){
				printf("Rf_Oper_New:Read set ack  from Secure fail!\n");
				return false;
			}else{
				printf("Rf_Oper_New:ack frame is :");
				MCUToSecureComm::printfSecFrame(pframe);
				//返回的是配置应答帧
				if((pframe->Type&0xF0)==0x20){ //位与是为去除版本差异
					if(pframe->OperId==6){
						if(pframe->DataBuf[0]==0){
							printf("Rf_Oper_New:set work mode success!\n");
							m_pM2SecComm->removeFrame(pframe);
							return true;
						}else{
							printf("Rf_Oper_New:set work mode fail!\n");
							m_pM2SecComm->removeFrame(pframe);
							return false;
						}
					}else{
						printf("Rf_Oper_New:Readed ack is not set work mode ack!\n");
						m_pM2SecComm->removeFrame(pframe);
						return false;
					}
				}else{
					printf("Rf_Oper_New:Readed frame is not set ack!\n");
					m_pM2SecComm->removeFrame(pframe);
					return false;
				}
	}

}



/*
 * 配置Select操作参数，同时，将参数发往安全模块
 */
bool Rf_Oper_HB::setContinueOpParam(CRfSpec *pSpec,Tag_SelectSpec *pTagSelectSpec){
	//printf("D1\n");
	if(pSpec==NULL) return false;

	//printf("D2\n");

	llrp_u8_t selecttype = pSpec->getSelectType();

	CMemoryBank *pbank = pSpec->getMemoryBank();

	AB_ConfigParam &= 0xFFFFFFFFFFFFFF00;
	if(selecttype==0){
		//AB_ConfigParam |= 0x00;
		AB_ConfigParam |= 0x02;
	}else{
		//AB_ConfigParam |= 0x01;
		//为测试continue操作加入
		AB_ConfigParam |= 0x02; //通知FPGA，接下来的是continue操作
	}
	//AB_ConfigParam = 0xAB01000000000001;
	printf("AB_ConfigParam = %llx\n",AB_ConfigParam);

	STRUCT_M2SEC_FRAME *pframe = NULL;

	if(selecttype==0){//盘点
		//printf("D3\n");
        if(pTagSelectSpec->currentpTagAccessSpec==NULL){ //是盘点而又没有Access，则下盘点帧
			pframe = this->genSecReadSetFrame(NULL,0);
			currentAccessBankCount = 0;
            //pTagSelectSpec->currentReadUserCount = 0;
		}else{ //是盘点又有Access
            CAccessSpec *paccessspec = pTagSelectSpec->currentpTagAccessSpec->getAccessSpec();
			CAccessCommand *paccesscmd = paccessspec->getAccessCommand();
			if(paccesscmd->beginOpSpec()!=paccesscmd->endOpSpec()){
				CParameter *popspec = *(paccesscmd->beginOpSpec());
				switch(popspec->m_pType->m_TypeNum+PARAM_BASE){
				case HbReadSpec: //是读，则将第一个读配入Select
				{
					CMemoryBank *pbank = ((CHbReadSpec *)popspec)->getMemoryBank();
					if(pbank==NULL){
                        printf("Memory bank is NULL，use default!\n");
                        pbank = this->getDefaultMemoryBank();
                        ((CHbReadSpec *)popspec)->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
                    }
                    Struct_TagBank_RWInfo bankinfo;
                    bankinfo = this->getBankinfoFromMemBank(pbank);
                    pframe = this->genSecReadSetFrame(&bankinfo,1);

				}
					break;
				case HbWriteSpec: //是写，则将第一个要写的分区配入Select中读一次
				{
					//printf("D4........................\n");
					CHbWriteSpec *pwritespec = (CHbWriteSpec *)popspec;
					CMemoryBank *pbank = (CMemoryBank*)HbFrame_Operation::genParam(MemoryBank,0,NULL);
					pbank->setMemoryBankID(pwritespec->getMemoryBankID());
					pbank->setCount(pwritespec->getData().m_nValue);
					pbank->setPointer(pwritespec->getPointer());
					pbank->setReadType(1); //按区读
					pbank->setBankType(1); //读上半区，只要读就能进行continue操作，为效率起见只读半区（只对0,2分区有效，其它分区还是读全区）
					if(pbank==NULL){
                        printf("Memory bank is NULL，use default!\n");
                        pbank = this->getDefaultMemoryBank();
                    }
                    Struct_TagBank_RWInfo bankinfo;
                    bankinfo = this->getBankinfoFromMemBank(pbank);
                    pframe = this->genSecReadSetFrame(&bankinfo,1);
                    delete pbank;

				}
					break;
				default:
					return false;
					break;
				}

			}
		}

	}else if(selecttype==1){//读
		//printf("D5\n");
        if(pbank==NULL){
            printf("Memory bank is NULL，use default!\n");
            pbank = this->getDefaultMemoryBank();
            pSpec->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
        }
			Struct_TagBank_RWInfo bankinfo;
			bankinfo = this->getBankinfoFromMemBank(pbank);
			pframe = this->genSecReadSetFrame(&bankinfo,1);

	}
	if(pframe==NULL){
        printf("Rf_Oper_New:gen set frame fail!\n");
		return false;
	}
	//发送配置帧

	printf("Select Sec module set frame is :");
    MCUToSecureComm::printfSecFrame(pframe);
	if(m_pM2SecComm->sendFrameToSecure(pframe)){
        printf("Rf_Oper_New:send select set secure module workmode frame success!\n");
	}else{
        printf("Rf_Oper_New:send select set secure module workmode frame fail!\n");
	}
	m_pM2SecComm->removeFrame(pframe);
	pframe = NULL;

	if(m_pM2SecComm->waitSecReadyForComm()<0){
        printf("Rf_Oper_New:wait set frame overtime!\n");
		return false;
	}

	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_SETACK_FRAME);
	if(pframe==NULL){
        printf("Rf_Oper_New:Read set ack  from Secure fail!\n");
		return false;
	}else{
        printf("Rf_Oper_New:ack frame is :");
        MCUToSecureComm::printfSecFrame(pframe);
		//返回的是配置应答帧
		if((pframe->Type&0xF0)==0x20){
			if(pframe->OperId==6){
				if(pframe->DataBuf[0]==0){
                    printf("Rf_Oper_New:set work mode success!\n");
					m_pM2SecComm->removeFrame(pframe);
					return true;
				}else{
                    printf("Rf_Oper_New:set work mode fail!\n");
					m_pM2SecComm->removeFrame(pframe);
					return false;
				}
			}else{
                printf("Rf_Oper_New:Readed ack is not set work mode ack!\n");
				m_pM2SecComm->removeFrame(pframe);
				return false;
			}
		}else{
            printf("Rf_Oper_New:Readed sec frame is not set ack!\n");
            MCUToSecureComm::printfSecFrame(pframe);
			m_pM2SecComm->removeFrame(pframe);
			return false;
		}

	}

}



/*
 * 这里返回的帧一定要手工调用remove删除
 */
STRUCT_M2SEC_FRAME* Rf_Oper_HB::genSecReadSetFrame(Struct_TagBank_RWInfo *pBankInfos,int infoCount){
	int contentlen = 7*infoCount+2;
	unsigned char *databuf =  new unsigned char[contentlen] ;

	databuf[0] = 6; //固定为6
	databuf[1] = infoCount;
	if(infoCount>0){
		int pos = 2;
		for(int i=0;i<infoCount;i++){
			databuf[pos++] = pBankInfos[i].BankNum;
			databuf[pos++] = pBankInfos[i].BankReadFlag;
			llrp_u8_t temp = pBankInfos[i].BankCryptFlag;
			temp = temp<<4;
			temp = temp|pBankInfos[i].BankReadSpeedFlag;
			databuf[pos++] = temp;

			databuf[pos++] = pBankInfos[i].BankReadPoint>>8;
			databuf[pos++] = pBankInfos[i].BankReadPoint;
			databuf[pos++] = pBankInfos[i].BankReadCount>>8;
			databuf[pos++] = pBankInfos[i].BankReadCount;
		}
	}
	/*printf("databuf is:\n");
	for(int i=0;i<contentlen;i++){
		printf("%02x,",databuf[i]);
	}
	printf("\n");*/
	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_SET_FRAME,databuf,contentlen);
	delete []databuf;//对于安全模块的配置使用完销毁
	return pframe;
}

CMemoryBank * Rf_Oper_HB::getDefaultMemoryBank(){
    CMemoryBank *pbank = (CMemoryBank*)HbFrame_Operation::genParam(MemoryBank,0,NULL);
    pbank->setMemoryBankID(0);
    pbank->setCount(10); //读10字，因为下面设为按全区，所以不起作用
    pbank->setPointer(4); //不读前四个字（不读密码区数据）
    pbank->setReadType(1); //按区读
    pbank->setBankType(2); //读全区
}


STRUCT_M2SEC_FRAME *Rf_Oper_HB::readTagData(){
    //读取安全模块数据
    STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_TAGDATA_FRAME);
    if(pframe==NULL){
        //printf("Rf_Oper_New_readTagData:getFrameFromSecure fail!\n");
        return NULL;
    }
    //printf("readed sec data!\n");
    //MCUToSecureComm::printfSecFrame(pframe);

    if(pframe->Head==0xAB&&(pframe->Type&0xF0)==0x50){//是识读信息上传帧才处理
			return pframe;
    }else{
        MCUToSecureComm::removeFrame(pframe);
        return NULL;
    }
}

/*
 * 读分区操作
 * 返回安全模块返回的帧
 * 操作时，标签应处于开放状态
 */
STRUCT_M2SEC_FRAME* Rf_Oper_HB::readTagBankData(llrp_u8v_t targettid,CHbReadSpec *spec){
	CMemoryBank *pbank = spec->getMemoryBank();
	if(pbank==NULL){
        printf("Memory bank is NULL，use default!\n");
        pbank = this->getDefaultMemoryBank();
        spec->setMemoryBank(pbank); //将新建的memorybank加入规则以便 于删除
	}

	Struct_TagBank_RWInfo bankinfo = this->getBankinfoFromMemBank(pbank);

	//================================//
	unsigned char contentbuf = 0;

	contentbuf = bankinfo.BankNum; //放入分区号（只会占用低4位

	contentbuf |= bankinfo.BankReadFlag<<4;
	contentbuf |= bankinfo.BankCryptFlag<<6;
	contentbuf |= bankinfo.BankReadSpeedFlag<<7;

	STRUCT_M2SEC_FRAME *pframe = this->m_pM2SecComm->creatFrame(M2SEC_READBANK_FRAME,&contentbuf,1);
	if(pframe!=NULL){
		//this->printfSecFrame(pframe);
		if(m_pM2SecComm->sendFrameToSecure(pframe)){
            //printf("Rf_Oper_New:send read bank request frame success!\n");
		}else{
            printf("Rf_Oper_New:send read bankrequest frame fail!\n");
		}
		m_pM2SecComm->removeFrame(pframe);
		pframe = NULL;

		if(m_pM2SecComm->waitSecReadyForComm()<0){
            printf("Rf_Oper_New:wait write bank ack frame overtime!\n");
			return NULL;
		}

		pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_READBANKACK_FRAME);
		if(pframe==NULL){
            printf("Rf_Oper_New:Read bank ack  from Secure fail!\n");
			return NULL;
		}else{
            //printf("Rf_Oper_New:Read bank ack  from Secure success!\n");
			//this->printfSecFrame(pframe);
			return pframe;
		}
	}else{
		return NULL;
	}

}

/*
 * 写之前应执行一次读相应分区的操作。
 * 返回的是模块返回的帧
 */
STRUCT_M2SEC_FRAME* Rf_Oper_HB::writeTagBankData(llrp_u8v_t targettid,CHbWriteSpec *spec){
	llrp_u8_t bankid = spec->getMemoryBankID();
	llrp_u16_t point = spec->getPointer()+(4-START_USER_POINT);
	llrp_u16v_t data = spec->getData();

	if(data.m_nValue>32){
        printf("Rf_Oper_HB:write data len too long!\n");
		return NULL;
	}

	int contentlen = 11+data.m_nValue*2;
	llrp_u8_t content[11+32];
	memset(content,0x00,contentlen);

	int pos = 0;
	memcpy(content+pos,targettid.m_pValue,targettid.m_nValue);
	pos += 8;
	content[pos++] = bankid;
	content[pos++] = point;
	content[pos++] = data.m_nValue;
	memcpy(content+pos,data.m_pValue,data.m_nValue*2);
	pos += data.m_nValue*2;

	//printf("pos=%d\n",pos);

	/*printf("content is ");
	for(int i=0;i<contentlen;i++){
		printf("0x%02x,",content[i]);
	}
	printf("\n");*/

	STRUCT_M2SEC_FRAME *pframe = this->m_pM2SecComm->creatFrame(M2SEC_WRITEBANK_FRAME,content,pos);
	if(pframe!=NULL){
		//发送写分区请求帧
        //this->printfSecFrame(pframe);
		if(m_pM2SecComm->sendFrameToSecure(pframe)){
            //printf("Rf_Oper_New:send write bank request frame success!\n");
		}else{
            printf("Rf_Oper_New:send wrtie bankrequest frame fail!\n");
		}
		m_pM2SecComm->removeFrame(pframe);
		pframe = NULL;

		if(m_pM2SecComm->waitSecReadyForComm()<0){
            printf("Rf_Oper_New:wait write bank ack frame overtime!\n");
			return NULL;
		}

		pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_WRITEBANKACK_FRAME);
		if(pframe==NULL){
            printf("Rf_Oper_New:Read write bank ack  from Secure fail!\n");
			return NULL;
		}else{
            //printf("Rf_Oper_New:Read write bank ack  from Secure success!\n");
            //this->printfSecFrame(pframe);
			if(pframe->OperId == 0){
                //printf("Rf_Oper_New:write bank ack!\n");
				switch(pframe->DataBuf[0]){
				case 0:
                    //printf("Rf_Oper_New:write bank success!\n");
					break;
				case 1:
                    printf("Rf_Oper_New:Permission denied!\n");
					break;
				case 2:
                    printf("Rf_Oper_New:write bank fail!\n");
					break;
				case 3:
                    printf("Rf_Oper_New:tag is not target tag!\n");
					break;
				case 4:
                    printf("Rf_Oper_New:write frame format error!\n");
					break;
				default:
                    printf("Rf_Oper_New:unknown write bank ack!\n");
					break;
				}
			}else{
                printf("Rf_Oper_New:no write bank ack!\n");
			}
			return pframe;
		}

	}else{
		return NULL;
	}


}