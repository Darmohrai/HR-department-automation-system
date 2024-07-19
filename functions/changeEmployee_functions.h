#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H

// declaration
void changeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                        std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                        Executive &executive);




// definition
void ChangeEmployeeFields(int choose_change, std::string &str_change, int &int_change) {
    switch (choose_change) {
        case 1:
            std::cout << "\n\nВведіть новий підрозділ - ";
            std::cin >> str_change;
            break;
        case 2:
            std::cout << "\n\nВведіть нову посаду - ";
            std::cin >> str_change;
            break;
        case 3:
            bool exit = false;
            int choose_manager;

            while (!exit) {
                try {
                    std::cout << "\n\nВведіть нову зарплату - ";
                    exit = true;
                    std::string choose;
                    std::cin >> choose;
                    int_change = std::stoi(choose);
                }
                catch (...) {
                    std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                    exit = false;
                }
            }
            break;
    }
}

void changeManagerInfo(std::vector<Manager> &managers, Marketing &marketing, Legal &legal, Executive &executive) {
    gap();

    std::cout << "Оберіть керівника\n";

    if (managers.size() == 0) {
        std::cout << "\nКерівників поки ще немає\n";
        return;
    }

    int count = 1;
    std::for_each(managers.begin(), managers.end(), [&count](Manager &manager) {
        std::cout << count << "). " << manager.getFullname();
    });


    bool exit = false;
    int choose_manager;

    while (!exit) {
        try {
            exit = true;
            std::string choose;
            std::cin >> choose;
            choose_manager = std::stoi(choose);
            if (choose_manager < 1 or choose_manager > managers.size()) throw 0;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            exit = false;
        }
    }

    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Премія\n";

    exit = false;
    int choose_change;

    while (!exit) {
        try {
            exit = true;
            std::string choose;
            std::cin >> choose;
            choose_change = std::stoi(choose);
            if (choose_change < 1 or choose_change > 4) throw 0;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            exit = false;
        }
    }

    std::string change_str;
    int change_int;

    switch (choose_change) {
        case 1:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager-1].setDepartment(change_str);
            managers[choose_manager-1].setSupervisoryDepartment(marketing, legal, executive);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            managers[choose_manager-1].setLastAppointment(change_str);
            break;
        case 2:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager-1].setPosition(change_str);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            managers[choose_manager-1].setLastAppointment(change_str);
            break;
        case 3:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager-1].setSalary(change_int);
            break;
        case 4:
            exit = false;
            int premium;

            while (!exit) {
                try {
                    std::cout << "\n\nВведіть премію - ";
                    exit = true;
                    std::string choose;
                    std::cin >> choose;
                    premium = std::stoi(choose);
                }
                catch (...) {
                    std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                    exit = false;
                }
            }
            managers[choose_manager-1].setPremium(premium);
            break;
    }
}

void changeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                        std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                        Executive &executive) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        gap();
        std::cout << "Оберіть дані якого робітника Ви хочете змінити (щоб повернутися до головного меню введіть '0')"
                     "\n1). Керівник"
                     "\n2). Офісний працівник"
                     "\n3). Додаткова посада\n";

        std::cin >> choose;

        try {
            if (choose.size() > 1) throw 0;
            switch (choose[0]) {
                case '1':
                    changeManagerInfo(managers, marketing, legal, executive);
                    exit = true;
                    break;
                case '2':

                    exit = true;
                    break;
                case '3':

                    exit = true;
                    break;
                case '0':
                    exit = true;
                    break;
            }
        }
        catch (int exception) { // should be improved
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        }
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H
