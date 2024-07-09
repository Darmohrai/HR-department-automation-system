#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H

#include "Employee.h"
#include <vector>
#include <memory>
#include <algorithm>

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


    // methods set
    void setWorker(Employee worker);

    void setManager(std::string manager) { this->manager = manager; }

    void setIncome(int income) { this->income = income; }

    void setPremium(int premium) { this->premium = premium; }


    // methods get
    void getWorkersInfo();

    virtual void getDepartmentInfo();

    int getIncome() { return income; }

    int getPremium() { return premium; }

    std::string getManager() { return manager; }


    // methods save
    virtual void saveInfo(std::ofstream &fout);

    virtual void readInfo(std::ifstream &fin);
};

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
