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
    checkCinAnswer([&managers, &office_workers, &auxiliary_position_workers, &marketing, &legal, &executive]
                           (bool &exit, std::string &choose) {
        {
            gap();
            std::cout << "Оберіть якого робітника Ви хочете додати (щоб повернутися до головного меню введіть '0')"
                         "\n1). Керівник"
                         "\n2). Офісний працівник"
                         "\n3). Додаткова посада\n";

            cin_line(choose);
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
    });
}

void readerPerson(std::string &fullname, int &age, int &passport_number,
                  std::string &education, std::string &entry_date, std::string &specialty) {
    std::cout << "\nВведіть ПІБ - ";
    cin_line(fullname);

    checkCinAnswer([&age](bool &error, std::string &reader) {
                       std::cout << "\nВведіть вік - ";
                       cin_line(reader);
                       age = std::stoi(reader);
                       error = true;
                   }
    );

    checkCinAnswer([&passport_number](bool &error, std::string &reader) {
                       std::cout << "\nВведіть паспортні дані (номер) - ";
                       cin_line(reader);;
                       passport_number = std::stoi(reader);
                       error = true;
                   }
    );

    std::cout << "\nВведіть ВНЗ, який закінчував - ";
    cin_line(education);


    checkCinAnswer([&entry_date](bool &error, std::string &reader) {
        std::cout << "\nВведіть дату прийняття на роботу (приклад: 24/08/1991) - ";
        cin_line(reader);
        entry_date = reader;
        std::stringstream ss_reader(reader);
        int data;
        for (int i = 0; i < 3; i++) {
            if (ss_reader.eof()) throw 0;
            std::getline(ss_reader, reader, '/');
            data = std::stoi(reader);
        }
        error = true;
    });


    std::cout << "\nВведіть спеціальність - ";
    cin_line(specialty);
}

void readerEmployee(std::string &fullname, int &age, int &passport_number,
                    std::string &education, std::string &entry_date, std::string &specialty, std::string &department,
                    std::string &position, int &salary, std::string &last_appointment, int &department_int) {
    readerPerson(fullname, age, passport_number, education, entry_date, specialty);

    checkCinAnswer([&department, &department_int](bool &error, std::string reader) {
                       std::cout << "\nОберіть підрозділ \n"
                                    "1). Маркетинговий\n"
                                    "2). Юридичний\n"
                                    "3). Виконавчий\n";
                       cin_line(reader);
                       department_int = std::stoi(reader);
                       error = true;
                       if (department_int == 1) department = "Marketing";
                       else if (department_int == 2) department = "Legal";
                       else if (department_int == 3) department = "Executive";
                       else throw 0;
                   }
    );

    std::cout << "\nВведіть посаду - ";
    cin_line(position);

    checkCinAnswer([&salary](bool &error, std::string reader) {
                       std::cout << "\nВведіть зарплату - ";
                       cin_line(reader);
                       salary = std::stoi(reader);
                       error = true;
                   }
    );

    checkCinAnswer([&last_appointment](bool &error, std::string &reader) {
        std::cout << "\nВведіть дату останнього призначення (приклад: 24/08/1991) - ";
        cin_line(reader);
        last_appointment = reader;
        std::stringstream ss_reader(reader);
        int data;
        for (int i = 0; i < 3; i++) {
            if (ss_reader.eof()) throw 0;
            std::getline(ss_reader, reader, '/');
            data = std::stoi(reader);
        }
        error = true;
    });
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

    int premium;

    checkCinAnswer([&premium](bool &error, std::string reader) {
                       std::cout << "\nВведіть премію - ";
                       cin_line(reader);
                       premium = std::stoi(reader);
                       error = true;
                   }
    );

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

    int experience;
    int id;
    int project_numbers;

    checkCinAnswer([&experience](bool &error, std::string &reader) {
        std::cout << "\nВведіть досвід роботи (в роках) - ";
        cin_line(reader);
        experience = std::stoi(reader);
        error = true;
    });

    checkCinAnswer([&id](bool &error, std::string reader) {
        std::cout << "\nВведіть id - ";
        cin_line(reader);
        id = std::stoi(reader);
        error = true;
    });

    checkCinAnswer([&project_numbers](bool &error, std::string &reader) {
        std::cout << "\nВведіть кількість проєктів у яких бере участь - ";
        cin_line(reader);
        project_numbers = std::stoi(reader);
        error = true;
    });

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
    int experience;
    int phone_number;

    checkCinAnswer([&experience](bool &error, std::string &reader) {
        std::cout << "\nВведіть досвід роботи (в роках) - ";
        cin_line(reader);
        experience = std::stoi(reader);
        error = true;
    });

    checkCinAnswer([&phone_number](bool &error, std::string &reader) {
        std::cout << "\nВведіть номер телефону - ";
        cin_line(reader);
        phone_number = std::stoi(reader);
        error = true;
    });

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