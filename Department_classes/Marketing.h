#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H

#include "Department.h"

class Marketing final : public Department {
private:
    int ad_success_rate;
public:
    Marketing() : Department(), ad_success_rate{0} {}

    Marketing(int income, int premium, int ad_success_rate);

    Marketing(Marketing &&marketing);

    Marketing(Marketing &marketing) = default;

    ~Marketing() { std::cout << "object deleted"; }


    // methods set
    void setAdSuccessRate(int ad_success_rate_in) { ad_success_rate = ad_success_rate_in; }

    void setAllInfo(int income, int premium, int ad_success_rate);


    // methods get
    void getDepartmentInfo() final;

    int getADSuccessRate() { return ad_success_rate; }


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;

};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_MARKETING_H
