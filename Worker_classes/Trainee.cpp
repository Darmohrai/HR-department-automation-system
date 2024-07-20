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

bool Trainee::checkStatus() {
    if (performance == "well") {
        std::cout << "\n" << getFullname() << " рекомендовано взяти на роботу"
                  << "\nВведіть '1', щоб побачити повну інформацію про претендента"
                     "\nВведіть '2', щоб побачити коротку інформацію про претендента"
                     "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                     "\nВведіть '0', щоб вийти\n";
        bool exit = false;

        while (!exit) {
            exit = true;
            try {
                std::string choose;
                std::cin >> choose;
                int answer;
                answer = std::stoi(choose);
                while (answer == 1 or answer == 2) {
                    answer = std::stoi(choose);
                    switch (answer) {
                        case 1:
                            getAllInfo();
                            std::cout << "\nНатисніть будь-яку клавішу, щоб продовжити\n";
                            system("pause");
                            std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                         "\nВведіть '0', щоб вийти\n";
                            break;
                        case 2:
                            getBriefInfo();
                            std::cout << "\nНатисніть будь-яку клавішу, щоб продовжити\n";
                            system("pause");
                            std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                         "\nВведіть '0', щоб вийти\n";
                            break;
                        case 3:
                            return prepareOrder();
                        case 0:
                            std::cout << "\n\nВи вийшли\n\n";
                            return false;
                        default:
                            throw 0;
                    }
                    std::cin >> choose;
                }
            }
            catch (...) {
                std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                exit = false;
            }
        }
    }
    return false;

}


void Trainee::saveInfo(std::ofstream &fout) {
    Person::saveInfo(fout);
    fout << probation << "\n" << performance << "\n" << mentor << "\n\n";
}

void Trainee::readInfo(std::ifstream &fin) {
    std::string reader;
    Person::readInfo(fin);
    fin >> probation >> performance >> mentor;
}