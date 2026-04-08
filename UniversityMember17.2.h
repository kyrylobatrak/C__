#pragma once

#include "Person17.2.h"
#include <string>

class UniversityMember : virtual public Person {
protected:
    std::string VUZ;

public:
    UniversityMember();

    UniversityMember(const std::string& name, const std::string& gender, const std::string& age, const std::string& VUZ);

    virtual ~UniversityMember();
    virtual void print() const override;
    virtual void input() override;
    std::string getVUZ() const;
};