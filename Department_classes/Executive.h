#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H

#include "Department.h"

class Executive final : public Department {
private:
    int project_quantity;
    int average_time; // average executive time
public:
    Executive() : Department(), project_quantity{0}, average_time{0} { setName("Executive"); }

    Executive(int income, int premium, int project_quantity, int average_time);

    Executive(Executive &&executive);

    Executive(Executive &executive) = default;

    ~Executive() { std::cout << "object deleted"; }


    // methods set
    void setAllInfo(int income, int premium, int project_quantity, int average_time);

    void setProjectQuantity(int project_quantity_in) { this->project_quantity = project_quantity_in; }

    void setAverageTime(int average_time_in) { this->average_time = average_time_in; }


    // methods get
    void getDepartmentInfo() final;

    int getProjectQuantity() { return project_quantity; }

    int getAverageTime() { return average_time; }


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;

};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_EXECUTIVE_H
