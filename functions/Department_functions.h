#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H

// declaration
void changeDepartmentInfo(Marketing &marketing);

void changeMarketing(Marketing &marketing);

void changeLegal(Legal &legal);

void changeExecutive(Executive &executive);

template<typename T>
void caseIncomeOrPremium(T &obj, int choose);

void addDepartmentInfo(int &income, int &premium);

void seeDepartmentInfo(Marketing &marketing, Legal &legal,
                       Executive &executive,
                       std::vector<Manager> &managers); // could be optimized to changeDepartmentInfo

template<typename T>
void chooseInfoForWatching(T &obj, std::vector<Manager> &managers);

// definition
void changeDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть підрозділ\n"
                     "1). Маркетинговий\n"
                     "2). Юридичний\n"
                     "3). Виконавчий\n";

        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;

            int choose_int = std::stoi(choose);
            switch (choose_int) {
                case 1:
                    changeMarketing(marketing);
                    exit = true;
                    break;
                case 2:
                    changeLegal(legal);
                    exit = true;
                    break;
                case 3:
                    changeExecutive(executive);
                case 0:
                    exit = true;
                    break;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

void changeMarketing(Marketing &marketing) {
    gap();

    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Відсоток успішності реклами\n"
                     "4). Змінити всю інформацію\n";
        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;
            int choose_int = std::stoi(choose);

            switch (choose_int) {
                case 1:
                case 2: {
                    caseIncomeOrPremium(marketing, choose_int);
                    exit = true;
                    break;
                }
                case 3: {
                    std::string ad_success_rate;
                    std::cout << "\n\nВведіть відсоток успішності реклами - ";
                    std::cin >> ad_success_rate;
                    int ad_success_rate_int = std::stoi(ad_success_rate);
                    marketing.setAdSuccessRate(ad_success_rate_int);
                    exit = true;
                    break;
                }
                case 4: {
                    int income, premium, ad_success_rate_int;
                    addDepartmentInfo(income, premium);
                    std::string ad_success_rate;
                    std::cout << "\n\nВведіть відсоток успішності реклами - ";
                    std::cin >> ad_success_rate;
                    ad_success_rate_int = std::stoi(ad_success_rate);
                    marketing.setAllInfo(income, premium, ad_success_rate_int);
                    exit = true;
                    break;
                }
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

void changeLegal(Legal &legal) {
    gap();

    bool exit = false;
    std::string choose;

    while (!exit) {

        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Кількість судових випадків\n"
                     "4). Кількість виграних судів\n"
                     "5). Змінити всю інформацію\n";
        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;
            int choose_int = std::stoi(choose);

            switch (choose_int) {
                case 1:
                case 2: {
                    caseIncomeOrPremium(legal, choose_int);
                    exit = true;
                    break;
                }

                case 3: {
                    std::string court_cases;
                    std::cout << "\n\nВведіть кількість судових випадків - ";
                    std::cin >> court_cases;
                    int court_cases_int = std::stoi(court_cases);
                    legal.setCourtCases(court_cases_int);
                    exit = true;
                    break;
                }
                case 4: {
                    std::string win_cases;
                    std::cout << "\n\nВведіть кількість виграних судів - ";
                    std::cin >> win_cases;
                    int win_cases_int = std::stoi(win_cases);
                    legal.setWinCases(win_cases_int);
                    exit = true;
                    break;
                }
                case 5: {
                    int income, premium, court_cases_int, win_cases_int;
                    addDepartmentInfo(income, premium);
                    std::string court_cases;
                    std::cout << "\n\nВведіть кількість судових випадків - ";
                    std::cin >> court_cases;
                    court_cases_int = std::stoi(court_cases);
                    std::string win_cases;
                    std::cout << "\n\nВведіть кількість виграних судів - ";
                    std::cin >> win_cases;
                    win_cases_int = std::stoi(win_cases);
                    legal.setAllInfo(income, premium, court_cases_int, win_cases_int);
                    exit = true;
                    break;
                }
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

void changeExecutive(Executive &executive) {
    gap();

    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Кількість проєктів\n"
                     "4). Середній час виконання проєкту (в тижнях)\n"
                     "5). Змінити всю інформацію\n";
        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;
            int choose_int = std::stoi(choose);

            switch (choose_int) {
                case 1:
                case 2: {
                    caseIncomeOrPremium(executive, choose_int);
                    exit = true;
                    break;
                }
                case 3: {
                    std::string project_quantity;
                    std::cout << "\n\nВведіть кількість судових випадків - ";
                    std::cin >> project_quantity;
                    int project_quantity_int = std::stoi(project_quantity);
                    executive.setProjectQuantity(project_quantity_int);
                    exit = true;
                    break;
                }
                case 4: {
                    std::string average_time;
                    std::cout << "\n\nВведіть кількість виграних судів - ";
                    std::cin >> average_time;
                    int average_time_int = std::stoi(average_time);
                    executive.setAverageTime(average_time_int);
                    exit = true;
                    break;
                }
                case 5: {
                    int income, premium, project_quantity_int, average_time_int;
                    addDepartmentInfo(income, premium);
                    std::string project_quantity;
                    std::cout << "\n\nВведіть кількість судових випадків - ";
                    std::cin >> project_quantity;
                    project_quantity_int = std::stoi(project_quantity);
                    std::string average_time;
                    std::cout << "\n\nВведіть кількість виграних судів - ";
                    std::cin >> average_time;
                    average_time_int = std::stoi(average_time);
                    executive.setAllInfo(income, premium, project_quantity_int, average_time_int);
                    exit = true;
                    break;
                }
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

template<typename T>
void caseIncomeOrPremium(T &obj, int choose) {
    if (choose == 1) {
        std::string income;
        std::cout << "\n\nВведіть дохід підрозділу - ";
        std::cin >> income;
        int income_int = std::stoi(income);
        obj.setIncome(income_int);
    } else {
        std::string premium;
        std::cout << "\n\nВведіть дохід підрозділу - ";
        std::cin >> premium;
        int premium_int = std::stoi(premium);
        obj.setPremium(premium_int);
    }
}

void addDepartmentInfo(int &income, int &premium) {
    std::string choose;
    bool exit = false;

    while (!exit) {
        try {
            exit = true;
            std::cout << "\nВведіть дохід підрозділу - ";
            std::cin >> choose;
            income = std::stoi(choose);
            std::cout << "\nВведіть преміальні кошти підрозділу - ";
            std::cin >> choose;
            premium = std::stoi(choose);
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
            exit = false;
        }
    }
}

void seeDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive, std::vector<Manager> &managers) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть підрозділ\n"
                     "1). Маркетинговий\n"
                     "2). Юридичний\n"
                     "3). Виконавчий\n";

        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;

            int choose_int = std::stoi(choose);
            switch (choose_int) {
                case 1:
                    chooseInfoForWatching(marketing, managers);
                    exit = true;
                    break;
                case 2:
                    chooseInfoForWatching(legal, managers);
                    exit = true;
                    break;
                case 3:
                    chooseInfoForWatching(executive, managers);
                    exit = true;
                    break;
                case 0:
                    exit = true;
                    break;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

template<typename T>
void chooseInfoForWatching(T &obj, std::vector<Manager> &managers) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть яку інформацію хочете побачити\n"
                     "1). Керівний склад\n"
                     "2). Працівників\n"
                     "3). Загальну інформацію\n";

        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;

            int choose_int = std::stoi(choose);
            switch (choose_int) {
                case 1:
                    std::cout << "\n\nКерівний склад: \n";
                    std::for_each(managers.begin(), managers.end(), [&obj](Manager &manager) {
                        if (obj.getName() == manager.getDepartment()) std::cout << " " << manager.getFullname() << "\n";
                    });
                    exit = true;
                    break;
                case 2:
                    obj.getWorkersInfo();
                    exit = true;
                    break;
                case 3:
                    obj.getDepartmentInfo();
                    exit = true;
                    break;
                case 0:
                    exit = true;
                    break;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n\n";
        }
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
