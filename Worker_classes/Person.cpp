#include "Person.h"

Person::Person(std::string &fullname, int age, int passport_number,
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
    pers.passport_number = 0;
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

bool Person::prepareOrder(){
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
                std::cout << getFullname() << "\nНаказ підписано\n";
                return true;
            } else if (answer == 0) {
                std::cout << "\nНаказ скасовано\n";
                return false;
            } else throw false;
        }
        catch (bool n) {
            std::cout << "\nВи ввели неправильний номер, спробуйте ще раз\n";
            numb = false;
        }
    }
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