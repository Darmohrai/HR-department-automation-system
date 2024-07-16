#include <iostream>
#include "Trainee.h"
#include "Manager.h"
#include "OfficeWorker.h"
#include "AuxiliaryPosition.h"
#include "AuxiliaryPosition.h"
#include "Legal.h"
#include "Marketing.h"
#include "addEmployee_functions.h" // function gap() here
#include "Trainee_functions.h"

void userInstruction();

int main() {
    system("chcp 65001");

    std::vector<Manager> managers;
    std::vector<OfficeWorker> office_workers;
    std::vector<AuxiliaryPosition> auxiliary_position_workers;
    std::vector<Trainee> trainees;

    bool exit = false;
    std::string answer;

    while (!exit) {
        gap();
        std::cout << "Оберіть що Ви хочете зробити та введіть відповідну цифру\n"
                     "1). Переглянути інструкцію користувача\n"
                     "2). Додати робітника\n"
                     "3). Додати практиканта\n"
                     "0). Вийти з програми\n";
        std::cin >> answer;

        // need to improve exception;

        try {
            if (answer.size() > 1) throw 0;
            switch (answer[0]) {
                case '0':
                    exit = true;
                    break;
                case '1':
                    userInstruction();
                    break;
                case '2':
                    addEmployee(managers, office_workers, auxiliary_position_workers);
                    break;
                case '3':
                    addTrainee(trainees);
                    break;
            }
        }
        catch (int exception) { // should be improved
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        }
        catch (bool exception) {
            std::cerr << "Error";
        }
    }

    return 0;
}

void userInstruction() {
    gap();
    std::cout << "Дана програма є системою автоматизації відділу кадрів\n"
                 "Щоб обрати дію запропоновану в консольному меню введіть відповідну цифру й натисніть Enter\n"
                 "Якщо Ви випадково обрали непотрібну дію, програма завжди дозволить скасувати її, для цього натисніть '0'\n"
                 "\nЩоб повернутися до головного меню введіть '0'\n";

    std::string answer;
    std::cin >> answer;

    while (answer != "0") {
        gap();
        std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        std::cin >> answer;
    }
}