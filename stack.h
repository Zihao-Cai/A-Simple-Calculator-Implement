#ifndef STACK_H
#define STACK_H
#include "point.h"
#define SIZE 100
class Stack
{
    Point *top;//top指针总是指向栈顶上面的空位置
    Point base[SIZE];//base为栈底，故作为数组首地址，栈最大长度为SIZE：100
    int length;//栈长变量
public:
    Stack();
    char gettop();//返回当前栈顶元素内容
    bool push(char data);//压栈，参数data作为内容入栈
    bool pop();//出栈，栈顶元素出栈（没有定义直接获取它的函数，因为可以先调用gettop函数获取它，然后调用pop出栈）
    bool isemp();//判断栈是否为空
    int getlength();//获取栈长

};

#endif // STACK_H
