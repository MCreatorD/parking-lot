#include "thread_runnable.h"

#include <stdio.h>
#include <unistd.h>

Thread_Runnable::Thread_Runnable(){
    m_RunnableList.clear();
    pthread_mutex_init(&m_RunnableMutex,NULL);
    m_pOnceRunnable = NULL;
}

/**
 * @brief createThread
 * 这里要注意，传入的函数中，必须要引用类对象中的m_ThreadFunc函数
 */
void Thread_Runnable::createThread(void *(*func) (void *)){
    pthread_create(&threadID,NULL,func,NULL);
}

void Thread_Runnable::createThread(void *(*func) (void *),void *arg){
    pthread_create(&threadID,NULL,func,arg);
}

//list<Runnable *> Thread_Runnable::m_RunnableList ; //必须在类外定义，且所有该类对象的该成员值都是一样的。
//pthread_mutex_t Thread_Runnable::m_RunnableMutex=PTHREAD_MUTEX_INITIALIZER;

//void *Thread_Runnable::m_ThreadFunc(void *arg){
void Thread_Runnable::m_ThreadFunc(){

    if(m_pOnceRunnable!=NULL){
        m_pOnceRunnable->run();
    }else{
        while(true){

            run();

            if(m_RunnableList.size()<=0){

                usleep(1000000);
            }else{
                //usleep(1000);
            }
        }
    }
}

void Thread_Runnable::join(){
    pthread_join(threadID,NULL);
}

void Thread_Runnable::detachThread(){
    pthread_detach(this->threadID);
}

void Thread_Runnable::run(){
    int val;
    //加锁时，如果不能获得锁，则进程会阻塞在这里,直到获得锁为止
    val = pthread_mutex_lock(&m_RunnableMutex);/*lock the mutex*/
    if(val != 0)
    {
        printf("run Runnable:lock error.");
    }
    for(list<Runnable*>::iterator it=m_RunnableList.begin();it!=m_RunnableList.end();++it){
        //printf("runnable.............\n");
        (*it)->run();
    }
    pthread_mutex_unlock(&m_RunnableMutex);/*unlock the mutex*/
}

void Thread_Runnable::addRunnable(Runnable *pRunnable){
    int val;
    //加锁时，如果不能获得锁，则进程会阻塞在这里,直到获得锁为止
    val = pthread_mutex_lock(&m_RunnableMutex);/*lock the mutex*/
    if(val != 0)
    {
        printf("addRunnable:lock error.");
    }
    printf("add runnable to thread!\n");
    m_RunnableList.push_back(pRunnable);
    printf("size is %d\n",m_RunnableList.size());
    pthread_mutex_unlock(&m_RunnableMutex);/*unlock the mutex*/
}

void Thread_Runnable::setOnceRunnable(Runnable *pRunnable){
    m_pOnceRunnable = pRunnable;
}

/**
 * @brief Thread_Runnable::deleteRunnable
 * @param pRunnable
 * 此函数必须在creatThread前被调用才能生效
 */
void Thread_Runnable::deleteRunnable(Runnable *pRunnable){
    int val;
    //加锁时，如果不能获得锁，则进程会阻塞在这里,直到获得锁为止
    val = pthread_mutex_lock(&m_RunnableMutex);/*lock the mutex*/
    if(val != 0)
    {
        printf("delRunnable:lock error.");
    }
    m_RunnableList.remove(pRunnable);
    pthread_mutex_unlock(&m_RunnableMutex);/*unlock the mutex*/
}
