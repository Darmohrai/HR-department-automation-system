#include "Department.h"

Department::Department(Department &&department) noexcept: officeWorkers{std::move(department.officeWorkers)},
                                                          auxiliaryPositionWorkers{
                                                                  std::move(department.auxiliaryPositionWorkers)},
                                                          manager{std::move(department.manager)},
                                                          name{std::move(department.name)},
                                                          income{department.income},
                                                          premium{department.premium} {
    department.income = 0;
    department.premium = 0;
    department.officeWorkers = nullptr;
    department.auxiliaryPositionWorkers = nullptr;
}

Department::Department(Department &department) : officeWorkers{department.officeWorkers},
                                                 auxiliaryPositionWorkers{department.auxiliaryPositionWorkers},
                                                 manager{department.manager},
                                                 name{department.name},
                                                 income{department.income},
                                                 premium{department.premium} {}


void Department::getWorkersInfo() {
    std::for_each(officeWorkers->begin(), officeWorkers->end(), [](OfficeWorker &employee) {
                      std::cout << "\n";
                      employee.getBriefInfo();
                  }
    );

}

void Department::getDepartmentInfo() {
    std::cout << "Кількість працівників - " << officeWorkers->size()
              << "\nКерівник - " << manager
              << "\nДохід підприємства - " << income
              << "\nПреміальні кошти виділені на підприємство - " << premium;
}


void Department::saveInfo(std::ofstream &fout) {
    fout << manager << "\n" << income << "\n" << premium << "\n";
}

void Department::readInfo(std::ifstream &fin) {
    fin >> manager >> income >> premium;
}