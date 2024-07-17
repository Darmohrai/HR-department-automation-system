#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H

#include <mutex>

std::mutex mtx_manager;

void clear_file(std::string &filename);

void saveManager(std::vector<Manager> &managers);


void readManager(std::vector<Manager> &managers);


void clear_file(std::string &filename) {
    std::ofstream fclear(filename, std::ios::trunc | std::ios::out);
    fclear.close();
}


void saveManager(std::vector<Manager> &managers) {
    std::string filename = "D:\\course project\\HR-department-automation-system\\savings_file\\manager.txt";
    clear_file(filename);
    try {
        std::lock_guard<std::mutex> lockGuard_manager(mtx_manager);
        std::ofstream fout(filename, std::ios::in);
        fout << managers.size() << "\n\n";
        std::for_each(managers.begin(), managers.end(), [&fout](Manager &manager) {
            manager.saveInfo(fout);
        });
        fout.close();
    }
    catch (...) {
        std::cout << "\nСталася помилка збереження інформації\n";
    }
}

void readManager(std::vector<Manager> &managers) {
    try {
        std::lock_guard<std::mutex> lockGuard_manager(mtx_manager);
        std::string file_name = "D:\\course project\\HR-department-automation-system\\savings_file\\manager.txt";
        std::ifstream fin(file_name);
        int count = 0;
        fin >> count;
        for (int i = 0; i < count; i++) {
            Manager manager;
            manager.readInfo(fin);
            managers.push_back(std::move(manager));
        }
    }
    catch (...) {
        std::cout << "\nСталася помилка зчитування інформації\n";
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
