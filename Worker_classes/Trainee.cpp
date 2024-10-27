#include "Trainee.h"

Trainee::Trainee() : Person(), probation{0}, performance{"bad"}, mentor{"None"} {
    Logger::add_log("base constructor", "Trainee");
}

Trainee::Trainee(std::string &fullname, int age, std::string &passport_number,
                 std::string &education, std::string &entry_date, std::string &specialty,
                 int probation, std::string &performance, std::string &mentor) :
        Person(fullname, age, passport_number, education, entry_date, specialty) {
    this->probation = probation;
    this->performance = performance;
    this->mentor = mentor;
    Logger::add_log("constructor input", "Trainee");
}

Trainee::Trainee(Trainee &&trainee) noexcept: Person(std::move(trainee)), probation{trainee.probation},
                                              performance{std::move(trainee.performance)},
                                              mentor{std::move(trainee.mentor)} {
    trainee.probation = 0;
    Logger::add_log("move constructor", "Trainee");;
}

Trainee::Trainee(Trainee &trainee) : Person(trainee) {
    this->probation = trainee.probation;
    this->performance = trainee.performance;
    this->mentor = trainee.mentor;
    Logger::add_log("copy constructor", "Trainee");
}

Trainee::~Trainee() {
    Logger::add_log("DESTRUCTOR", "Trainee");
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
    bool exit = false;
    while (!exit) {
        exit = true;
        if (performance == "well") {
            std::cout << "\n" << getFullname() << " рекомендовано взяти на роботу"
                      << "\nВведіть '1', щоб побачити повну інформацію про претендента"
                         "\nВведіть '2', щоб побачити коротку інформацію про претендента"
                         "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                         "\nВведіть '0', щоб пропустити\n";
            try {
                std::string choose;
                cin_line(choose);
                int answer;
                answer = std::stoi(choose);
                while (answer != 0 or answer != 3) {
                    answer = std::stoi(choose);
                    switch (answer) {
                        case 1:
                            make_cout_yellow();
                            getAllInfo();
                            make_cout_normal();
                            std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n";
                            pause_class();
                            std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                         "\nВведіть '0', щоб пропустити\n";
                            break;
                        case 2:
                            make_cout_yellow();
                            getBriefInfo();
                            make_cout_normal();
                            std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n";
                            pause_class();
                            std::cout << "\nВведіть '3', щоб підготувати наказ про взяття на роботу"
                                         "\nВведіть '0', щоб пропустити\n";
                            break;
                        case 3:
                            return prepareOrder();
                        case 0:
                            std::cout << "\n\nВи пропустили\n\n";
                            return false;
                        default:
                            throw std::out_of_range("\nНеправильно введене число\n");
                    }
                    cin_line(choose);
                }
            }
            catch (std::out_of_range &e){
                make_cout_red();
                std::cout << e.what();
                make_cout_normal();
                exit = false;
            }
            catch (std::invalid_argument &e) {
                make_cout_red();
                std::cout << "\nВи ввели некоректні дані, спробуйте ще раз\n";
                make_cout_normal();
                exit = false;
            }
            catch (...) {
                make_cout_red();
                std::cout << "\nНевідома помилка, спробуйте ще раз\n";
                make_cout_normal();
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
    Person::readInfo(fin);
    std::string reader;
    fin_int(fin, probation, reader);
    fin_line(fin, performance);
    fin_line(fin, mentor);
}
