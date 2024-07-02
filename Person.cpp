#include "Person.h"

void Person::getAllInfo() {
    std::cout << "ПІБ - " << fullname
              << "\nВік - " << age
              << "\nНомер паспорта - " << passport_number
              << "\nОсвіта" << education
              << "\nДата надходження у фірму" << entry_date
              << "\nСпеціальність - " << specialty;
}

void Person::getBriefInfo() {
    std::cout << "ПІБ - " << fullname
              << "\nВік - " << age;
}

void Person::checkStatus() {
    if (age >= 65) std::cout << "Працівника можна відправити на пенсію";
    else if (age >= 55)
        std::cout << "Працівник передпенсійного віку, до пенсійного віку залишилося - " << 65 - age << " років";
    else std::cout << "Працівник не є пенсійного або передпенсійного віку";
}

void Person::saveInfo(std::string file_name) {
    std::ofstream fout(file_name, std::ios::app);
    fout << fullname << "\n" << age << "\n" << passport_number << "\n" << education << "\n" << entry_date << "\n"
         << specialty;
    fout.close();
}