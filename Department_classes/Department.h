#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H

#include "../Worker_classes/Employee.h"
#include <vector>
#include <memory>
#include <algorithm>

class Department {
private:
    std::vector<std::unique_ptr<Employee>> workers;
    int income;
    int premium;
    std::string name = "None";
public:
    Department() : income{0}, premium{0} {}

    Department(int income, int premium) : income{income}, premium{premium} {}

    Department(Department &&department) noexcept;

    Department(Department &department) = default;

    ~Department() {
        std::cout << "object deleted";
    }


    // methods set
    void setAllInfo(int &income, int &premium);

    void setWorker(Employee &worker);

    void setName(std::string name_set) { this->name = name_set; }

    void changeWorker(Employee &worker);

    void deleteWorker(std::string fullname);

    void setIncome(int income_in) { this->income = income_in; }

    void setPremium(int premium_in) { this->premium = premium_in; }


    // methods get
    void getWorkersInfo();

    void getWorkers();

    virtual void getDepartmentInfo();

    int getIncome() { return income; }

    int getPremium() { return premium; }

    virtual void getSalaryInformation();

    std::string getName() { return name; }


    // methods save
    virtual void saveInfo(std::ofstream &fout);

    virtual void readInfo(std::ifstream &fin);

};

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
