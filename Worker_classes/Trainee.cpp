#include "Trainee.h"

Trainee::Trainee(std::string &fullname, int age, int passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty,
                 int probation, std::string &performance, std::string &mentor) :
        Person(fullname, age, passport_number, education, entry_date, specialty) {
    this->probation = probation;
    this->performance = performance;
    this->mentor = mentor;
}

Trainee::Trainee(Trainee &&trainee) noexcept: Person(std::move(trainee)), probation{trainee.probation},
                                              performance{trainee.performance}, mentor{trainee.mentor} {
    trainee.probation = 0;
    trainee.performance = "";
    trainee.mentor = "";
}

Trainee::Trainee(Trainee &trainee) : Person(trainee) {
    this->probation = trainee.probation;
    this->performance = trainee.performance;
    this->mentor = trainee.mentor;
}

void Trainee::getAllInfo() {
    Person::getAllInfo();
    std::cout << "\nТермін завершення пробного періоду - " << probation
              << "\nПродуктивність - " << performance
              << "\nМентор - " << mentor;
}

void Trainee::getBriefInfo() {
    Person::getBriefInfo();
    std::cout << "\nПосада - практикант"
              << "\nПродуктивність - " << performance;
}

bool Trainee::prepareOrder() {
    std::cout << "\nНаказ підготовлений"
                 "\nНатисніть 1, щоб підписати"
                 "\nНатисніть 0, щоб скасувати\n";
    // need to update ...
}

bool Trainee::checkStatus() {
    if (performance == "well") {
        std::cout << "\n" << getFullname() << " рекомендовано взяти на роботу"
                  << "\nВведіть '1', щоб побачити повну інформацію про претендента"
                     "\nВведіть '2', щоб побачити коротку інформацію про претендента"
                     "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                     "\nВведіть '0', щоб вийти\n";
        int answer = 1;

        while (answer == 1 or answer == 2) {
            std::cin >> answer;
            switch (answer) {
                case 1:
                    getAllInfo();
                    std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                 "\nВведіть '0', щоб вийти\n";
                case 2:
                    getBriefInfo();
                    std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                 "\nВведіть '0', щоб вийти\n";
                case 3:
                    prepareOrder();
                case 0:
                    std::cout << "\n\nВи вийшли\n\n";
                default:
                    std::cout << "\nВи ввели неправильний номер, спробуйте ще раз\n";
            }
        }
    }
}


void Trainee::saveInfo(std::ofstream &fout){
    Person::saveInfo(fout);
    fout << probation << "\n" << performance << "\n" << mentor << "\n\n";
}

void Trainee::readInfo(std::ifstream &fin){
    std::string reader;
    Person::readInfo(fin);
    fin >> probation >> performance >> mentor;
}