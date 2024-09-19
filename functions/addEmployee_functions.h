#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H

// declaration
void gap();

void setID(int &id, std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
           std::vector<AuxiliaryPosition> &auxiliary_position_workers);

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                 Executive &executive);

void readerPerson(std::string &fullname, int &age, int &passport_number,
                  std::string &education, std::string &entry_date, std::string &specialty);

void readerEmployee(std::string &fullname, int &age, int &passport_number,
                    std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                    std::string &position, int &salary, std::string &last_appointment, int &department_int);

void addManager(std::vector<Manager> &managers, Marketing &marketing, Legal &legal,
                Executive &executive, int &id);

void addOfficeWorker(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                     Executive &executive, int &id);

void
addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                     Executive &executive, int &id);

bool isLeapYear(int year);

void validateDate(int day, int month, int year);


// definition
void gap() {
    std::cout << "\n--------------------------------------------------------------\n";
}

void setID(int &id, std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
           std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    int id_managers, id_office_workers, id_auxiliary_position;
    if (!managers.empty()) id_managers = managers[managers.size() - 1].getID();
    else id_managers = 0;
    if (!office_workers.empty()) id_office_workers = office_workers[office_workers.size() - 1].getID();
    else id_office_workers = 0;
    if (!auxiliary_position_workers.empty())
        id_auxiliary_position = auxiliary_position_workers[auxiliary_position_workers.size() - 1].getID();
    else id_auxiliary_position = 0;
    if (id_managers > id_office_workers and id_managers > id_auxiliary_position) id = id_managers + 1;
    else if (id_office_workers > id_managers and id_office_workers > id_auxiliary_position) id = id_office_workers + 1;
    else id = id_auxiliary_position + 1;
}

void addEmployee(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                 std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                 Executive &executive) {
    int id;
    setID(id, managers, office_workers, auxiliary_position_workers);
    checkCinAnswer([&managers, &office_workers, &auxiliary_position_workers, &marketing, &legal, &executive, &id]
                           (std::string &choose) {
        gap();
        std::cout << "Оберіть якого робітника Ви хочете додати (щоб повернутися до головного меню введіть '0')"
                     "\n  ID робітника буде - " << id <<
                  "\n1). Керівник"
                  "\n2). Офісний працівник"
                  "\n3). Додаткова посада\n";
        int choose_int;
        cin_line(choose);
        choose_int = std::stoi(choose);
        switch (choose_int) {
            case 1:
                addManager(managers, marketing, legal, executive, id);
                break;
            case 2:
                addOfficeWorker(office_workers, marketing, legal, executive, id);
                break;
            case 3:
                addAuxiliaryPosition(auxiliary_position_workers, marketing, legal, executive, id);
                break;
            case 0:
                break;
            default:
                throw std::out_of_range("\nНеправильно введене число\n");
        }
    });
}

void readerPerson(std::string &fullname, int &age, int &passport_number,
                  std::string &education, std::string &entry_date, std::string &specialty) {
    std::cout << "\nВведіть ПІБ - ";
    cin_line(fullname);

    checkCinAnswer([&age](std::string &reader) {
                       std::cout << "\nВведіть вік - ";
                       cin_line(reader);
                       age = std::stoi(reader);
                   }
    );

    checkCinAnswer([&passport_number](std::string &reader) {
                       std::cout << "\nВведіть паспортні дані (номер) - ";
                       cin_line(reader);
                       passport_number = std::stoi(reader);
                   }
    );

    std::cout << "\nВведіть ВНЗ, який закінчував - ";
    cin_line(education);


    checkCinAnswer([&entry_date](std::string &reader) {
        std::cout << "\nВведіть дату прийняття на роботу (приклад: 24/08/1991) - ";
        cin_line(reader);
        entry_date = reader;
        std::stringstream ss_reader(reader);
        int data;
        int date_arr[3];
        for (int i = 0; i < 3; i++) {
            if (ss_reader.eof()) throw std::invalid_argument("");
            std::getline(ss_reader, reader, '/');
            data = std::stoi(reader);
            date_arr[i] = data;
        }
        validateDate(date_arr[0], date_arr[1], date_arr[2]);
    });

    std::cout << "\nВведіть спеціальність - ";
    cin_line(specialty);
}

