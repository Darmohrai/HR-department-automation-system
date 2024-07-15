#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H

void gap();

void addEmployee(std::vector<Manager> &managers);

void addManager(std::vector<Manager> &managers);


void gap() {
    std::cout << "\n--------------------------------------------------------------\n";
}

void addEmployee(std::vector<Manager> &managers) {
    bool exit = false;
    std::string choose;

    while (!exit) {
        gap();
        std::cout << "Оберіть якого робітника Ви хочете додати (щоб повернутися до головного меню введіть '0')"
                     "\n1). Керівник"
                     "\n2). Офісний працівник"
                     "\n3). Додаткова посада\n";

        std::cin >> choose;

        try {
            if (choose.size() > 1) throw 0;
            switch (choose[0]) {
                case '1':
                    addManager(managers);
                    exit = true;
                    break;
                case '2':
                    // should be function OfficeWorker();
                    exit = true;
                    break;
                case '3':
                    // should be function addAuxiliaryPosition();
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

void addManager(std::vector<Manager> &managers) {
    gap();
    bool error = false;
    std::string reader;

    std::string fullname;
    int age;
    int passport_number;
    std::string education;
    std::string entry_date;
    std::string specialty;
    std::string department;
    std::string position;
    int salary;
    std::string last_appointment;
    int premium;


    std::cout << "\nВведіть ПІБ - ";
    std::cin >> fullname;

    while (!error) {
        try {
            std::cout << "\nВведіть вік - ";
            std::cin >> reader;
            age = std::stoi(reader);
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
            std::cout << "\nВведіть паспортні дані (номер) - ";
            std::cin >> reader;
            passport_number = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    std::cout << "\nВведіть ВНЗ, який закінчував - ";
    std::cin >> education;

    std::cout << "\nВведіть дату прийняття на роботу - ";
    std::cin >> entry_date;

    std::cout << "\nВведіть спеціальність - ";
    std::cin >> specialty;

    std::cout << "\nВведіть підрозділ - ";
    std::cin >> department;

    std::cout << "\nВведіть посаду - ";
    std::cin >> position;

    error = false;
    while (!error) {
        try {
            std::cout << "\nВведіть зарплату - ";
            std::cin >> reader;
            salary = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    std::cout << "\nВведіть дату останнього призначення - ";
    std::cin >> last_appointment;

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

    Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position, salary,
                        last_appointment, premium);

    managers.push_back(std::move(new_manager));
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H