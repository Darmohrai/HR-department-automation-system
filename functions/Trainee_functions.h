#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H

// declaration
void addTrainee();


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

    std::cout << "\nВведіть продуктивність (bad, normal, well) - ";
    std::cin >> performance;

    std::cout << "\nВведіть ПІБ ментора - ";
    std::cin >> mentor;

    Trainee new_Trainee(fullname, age, passport_number, education, entry_date, specialty,
                        probation, performance, mentor);

    trainees.push_back(std::move(new_Trainee));
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_TRAINEE_FUNCTIONS_H
