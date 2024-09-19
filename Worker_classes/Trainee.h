#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H

#include "Person.h"

class Trainee final : public Person {
private:
    int probation;
    std::string performance;
    std::string mentor;
public:
    Trainee();

    Trainee(std::string &fullname, int age, int passport_number,
            std::string &education, std::string &entry_date, std::string &specialty,
            int probation, std::string &performance, std::string &mentor);

    Trainee(Trainee &&trainee) noexcept; // need check

    Trainee(Trainee &trainee);

    ~Trainee();

    // methods get
    void getAllInfo() final;

    void getBriefInfo() final;

    bool getPerformance() { if (performance == "well") return true; else return false; }

    [[nodiscard]] int getSalary() final { return 0; }

    bool checkStatus() final;


    // methods set
    void setPerformance(std::string &performance_set) { this->performance = performance_set; }

    // methods save
    void saveInfo(std::ofstream &fout) final;

    void readInfo(std::ifstream &fin) final;

    Trainee &operator=(const Trainee &employee) = default;

    bool operator<(const Trainee &trainee) const {
        return this->probation < trainee.probation;
    }

    bool operator<=(const Trainee &trainee) const {
        return this->performance[0] <= trainee.performance[0];
    }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_H
