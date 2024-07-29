#include "Employee.h"

Employee::Employee(std::string &fullname, int age, int passport_number,
                   std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                   std::string &position, int salary,
                   std::string &last_appointment, int id) : Person(fullname, age,
                                                           passport_number, education,
                                                           entry_date, specialty) {
    this->department = department;
    this->salary = salary;
    this->position = position;
    this->last_appointment = last_appointment;
    this->id = id;
}

Employee::Employee(Employee &&employee) noexcept: Person(std::move(employee)), department{employee.department},
                                                  salary{employee.salary}, position{employee.position},
                                                  last_appointment{employee.last_appointment}, id(employee.id){
    employee.department = "";
    employee.salary = 0;
    employee.position = "";
    employee.last_appointment = "";
    employee.id = 0;
}

Employee::Employee(Employee &employee) : Person(employee), department{employee.department},
                                         salary{employee.salary}, position{employee.position},
                                         last_appointment{employee.last_appointment}, id(employee.id) {}


void Employee::getAllInfo() {
    Person::getAllInfo();
    std::cout << "\nПідрозділ -" << department
              << "\nПосада - " << position
              << "\nОклад - " << salary
              << "\nОстаннє призначення - " << last_appointment
              << "\nID - " << id;
}

void Employee::getBriefInfo() {
    Person::getBriefInfo();
    std::cout << "\nПідрозділ - " << department
              << "\nПосада - " << position
              << "\nОклад - " << salary
              << "\nID - " << id;
}


bool Employee::checkStatus() {
    if (getAge() >= 65) {
        std::cout << "\n" << getFullname() << " рекомендовано звільнити"
                  << "\nВведіть '1', щоб побачити повну інформацію про робітника"
                     "\nВведіть '2', щоб побачити коротку інформацію про робітника"
                     "\nВведіть '3', щоб підготувати наказ про звільнення"
                     "\nВведіть '0', щоб вийти\n";
        bool exit = false;
        while (!exit) {
            exit = true;
            try {
                std::string choose;
                cin_line(choose);
                int answer;
                answer = std::stoi(choose);
                while (answer == 1 or answer == 2) {
                    answer = std::stoi(choose);
                    switch (answer) {
                        case 1:
                            getAllInfo();
                            std::cout << "\nНатисніть будь-яку клавішу, щоб продовжити\n";
                            system("pause");
                            std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                         "\nВведіть '0', щоб вийти\n";
                            break;
                        case 2:
                            getBriefInfo();
                            std::cout << "\nНатисніть будь-яку клавішу, щоб продовжити\n";
                            system("pause");
                            std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                         "\nВведіть '0', щоб вийти\n";
                            break;
                        case 3:
                            return prepareOrder();
                        case 0:
                            std::cout << "\n\nВи вийшли\n\n";
                            return false;
                        default:
                            throw 0;
                    }
                    cin_line(choose);
                }
            }
            catch (...) {
                std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                exit = false;
            }
        }
    }
    return false;
}


void Employee::saveInfo(std::ofstream &fout) {
    Person::saveInfo(fout);
    fout << department << "\n" << salary << "\n" << position << "\n" << last_appointment << "\n" << id << "\n";
}

void Employee::readInfo(std::ifstream &fin) {
    Person::readInfo(fin);
    std::string reader;
    fin_line(fin, department);
    fin_int(fin, salary, reader);
    fin_line(fin, position);
    fin_line(fin, last_appointment);
    fin_int(fin, id, reader);
}