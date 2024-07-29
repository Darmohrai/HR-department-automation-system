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
void cases_Office_Auxiliary(std::vector<T> &vec, int &choose_worker, int &choose_change, std::string &change_str,
                            int &change_int, Marketing &marketing, Legal &legal, Executive &executive);

void fireEmployeeOrTrainee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                           std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainee,
                           Marketing &marketing, Legal &legal, Executive &executive);

template<typename T>
void fireEmployee(std::vector<T> &vec, Marketing &marketing, Legal &legal, Executive &executive);

void fireTrainee(std::vector<Trainee> &trainees);


// definition
void ChangeEmployeeFields(int choose_change, std::string &str_change, int &int_change) {
    switch (choose_change) {
        case 1: {
            checkCinAnswer([&str_change](std::string &reader) {
                std::cout << "\nОберіть підрозділ \n"
                             "1). Маркетинговий\n"
                             "2). Юридичний\n"
                             "3). Вмконавчий\n";
                cin_line(reader);
                int department_int = std::stoi(reader);
                if (department_int == 1) str_change = "Marketing";
                else if (department_int == 2) str_change = "Legal";
                else if (department_int == 3) str_change = "Executive";
                else throw 0;
            });
            break;
        }
        case 2:
            std::cout << "\n\nВведіть нову посаду - ";
            cin_line(str_change);
            break;
        case 3:
            checkCinAnswer([&int_change](std::string &reader) {
                std::cout << "\n\nВведіть нову зарплату - ";
                std::string choose;
                cin_line(choose);
                int_change = std::stoi(choose);
            });
            break;
    }
}

void changeManagerInfo(std::vector<Manager> &managers, Marketing &marketing, Legal &legal, Executive &executive) {
    if (managers.empty()) {
        std::cout << "\nСуб'єктів поки ще немає\n";
        return;
    }

    int choose_manager;
    findWorker<Manager>(managers, choose_manager);

    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Премія\n";

    int choose_change;
    checkCinAnswer([&choose_change](std::string &choose) {
        cin_line(choose);
        choose_change = std::stoi(choose);
        if (choose_change < 1 or choose_change > 4) throw 0;
    });

    std::string change_str;
    int change_int;

    switch (choose_change) {
        case 1:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager - 1].setDepartment(change_str);
            managers[choose_manager - 1].setSupervisoryDepartment(marketing, legal, executive);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            cin_line(change_str);
            managers[choose_manager - 1].setLastAppointment(change_str);
            break;
        case 2:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager - 1].setPosition(change_str);
            std::cout << "\nВведіть сьогоднішню дату - \n";
            cin_line(change_str);
            managers[choose_manager - 1].setLastAppointment(change_str);
            break;
        case 3:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            managers[choose_manager - 1].setSalary(change_int);
            break;
        case 4:
            int premium;
            checkCinAnswer([&premium](std::string choose) {
                std::cout << "\n\nВведіть премію - ";
                cin_line(choose);
                premium = std::stoi(choose);
            });
            managers[choose_manager - 1].setPremium(premium);
            break;
    }
}

void changeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                        std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                        Executive &executive) {
    checkCinAnswer([&](std::string &choose) {
        gap();
        std::cout << "Оберіть дані якого робітника Ви хочете змінити (щоб повернутися до головного меню введіть '0')"
                     "\n1). Керівник"
                     "\n2). Офісний працівник"
                     "\n3). Додаткова посада\n";
        cin_line(choose);
        if (choose.size() > 1) throw 0;
        switch (choose[0]) {
            case '1':
                changeManagerInfo(managers, marketing, legal, executive);
                break;
            case '2':
                changeOfficeWorkerInfo(office_workers, marketing, legal, executive);
                break;
            case '3':
                changeAuxiliaryPositionInfo(auxiliary_position_workers, marketing, legal, executive);
                break;
            case '0':
                break;
        }
    });
}

