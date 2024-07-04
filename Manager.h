#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H

#include "Employee.h"

class Manager final : public Employee {
private:
    std::string supervisory_department; // need to create 'has a relationship' with class Department
    int premium;
public:
    Manager() : supervisory_department{"None"}, premium{0} {}

    Manager(std::string &fullname, int age, int passport_number,
            std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
            std::string &position, int salary, std::string &last_appointment, std::string &supervisory_department,
            int premium);

    Manager(Manager &&manager) noexcept;

    Manager(Manager &manager);

    ~Manager() { std::cout << "object deleted"; }


    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;

    [[nodiscard]] int getSalary() final { return Employee::getSalary(); }

    [[nodiscard]] int getPremium() { return premium; }


    // methods set
    void prepareOrder() final { Employee::prepareOrder(); }

    void checkStatus() final { Employee::checkStatus(); }

    void setPremium() { std::cin >> premium; }


};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H
