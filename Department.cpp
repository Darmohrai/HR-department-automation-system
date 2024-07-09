#include "Department.h"

Department::Department(Department &&department) : workers{std::move(department.workers)},
                                                  manager{std::move(department.manager)},
                                                  income{department.income},
                                                  premium{department.premium} {
    department.income = 0;
    department.premium = 0;
}


void Department::setWorker(Employee worker) {
    workers.push_back(std::make_unique<Employee>(worker));
}


void Department::getWorkersInfo() {
    std::for_each(workers.begin(), workers.end(), [](std::unique_ptr<Employee> &employee) {
                      std::cout << "\n";
                      employee->getBriefInfo();
                  }
    );

}

void Department::getDepartmentInfo() {
    std::cout << "Кількість працівників - " << workers.size()
              << "\nКерівник" << manager
              << "\nДохід підприємства" << income
              << "\nПреміальні кошти виділені на підприємство" << premium;
}