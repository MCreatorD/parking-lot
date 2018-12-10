#ifndef THREAD_RUNNABLE_H
#define THREAD_RUNNABLE_H

#include <list>
using namespace std;

#include <pthread.h>

#include "runnable.h"

/**
 * @brief The Thread_Runnable class
 * by lijin 2017.02.16
 * 一个可在其中运行多个runable的线程类
 * 参考Android中的runbale概念设计
 * 可通过继函该类实现更多的功能。
 */

class Thread_Runnable
{
public:
   // Thread_Runnable(pthread_t threadid,void *(*threadfunc)(void *));
    Thread_Runnable();
protected:
    //这里定义互斥锁
    pthread_mutex_t m_RunnableMutex;

    pthread_t threadID;

    //static void *m_ThreadFunc(void *arg);

    list<Runnable *> m_RunnableList;
    Runnable *m_pOnceRunnable;
    void run();
public:
    void createThread(void *(*func) (void *));
    void createThread(void *(*func) (void *),void *arg);

    void m_ThreadFunc();
    void addRunnable(Runnable *pRunnable);
    void deleteRunnable(Runnable *pRunnable);
    void setOnceRunnable(Runnable *pRunnable);//设置只运行一次的Runnable，一旦设置，则普通的runnable不再有效
    void join();
    void detachThread(); //将当前线程置为unjoinables模式，以方便线程自动释放资源
};

#endif // THREAD_RUNNABLE_H
