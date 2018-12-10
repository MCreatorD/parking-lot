#include "sleep_runnable.h"
#include <unistd.h>

Sleep_Runnable::Sleep_Runnable(int us)
{
    usleepCount = us;
}

void Sleep_Runnable::run(){
    usleep(usleepCount);
}
