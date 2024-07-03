#include "Employee.h"

Employee::Employee(std::string &fullname, int age, int passport_number,
                   std::string &education, int entry_date, std::string &specialty, std::string &department,
                   std::string &position, int salary,
                   std::string &last_appointment) : Person(fullname, age,
                                                           passport_number, education,
                                                           entry_date, specialty) {
    this->department = department;
    this->salary = salary;
    this->position = position;
    this->last_appointment = last_appointment;
}

Employee::Employee(Employee &&employee) noexcept: Person(std::move(employee)), department{employee.department},
                                                  salary{employee.salary}, position{employee.position},
                                                  last_appointment{employee.last_appointment} {
    employee.department = "";
    employee.salary = 0;
    employee.position = "";
    employee.last_appointment = "";
}

Employee::Employee(Employee &employee) : Person(employee), department{employee.department},
                                         salary{employee.salary}, position{employee.position},
                                         last_appointment{employee.last_appointment} {}