#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H

#include "Interface.h"
#include "../Logger.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <thread>


class Person : public Interface {
private:
    std::string fullname;
    int age;
    std::string passport_number;
    std::string education;
    std::string entry_date;
    std::string specialty;
public:
    Person() : Interface(), fullname{"None"}, age{0}, passport_number{"None"},
               education{"None"}, entry_date{"None"}, specialty{"None"} {};

    Person(std::string &fullname, int age, std::string &passport_number,
           std::string &education, std::string &entry_date, std::string &specialty);

    Person(Person &pers);

    Person(Person &&pers) noexcept;

    ~Person() = default;

    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    [[nodiscard]] std::string getFullname() const { return fullname; }

    [[nodiscard]] int getAge() const { return age; }

    [[nodiscard]] std::string getPassportNumber() const { return passport_number; }

    [[nodiscard]] std::string getEducation() const { return education; }

    [[nodiscard]] std::string getSpecialty() const { return specialty; }

    [[nodiscard]] std::string getEntryDate() const { return entry_date; }


    // methods set
    [[nodiscard]] bool checkStatus() override;

    [[nodiscard]] bool prepareOrder() final;


    // methods save
    void saveInfo(std::ofstream &fout) override;

    void readInfo(std::ifstream &fin) override;


    // operators
    Person &operator=(const Person &employee) = default;

    bool operator>(const Person &person) const {
        return this->getFullname() > person.getFullname();
    }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_PERSON_H
