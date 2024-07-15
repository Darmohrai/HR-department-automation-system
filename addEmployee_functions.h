#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H

void gap();

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers);

void reader();

void addManager(std::vector<Manager> &managers);

void addOfficeWorker(std::vector<OfficeWorker> &office_workers);

void addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers);


void gap() {
    std::cout << "\n--------------------------------------------------------------\n";
}

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
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
                    addOfficeWorker(office_workers);
                    exit = true;
                    break;
                case '3':
                    addAuxiliaryPosition(auxiliary_position_workers);
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

void reader(std::string &fullname, int &age, int &passport_number,
            std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
            std::string &position, int &salary, std::string &last_appointment) {
    bool error = false;
    std::string reader;

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
}

void addManager(std::vector<Manager> &managers) {
    gap();

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

    reader(fullname, age, passport_number, education, entry_date, specialty, department, position, salary,
           last_appointment);

    bool error = false;
    std::string reader;
    int premium;

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

void addOfficeWorker(std::vector<OfficeWorker> &office_workers) {
    gap();

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

    reader(fullname, age, passport_number, education, entry_date, specialty, department,
           position, salary, last_appointment);

    bool error = false;
    std::string reader;

    int experience;
    int id;
    int project_numbers;

    while (!error) {
        try {
            std::cout << "\nВведіть досвід роботи (в роках) - ";
            std::cin >> reader;
            experience = std::stoi(reader);
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
            std::cout << "\nВведіть id - ";
            std::cin >> reader;
            id = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    while (!error) {
        try {
            std::cout << "\nВведіть кількість проєктів у яких бере участь - ";
            std::cin >> reader;
            project_numbers = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    OfficeWorker new_officeWorker;
    office_workers.push_back(std::move(new_officeWorker));
}

void addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    gap();

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

    reader(fullname, age, passport_number, education, entry_date, specialty, department,
           position, salary, last_appointment);

    bool error = false;
    std::string reader;

    int experience;
    int phone_number;

    while (!error) {
        try {
            std::cout << "\nВведіть досвід роботи (в роках) - ";
            std::cin >> reader;
            experience = std::stoi(reader);
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
            std::cout << "\nВведіть номер телефону - ";
            std::cin >> reader;
            phone_number = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    AuxiliaryPosition new_auxiliaryPosition;
    auxiliary_position_workers.push_back(std::move(new_auxiliaryPosition));
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H