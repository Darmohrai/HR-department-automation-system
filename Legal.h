#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H

#include "Department.h"

class Legal final : public Department {
private:
    int court_cases; // number of court cases
    int win_cases; // number of court cases won
public:
    Legal() : Department(), court_cases{0}, win_cases{0} {}

    Legal(std::string &manager, int income, int premium, int court_cases, int win_cases);

    Legal(Legal &&legal) noexcept;

    ~Legal() { std::cout << "object deleted"; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H
