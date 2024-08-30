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
                                         last_appointment{employee.last_appointment}, id(employee.id) {
}


void Employee::getAllInfo() {
    Person::getAllInfo();
    std::cout << "\nПідрозділ - " << department
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
    if (getAge() >= 60) {
        std::string retire_age;
        if(getAge() > 65) retire_age = " пенсійного віку, ";
        else retire_age = " передпенсійного віку, ";
        std::cout << "\n" << getFullname() << retire_age << " рекомендовано звільнити"
                  << "\nВведіть '1', щоб побачити повну інформацію про робітника"
                     "\nВведіть '2', щоб побачити коротку інформацію про робітника"
                     "\nВведіть '3', щоб підготувати наказ про звільнення"
                     "\nВведіть '0', щоб пропустити\n";
        bool exit = false;
        while (!exit) {
            exit = true;
            try {
                std::string choose;
                cin_line(choose);
                int answer;
                answer = 1;
                while (answer == 1 or answer == 2) {
                    answer = std::stoi(choose);
                    switch (answer) {
                        case 1:
                            getAllInfo();
                            std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n";
                            pause_class();
                            std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                         "\nВведіть '0', щоб пропустити\n";
                            break;
                        case 2:
                            getBriefInfo();
                            std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n";
                            pause_class();
                            std::cout << "\nВведіть '3', щоб підготувати наказ про звільнення"
                                         "\nВведіть '0', щоб пропустити\n";
                            break;
                        case 3:
                            return prepareOrder();
                        case 0:
                            std::cout << "\n\nВи пропустили\n\n";
                            return false;
                        default:
                            throw std::out_of_range("\nНеправильно введене число\n");
                    }
                    cin_line(choose);
                }
            }
            catch (std::out_of_range &e){
                std::cout << "\\033[31m" << e.what() << "\\033[0m"; // make cout red
                exit = false;
            }
            catch (std::invalid_argument &e) {
                std::cout << "\n\\033[31m Ви ввели некоректні дані, спробуйте ще раз\\033[0m\n"; // make cout red
                exit = false;
            }
            catch (...) {
                std::cout << "\n\\033[31m Невідома помилка, спробуйте ще раз\\033[0m\n"; // make cout red
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