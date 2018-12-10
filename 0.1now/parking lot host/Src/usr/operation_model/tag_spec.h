#ifndef TAG_SPEC_H
#define TAG_SPEC_H

#include "class_retain.h"

/**
 * @brief The Tag_Spec class
 * by lijin 2017.02.27
 * 标签操作规则的基础类。主要是实现了类似object C的内存管理方法
 */

class Tag_Spec:public Class_Retain
{
public:
    Tag_Spec();
    //以下参考objectC（ios编程语言的内存管理方法）
};

#endif // TAG_SPEC_H
