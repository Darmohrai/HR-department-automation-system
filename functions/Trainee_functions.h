#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H

// declaration
void addTrainee();

void changeTraineeInfo(std::vector<Trainee> &trainees);

void performanceTrainee(std::string &performance);

void employ(Trainee &trainee, std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
            Executive &executive);

void seeTraineeInfo(std::vector<Trainee> &trainees);


// definition
void addTrainee(std::vector<Trainee> &trainees) {
    gap();

    std::string fullname;
    int age;
    int passport_number;
    std::string education;
    std::string entry_date;
    std::string specialty;

    readerPerson(fullname, age, passport_number, education, entry_date, specialty);

    int probation;
    std::string performance;
    std::string mentor;

    checkCinAnswer([&probation](bool &error, std::string &reader) {
        std::cout << "\nВведіть кількість днів стажування - ";
        cin_line(reader);
        probation = std::stoi(reader);
        error = true;
    });

    performanceTrainee(performance);

    std::cout << "\nВведіть ПІБ ментора - ";
    cin_line(mentor);

    Trainee new_Trainee(fullname, age, passport_number, education, entry_date, specialty,
                        probation, performance, mentor);

    trainees.push_back(std::move(new_Trainee));
}

void changeTraineeInfo(std::vector<Trainee> &trainees) {
    if (trainees.empty()) {
        std::cout << "\nПрактикантів поки немає\n";
        return;
    }
    int choose_trainee;

    //import from file changeEmployee_functions
    findWorker(trainees, choose_trainee);

    std::string performance;
    performanceTrainee(performance);

    trainees[choose_trainee - 1].setPerformance(performance);
}

void performanceTrainee(std::string &performance) {
    checkCinAnswer([&](bool &exit, std::string &choose) {
        int performance_int;
        std::cout << "\nВведіть продуктивність\n"
                     "1). Добре\n"
                     "2). Нормально\n"
                     "3). Погано\n";
        cin_line(choose);
        performance_int = std::stoi(choose);
        exit = true;
        switch (performance_int) {
            case 1:
                performance = "well";
                break;
            case 2:
                performance = "normal";
                break;
            case 3:
                performance = "bad";
                break;
            default:
                throw 0;
        }
    });
}

void employ(Trainee &trainee, std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
            Executive &executive, int &id) {
    std::string department;
    std::string position;
    int salary;
    std::string last_appointment;
    int department_int;

    checkCinAnswer([&department_int, &department](bool &error, std::string &reader) {
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
    });

    std::cout << "\nВведіть посаду - ";
    cin_line(position);

    checkCinAnswer([&salary](bool &error, std::string &reader) {
        std::cout << "\nВведіть зарплату - ";
        cin_line(reader);
        salary = std::stoi(reader);
        error = true;
    });

    std::cout << "\nВведіть дату останнього призначення - ";
    cin_line(last_appointment);


    int experience;
    int project_numbers;

    checkCinAnswer([&experience](bool &error, std::string &reader) {
        std::cout << "\nВведіть досвід роботи (в роках) - ";
        cin_line(reader);
        experience = std::stoi(reader);
        error = true;
    });

    checkCinAnswer([&project_numbers](bool &error, std::string &reader) {
        std::cout << "\nВведіть кількість проєктів у яких бере участь - ";
        cin_line(reader);
        project_numbers = std::stoi(reader);
        error = true;
    });

    std::string fullname = trainee.getFullname();
    int age = trainee.getAge();
    int passport_number = trainee.getPassportNumber();
    std::string education = trainee.getEducation();
    std::string specialty = trainee.getSpecialty();

    OfficeWorker new_officeWorker(fullname, age, passport_number, education, last_appointment, specialty,
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
    }
}

void seeTraineeInfo(std::vector<Trainee> &trainees) {
    bool exit = false;
    std::string choose;

    if (trainees.empty()) {
        std::cout << "\nСтажерів поки немає\n";
        return;
    }
    checkCinAnswer([&](bool &error, std::string &reader) {
        std::cout << "\nОберіть тип інформації\n"
                     "1). Повна\n"
                     "2). Коротка\n";
        exit = true;
        cin_line(choose);
        int choose_int = std::stoi(choose);
        std::cout << "\n\n";
        switch (choose_int) {
            case 1:
                std::for_each(trainees.begin(), trainees.end(), [](Trainee &trainee) {
                    std::cout << "\n";
                    trainee.getAllInfo();
                });
                break;
            case 2:
                std::for_each(trainees.begin(), trainees.end(), [](Trainee &trainee) {
                    std::cout << "\n";
                    trainee.getBriefInfo();
                });
                break;
            default:
                throw 0;
        }
    });

    std::cout << "\n\nНатисніть будь-яку кнопку, щоб продовжити\n ";
    system("pause");
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H
