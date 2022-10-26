#include "point.h"

Point::Point()
{

}

char Point::getdata(){
    return this->data;
}

bool Point::setdata(char data){
    if((this->data = data))
        return true;
    return false;
}

