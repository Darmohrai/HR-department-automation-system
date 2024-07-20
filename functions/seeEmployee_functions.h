#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H

// declaration
void seeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers);

template<typename T>
void chooseWorkerSort(std::vector<T> &vec, T &arr_obj, std::string &choose, bool &exit);

void seeManagerInfo(std::vector<Manager> &managers);

template<typename T>
void seeWorkerInfo(std::vector<T> &vec);


//definition
void seeEmployeeInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    bool exit = false;
    int choose_int;

    while (!exit) {
        std::string choose;
        gap();
        std::cout
                << "Оберіть тип робітників, інформацію про яких Ви хочете побачити (щоб повернутися до головного меню введіть '0')"
                   "\n1). Керівники"
                   "\n2). Офісні працівники"
                   "\n3). Додаткова посада\n";


        try {
            std::cin >> choose;
            if (choose.size() > 1) throw 0;
            choose_int = std::stoi(choose);


            switch (choose_int) {
                case 1:
                    seeManagerInfo(managers);
                    exit = true;
                    break;
                case 2:
                    seeWorkerInfo(office_workers);
                    exit = true;
                    break;
                case 3:
                    seeWorkerInfo(auxiliary_position_workers);
                    exit = true;
                    break;
                case 0:
                    exit = true;
                    break;
            }
        }
        catch (...) { // should be improved
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            exit = false;
        }
    }
}

template<typename T>
void chooseWorkerSort(std::vector<T> &vec, std::string &choose, bool &exit) {
    int choose_int;

    T arr_obj[vec.size()];
    std::copy(vec.begin(), vec.end(), arr_obj);

    try {
        std::cin >> choose;
        if (choose.size() > 1) throw 0;
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
                    arr_obj[i].getAllInfo();
                }
                exit = true;
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
                    arr_obj[i].getAllInfo();
                }
                exit = true;
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
                    arr_obj[i].getAllInfo();
                }
                exit = true;
                break;
            case 0:
                exit = true;
                break;
        }
    }
    catch (...) { // should be improved
        gap();
        std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        exit = false;
    }
}


void seeManagerInfo(std::vector<Manager> &managers) {
    bool exit = false;

    if (managers.size() == 1) {
        managers[0].getAllInfo();
        return;
    }
    if (managers.size() == 0) {
        std::cout << "Робітників поки немає";
        return;
    }

    while (!exit) {
        std::string choose;
        gap();
        std::cout << "Оберіть за чим сортувати керівників (щоб повернутися до головного меню введіть '0')"
                     "\n1). Прізвище"
                     "\n2). Оклад"
                     "\n3). Відділами\n";
        chooseWorkerSort<Manager>(managers, choose, exit);
    }
    std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n ";
    system("pause");
}

template<typename T>
void seeWorkerInfo(std::vector<T> &vec) {
    bool exit = false;

    if (vec.size() == 1) {
        vec[0].getAllInfo();
        return;
    }
    if (vec.size() == 0) {
        std::cout << "Робітників поки немає";
        return;
    }

    while (!exit) {
        std::string choose;
        gap();
        std::cout << "Оберіть за чим сортувати керівників (щоб повернутися до головного меню введіть '0')"
                     "\n1). Прізвище"
                     "\n2). Оклад"
                     "\n3). Стаж\n";
        chooseWorkerSort<T>(vec, choose, exit);
    }
    std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n ";
    system("pause");
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_SEEEMPLOYEE_FUNCTIONS_H
