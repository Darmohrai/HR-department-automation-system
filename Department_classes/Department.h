#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_H

#include "../Worker_classes/OfficeWorker.h"
#include "../Worker_classes/AuxiliaryPosition.h"
#include <vector>
#include <memory>
#include <algorithm>

class Department {
private:
    std::vector<OfficeWorker> *officeWorkers;
    std::vector<AuxiliaryPosition> *auxiliaryPositionWorkers;
    std::string manager;
    std::string name;
    int income;
    int premium;
public:
    Department() : manager{"None"}, name{"None"}, income{0}, premium{0}, officeWorkers{nullptr},
                   auxiliaryPositionWorkers{nullptr} {}

    Department(std::string &manager, int income, int premium) : manager{manager},
                                                                income{income},
                                                                premium{premium} {}

    Department(Department &&department) noexcept;

    Department(Department &department);

    ~Department() {
        std::cout << "object deleted";
        delete officeWorkers;
    }


    // methods set
   void setVectors(std::vector<OfficeWorker> *office_workers,
                    std::vector<AuxiliaryPosition> *auxiliary_positionWorkers) {
        this->officeWorkers = office_workers;
        this->auxiliaryPositionWorkers = auxiliary_positionWorkers;
    }

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
