#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H

#include "Employee.h"

class OfficeWorker final : public Employee {
private:
    int experience;

    int project_numbers;
public:
    OfficeWorker() : Employee(), experience{0}, project_numbers{0} {}

    OfficeWorker(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                 std::string &position, int salary, std::string &last_appointment, int id, int experience,
                 int project_numbers);

    OfficeWorker(OfficeWorker &&officeWorker);

    OfficeWorker(OfficeWorker &officeWorker);

    ~OfficeWorker() { std::cout << "object deleted"; }


    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;

    [[nodiscard]] int getSalary() final { return Employee::getSalary(); }

    [[nodiscard]] int getExperience() { return experience; }


    // methods set
    [[nodiscard]] bool prepareOrder() final { return Employee::prepareOrder(); }

    [[nodiscard]] bool checkStatus() final { return Employee::checkStatus(); }

    void setProjectNumbers(int project_numbers_set) { this->project_numbers = project_numbers_set; }


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;


    OfficeWorker &operator=(const OfficeWorker &officeWorker) = default;

    // for experience
    bool operator<=(const OfficeWorker &officeWorker) const {
        return this->experience <= officeWorker.experience;
    }

};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_OFFICEWORKER_H
