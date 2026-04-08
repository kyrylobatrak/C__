#pragma once

#include "UniversityMember17.2.h"
#include <string>

class Student : virtual public UniversityMember {
protected:
    int course;
    std::string group;

public:
    Student();
    Student(const std::string& name, const std::string& gender, const std::string& age,
            const std::string& vuz, int course, const std::string& group);

    virtual ~Student();

    virtual void print() const override;
    virtual void input() override;
};