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


    bool error = false;
    std::string reader;

    int probation;
    std::string performance;
    std::string mentor; // // should be 'has a relationship' with class Employee

    while (!error) {
        try {
            std::cout << "\nВведіть кількість днів стажування - ";
            std::cin >> reader;
            probation = std::stoi(reader);
            error = true;
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }

    performanceTrainee(performance);

    std::cout << "\nВведіть ПІБ ментора - ";
    std::cin >> mentor;

    Trainee new_Trainee(fullname, age, passport_number, education, entry_date, specialty,
                        probation, performance, mentor);

    trainees.push_back(std::move(new_Trainee));
}

void changeTraineeInfo(std::vector<Trainee> &trainees) {
    int choose_trainee;

    //import from file changeEmployee_functions
    findWorker(trainees, choose_trainee);

    int exit = false;
    std::string performance;

    performanceTrainee(performance);

    trainees[choose_trainee-1].setPerformance(performance);
}

void performanceTrainee(std::string &performance) {
    bool error = false;
    std::string reader;
    while (!error) {
        try {
            int performance_int;
            std::cout << "\nВведіть продуктивність\n"
                         "1). Добре\n"
                         "2). Нормально\n"
                         "3). Погано\n";
            std::cin >> reader;
            performance_int = std::stoi(reader);
            error = true;
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
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            error = false;
        }
    }
}

void employ(Trainee &trainee, std::vector<OfficeWorker> &office_workers, Marketing &marketing, Legal &legal,
            Executive &executive) {
    std::string department;
    std::string position;
    int salary;
    std::string last_appointment;
    int department_int;

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


    int experience;
    int id;
    int project_numbers;

    error = false;
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

    std::string fullname = trainee.getFullname();
    int age = trainee.getAge();
    int passport_number = trainee.getPassportNumber();
    std::string education = trainee.getEducation();
    std::string specialty = trainee.getSpecialty();

    OfficeWorker new_officeWorker(fullname, age, passport_number, education, last_appointment, specialty,
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

void seeTraineeInfo(std::vector<Trainee> &trainees){
    bool exit = false;
    std::string choose;

    while (!exit){
        std::cout << "\nОберіть тип інформації\n"
                     "1). Повна\n"
                     "2). Коротка\n";
        try{
            exit = true;
            std::cin >> choose;
            int choose_int = std::stoi(choose);
            std::cout << "\n\n";
            switch (choose_int) {
                case 1:
                    std::for_each(trainees.begin(), trainees.end(), [](Trainee &trainee){
                        std::cout << "\n";
                        trainee.getAllInfo();
                    });
                    break;
                case 2:
                    std::for_each(trainees.begin(), trainees.end(), [](Trainee &trainee){
                        std::cout << "\n";
                        trainee.getBriefInfo();
                    });
                    break;
                default:
                    throw 0;
            }
        }
        catch (...) {
            std::cout << "\nПомилка вводу, спробуйте ще раз\n";
            exit = false;
        }
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H
