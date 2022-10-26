#include "stack.h"

Stack::Stack()
{
    top = base;//初始化栈，让栈顶和栈底相等
    length = 0;//栈长为0
}

char Stack::gettop(){
    if(length == 0){
        return '0';
    }
    return (top-1)->getdata();//栈顶指针指向栈顶上面，故指针减一指向栈顶，->获取栈顶元素
}

bool Stack::push(char data){
    if(length == SIZE){
        return false;
    }
    top->setdata(data);
    top++;
    length++;
    return true;
}

bool Stack::pop(){
    if(isemp()){//判断栈是否为空再考虑出栈问题
        return false;
    }
    top--;
    length--;//出栈不需要额外对栈顶元素做操作，因为下次压栈时它仍会被覆盖
    return true;
}

bool Stack::isemp(){
    if(top == base){
        return true;
    }
    return false;
}

int Stack::getlength(){
    return length;
}








