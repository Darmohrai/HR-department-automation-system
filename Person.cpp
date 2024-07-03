#include "Person.h"

Person::Person(std::string &fullname, int age, int passport_number,
               std::string &education, int entry_date, std::string &specialty) {
    this->fullname = fullname;
    this->age = age;
    this->passport_number = passport_number;
    this->education = education;
    this->entry_date = entry_date;
    this->specialty = specialty;
}

Person::Person(Person &&pers) noexcept: fullname{pers.fullname}, age{pers.age}, passport_number{pers.passport_number},
                                        education{pers.education}, entry_date{pers.entry_date},
                                        specialty{pers.specialty} {
    pers.fullname = "";
    pers.age = 0;
    pers.passport_number = 0;
    pers.education = "";
    pers.entry_date = 0;
    pers.specialty = "";
}

Person::Person(Person &pers) : fullname{pers.fullname}, age{pers.age}, passport_number{pers.passport_number},
                               education{pers.education}, entry_date{pers.entry_date},
                               specialty{pers.specialty} {}

void Person::getAllInfo() {
    std::cout << "\nПІБ - " << fullname
              << "\nВік - " << age
              << "\nНомер паспорта - " << passport_number
              << "\nОсвіта - " << education
              << "\nДата надходження у фірму - " << entry_date
              << "\nСпеціальність - " << specialty;
}

void Person::getBriefInfo() {
    std::cout << "\nПІБ - " << fullname
              << "\nВік - " << age;
}

void Person::checkStatus() {
    if (age >= 65) std::cout << "Працівника можна відправити на пенсію";
    else if (age >= 55)
        std::cout << "Працівник передпенсійного віку, до пенсійного віку залишилося - " << 65 - age << " років";
    else std::cout << "Працівник не є пенсійного або передпенсійного віку";
}

void Person::saveInfo(std::ofstream &fout) {
    //std::ofstream fout(file_name, std::ios::app);
    fout << fullname << "\n" << age << "\n" << passport_number << "\n" << education << "\n" << entry_date << "\n"
         << specialty << "\n";
    //fout.close();
}

void Person::readInfo(std::ifstream &fin) {
    //std::ifstream fin(file_name, std::ios::app);
    fin >> fullname >> age >> passport_number >> education >> entry_date >> specialty;
    // need to update ...
}