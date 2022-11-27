#include "myException.h"


    MyException::MyException(const std::string& msg_, int x_) : msg(msg_), x(x_) {}

    int MyException::getX() const { return x; }
    const std::string MyException::getMsg() const { return msg; }