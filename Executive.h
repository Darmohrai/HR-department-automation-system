#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H

#include "Department.h"

class Executive final : public Department {
private:
    int project_quantity;
    int average_time; // average executive time
public:
    Executive() : project_quantity{0}, average_time{0} {}

    Executive(std::string &manager, int income, int premium, int project_quantity, int average_time);

    Executive(Executive &&executive);

    ~Executive() { std::cout << "object deleted"; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H
