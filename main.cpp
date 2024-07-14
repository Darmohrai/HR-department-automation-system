#include <iostream>
#include "Trainee.h"
#include "Manager.h"
#include "OfficeWorker.h"
#include "AuxiliaryPosition.h"
#include "AuxiliaryPosition.h"
#include "Legal.h"
#include "Marketing.h"

void userInstruction();

int main() {
    system("chcp 65001");

    bool exit = false;
    std::string answer;

    while (!exit) {
        std::cout << "Оберіть що Ви хочете зробити та введіть відповідну цифру\n"
                     "1). Переглянути інструкцію користувача\n"
                     "0). Вийти з програми\n";
        std::cin >> answer;

        // need to improve exception;

        try {
            if (answer.size() > 1) throw 0;
            switch (answer[0]) {
                case '0': {
                    exit = true;
                    break;
                }
                case '1': {
                    userInstruction();
                    break;
                }
            }
        }
        catch (int exception) { // should be improved
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        }
        catch (bool exception) {
            std::cerr << "Error";
        }
    }

    return 0;
}

void userInstruction() {
    std::cout << "Дана програма є системою автоматизації відділу кадрів\n"
                 "Щоб обрати дію запропоновану в консольному меню введіть відповідну цифру й натисніть Enter\n"
                 "Якщо Ви випадково обрали непотрібну дію, програма завжди дозволить відмінити її, для цього натисніть '0'\n"
                 "\n Щоб повернутися до головного меню введіть '0'";

    std::string answer;
    std::cin >> answer;

    while (answer != "0") {
        std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        std::cin >> answer;
    }
}
