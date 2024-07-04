#include "Employee.h"

Employee::Employee(std::string &fullname, int age, int passport_number,
                   std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                   std::string &position, int salary,
                   std::string &last_appointment) : Person(fullname, age,
                                                           passport_number, education,
                                                           entry_date, specialty) {
    this->department = department;
    this->salary = salary;
    this->position = position;
    this->last_appointment = last_appointment;
}

Employee::Employee(Employee &&employee) noexcept: Person(std::move(employee)), department{employee.department},
                                                  salary{employee.salary}, position{employee.position},
                                                  last_appointment{employee.last_appointment} {
    employee.department = "";
    employee.salary = 0;
    employee.position = "";
    employee.last_appointment = "";
}

Employee::Employee(Employee &employee) : Person(employee), department{employee.department},
                                         salary{employee.salary}, position{employee.position},
                                         last_appointment{employee.last_appointment} {}


void Employee::getAllInfo() {
    Person::getAllInfo();
    std::cout << "\nПідрозділ -" << department
              << "\nПосада - " << position
              << "\nОклад - " << salary
              << "\nОстаннє призначення - " << last_appointment;
}

void Employee::getBriefInfo() {
    Person::getBriefInfo();
    std::cout << "\nПідрозділ - " << department
              << "\nПосада - " << position
              << "\nОклад - " << salary;
}


void Employee::prepareOrder() {
    int answer;
    bool numb = false;
    std::cout << "\n\nНаказ про звільнення підготовлено, "
                 "\nНатисніть '1', щоб підписати "
                 "\nНатисніть '0', щоб скасувати ";

    while (numb == false) {
        try {
            numb = true;
            std::cin >> answer;
            if (answer == 1) {
                std::cout << getFullname() << "\nЗвільнено\n";
                Employee::~Employee();
            } else if (answer == 0) std::cout << "\nНаказ скасовано\n";
            else throw false;
        }
        catch (bool n) {
            std::cout << "\nВи ввели неправильний номер, спробуйте ще раз\n";
            numb = false;
        }
    }
}

void Employee::checkStatus() {
    if (getAge() >= 65) {
        std::cout << "\n" << getFullname() << " рекомендовано звільнити"
                  << "\nВведіть '1', щоб побачити повну інформацію про робітника"
                     "\nВведіть '2', щоб побачити коротку інформацію про робітника"
                     "\nВведіть '3', щоб підготувати наказ про звільнення"
                     "\nВведіть '0', щоб вийти\n";
        int answer = 1;

        while (answer == 1 or answer == 2) {
            std::cin >> answer;
            switch (answer) {
                case 1:
                    getAllInfo();
                    std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                 "\nВведіть '0', щоб вийти\n";
                case 2:
                    getBriefInfo();
                    std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                 "\nВведіть '0', щоб вийти\n";
                case 3:
                    prepareOrder();
                case 0:
                    std::cout << "\n\nВи вийшли\n\n";
                default:
                    std::cout << "\nВи ввели неправильний номер, спробуйте ще раз\n";
            }
        }
    }
}


void Employee::saveInfo(std::ofstream &fout) {
    Person::saveInfo(fout);
    fout << department << "\n" << salary << "\n" << position << "\n" << last_appointment << "\n";
}

void Employee::readInfo(std::ifstream &fin) {
    Person::readInfo(fin);
    fin >> department >> department >> position >> last_appointment;
}