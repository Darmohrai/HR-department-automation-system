#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H

#include "Department.h"

class Legal final : public Department {
private:
    int court_cases; // number of court cases
    int win_cases; // number of court cases won
public:
    Legal() : Department(), court_cases{0}, win_cases{0} { setName("Legal"); }

    Legal(int income, int premium, int court_cases, int win_cases);

    Legal(Legal &&legal) noexcept;

    Legal(Legal &legal) = default;

    ~Legal() { std::cout << "object deleted"; }


    // set methods
    void setAllInfo(int income, int premium, int court_cases, int win_cases);

    void setCourtCases(int court_cases_in) { this->court_cases = court_cases_in; }

    void setWinCases(int win_cases_in) { this->win_cases = win_cases_in; }


    // get methods
    void getDepartmentInfo() final;

    int getCourtCases() { return court_cases; }

    int getWinCases() { return win_cases; }


    // save methods
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_LEGAL_H
