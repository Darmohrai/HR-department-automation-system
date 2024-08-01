#include "Department.h"

Department::Department(Department &&department) noexcept: workers{std::move(department.workers)},
                                                          income{department.income},
                                                          premium{department.premium},
                                                          name{std::move(department.name)} {
    department.income = 0;
    department.premium = 0;
}

void Department::setWorker(Employee &worker) {
    workers.push_back(std::make_unique<Employee>(worker));
}

void Department::setAllInfo(int &income, int &premium) {
    this->income = income;
    this->premium = premium;
}

void Department::changeWorker(Employee &worker) {
    std::for_each(workers.begin(), workers.end(), [&worker](std::unique_ptr<Employee> &employee) {
        if (employee->getFullname() == worker.getFullname()) {
            employee = std::make_unique<Employee>(worker);
        }
    });
}

void Department::deleteWorker(std::string fullname) {
    int numb;
    int count = 0;
    std::for_each(workers.begin(), workers.end(), [&count, &fullname, &numb](std::unique_ptr<Employee> &employee) {
        if (employee->getFullname() == fullname) numb = count;
        count++;
    });

    workers.erase(workers.begin() + numb);
}

void Department::getWorkersInfo() {
    if(workers.empty()){
        std::cout << "\n\nРобітників поки що немає\n\n";
        return;
    }
    std::for_each(workers.begin(), workers.end(), [](std::unique_ptr<Employee> &employee) {
                      std::cout << "\n";
                      employee->getBriefInfo();
                  }
    );

}

void Department::getWorkers() {
    if (workers.empty()) {
        std::cout << "\nРобітників поки немає\n";
        return;
    }
    std::for_each(workers.begin(), workers.end(), [](std::unique_ptr<Employee> &employee) {
                      std::cout << "\n" << employee->getFullname();
                  }
    );
}

void Department::getDepartmentInfo() {
    std::cout << "Кількість працівників - " << workers.size()
              << "\nДохід підприємства - " << income
              << "\nПреміальні кошти виділені на підприємство - " << premium;
}

void Department::getSalaryInformation(int managers_salary) {
    std::cout << "\n---Зарплатана відомість підрозділу---\n";

    int total_salary;
    Employee richest_employee;
    std::for_each(workers.begin(), workers.end(),
                  [&total_salary, &richest_employee](std::unique_ptr<Employee> &employee) {
                      total_salary += employee->getSalary();

                      if (richest_employee.getSalary() < employee->getSalary()) richest_employee = *employee;
                  });

    std::cout << "\nЗагальний прибуток - " << income
              << "\nЧистий прибуток - " << income - total_salary - premium - managers_salary
              << "\nЗагальні витрати на зарплати робітників - " << total_salary
              << "\nЗагальні витрати на керівників - " << managers_salary
              << "\nПреміальні кошти - " << premium
              << "\nНайвища зарплатня " << richest_employee.getSalary() << " у робітника "
              << richest_employee.getFullname() << "\n\n";
}


void Department::saveInfo(std::ofstream &fout) {
    fout << income << "\n" << premium << "\n";
}

void Department::readInfo(std::ifstream &fin) {
    fin >> income >> premium;
}