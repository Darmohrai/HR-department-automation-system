#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    std::string department;
    std::string position;
    int salary;
    std::string last_appointment;
    int id;
public:
    Employee() : Person(), department{"None"}, position{"None"}, salary{0}, last_appointment{"None"}, id{0} {}

    Employee(std::string &fullname, int age, int passport_number,
             std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
             std::string &position, int salary, std::string &last_appointment, int id);

    Employee(Employee &&employee) noexcept;

    Employee(Employee &employee);

    ~Employee() = default;


    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    [[nodiscard]] int getSalary() override { return salary; }

    [[nodiscard]] std::string getDepartment() { return department; }

    [[nodiscard]] int getID() const { return id; }


    // methods set
    void setDepartment(std::string &department_set) { this->department = department_set; }

    void setLastAppointment(std::string &last_appointment_set) { this->last_appointment = last_appointment_set; }

    void setPosition(std::string &position_set) { this->position = position_set; }

    void setSalary(int salary_set) { this->salary = salary_set; }

    [[nodiscard]] bool prepareOrder() override { return Person::prepareOrder(); }

    [[nodiscard]] bool checkStatus() override;


    // methods save
    void saveInfo(std::ofstream &fout) override;

    void readInfo(std::ifstream &fin) override;


    //for salary
    bool operator<(const Employee &employee) const {
        return this->salary < employee.salary;
    }

    //for id
    bool operator<=(const Employee &employee) const {
        return this->id <= employee.id;
    }

    Employee &operator=(const Employee &employee) = default;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_EMPLOYEE_H
