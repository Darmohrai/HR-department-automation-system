#include "Manager.h"

Manager::Manager(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                 std::string &position, int salary, std::string &last_appointment, int premium,
                 Department &supervisory_department) :
        Employee(fullname, age, passport_number, education, entry_date, specialty, department,
                 position, salary, last_appointment) {
    this->premium = premium;
    this->supervisory_department = std::make_shared<Department>(supervisory_department);
}

Manager::Manager(Manager &&manager) noexcept: Employee(std::move(manager)), premium{manager.premium},
                                              supervisory_department{std::move(manager.supervisory_department)} {
    manager.premium = 0;
}

Manager::Manager(Manager &manager) : Employee(manager), premium{manager.premium},
                                     supervisory_department{manager.supervisory_department} {}


void Manager::getAllInfo() {
    Employee::getAllInfo();
    std::cout << "\nПремія - " << premium;
}

void Manager::getBriefInfo() {
    Employee::getBriefInfo();
    std::cout << "\nПремія - " << premium;
}


void Manager::saveInfo(std::ofstream &fout) {
    Employee::saveInfo(fout);
    fout << premium << "\n" << "\n";
}

void Manager::readInfo(std::ifstream &fin) {
    Employee::readInfo(fin);
    fin >> premium;
}