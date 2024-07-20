#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H

// declaration
void ChangeEmployeeFields(int choose_change, std::string &str_change, int &int_change);

void changeManagerInfo(std::vector<Manager> &managers, Marketing &marketing, Legal &legal, Executive &executive);

void changeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                        std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                        Executive &executive);

void changeOfficeWorkerInfo(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                            Executive &executive);

void changeAuxiliaryPositionInfo(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing,
                                 Legal &legal,
                                 Executive &executive);

template<typename T>
void findWorker(std::vector<T> &obj, int &choose_worker);

template<typename T>
void cases_Office_Auxiliary(std::vector<T> &obj, int &choose_worker, int &choose_change, std::string &change_str,
                            int &change_int, Marketing &marketing,
                            Legal &legal, Executive &executive);


// definition
void ChangeEmployeeFields(int choose_change, std::string &str_change, int &int_change) {
    switch (choose_change) {
        case 1: {
            bool error = false;
            std::string reader;
            int department_int;
            while (!error) {
                try {
                    std::cout << "\nОберіть підрозділ \n"
                                 "1). Маркетинговий\n"
                                 "2). Юридичний\n"
                                 "3). Вмконавчий\n";
                    std::cin >> reader;
                    department_int = std::stoi(reader);
                    error = true;
                    if (department_int == 1) str_change = "Marketing";
                    else if (department_int == 2) str_change = "Legal";
                    else if (department_int == 3) str_change = "Executive";
                    else throw 0;
                }
                catch (...) {
                    std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                    error = false;
                }
            }
            break;
        }
        case 2:
            std::cout << "\n\nВведіть нову посаду - ";
            std::cin >> str_change;
            break;
        case 3:
            bool exit = false;

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

    int choose_manager;
    findWorker<Manager>(managers, choose_manager);


    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Премія\n";

    bool exit = false;
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
            managers[choose_manager - 1].setDepartment(change_str);
            managers[choose_manager - 1].setSupervisoryDepartment(marketing, legal, executive);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            managers[choose_manager - 1].setLastAppointment(change_str);
            break;
        case 2:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager - 1].setPosition(change_str);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            managers[choose_manager - 1].setLastAppointment(change_str);
            break;
        case 3:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager - 1].setSalary(change_int);
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
            managers[choose_manager - 1].setPremium(premium);
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
                    changeOfficeWorkerInfo(office_workers, marketing, legal, executive);
                    exit = true;
                    break;
                case '3':
                    changeAuxiliaryPositionInfo(auxiliary_position_workers, marketing, legal, executive);
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

void changeOfficeWorkerInfo(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                            Executive &executive) {

    int choose_office_worker;
    findWorker<OfficeWorker>(office_workers, choose_office_worker);


    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Кількість проєктів\n";

    int exit = false;
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
        case 2:
        case 3:
            cases_Office_Auxiliary<OfficeWorker>(office_workers, choose_office_worker, choose_change, change_str, change_int,
                                   marketing, legal, executive);
            break;
        case 4:
            exit = false;
            int project_numbers;

            while (!exit) {
                try {
                    std::cout << "\n\nВведіть кількість проєктів - ";
                    exit = true;
                    std::string choose;
                    std::cin >> choose;
                    project_numbers = std::stoi(choose);
                }
                catch (...) {
                    std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                    exit = false;
                }
            }
            office_workers[choose_office_worker - 1].setProjectNumbers(project_numbers);
            break;
    }

    if (choose_change != 1) {
        if (office_workers[choose_office_worker - 1].getDepartment() == "Marketing")
            marketing.changeWorker(office_workers[choose_office_worker - 1]);
        else if (office_workers[choose_office_worker - 1].getDepartment() == "Legal")
            legal.changeWorker(office_workers[choose_office_worker - 1]);
        else if (office_workers[choose_office_worker - 1].getDepartment() == "Executive")
            executive.changeWorker(office_workers[choose_office_worker - 1]);
    }
}

