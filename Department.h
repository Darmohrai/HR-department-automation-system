#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H

#include "Employee.h"
#include <vector>
#include <memory>

class Department {
private:
    std::vector<std::unique_ptr<Employee>> workers;
    std::string manager;
    int income;
    int premium;
public:
    Department() : manager{"None"}, income{0}, premium{0} {}

    Department(std::string &manager_in, int income_in, int premium_in) : manager{manager_in}, income{income_in},
                                                                         premium{premium_in} {}

    Department(Department &&department);

    ~Department() { std::cout << "object deleted"; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
