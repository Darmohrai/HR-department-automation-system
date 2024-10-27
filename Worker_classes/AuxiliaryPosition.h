#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_AUXILIARYPOSITION_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_AUXILIARYPOSITION_H

#include "Employee.h"

class AuxiliaryPosition final : public Employee {
private:
    int experience;
    int phone_number;
public:
    AuxiliaryPosition();

    AuxiliaryPosition(std::string &fullname, int age, std::string &passport_number,
                      std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                      std::string &position, int salary, std::string &last_appointment, int id, int experience,
                      int phone_number);

    AuxiliaryPosition(AuxiliaryPosition &&auxiliaryPosition) noexcept;

    AuxiliaryPosition(AuxiliaryPosition &auxiliaryPosition);

    ~AuxiliaryPosition();


    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;


    // methods set
    void setPhoneNumber(int phone_number_set) { this->phone_number = phone_number_set; }


    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;


    AuxiliaryPosition &operator=(const AuxiliaryPosition &auxiliaryPosition) = default;

    // for experience
    bool operator<=(const AuxiliaryPosition &auxiliaryPosition) const {
        return this->experience <= auxiliaryPosition.experience;
    }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_AUXILIARYPOSITION_H
