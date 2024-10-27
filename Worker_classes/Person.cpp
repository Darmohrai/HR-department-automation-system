#include "Person.h"

Person::Person(std::string &fullname, int age, std::string &passport_number,
               std::string &education, std::string &entry_date, std::string &specialty) {
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
    pers.passport_number = "";
    pers.education = "";
    pers.entry_date = "";
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

bool Person::checkStatus() {
    if (age >= 65) return true;
    else return false;
}

bool Person::prepareOrder() {
    int answer_int;
    bool numb = false;
    std::cout << "\n\nНаказ підготовлено, "
                 "\nНатисніть '1', щоб підписати "
                 "\nНатисніть '0', щоб скасувати \n";

    while (!numb) {
        try {
            std::string answer;
            cin_line(answer);
            answer_int = std::stoi(answer);
            if (answer_int == 1) {
                std::cout << getFullname() << "\033[32m\n\nНаказ підписано\n\n\033[0m"; // create cout green
                return true;
            } else if (answer_int == 0) {
                std::cout << "\033[31m\n\nНаказ скасовано\n\n\033[0m"; // create cout red
                return false;
            } else throw std::out_of_range("");
        }
        catch (...) {
            std::cout << "\nВи ввели неправильний номер, спробуйте ще раз\n";
            numb = false;
        }
    }
    return false;
}

void Person::saveInfo(std::ofstream &fout) {
    fout << fullname << "\n" << age << "\n" << passport_number << "\n" << education << "\n" << entry_date << "\n"
         << specialty << "\n";
}

void Person::readInfo(std::ifstream &fin) {
    std::string reader;
    fin_line(fin, reader);
    fin_line(fin, fullname);
    fin_int(fin, age, reader);
    fin_line(fin, passport_number);
    fin_line(fin, education);
    fin_line(fin, entry_date);
    fin_line(fin, specialty);
}