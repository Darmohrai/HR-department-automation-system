#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H

// declaration
void gap();

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                 Executive &executive);

void readerPerson(std::string &fullname, int &age, int &passport_number,
                  std::string &education, std::string &entry_date, std::string &specialty);

void readerEmployee(std::string &fullname, int &age, int &passport_number,
                    std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                    std::string &position, int &salary, std::string &last_appointment, int &department_int);

void addManager(std::vector<Manager> &managers, Marketing &marketing, Legal &legal,
                Executive &executive);

void addOfficeWorker(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                     Executive &executive);

void
addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                     Executive &executive);



// definition
void gap() {
    std::cout << "\n--------------------------------------------------------------\n";
}

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                 Executive &executive) {
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
                    addManager(managers, marketing, legal, executive);
                    exit = true;
                    break;
                case '2':
                    addOfficeWorker(office_workers, marketing, legal, executive);
                    exit = true;
                    break;
                case '3':
                    addAuxiliaryPosition(auxiliary_position_workers, marketing, legal, executive);
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

void readerPerson(std::string &fullname, int &age, int &passport_number,
                  std::string &education, std::string &entry_date, std::string &specialty) {
    bool error = false;
    std::string reader;

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
}

void readerEmployee(std::string &fullname, int &age, int &passport_number,
                    std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                    std::string &position, int &salary, std::string &last_appointment, int &department_int) {
    readerPerson(fullname, age, passport_number, education, entry_date, specialty);

    bool error = false;
    std::string reader;


    while (!error) {
        try {
            std::cout << "\nОберіть підрозділ \n"
                         "1). Маркетинговий\n"
                         "2). Юридичний\n"
                         "3). Виконавчий\n";
            std::cin >> reader;
            department_int = std::stoi(reader);
            error = true;
            if (department_int == 1) department = "Marketing";
            else if (department_int == 2) department = "Legal";
            else if (department_int == 3) department = "Executive";
            else throw 0;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

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

void addManager(std::vector<Manager> &managers, Marketing &marketing, Legal &legal,
                Executive &executive) {
    gap();
    int department_int;

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

    readerEmployee(fullname, age, passport_number, education, entry_date, specialty, department, position, salary,
                   last_appointment, department_int);

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

    switch (department_int) {
        case 1: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, premium, &marketing);
            managers.push_back(std::move(new_manager));
            break;
        }
        case 2: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, premium, &legal);
            managers.push_back(std::move(new_manager));
            break;
        }
        case 3: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, premium, &executive);
            managers.push_back(std::move(new_manager));
            break;
        }
    }
}

void addOfficeWorker(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                     Executive &executive) {
    gap();
    int department_int;

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

    readerEmployee(fullname, age, passport_number, education, entry_date, specialty, department,
                   position, salary, last_appointment, department_int);

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

    error = false;
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

    OfficeWorker new_officeWorker(fullname, age, passport_number, education, entry_date, specialty,
                                  department, position, salary, last_appointment, experience, id,
                                  project_numbers);
    office_workers.push_back(std::move(new_officeWorker));

    switch (department_int) {
        case 1:
            marketing.setWorker(office_workers.back());
            break;
        case 2:
            legal.setWorker(office_workers.back());
            break;
        case 3:
            executive.setWorker(office_workers.back());
            break;
    }
}

void
addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                     Executive &executive) {
    gap();
    int department_int;

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

    readerEmployee(fullname, age, passport_number, education, entry_date, specialty, department,
                   position, salary, last_appointment, department_int);

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

    AuxiliaryPosition new_auxiliaryPosition(fullname, age, passport_number, education, entry_date,
                                            specialty, department, position, salary, last_appointment,
                                            experience, phone_number);
    auxiliary_position_workers.push_back(std::move(new_auxiliaryPosition));

    switch (department_int) {
        case 1:
            marketing.setWorker(auxiliary_position_workers.back());
            break;
        case 2:
            legal.setWorker(auxiliary_position_workers.back());
            break;
        case 3:
            executive.setWorker(auxiliary_position_workers.back());
            break;
    }
}



#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H