#include <iostream>
#include <filesystem> // C++ 17 !!!

#define cin_line(string) (std::getline(std::cin, string))

#include "Worker_classes/Trainee.h"
#include "Worker_classes/Manager.h"
#include "Worker_classes/OfficeWorker.h"
#include "Worker_classes/AuxiliaryPosition.h"
#include "Department_classes/Executive.h"
#include "Department_classes/Legal.h"
#include "Department_classes/Marketing.h"

#include "functions/Save&Read_functions.h"
#include "functions/addEmployee_functions.h" // function gap() here
#include "functions/Department_functions.h"
#include "functions/changeEmployee_functions.h"
#include "functions/Trainee_functions.h"
#include "functions/seeEmployee_functions.h"


void userInstruction();

void workerStatus(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                  std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees,
                  Marketing &marketing, Legal &legal, Executive &executive);

void createDirectory();

int main() {
    system("chcp 65001");

    createDirectory();

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


    threadsReadDepartmentInfo(marketing, legal, executive, office_workers, auxiliary_position_workers);


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
                     "6). Змінити дані про практиканта\n"
                     "7). Переглянути інформацію про всіх робітників\n"
                     "8). Переглянути інформацію про підрозділи\n"
                     "9). Переглянути інформацію про стажерів\n"
                     "10). Перевірити статус робітників\n"
                     "11). Переглянути зарплатні відомості\n"
                     "0). Вийти з програми\n";
        cin_line(answer);

        try {
            int answer_int = std::stoi(answer);
            switch (answer_int) {
                case 0:
                    exit = true;
                    break;
                case 1:
                    userInstruction();
                    break;
                case 2:
                    addEmployee(managers, office_workers, auxiliary_position_workers,
                                marketing, legal, executive);
                    break;
                case 3:
                    addTrainee(trainees);
                    break;
                case 4:
                    changeDepartmentInfo(marketing, legal, executive);
                    break;
                case 5:
                    changeEmployeeInfo(managers, office_workers, auxiliary_position_workers,
                                       marketing, legal, executive);
                    break;
                case 6:
                    changeTraineeInfo(trainees);
                    break;
                case 7:
                    seeEmployeeInfo(managers, office_workers, auxiliary_position_workers);
                    break;
                case 8:
                    seeDepartmentInfo(marketing, legal, executive, managers);
                    break;
                case 9:
                    seeTraineeInfo(trainees);
                    break;
                case 10:
                    workerStatus(managers, office_workers, auxiliary_position_workers, trainees, marketing, legal,
                                 executive);
                    break;
                case 11:
                    seeDepartmentSalaryInfo(marketing, legal, executive);
                    break;
                default:
                    throw 0;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
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
    cin_line(answer);

    while (answer != "0") {
        gap();
        std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        cin_line(answer);
    }
}

void workerStatus(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                  std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees,
                  Marketing &marketing, Legal &legal, Executive &executive) {
    bool changes = false;
    int counter = 0;
    std::for_each(managers.begin(), managers.end(), [&managers, &counter, &changes](Manager &manager) {
        if (manager.checkStatus()) {
            managers.erase(managers.begin() + counter);
            changes = true;
        }
        counter++;
    });

    counter = 0;
    std::for_each(office_workers.begin(), office_workers.end(),
                  [&office_workers, &marketing, &legal, &executive, &counter, &changes](
                          OfficeWorker &officeWorker) {
                      if (officeWorker.checkStatus()) {
                          office_workers.erase(office_workers.begin() + counter);
                          if (officeWorker.getDepartment() == "Marketing")
                              marketing.deleteWorker(officeWorker.getFullname());
                          else if (officeWorker.getDepartment() == "Legal")
                              legal.deleteWorker(officeWorker.getFullname());
                          else if (officeWorker.getDepartment() == "Executive")
                              executive.deleteWorker(officeWorker.getFullname());
                          changes = true;
                      }
                      counter++;
                  });

    counter = 0;
    std::for_each(auxiliary_position_workers.begin(), auxiliary_position_workers.end(),
                  [&auxiliary_position_workers, &marketing, &legal, &executive, &counter, &changes](
                          AuxiliaryPosition &auxiliaryPosition) {
                      if (auxiliaryPosition.checkStatus()) {
                          auxiliary_position_workers.erase(auxiliary_position_workers.begin() + counter);
                          if (auxiliaryPosition.getDepartment() == "Marketing")
                              marketing.deleteWorker(auxiliaryPosition.getFullname());
                          else if (auxiliaryPosition.getDepartment() == "Legal")
                              legal.deleteWorker(auxiliaryPosition.getFullname());
                          else if (auxiliaryPosition.getDepartment() == "Executive")
                              executive.deleteWorker(auxiliaryPosition.getFullname());
                          changes = true;
                      }
                      counter++;
                  });

    counter = 0;
    std::for_each(trainees.begin(), trainees.end(),
                  [&trainees, &office_workers, &marketing, &legal, &executive, &counter, &changes](Trainee &trainee) {
                      if (trainee.checkStatus()) {
                          employ(trainee, office_workers, marketing, legal, executive);
                          trainees.erase(trainees.begin() + counter);
                          changes = true;
                      }
                      counter++;
                  });

    if (!changes) std::cout << "\n\nНемає суб'єктів для звільнення/приймання \n\n";
}

void createDirectory() {
    const std::string path = "..//savings_file";
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
}