#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H

void gap() {
    std::cout << "\n--------------------------------------------------------------\n";
}

void addEmployee() {
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
                    // should be function addManager();
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


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_ADDEMPLOYEE_FUNCTIONS_H