#include "Trainee.h"

Trainee::Trainee(std::string &fullname, int age, int passport_number,
                 std::string &education, int entry_date, std::string &specialty,
                 int &probation, std::string &performance, std::string *mentor) :
        Person(fullname, age, passport_number, education, entry_date, specialty) {
    this->probation = probation;
    this->performance = performance;
    this->mentor = mentor;
}

Trainee::Trainee(Trainee &&trainee) noexcept: Person(std::move(trainee)), probation{trainee.probation},
                                              performance{trainee.performance}, mentor{trainee.mentor} {
    trainee.probation = 0;
    trainee.performance = "";
    trainee.mentor = nullptr;
}

Trainee::Trainee(Trainee &trainee): Person(trainee){
    this->probation = trainee.probation;
    this->performance = trainee.performance;
    this->mentor = trainee.mentor;
}