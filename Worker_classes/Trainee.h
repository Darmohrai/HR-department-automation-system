#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H

#include "Person.h"

class Trainee final : public Person {
private:
    int probation;
    std::string performance;
    std::string mentor;
public:
    Trainee() : Person(), probation{0}, performance{"bad"}, mentor{"None"} {};

    Trainee(std::string &fullname, int age, int passport_number,
            std::string &education, std::string &entry_date, std::string &specialty,
            int probation, std::string &performance, std::string &mentor);

    Trainee(Trainee &&trainee) noexcept; // need check

    Trainee(Trainee &trainee);

    ~Trainee() { std::cout << "object deleted"; }

    // methods get
    void getAllInfo() override;

    void getBriefInfo() override;

    [[nodiscard]] int getSalary() override { return 0; }


    // methods set
    [[nodiscard]] bool prepareOrder() override {return Person::prepareOrder(); };

    bool checkStatus() override;


    // methods save
    void saveInfo(std::ofstream &fout) override;

    void readInfo(std::ifstream &fin) override;

    Trainee &operator=(const Trainee &employee) = default;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
