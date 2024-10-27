#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H

// declaration
void changeDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive);

void changeMarketing(Marketing &marketing);

void changeLegal(Legal &legal);

void changeExecutive(Executive &executive);

template<typename T>
void caseIncomeOrPremium(T &obj, int choose);

void addDepartmentInfo(int &income, int &premium);

void seeDepartmentInfo(Marketing &marketing, Legal &legal,
                       Executive &executive,
                       std::vector<Manager> &managers);

template<typename T>
void chooseInfoForWatching(T &obj, std::vector<Manager> &managers);

void seeDepartmentSalaryInfo(Marketing &marketing, Legal &legal, Executive &executive, std::vector<Manager> &managers);

[[nodiscard]] int managersSalary(std::vector<Manager> &managers, std::string department);


// definition
void changeDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive) {
    checkCinAnswer([&marketing, &legal, &executive](std::string &choose) {
        gap();
        std::cout << "Оберіть підрозділ (натисніть '0', щоб повернутися назад)\n"
                     "1). Маркетинговий\n"
                     "2). Юридичний\n"
                     "3). Виконавчий\n";
        cin_line(choose);

        int choose_int = std::stoi(choose);
        switch (choose_int) {
            case 1:
                changeMarketing(marketing);
                break;
            case 2:
                changeLegal(legal);
                break;
            case 3:
                changeExecutive(executive);
            case 0:
                break;
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
}

void changeMarketing(Marketing &marketing) {
    checkCinAnswer([&marketing](std::string &choose) {
        gap();
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Відсоток успішності реклами\n"
                     "4). Змінити всю інформацію\n";
        cin_line(choose);
        int choose_int = std::stoi(choose);

        switch (choose_int) {
            case 1:
            case 2: {
                caseIncomeOrPremium(marketing, choose_int);
                break;
            }
            case 3: {
                std::string ad_success_rate;
                std::cout << "\n\nВведіть відсоток успішності реклами (%11 ) - ";
                cin_line(ad_success_rate);
                int ad_success_rate_int = std::stoi(ad_success_rate);
                marketing.setAdSuccessRate(ad_success_rate_int);
                break;
            }
            case 4: {
                int income, premium, ad_success_rate_int;
                addDepartmentInfo(income, premium);
                std::string ad_success_rate;
                std::cout << "\n\nВведіть відсоток успішності реклами - ";
                cin_line(ad_success_rate);
                ad_success_rate_int = std::stoi(ad_success_rate);
                marketing.setAllInfo(income, premium, ad_success_rate_int);
                break;
            }
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
}

void changeLegal(Legal &legal) {
    checkCinAnswer([&legal](std::string &choose) {
        gap();
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Кількість судових випадків\n"
                     "4). Кількість виграних судів\n"
                     "5). Змінити всю інформацію\n";
        cin_line(choose);
        int choose_int = std::stoi(choose);

        switch (choose_int) {
            case 1:
            case 2: {
                caseIncomeOrPremium(legal, choose_int);
                break;
            }

            case 3: {
                std::string court_cases;
                std::cout << "\n\nВведіть кількість судових випадків - ";
                cin_line(court_cases);
                int court_cases_int = std::stoi(court_cases);
                legal.setCourtCases(court_cases_int);
                break;
            }
            case 4: {
                std::string win_cases;
                std::cout << "\n\nВведіть кількість виграних судів - ";
                cin_line(win_cases);
                int win_cases_int = std::stoi(win_cases);
                legal.setWinCases(win_cases_int);
                break;
            }
            case 5: {
                int income, premium, court_cases_int, win_cases_int;
                addDepartmentInfo(income, premium);
                std::string court_cases;
                std::cout << "\n\nВведіть кількість судових випадків - ";
                cin_line(court_cases);
                court_cases_int = std::stoi(court_cases);
                std::string win_cases;
                std::cout << "\n\nВведіть кількість виграних судів - ";
                cin_line(win_cases);
                win_cases_int = std::stoi(win_cases);
                legal.setAllInfo(income, premium, court_cases_int, win_cases_int);
                break;
            }
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
}

void changeExecutive(Executive &executive) {
    checkCinAnswer([&executive](std::string choose) {
        gap();
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Кількість проєктів\n"
                     "4). Середній час виконання проєкту (в тижнях)\n"
                     "5). Змінити всю інформацію\n";
        cin_line(choose);
        int choose_int = std::stoi(choose);

        switch (choose_int) {
            case 1:
            case 2: {
                caseIncomeOrPremium(executive, choose_int);
                break;
            }
            case 3: {
                std::string project_quantity;
                std::cout << "\n\nВведіть кількість проєктів - ";
                cin_line(project_quantity);
                int project_quantity_int = std::stoi(project_quantity);
                executive.setProjectQuantity(project_quantity_int);
                break;
            }
            case 4: {
                std::string average_time;
                std::cout << "\n\nВведіть середній час виконання проєкту (в тижнях) - ";
                cin_line(average_time);
                int average_time_int = std::stoi(average_time);
                executive.setAverageTime(average_time_int);
                break;
            }
            case 5: {
                int income, premium, project_quantity_int, average_time_int;
                addDepartmentInfo(income, premium);
                std::string project_quantity;
                std::cout << "\n\nВведіть кількість проєктів - ";
                cin_line(project_quantity);
                project_quantity_int = std::stoi(project_quantity);
                std::string average_time;
                std::cout << "\n\nВведіть середній час виконання проєкту (в тижнях) - ";
                cin_line(average_time);
                average_time_int = std::stoi(average_time);
                executive.setAllInfo(income, premium, project_quantity_int, average_time_int);
                break;
            }
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
}

template<typename T>
void caseIncomeOrPremium(T &obj, int choose) {
    if (choose == 1) {
        std::string income;
        std::cout << "\n\nВведіть дохід підрозділу - ";
        cin_line(income);
        int income_int = std::stoi(income);
        obj.setIncome(income_int);
    } else {
        std::string premium;
        std::cout << "\n\nВведіть преміальні кошти підрозділу - ";
        cin_line(premium);
        int premium_int = std::stoi(premium);
        obj.setPremium(premium_int);
    }
}

void addDepartmentInfo(int &income, int &premium) {
    checkCinAnswer([&income, &premium](std::string &choose) {
        std::cout << "\nВведіть дохід підрозділу - ";
        cin_line(choose);
        income = std::stoi(choose);
        std::cout << "\nВведіть преміальні кошти підрозділу - ";
        cin_line(choose);
        premium = std::stoi(choose);
    });
}

void seeDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive, std::vector<Manager> &managers) {
    checkCinAnswer([&marketing, &legal, &executive, &managers](std::string &choose) {
        {
            gap();
            std::cout << "\nОберіть підрозділ (натисніть '0', щоб повернутися назад)\n"
                         "1). Маркетинговий\n"
                         "2). Юридичний\n"
                         "3). Виконавчий\n";
            cin_line(choose);
            int choose_int = std::stoi(choose);
            switch (choose_int) {
                case 1:
                    chooseInfoForWatching(marketing, managers);
                    break;
                case 2:
                    chooseInfoForWatching(legal, managers);
                    break;
                case 3:
                    chooseInfoForWatching(executive, managers);
                    break;
                case 0:
                    break;
                default:
                    throw std::out_of_range("\nНеправильно введене число\n");
            }
        }
    });
    pause();
}

template<typename T>
void chooseInfoForWatching(T &obj, std::vector<Manager> &managers) {
    checkCinAnswer([&obj, &managers](std::string &choose) {
        gap();
        std::cout << "Оберіть яку інформацію хочете побачити\n"
                     "1). Керівний склад\n"
                     "2). Працівників\n"
                     "3). Загальну інформацію\n";
        cin_line(choose);
        bool exist = false;
        int choose_int = std::stoi(choose);
        make_cout_yellow();
        switch (choose_int) {
            case 1:
                std::cout << "\n\nКерівний склад: \n";
                std::for_each(managers.begin(), managers.end(), [&obj, &exist](Manager &manager) {
                    if (obj.getName() == manager.getDepartment()) {
                        std::cout << " " << manager.getFullname() << "\n";
                        exist = true;
                    }
                });
                if (!exist) std::cout << "\n\nКерівників поки що немає\n\n";
                break;
            case 2:
                checkCinAnswer([&](std::string &choose) {
                    make_cout_normal();
                    gap();
                    std::cout << "Оберіть за чим сортувати керівників"
                                 "\n1). Прізвище"
                                 "\n2). Оклад"
                                 "\n3). ID\n";
                    std::vector<Employee> workers = obj.getWorkers();
                    chooseWorkerSort<Employee>(workers, choose);
                });
                break;
            case 3:
                obj.getDepartmentInfo();
                break;
            case 0:
                break;
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
        make_cout_normal();
    });
}

void seeDepartmentSalaryInfo(Marketing &marketing, Legal &legal, Executive &executive, std::vector<Manager> &managers) {
    checkCinAnswer([&](std::string &choose) {
        gap();
        std::cout << "Оберіть підрозділ (натисніть '0', щоб повернутися назад)\n"
                     "1). Маркетинговий\n"
                     "2). Юридичний\n"
                     "3). Виконавчий\n";
        cin_line(choose);
        int choose_int = std::stoi(choose);
        make_cout_yellow();

        switch (choose_int) {
            case 1:
                marketing.getSalaryInformation(managersSalary(managers, "Marketing"));
                break;
            case 2:
                legal.getSalaryInformation(managersSalary(managers, "Legal"));
                break;
            case 3:
                executive.getSalaryInformation(managersSalary(managers, "Executive"));
                break;
            case 0:
                break;
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
        make_cout_normal();
    });
    pause();
}

[[nodiscard]] int managersSalary(std::vector<Manager> &managers, std::string department) {
    int total_salary = 0;
    std::for_each(managers.begin(), managers.end(), [&department, &total_salary](Manager &manager) {
        if (manager.getDepartment() == department) {
            total_salary = manager.getSalary() + manager.getPremium();
        }
    });
    return total_salary;
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
