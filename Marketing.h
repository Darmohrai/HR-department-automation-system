#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H

#include "Department.h"

class Marketing final : public Department {
private:
    int ad_success_rate;
public:
    Marketing() : Department(), ad_success_rate{0} {}

    Marketing(std::string &manager, int income, int premium, int ad_success_rate);

    Marketing(Marketing &&marketing);

    ~Marketing() { std::cout << "object deleted"; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
