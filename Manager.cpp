#include "Manager.h"

Manager::Manager(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                 std::string &position, int salary, std::string &last_appointment, std::string &supervisory_department,
                 int premium) : Employee(fullname, age, passport_number, education, entry_date, specialty, department,
                                         position, salary, last_appointment) {
    this->supervisory_department = supervisory_department;
    this->premium = premium;
}

Manager::Manager(Manager &&manager) noexcept: Employee(std::move(manager)),
                                              supervisory_department{manager.supervisory_department},
                                              premium{manager.premium} {
    manager.supervisory_department = "";
    manager.premium = 0;
}

Manager::Manager(Manager &manager) : Employee(manager), supervisory_department{manager.supervisory_department},
                                     premium{manager.premium} {}