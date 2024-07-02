#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H

#include "Interface.h"
#include <iostream>
#include <fstream>


class Person : public Interface {
private:
    std::string fullname;
    int age;
    int passport_number;
    std::string education;
    int entry_date;
    std::string specialty;
public:
    Person() : fullname{"None"}, age{0}, passport_number{0},
               education{"None"}, entry_date{0}, specialty{"None"} {};

    Person(std::string &fullname, int age, int passport_number,
           std::string &education, int entry_date, std::string &specialty);

    Person(Person &pers);

    Person(Person &&pers) noexcept;

    ~Person() { std::cout << "\nobj delete\n"; };

    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    // methods set
    void checkStatus() override;

    // methods save
    void saveInfo(std::string file_name) override;
    void readInfo(std::string file_name) override;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
