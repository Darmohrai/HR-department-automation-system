#include "Marketing.h"

Marketing::Marketing() : Department(), ad_success_rate{0} {
    setName("Marketing");
    Logger::add_log("base constructor", "Marketing");
}

Marketing::Marketing(int income, int premium, int ad_success_rate) :
        Department(income, premium), ad_success_rate{ad_success_rate} {
    Logger::add_log("input constructor", "Marketing");
}

Marketing::Marketing(Marketing &&marketing) noexcept: Department(std::move(marketing)),
                                                      ad_success_rate{marketing.ad_success_rate} {
    marketing.ad_success_rate = 0;
    Logger::add_log("move constructor", "Marketing");
}

Marketing::~Marketing() { Logger::add_log("DESTRUCTOR", "Marketing"); }


void Marketing::setAllInfo(int income, int premium, int ad_success_rate) {
    Department::setAllInfo(income, premium);
    this->ad_success_rate = ad_success_rate;
    setName("Marketing");
}

void Marketing::getDepartmentInfo() {
    Department::getDepartmentInfo();
    std::cout << "\nУспішність реклами (%) - " << ad_success_rate;
}

void Marketing::getSalaryInformation(int managers_salary) {
    Department::getSalaryInformation(managers_salary);
    std::cout << "\nУспішність реклами - " << ad_success_rate << "%";
}


void Marketing::saveInfo(std::ofstream &fout) {
    Department::saveInfo(fout);
    fout << ad_success_rate << "\n";
}

void Marketing::readInfo(std::ifstream &fin) {
    Department::readInfo(fin);
    fin >> ad_success_rate;
}