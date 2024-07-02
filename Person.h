#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H

#include "Interface.h"
#include <string>
#include <iostream>


class Person : Interface {
private:
    std::string fullname;
    int age;
    int passport_number;
    std::string education;
    int entry_date;
    std::string specialty;
public:
    // methods get
    void getAllInfo() override;
    void getBriefInfo() override;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
