#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H

#include "Department.h"

class Marketing final : public Department {
private:
    int ad_success_rate;
public:
    Marketing();

    Marketing(int income, int premium, int ad_success_rate);

    Marketing(Marketing &&marketing) noexcept;

    ~Marketing();


    // methods set
    void setAllInfo(int income, int premium, int ad_success_rate);

    void setAdSuccessRate(int ad_success_rate_in) { ad_success_rate = ad_success_rate_in; }


    // methods get
    void getDepartmentInfo() final;

    void getSalaryInformation(int managers_salary) final;


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;

};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
