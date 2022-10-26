#include "calculate.h"
#include <iostream>
#include <iomanip>
#include "stack.h"
//**************操作符优先级说明：'(' = ')' > '~' > '*' = '/' > '+' = '-' **************//同级别从左到右算，按照入栈先后顺序排等级//
QString calculate(QString t,int* signal){//t为传过来的表达式，为一个QString的字符串类型//signal为信号量,返回错误类型//
    QString result = "";
    char* data = new char[t.length()]();
    QByteArray ba = t.toLatin1();
    data = ba.data();//将表达式t转换为字符数组的形式存储，存在data中//测试完成，成功//
    Stack optr = Stack();//构建一个自定义栈的实例//此栈用来读取存放中缀表达式的运算符
    QString oprand[t.length()];//oprand顺序存放后缀表达式
    int j=0;

    if(*(data+t.length()-1) == '#'){*signal = -1;return "";}//****'#'运算符不能作用在表达式末尾，有歧义****//
    for(int i=0;i<(int)strlen(data);i++){
        switch(*(data+i)){
        case '(': optr.push('(');break;
        case ')':
            if(optr.isemp()){*signal = -1;return "";}//**********提示表达式错误************//
            else{
                while(!optr.isemp() && optr.gettop()!='('){
                    oprand[j] = optr.gettop();optr.pop();j++;
                }
                if(optr.isemp()){*signal = -1;return "";}//********提示表达式错误*********//
                else{optr.pop();}
            } break;
        case '#':optr.push('#');break;
        case '*':while(optr.gettop() == '#' ||optr.gettop() == '/'){
                oprand[j] = optr.gettop();optr.pop();j++;
            }
            optr.push('*');break;
        case '/':while(optr.gettop() == '#'||optr.gettop() == '*'){
                oprand[j] = optr.gettop();optr.pop();j++;
            }
            optr.push('/');break;
        case '+':while(optr.gettop() == '#'||optr.gettop() =='*'||optr.gettop() == '/'||optr.gettop() == '-'){
                oprand[j] = optr.gettop();optr.pop();j++;
            }
            optr.push('+');break;
        case '-': while(optr.gettop() == '#'||optr.gettop() =='*'||optr.gettop() == '/'||optr.gettop() == '+'){
                oprand[j] = optr.gettop();optr.pop();j++;
            }
            optr.push('-');break;
        default:
           int r=0;
           while(r<=(int)t.length()-1-i &&((*(data+i+r)<='9'&& *(data+i+r)>='0')|| *(data+i+r)=='.')){
           oprand[j]= oprand[j].append(*(data+i+r));
            r++;
           }
           j++;
           i+=r-1;break;
        }//这里将读取到的连续数字(包含小数点)作为整体存放在一个格子内
    }//循环完成后，将optr栈内退空到oprand内
    int count = optr.getlength();
    for(int k=0;k<count;k++){
        if(optr.gettop() =='('){*signal = -1;return "";}//****************提示表达式错误***********//
        else{oprand[j] = optr.gettop();optr.pop();
            j++;
        }
    }//现在后缀表达式已经完全生成，存放在oprand数组内//大小为j//测试完成，成功!//

    QString outer[j];
    char* ch;
    int cnt=0;
    for(int i=0;i<j;i++){
        QByteArray b = oprand[i].toLatin1();
        ch = b.data();
        while((*ch && *ch<='9' && *ch>='0')||*ch =='.'){ch++;}
        if(!*ch){//这里判断取到的元素是否为纯数字格式,若是则执行if条件语句:将操作数存入表内
            if(oprand[i].left(1)=='.'||oprand[i].right(1)=='.'||istoodot(oprand[i])){*signal = -1;return "";}
            outer[cnt] = oprand[i];cnt++;continue;
        }else{//若不是则为运算符，取前列元素进行计算
           if(oprand[i] == '#'){
               if(cnt < 1){*signal = -1;return "";}//**************提示表达式错误************//
               else{double temp = -1*(outer[cnt-1].toDouble());outer[cnt-1] = QString::number(temp,'f',6);}continue;//单目运算符是取一存一，故cnt不变//
           }else if(oprand[i] == '*'){
               if(cnt < 2){*signal = -1;return "";}
               else{double temp = outer[cnt-1].toDouble()*outer[cnt-2].toDouble();outer[cnt-1] = "";outer[cnt-2] = QString::number(temp,'f',6);cnt--;}continue;
           }else if(oprand[i] == '/'){
               if(cnt < 2){*signal = -1;return "";}
               else{if(outer[cnt-1].toDouble() == 0){*signal = 0;return "";}double temp = outer[cnt-2].toDouble()/outer[cnt-1].toDouble();outer[cnt-1] = "";outer[cnt-2] = QString::number(temp,'f',6);cnt--;}continue;
           }else if(oprand[i] == '+'){
               if(cnt < 2){*signal = -1;return "";}
               else{double temp = outer[cnt-2].toDouble()+outer[cnt-1].toDouble();outer[cnt-1] = "";outer[cnt-2] = QString::number(temp,'f',6);cnt--;}continue;
           }else if(oprand[i] == '-'){
               if(cnt < 2){*signal = -1;return "";}
               else{double temp = outer[cnt-2].toDouble()-outer[cnt-1].toDouble();outer[cnt-1] = "";outer[cnt-2] = QString::number(temp,'f',6);cnt--;}continue;}
        }
         *signal = -1;return "";
    }
    if(cnt != 1){
        *signal = -1;return "";
    }

  /*printf("cnt =%d\n",cnt);//理论上cnt和*signal最终要为1//
    printf("signal =%d\n",*signal);*///****调试代码，测试完成，成功！****//

    result = outer[0];
    return result;
}


bool istoodot(QString str){
    int dots = 0;int pos = -1;
    for(int k=0;k<str.length();k++){
        if(pos == str.length()-1){break;}
        pos = str.indexOf('.',pos+1);
    if(pos!=-1){
        dots++;continue;
    }else{
        break;
    }

    }
    if(dots>1){return true;}
    return false;
}

