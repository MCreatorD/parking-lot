#ifndef SLEEP_RUNNABLE_H
#define SLEEP_RUNNABLE_H

#include "runnable.h"

/**
 * @brief The Sleep_Runnable class
 * 该类仅实现一个休眠
 */

class Sleep_Runnable : public Runnable
{
public:
    Sleep_Runnable(int us);
private:
    int usleepCount; //休眠时长
    void run();
};

#endif // SLEEP_RUNNABLE_H
