#include "Manager.h"

Manager::Manager(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                 std::string &position, int salary, std::string &last_appointment, int id, int premium,
                 Department *supervisory_department) :
        Employee(fullname, age, passport_number, education, entry_date, specialty, department,
                 position, salary, last_appointment, id) {
        Person::log_Worker_class("input constructor", "Manager");

    this->premium = premium;
    this->supervisory_department = supervisory_department;
}

Manager::Manager(Manager &&manager) noexcept: Employee(std::move(manager)), premium{manager.premium},
                                              supervisory_department{manager.supervisory_department} {

        Person::log_Worker_class("move constructor", "Manager");
    manager.premium = 0;
    supervisory_department = nullptr;
}

Manager::Manager(Manager &manager) : Employee(manager), premium{manager.premium},
                                     supervisory_department{manager.supervisory_department} {}

Manager::~Manager() {
        Person::log_Worker_class("DESTRUCTOR", "Manager");
    if (supervisory_department != nullptr) supervisory_department = nullptr;
}


void Manager::setSupervisoryDepartment(Department &manager, Department &legal, Department &executive) {
    if (this->getDepartment() == "Marketing") this->supervisory_department = &manager;
    else if (this->getDepartment() == "Legal") this->supervisory_department = &legal;
    else if (this->getDepartment() == "Executive")
        this->supervisory_department = &executive;
}


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
    std::string reader;
    fin_int(fin, premium, reader);
}