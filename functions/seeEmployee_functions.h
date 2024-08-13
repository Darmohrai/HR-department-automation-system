#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H

// declaration
void seeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers);

template<typename T>
void chooseWorkerSort(std::vector<T> &vec, std::string &choose);

void seeManagerInfo(std::vector<Manager> &managers);

template<typename T>
void seeWorkerInfo(std::vector<T> &vec);

void searchEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                    std::vector<AuxiliaryPosition> &auxiliary_position_workers);


//definition
void seeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    int choose_int;

    checkCinAnswer([&](std::string &choose) {
        gap();
        std::cout
                << "Оберіть тип робітників, інформацію про яких Ви хочете побачити (щоб повернутися до головного меню введіть '0')"
                   "\n1). Керівники"
                   "\n2). Офісні працівники"
                   "\n3). Додаткова посада\n";
        cin_line(choose);
        choose_int = std::stoi(choose);

        switch (choose_int) {
            case 1:
                seeManagerInfo(managers);
                break;
            case 2:
                seeWorkerInfo(office_workers);
                break;
            case 3:
                seeWorkerInfo(auxiliary_position_workers);
                break;
            case 0:
                break;
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
    pause();
}

template<typename T>
void chooseWorkerSort(std::vector<T> &vec, std::string &choose) {
    int choose_int;
    T arr_obj[vec.size()];
    std::copy(vec.begin(), vec.end(), arr_obj);

    cin_line(choose);
    choose_int = std::stoi(choose);

    switch (choose_int) {
        case 1:
            for (int i = 0; i < vec.size() - 1; ++i) {
                for (int j = 0; j < vec.size() - i - 1; ++j) {
                    if (arr_obj[j] > arr_obj[j + 1]) {
                        T temp = arr_obj[j + 1];
                        arr_obj[j + 1] = arr_obj[j];
                        arr_obj[j] = temp;
                    }
                }
            }
            for (int i = 0; i < vec.size(); ++i) {
                std::cout << "\n";
                make_cout_yellow();
                arr_obj[i].getAllInfo();
            }
            break;
        case 2:
            for (int i = 0; i < vec.size() - 1; ++i) {
                for (int j = 0; j < vec.size() - i - 1; ++j) {
                    if (arr_obj[j] < arr_obj[j + 1]) {
                        T temp = arr_obj[j + 1];
                        arr_obj[j + 1] = arr_obj[j];
                        arr_obj[j] = temp;
                    }
                }
            }
            for (int i = 0; i < vec.size(); ++i) {
                std::cout << "\n";
                make_cout_yellow();
                arr_obj[i].getAllInfo();
            }
            break;
        case 3:
            for (int i = 0; i < vec.size() - 1; ++i) {
                for (int j = 0; j < vec.size() - i - 1; ++j) {
                    if (arr_obj[j] <= arr_obj[j + 1]) {
                        T temp = arr_obj[j + 1];
                        arr_obj[j + 1] = arr_obj[j];
                        arr_obj[j] = temp;
                    }
                }
            }
            for (int i = 0; i < vec.size(); ++i) {
                std::cout << "\n";
                make_cout_yellow();
                arr_obj[i].getAllInfo();
            }
            break;
        case 0:
            break;
        default:
            throw std::out_of_range("\nНеправильно введене число\n");
    }
    make_cout_normal();
}


void seeManagerInfo(std::vector<Manager> &managers) {
    if (managers.size() == 1) {
        make_cout_yellow();
        managers[0].getAllInfo();
        make_cout_normal();
        return;
    }
    if (managers.empty()) {
        make_cout_yellow();
        std::cout << "\n\nРобітників поки немає\n\n";
        make_cout_normal();
        return;
    }

    checkCinAnswer([&managers](std::string &choose) {
        gap();
        std::cout << "Оберіть за чим сортувати керівників (щоб повернутися до головного меню введіть '0')"
                     "\n1). Прізвище"
                     "\n2). Оклад"
                     "\n3). Відділами\n";
        chooseWorkerSort<Manager>(managers, choose);
    });
}

template<typename T>
void seeWorkerInfo(std::vector<T> &vec) {

    if (vec.size() == 1) {
        make_cout_yellow();
        vec[0].getAllInfo();
        make_cout_normal();
        return;
    }
    if (vec.empty()) {
        make_cout_yellow();
        std::cout << "\n\nРобітників поки немає\n\n";
        make_cout_normal();
        return;
    }

    checkCinAnswer([&vec](std::string &choose) {
        gap();
        std::cout << "Оберіть за чим сортувати керівників (щоб повернутися до головного меню введіть '0')"
                     "\n1). Прізвище"
                     "\n2). Оклад"
                     "\n3). Стаж\n";
        chooseWorkerSort<T>(vec, choose);
    });
}

void searchEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                    std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    bool worker_exist = false;
    int id;
    checkCinAnswer([&id](std::string &choose) {
        gap();
        std::cout << "\nВведіть ID робітника якого хочете знайти - ";
        cin_line(choose);
        id = std::stoi(choose);
    });

    make_cout_yellow();
    std::thread searchManager([&managers, &id, &worker_exist]() {
        std::for_each(managers.begin(), managers.end(), [&id, &worker_exist](Manager &manager) {
            if (manager.getID() == id) {
                manager.getAllInfo();
                worker_exist = true;
            }
        });
    });

    std::thread searchOfficeWorker([&office_workers, &id, &worker_exist]() {
        std::for_each(office_workers.begin(), office_workers.end(), [&id, &worker_exist](OfficeWorker &officeWorker) {
            if (officeWorker.getID() == id) {
                officeWorker.getAllInfo();
                worker_exist = true;
            }
        });
    });

    std::thread searchAuxiliaryPosition([&auxiliary_position_workers, &id, &worker_exist]() {
        std::for_each(auxiliary_position_workers.begin(), auxiliary_position_workers.end(),
                      [&id, &worker_exist](AuxiliaryPosition &auxiliaryPosition) {
                          if (auxiliaryPosition.getID() == id) {
                              auxiliaryPosition.getAllInfo();
                              worker_exist = true;
                          }
                      });
    });

    searchManager.join();
    searchOfficeWorker.join();
    searchAuxiliaryPosition.join();

    if (!worker_exist) std::cout << "\nРобітника із даним ID немає\n";
    make_cout_normal();
    pause();
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H
