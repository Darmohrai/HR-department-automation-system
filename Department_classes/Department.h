#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H

#include "../Worker_classes/Employee.h"
#include <vector>
#include <memory>
#include <algorithm>

class Department {
private:
    std::vector<std::unique_ptr<Employee>> workers;
    std::string manager;
    std::string name;
    int income;
    int premium;
public:
    Department() : manager{"None"}, name{"None"}, income{0}, premium{0} {}

    Department(std::string &manager, int income, int premium) : manager{manager}, income{income},
                                                                premium{premium} {}

    Department(Department &&department) noexcept;

    ~Department() { std::cout << "object deleted"; }


    // methods set
    void setWorker(Employee worker);

    void setManager(std::string &manager_in) { this->manager = manager_in; }

    void setIncome(int income_in) { this->income = income_in; }

    void setPremium(int premium_in) { this->premium = premium_in; }


    // methods get
    void getWorkersInfo();

    virtual void getDepartmentInfo();

    int getIncome() { return income; }

    int getPremium() { return premium; }

    std::string getName() { return name; }

    std::string getManager() { return manager; }


    // methods save
    virtual void saveInfo(std::ofstream &fout);

    virtual void readInfo(std::ifstream &fin);
};

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
