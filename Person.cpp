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