#include "Legal.h"

Legal::Legal(int income, int premium, int court_cases, int win_cases) :
        Department(income, premium), court_cases{court_cases}, win_cases{win_cases} {}

Legal::Legal(Legal &&legal) noexcept: Department(std::move(legal)), court_cases{legal.court_cases},
                                      win_cases{legal.win_cases} {
    legal.court_cases = 0;
    legal.win_cases = 0;
}

void Legal::setAllInfo(int income, int premium, int court_cases, int win_cases) {
    Department::setAllInfo(income, premium);
    this->court_cases = court_cases;
    this->win_cases = win_cases;
}

void Legal::getDepartmentInfo() {
    Department::getDepartmentInfo();
    std::cout << "\nКількість судових справ - " << court_cases
              << "\nКількість виграних справ - " << win_cases;
}


void Legal::saveInfo(std::ofstream &fout) {
    Department::saveInfo(fout);
    fout << court_cases << "\n" << win_cases << "\n";
}

void Legal::readInfo(std::ifstream &fin) {
    Department::readInfo(fin);
    fin >> court_cases >> win_cases;
}