void readerEmployee(std::string &fullname, int &age, int &passport_number,
                    std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                    std::string &position, int &salary, std::string &last_appointment, int &department_int) {
    readerPerson(fullname, age, passport_number, education, entry_date, specialty);

    checkCinAnswer([&department, &department_int](std::string reader) {
                       std::cout << "\nОберіть підрозділ \n"
                                    "1). Маркетинговий\n"
                                    "2). Юридичний\n"
                                    "3). Виконавчий\n";
                       cin_line(reader);
                       department_int = std::stoi(reader);
                       if (department_int == 1) department = "Marketing";
                       else if (department_int == 2) department = "Legal";
                       else if (department_int == 3) department = "Executive";
                       else throw std::out_of_range("\nНеправильно введене число\n");
                   }
    );

    std::cout << "\nВведіть посаду - ";
    cin_line(position);

    checkCinAnswer([&salary](std::string reader) {
                       std::cout << "\nВведіть зарплату - ";
                       cin_line(reader);
                       salary = std::stoi(reader);
                   }
    );

    checkCinAnswer([&last_appointment](std::string &reader) {
        std::cout << "\nВведіть дату останнього призначення (приклад: 24/08/1991) - ";
        cin_line(reader);
        last_appointment = reader;
        std::stringstream ss_reader(reader);
        int data;
        int date_arr[3];
        for (int i = 0; i < 3; i++) {
            if (ss_reader.eof()) throw std::invalid_argument("");
            std::getline(ss_reader, reader, '/');
            data = std::stoi(reader);
            date_arr[i] = data;
        }
        validateDate(date_arr[0], date_arr[1], date_arr[2]);
    });
}

void addManager(std::vector<Manager> &managers, Marketing &marketing, Legal &legal,
                Executive &executive, int &id) {
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

    int premium;

    checkCinAnswer([&premium](std::string reader) {
                       std::cout << "\nВведіть премію - ";
                       cin_line(reader);
                       premium = std::stoi(reader);
                   }
    );

    switch (department_int) {
        case 1: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, id, premium, &marketing);
            managers.push_back(std::move(new_manager));
            break;
        }
        case 2: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, id, premium, &legal);
            managers.push_back(std::move(new_manager));
            break;
        }
        case 3: {
            Manager new_manager(fullname, age, passport_number, education, entry_date, specialty, department, position,
                                salary,
                                last_appointment, id, premium, &executive);
            managers.push_back(std::move(new_manager));
            break;
        }
        default:
            break;
    }
}

void addOfficeWorker(std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
                     Executive &executive, int &id) {
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

    int experience;
    int project_numbers;

    checkCinAnswer([&experience](std::string &reader) {
        std::cout << "\nВведіть досвід роботи (в роках) - ";
        cin_line(reader);
        experience = std::stoi(reader);
    });

    checkCinAnswer([&project_numbers](std::string &reader) {
        std::cout << "\nВведіть кількість проєктів у яких бере участь - ";
        cin_line(reader);
        project_numbers = std::stoi(reader);
    });

    OfficeWorker new_officeWorker(fullname, age, passport_number, education, entry_date, specialty,
                                  department, position, salary, last_appointment, id, experience,
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
        default:
            break;
    }
}

void
addAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing, Legal &legal,
                     Executive &executive, int &id) {
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
    int experience;
    int phone_number;

    checkCinAnswer([&experience](std::string &reader) {
        std::cout << "\nВведіть досвід роботи (в роках) - ";
        cin_line(reader);
        experience = std::stoi(reader);
    });

    checkCinAnswer([&phone_number](std::string &reader) {
        std::cout << "\nВведіть номер телефону - ";
        cin_line(reader);
        phone_number = std::stoi(reader);
    });

    AuxiliaryPosition new_auxiliaryPosition(fullname, age, passport_number, education, entry_date,
                                            specialty, department, position, salary, last_appointment, id,
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
        default:
            break;
    }
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void validateDate(int day, int month, int year) {
    if (month < 1 || month > 12 || day < 1) {
        throw std::invalid_argument("");
    }

    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    } else if (month == 2) {
        maxDays = isLeapYear(year) ? 29 : 28;
    }

    if (day > maxDays)
    {
        throw std::invalid_argument("");
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H