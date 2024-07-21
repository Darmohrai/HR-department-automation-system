#include "OfficeWorker.h"

OfficeWorker::OfficeWorker(std::string &fullname, int age, int passport_number,
                           std::string &education, std::string &entry_date, std::string &specialty,
                           std::string &department,
                           std::string &position, int salary, std::string &last_appointment, int experience, int id,
                           int project_numbers) : Employee(fullname, age, passport_number, education, entry_date,
                                                           specialty, department,
                                                           position, salary, last_appointment) {
    this->experience = experience;
    this->id = id;
    this->project_numbers = project_numbers;
}

OfficeWorker::OfficeWorker(OfficeWorker &&officeWorker) : Employee(std::move(officeWorker)),
                                                          experience{officeWorker.experience}, id{officeWorker.id},
                                                          project_numbers{officeWorker.project_numbers} {
    officeWorker.experience = 0;
    officeWorker.id = 0;
    officeWorker.project_numbers = 0;
}

OfficeWorker::OfficeWorker(OfficeWorker &officeWorker) : Employee(officeWorker), experience{officeWorker.experience},
                                                         id{officeWorker.id},
                                                         project_numbers{officeWorker.project_numbers} {}


void OfficeWorker::getAllInfo() {
    Employee::getAllInfo();
    std::cout << "\nСтаж - " << experience
              << "\nID - " << id
              << "\nКількість проєктів у яких бере участь - " << project_numbers;
}

void OfficeWorker::getBriefInfo() {
    Employee::getBriefInfo();
    std::cout << "\nID - " << id;
}


void OfficeWorker::saveInfo(std::ofstream &fout) {
    Employee::saveInfo(fout);
    fout << experience << "\n" << id << "\n" << project_numbers << "\n" << "\n";
}

void OfficeWorker::readInfo(std::ifstream &fin) {
    Employee::readInfo(fin);
    std::string reader;
    fin_int(fin, experience, reader);
    fin_int(fin, id, reader);
    fin_int(fin, project_numbers, reader);
}