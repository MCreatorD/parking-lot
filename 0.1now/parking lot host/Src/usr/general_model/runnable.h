#ifndef RUNNABLE_H
#define RUNNABLE_H

/**
 * @brief The Runnable class
 * by lijin 2017.02.16
 * 可在线程中运行的代码，
 * 参考Android中的Runnable概念设计
 */

class Runnable
{
public:
     Runnable();
public:
     virtual void run();
};

#endif // RUNNABLE_H
