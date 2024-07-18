#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H

// declaration
void changeDepartmentInfo(Marketing &marketing);

void changeMarketing(Marketing &marketing);


// definition
void changeDepartmentInfo(Marketing &marketing) {
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
                case 0:
                    exit = true;
                    break;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        }
    }
}

void changeMarketing(Marketing &marketing) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        std::cout << "Оберіть що хочете змінити\n"
                     "1). Дохід\n"
                     "2). Премія\n"
                     "3). Відсоток успішності реклами\n";
        std::cin >> choose;
        try {
            if (choose.size() > 1) throw 0;
            int choose_int = std::stoi(choose);

            switch (choose_int) {
                case 1: {
                    std::string income;
                    std::cout << "\n\nВведіть дохід підрозділу - ";
                    std::cin >> income;
                    int income_int = std::stoi(income);
                    marketing.setIncome(income_int);
                    exit = true;
                    break;
                }
                case 2: {
                    std::string premium;
                    std::cout << "\n\nВведіть дохід підрозділу - ";
                    std::cin >> premium;
                    int premium_int = std::stoi(premium);
                    marketing.setPremium(premium_int);
                    exit = true;
                    break;
                }
                case 3:
                    std::string ad_success_rate;
                    std::cout << "\n\nВведіть дохід підрозділу - ";
                    std::cin >> ad_success_rate;
                    int ad_success_rate_int = std::stoi(ad_success_rate);
                    marketing.setAdSuccessRate(ad_success_rate_int);
                    exit = true;
                    break;
            }
        }
        catch (...) {
            gap();
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
        }
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
