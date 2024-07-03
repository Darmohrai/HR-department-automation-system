#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H

#include "Person.h"

class Trainee : Person {
private:
    int probation;
    std::string performance;
    std::string *mentor; // should be 'has a relationship' with class Employee
public:
    Trainee() : probation{0}, performance{"bad"}, mentor{nullptr} {};

    Trainee(std::string &fullname, int age, int passport_number,
            std::string &education, int entry_date, std::string &specialty,
            int &probation, std::string &performance, std::string *mentor);

    Trainee(Trainee &&trainee) noexcept; // need check

    Trainee(Trainee &trainee);

    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    [[nodiscard]] int getSalary() override { return 0; }


    // methods set
    void prepareOrder() override;

    void checkStatus() override;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
