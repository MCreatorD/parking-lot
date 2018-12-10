#ifndef CLASS_RETAIN_H
#define CLASS_RETAIN_H


/**
 * @brief The Class_Retain class
 * by lijin 2017.03.13.
 * 用于Retain式内存管理的类。需要该种内存管理的类可通过继承该类来实现。
 * 注：该方式 是参考IOS的内存管理机制设计。
 */

class Class_Retain
{
public:
    Class_Retain();
    //以下参考objectC（ios编程语言的内存管理方法）

private:
    int retainCount; //被要求保留的次数
public:
    inline int getRetainCount(){
        return retainCount;
    }

    void retain();
    void release();
    bool isRetainZero();
};

#endif // CLASS_RETAIN_H
