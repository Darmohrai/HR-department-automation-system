#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H

// declaration
void createDepartment(std::vector<Marketing> &marketing_departments);

void addDepartment(std::string &manager, int &income, int &premium);

void addMarketing(std::vector<Marketing> &marketing_departments);


// definition
void createDepartment(std::vector<Marketing> &marketing_departments) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        gap();

        std::cout << "Оберіть тип підрозділу\n"
                     "1). Маркетинговий\n"
                     "2). Юридичний\n"
                     "3). Виконавчий\n";

        std::cin >> choose;

        try {
            if (choose.size() > 1) throw 0;
            switch (choose[0]) {
                case '1':
                    addMarketing(marketing_departments);
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

void addDepartment(std::string &manager, int &income, int &premium){
    manager = "None";

    bool error = false;
    std::string reader;

    while (!error) {
        try {
            std::cout << "\nВведіть дохід - ";
            std::cin >> reader;
            income = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    error = false;
    while (!error) {
        try {
            std::cout << "\nВведіть премію - ";
            std::cin >> reader;
            premium = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }
}

void addMarketing(std::vector<Marketing> &marketing_departments) {
    gap();

    std::string manager;
    int income;
    int premium;

    addDepartment(manager, income, premium);

    int ad_success_rate;

    bool error = false;
    std::string reader;

    while (!error) {
        try {
            std::cout << "\nВведіть успішність реклами (у відсотках) - ";
            std::cin >> reader;
            ad_success_rate = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    Marketing new_marketing(manager, income, premium, ad_success_rate);
    marketing_departments.push_back(std::move(new_marketing));
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_DEPARTMENT_FUNCTIONS_H
