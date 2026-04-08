#pragma once

#include <string>
#include <iostream>

class Person {
    protected:
    std::string name;
    std::string gender;
    std::string age;

    public:
    Person(const std::string& name, const std::string& gender, const std::string& age);

    virtual ~Person(){}

    virtual void print() const;

    virtual void input();

    std::string getPIB() const;
};