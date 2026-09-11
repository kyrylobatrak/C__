#pragma once

#include "UniversityMember17.2.h"
#include <string>

class Teacher : virtual public UniversityMember {
protected:
    std::string position;
    double salary;

public:
    Teacher();
    Teacher(const std::string& name, const std::string& gender, const std::string& age,
            const std::string& vuz, const std::string& position, double salary);

    virtual ~Teacher();

    virtual void print() const override;
    virtual void input() override;
};