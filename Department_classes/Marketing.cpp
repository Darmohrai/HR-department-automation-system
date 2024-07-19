#include "Marketing.h"

Marketing::Marketing(int income, int premium, int ad_success_rate) :
        Department(income, premium), ad_success_rate{ad_success_rate} {}

Marketing::Marketing(Marketing &&marketing) : Department(std::move(marketing)),
                                              ad_success_rate{marketing.ad_success_rate} {
    marketing.ad_success_rate = 0;
}

void Marketing::setAllInfo(int income, int premium, int ad_success_rate){
    Department::setAllInfo(income, premium);
    this->ad_success_rate = ad_success_rate;
}

void Marketing::getDepartmentInfo() {
    Department::getDepartmentInfo();
    std::cout << "\nУспішність реклами (%)" << ad_success_rate;
}


void Marketing::saveInfo(std::ofstream &fout) {
    Department::saveInfo(fout);
    fout << ad_success_rate << "\n";
}

void Marketing::readInfo(std::ifstream &fin) {
    Department::readInfo(fin);
    fin >> ad_success_rate;
}