void changeAuxiliaryPositionInfo(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing,
                                 Legal &legal,
                                 Executive &executive) {

    int choose_auxiliary_position;
    findWorker<AuxiliaryPosition>(auxiliary_position_workers, choose_auxiliary_position);


    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Номер телефону\n";

    int exit = false;
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
        case 2:
        case 3:
            cases_Office_Auxiliary<AuxiliaryPosition>(auxiliary_position_workers, choose_auxiliary_position, choose_change, change_str,
                                   change_int, marketing, legal, executive);
            break;
        case 4:
            exit = false;
            int phone_number;

            while (!exit) {
                try {
                    std::cout << "\n\nВведіть номер телефону - ";
                    exit = true;
                    std::string choose;
                    std::cin >> choose;
                    phone_number = std::stoi(choose);
                }
                catch (...) {
                    std::cout << "\nПомилка вводу, спробуйте ще раз\n";
                    exit = false;
                }
            }
            auxiliary_position_workers[choose_auxiliary_position - 1].setPhoneNumber(phone_number);
            break;
    }

    if (choose_change != 1) {
        if (auxiliary_position_workers[choose_auxiliary_position - 1].getDepartment() == "Marketing")
            marketing.changeWorker(auxiliary_position_workers[choose_auxiliary_position - 1]);
        else if (auxiliary_position_workers[choose_auxiliary_position - 1].getDepartment() == "Legal")
            legal.changeWorker(auxiliary_position_workers[choose_auxiliary_position - 1]);
        else if (auxiliary_position_workers[choose_auxiliary_position - 1].getDepartment() == "Executive")
            executive.changeWorker(auxiliary_position_workers[choose_auxiliary_position - 1]);
    }
}

template<typename T>
void findWorker(std::vector<T> &obj, int &choose_worker) {
    gap();

    std::cout << "Оберіть суб'єкт\n";

    if (obj.size() == 0) {
        std::cout << "\nСуб'єктів поки ще немає\n";
        return;
    }

    int count = 1;
    std::for_each(obj.begin(), obj.end(),
                  [&count](T &obj) {
                      std::cout << count << "). " << obj.getFullname() << "\n";
                      count++;
                  });

    bool exit = false;

    while (!exit) {
        try {
            exit = true;
            std::string choose;
            std::cin >> choose;
            choose_worker = std::stoi(choose);
            if (choose_worker < 1 or choose_worker > obj.size()) throw 0;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            exit = false;
        }
    }
}

template<typename T>
void cases_Office_Auxiliary(std::vector<T> &vec, int &choose_worker, int &choose_change, std::string &change_str,
                            int &change_int, Marketing &marketing, Legal &legal, Executive &executive) {
    switch (choose_change) {
        case 1:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            if (vec[choose_worker - 1].getDepartment() == "Marketing")
                marketing.deleteWorker(vec[choose_worker - 1].getFullname());
            else if (vec[choose_worker - 1].getDepartment() == "Legal")
                legal.deleteWorker(vec[choose_worker - 1].getFullname());
            else if (vec[choose_worker - 1].getDepartment() == "Executive")
                executive.deleteWorker(vec[choose_worker - 1].getFullname());

            vec[choose_worker - 1].setDepartment(change_str);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            vec[choose_worker - 1].setLastAppointment(change_str);

            if (vec[choose_worker - 1].getDepartment() == "Marketing")
                marketing.setWorker(vec[choose_worker - 1]);
            else if (vec[choose_worker - 1].getDepartment() == "Legal")
                legal.setWorker(vec[choose_worker - 1]);
            else if (vec[choose_worker - 1].getDepartment() == "Executive")
                executive.setWorker(vec[choose_worker - 1]);

            break;
        case 2:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            vec[choose_worker - 1].setPosition(change_str);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            std::cin >> change_str;
            vec[choose_worker - 1].setLastAppointment(change_str);

            break;
        case 3:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            vec[choose_worker - 1].setSalary(change_int);

            break;
    }
}


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H
