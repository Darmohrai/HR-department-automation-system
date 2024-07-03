#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    std::string department;
    std::string position;
    int salary;
    std::string last_appointment;
public:
    Employee() : department{"None"}, position{"None"}, salary{0}, last_appointment{"None"} {}

    Employee(std::string &fullname, int age, int passport_number,
             std::string &education, int entry_date, std::string &specialty, std::string &department,
             std::string &position, int salary, std::string &last_appointment);

    Employee(Employee &&employee) noexcept;

    Employee(Employee &employee);


    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    [[nodiscard]] int getSalary() override { return salary; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H
