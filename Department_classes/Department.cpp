#include "Department.h"

Department::Department(Department &&department) noexcept: workers{std::move(department.workers)},
                                                          income{department.income},
                                                          premium{department.premium} {
    department.income = 0;
    department.premium = 0;
}

void Department::setWorker(Employee &worker) {
    workers.push_back(std::make_unique<Employee>(worker));
}

void Department::setAllInfo(int &income, int &premium){
    this->income = income;
    this->premium = premium;
}

void Department::changeWorker(Employee &worker){
    std::for_each(workers.begin(), workers.end(), [&worker](std::unique_ptr<Employee> &employee){
        if(employee->getFullname() == worker.getFullname()) {
            employee = std::make_unique<Employee>(worker);
        }
    });
}

void Department::deleteWorker(std::string fullname){
    int numb;
    int count = 0;
    std::for_each(workers.begin(), workers.end(), [&count, &fullname, &numb](std::unique_ptr<Employee> &employee){
        if(employee->getFullname() == fullname) numb = count;
        count++;
    });

    workers.erase(workers.begin() + numb);
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
              << "\nДохід підприємства - " << income
              << "\nПреміальні кошти виділені на підприємство - " << premium;
}


void Department::saveInfo(std::ofstream &fout) {
    fout << income << "\n" << premium << "\n";
}

void Department::readInfo(std::ifstream &fin) {
    fin >> income >> premium;
}