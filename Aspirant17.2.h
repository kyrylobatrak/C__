#pragma once

#include "Student17.2.h"
#include "Teacher17.2.h"

class Aspirant : public Student, public Teacher {
public:
    Aspirant();
    Aspirant(const std::string& name, const std::string& gender, const std::string& age,
             const std::string& vuz, int course, const std::string& group,
             const std::string& position, double salary);

    virtual ~Aspirant();

    virtual void print() const override;
    virtual void input() override;
};