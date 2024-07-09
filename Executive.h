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


    // methods set
    void setProjectQuantity(int project_quantity) { this->project_quantity = project_quantity; }

    void setAverageTime(int average_time) { this->average_time = average_time; }


    // methods get
    void getDepartmentInfo() final;

    int getProjectQuantity() { return project_quantity; }

    int getAverageTime() { return average_time; }


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;

};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H
