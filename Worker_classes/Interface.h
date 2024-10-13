#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H

// macros use in daughters classes
#define cin_line(string) (std::getline(std::cin, string))
#define fin_line(fin, string) (std::getline(fin, string))
#define fin_int(fin, int_variable, string) (std::getline(fin, string), int_variable = std::stoi(string))
#define pause_class() (std::cout << "\n\nНатисніть будь-яку кнопку ДВІЧІ, щоб продовжити" << std::endl, system("pause"), \
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'))
#define make_cout_normal() (std::cout << "\033[0m")
#define make_cout_red() (std::cout << "\033[31m")
#define make_cout_yellow() (std::cout << "\033[33m")


#include <string>
#include <mutex>

class Interface {
public:
    // methods get
    virtual void getAllInfo() = 0;

    virtual void getBriefInfo() = 0;

    [[nodiscard]] virtual int getSalary() = 0;


    // methods set
    [[nodiscard]] virtual bool prepareOrder() = 0;

    [[nodiscard]] virtual bool checkStatus() = 0;


    // methods save
    virtual void saveInfo(std::ofstream &fout) = 0;

    virtual void readInfo(std::ifstream &fin) = 0;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
