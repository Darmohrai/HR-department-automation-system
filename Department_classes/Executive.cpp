#include "Executive.h"

Executive::Executive(int income, int premium, int project_quantity, int average_time)
        : Department(income, premium), project_quantity{project_quantity}, average_time{average_time} {}

Executive::Executive(Executive &&executive) noexcept: Department(std::move(executive)),
                                                      project_quantity{executive.project_quantity},
                                                      average_time{executive.average_time} {
    executive.project_quantity = 0;
    executive.average_time = 0;
}

void Executive::setAllInfo(int income, int premium, int project_quantity, int average_time) {
    Department::setAllInfo(income, premium);
    this->project_quantity = project_quantity;
    this->average_time = average_time;
    setName("Executive");
}

void Executive::getDepartmentInfo() {
    Department::getDepartmentInfo();
    std::cout << "\nКількість проєктів - " << project_quantity
              << "\nСередній час виконання (в тижнях) - " << average_time;
}

void Executive::getSalaryInformation() {
    std::cout << "\nЧас на виконання всіх проєктів - " << average_time * project_quantity << " тижнів";
    Department::getSalaryInformation();
}


void Executive::saveInfo(std::ofstream &fout) {
    Department::saveInfo(fout);
    fout << project_quantity << "\n" << average_time << "\n";
}

void Executive::readInfo(std::ifstream &fin) {
    Department::readInfo(fin);
    fin >> project_quantity >> average_time;
}