void changeOfficeWorkerInfo(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                            Executive &executive) {

    if (office_workers.empty()) {
        std::cout << "\nСуб'єктів поки ще немає\n";
        return;
    }

    int choose_office_worker;
    findWorker<OfficeWorker>(office_workers, choose_office_worker);


    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Кількість проєктів\n";

    int choose_change;

    checkCinAnswer([&choose_change](std::string &choose) {
        cin_line(choose);
        choose_change = std::stoi(choose);
        if (choose_change < 1 or choose_change > 4) throw 0;
    });

    std::string change_str;
    int change_int;

    switch (choose_change) {
        case 1:
        case 2:
        case 3:
            cases_Office_Auxiliary<OfficeWorker>(office_workers, choose_office_worker, choose_change, change_str,
                                                 change_int,
                                                 marketing, legal, executive);
            break;
        case 4:
            int project_numbers;
            checkCinAnswer([&project_numbers](std::string &choose) {
                std::cout << "\n\nВведіть кількість проєктів - ";
                cin_line(choose);
                project_numbers = std::stoi(choose);
            });
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

    if (auxiliary_position_workers.empty()) {
        std::cout << "\nСуб'єктів поки ще немає\n";
        return;
    }

    int choose_auxiliary_position;
    findWorker<AuxiliaryPosition>(auxiliary_position_workers, choose_auxiliary_position);

    std::cout << "\n\nОберіть які дані хочете змінити\n"
                 "1). Підрозділ\n"
                 "2). Посада\n"
                 "3). Зарплата\n"
                 "4). Номер телефону\n";

    int choose_change;

    checkCinAnswer([&choose_change](std::string &choose) {
        cin_line(choose);
        choose_change = std::stoi(choose);
        if (choose_change < 1 or choose_change > 4) throw 0;
    });


    std::string change_str;
    int change_int;

    switch (choose_change) {
        case 1:
        case 2:
        case 3:
            cases_Office_Auxiliary<AuxiliaryPosition>(auxiliary_position_workers, choose_auxiliary_position,
                                                      choose_change, change_str,
                                                      change_int, marketing, legal, executive);
            break;
        case 4:
            int phone_number;
            checkCinAnswer([&phone_number](std::string &choose) {
                std::cout << "\n\nВведіть номер телефону - ";
                cin_line(choose);
                phone_number = std::stoi(choose);
            });
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

    int count = 1;
    std::for_each(obj.begin(), obj.end(),
                  [&count](T &obj) {
                      std::cout << count << "). " << obj.getFullname() << "\n";
                      count++;
                  });

    checkCinAnswer([&choose_worker, &obj](std::string &choose) {
        cin_line(choose);
        choose_worker = std::stoi(choose);
        if (choose_worker < 1 or choose_worker > obj.size()) throw 0;
    });
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
            std::getline(std::cin, change_str);
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
            cin_line(change_str);
            vec[choose_worker - 1].setLastAppointment(change_str);

            break;
        case 3:
            ChangeEmployeeFields(choose_change, change_str, change_int);
            vec[choose_worker - 1].setSalary(change_int);
            break;
    }
}

void fireEmployeeOrTrainee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                           std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees,
                           Marketing &marketing, Legal &legal, Executive &executive) {
    checkCinAnswer([&](std::string &choose) {
        gap();
        std::cout << "Оберіть тип (введіть '0', щоб повернутися назад)"
                     "\n 1). Керівник"
                     "\n 2). Офісний працівник"
                     "\n 3). Додаткова посада"
                     "\n 4). Стажер\n";
        cin_line(choose);
        int choose_int = std::stoi(choose);
        switch (choose_int) {
            case 1:
                fireEmployee<Manager>(managers, marketing, legal, executive);
                break;
            case 2:
                fireEmployee<OfficeWorker>(office_workers, marketing, legal, executive);
                break;
            case 3:
                fireEmployee<AuxiliaryPosition>(auxiliary_position_workers, marketing, legal, executive);
                break;
            case 4:
                fireTrainee(trainees);
                break;
            case 0:
                break;
            default:
                throw 0;
        }
    });
}

template<typename T>
void fireEmployee(std::vector<T> &vec, Marketing &marketing, Legal &legal, Executive &executive) {
    checkCinAnswer([&](std::string &choose) {
        if (vec.empty()) {
            std::cout << "\nДаного типу робітників немає\n";
            return;
        }
        int count = 1;
        gap();
        std::cout << "\nОберіть робітника\n ";
        std::for_each(vec.begin(), vec.end(), [&count](T &obj) {
            std::cout << count++ << "). " << obj.getFullname() << "\n ";
        });
        cin_line(choose);
        int choose_int = std::stoi(choose);
        if (choose_int < 1 or choose_int > vec.size()) throw 0;
        else if (vec[choose_int - 1].prepareOrder()) {
            if (typeid(T) == typeid(OfficeWorker) or typeid(T) == typeid(AuxiliaryPosition)) {
                if (vec[choose_int - 1].getDepartment() == "Marketing")
                    marketing.deleteWorker(vec[choose_int - 1].getFullname());
                else if (vec[choose_int - 1].getDepartment() == "Legal")
                    legal.deleteWorker(vec[choose_int - 1].getFullname());
                else if (vec[choose_int - 1].getDepartment() == "Executive")
                    executive.deleteWorker(vec[choose_int - 1].getFullname());
            }
            vec.erase(vec.begin() + choose_int - 1);
        }
    });
}

void fireTrainee(std::vector<Trainee> &trainees) {
    checkCinAnswer([&](std::string &choose) {
        if (trainees.empty()) {
            std::cout << "\nДаного типу робітників немає\n";
            return;
        }
        int count = 1;
        gap();
        std::cout << "\nОберіть робітника\n ";
        std::for_each(trainees.begin(), trainees.end(), [&count](Trainee &trainee) {
            std::cout << count++ << "). " << trainee.getFullname() << "\n ";
        });
        cin_line(choose);
        int choose_int = std::stoi(choose);
        if (trainees[choose_int - 1].prepareOrder()) trainees.erase(trainees.begin() + choose_int - 1);
    });
}


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_CHANGEEMPLOYEE_FUNCTIONS_H
