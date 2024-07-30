#include "AuxiliaryPosition.h"

AuxiliaryPosition::AuxiliaryPosition(std::string &fullname, int age, int passport_number,
                                     std::string &education, std::string &entry_date, std::string &specialty,
                                     std::string &department, std::string &position, int salary,
                                     std::string &last_appointment, int id, int experience, int phone_number) : Employee(
        fullname, age, passport_number, education, entry_date, specialty, department, position,
        salary, last_appointment, id) {
    this->experience = experience;
    this->phone_number = phone_number;
}

AuxiliaryPosition::AuxiliaryPosition(AuxiliaryPosition &&auxiliaryPosition) noexcept : Employee(std::move(auxiliaryPosition)),
                                                                              experience{auxiliaryPosition.experience},
                                                                              phone_number{
                                                                                      auxiliaryPosition.phone_number} {
    auxiliaryPosition.experience = 0;
    auxiliaryPosition.phone_number = 0;
}

AuxiliaryPosition::AuxiliaryPosition(AuxiliaryPosition &auxiliaryPosition) : Employee(auxiliaryPosition),
                                                                             experience{auxiliaryPosition.experience},
                                                                             phone_number{
                                                                                     auxiliaryPosition.phone_number} {}


void AuxiliaryPosition::getAllInfo() {
    Employee::getAllInfo();
    std::cout << "\nСтаж - " << experience
              << "\nНомер телефону - " << phone_number;
}

void AuxiliaryPosition::getBriefInfo() {
    Employee::getBriefInfo();
    std::cout << "\nНомер телефону - " << phone_number;
}


void AuxiliaryPosition::saveInfo(std::ofstream &fout) {
    Employee::saveInfo(fout);
    fout << experience << "\n" << phone_number << "\n" << "\n";
}

void AuxiliaryPosition::readInfo(std::ifstream &fin) {
    Employee::readInfo(fin);
    std::string read;
    fin_int(fin, experience, read);
    fin_int(fin, phone_number, read);
}