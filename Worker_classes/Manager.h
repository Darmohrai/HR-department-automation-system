#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H

#include <memory>
#include "Employee.h"
#include "../Department_classes/Department.h"

class Manager final : public Employee {
private:
    Department *supervisory_department = new Department; // need to create 'has a relationship' with class Department
    int premium;
public:
    Manager() : Employee(), premium{0}, supervisory_department{nullptr} {}

    Manager(std::string &fullname, int age, int passport_number,
            std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
            std::string &position, int salary, std::string &last_appointment, int id, int premium,
            Department *supervisory_department);

    Manager(Manager &&manager) noexcept;

    Manager(Manager &manager);

    ~Manager() {
        if (supervisory_department != nullptr) supervisory_department = nullptr;
        std::cout << "object deleted";
    }


    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;

    void getSubordinateInfo() { supervisory_department->getWorkersInfo(); }

    void getSubordinate() { supervisory_department->getWorkersInfo(); }

    void getSupervisoryDepartmentInfo() { supervisory_department->getWorkersInfo(); }

    //void

    [[nodiscard]] int getSalary() final { return Employee::getSalary(); }

    [[nodiscard]] int getPremium() { return premium; }


    // methods set
    [[nodiscard]] bool prepareOrder() final { return Employee::prepareOrder(); }

    [[nodiscard]] bool checkStatus() final { return Employee::checkStatus(); }

    void setPremium(int premium_set) { this->premium = premium_set; }

    void setSupervisoryDepartment(Department &manager, Department &legal, Department &executive);


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;


    Manager &operator=(const Manager &manager) = default;


    // for department
    bool operator<=(const Manager &manager) const {
        return this->supervisory_department->getName() < manager.supervisory_department->getName();
    }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_MANAGER_H
