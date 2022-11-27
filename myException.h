#pragma once
#include <exception>
#include <iostream>


class MyException : public std::exception {
    std::string msg;
    int x;

public:
    MyException(const std::string& msg_, int x_);

    int getX() const;
    const std::string getMsg() const;
};