#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H

#include "Employee.h"

class OfficeWorker final : public Employee {
private:
    int experience;
    int id;
    int project_numbers;
public:
    OfficeWorker() : experience{0}, id{0}, project_numbers{0} {}

    OfficeWorker(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                 std::string &position, int salary, std::string &last_appointment, int experience, int id,
                 int project_numbers);

    OfficeWorker(OfficeWorker &&officeWorker);

    OfficeWorker(OfficeWorker &officeWorker);

    ~OfficeWorker() { std::cout << "object deleted"; }


    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;

    [[nodiscard]] int getSalary() final { return Employee::getSalary(); }

    [[nodiscard]] int getExperience() { return experience; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H
