#include <iostream>

#include "Worker_classes/Trainee.h"
#include "Worker_classes/Manager.h"
#include "Worker_classes/OfficeWorker.h"
#include "Worker_classes/AuxiliaryPosition.h"
#include "Department_classes/Executive.h"
#include "Department_classes/Legal.h"
#include "Department_classes/Marketing.h"

#include "functions/Save&Read_functions.h"
#include "functions/addEmployee_functions.h" // function gap() here
#include "functions/Trainee_functions.h"
#include "functions/Department_functions.h"
#include "functions/changeEmployee_functions.h"


void userInstruction();


int main() {
    system("chcp 65001");
    Marketing marketing;
    Legal legal;
    Executive executive;

    std::vector<Manager> managers;
    std::vector<OfficeWorker> office_workers;
    std::vector<AuxiliaryPosition> auxiliary_position_workers;
    std::vector<Trainee> trainees;

    threadsReadInfo(managers, office_workers, auxiliary_position_workers, trainees);

    std::for_each(managers.begin(), managers.end(), [&marketing, &legal, &executive](Manager &manager) {
        manager.setSupervisoryDepartment(marketing, legal, executive);
    });

    // need be threads for Department read
    readDepartmentWorkers(office_workers, auxiliary_position_workers, marketing, legal, executive);


    bool exit = false;
    std::string answer;

    while (!exit) {
        gap();
        std::cout << "Оберіть що Ви хочете зробити та введіть відповідну цифру\n"
                     "1). Переглянути інструкцію користувача\n"
                     "2). Додати робітника\n"
                     "3). Додати практиканта\n"
                     "4). Змінити дані про підрозділи\n"
                     "5). Змінити дані про робітника\n"
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
                    addEmployee(managers, office_workers, auxiliary_position_workers,
                                marketing, legal, executive);
                    break;
                case '3':
                    addTrainee(trainees);
                    break;
                case '4':
                    changeDepartmentInfo(marketing, legal, executive);
                    break;
                case '5':
                    changeEmployeeInfo(managers, office_workers, auxiliary_position_workers,
                                       marketing, legal, executive);
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


    threadsSaveInfo(managers, office_workers, auxiliary_position_workers, trainees);

    threadsSaveDepartmentInfo(marketing, legal, executive);

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

