#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H

#include <mutex>

std::mutex mtx_manager, mtx_office_worker, mtx_auxiliary_position;

void clear_file(std::string &filename);

void saveManager(std::vector<Manager> &managers);

void saveOfficeWorker(std::vector<OfficeWorker> &office_workers);

void saveAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers);


void readManager(std::vector<Manager> &managers);

void readOfficeWorker(std::vector<OfficeWorker> &office_workers);

void readAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers);


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

void saveOfficeWorker(std::vector<OfficeWorker> &office_workers) {
    std::string filename = "D:\\course project\\HR-department-automation-system\\savings_file\\office_worker.txt";
    clear_file(filename);
    try {
        std::lock_guard<std::mutex> lockGuard_office_worker(mtx_office_worker);
        std::ofstream fout(filename, std::ios::in);
        fout << office_workers.size() << "\n\n";
        std::for_each(office_workers.begin(), office_workers.end(), [&fout](OfficeWorker &officeWorker) {
            officeWorker.saveInfo(fout);
        });
        fout.close();
    }
    catch (...) {
        std::cout << "\nСталася помилка збереження інформації\n";
    }
}

void saveAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    std::string filename = "D:\\course project\\HR-department-automation-system\\savings_file\\auxiliary_position.txt";
    clear_file(filename);
    try {
        std::lock_guard<std::mutex> lockGuard_auxiliary_position(mtx_auxiliary_position);
        std::ofstream fout(filename, std::ios::in);
        fout << auxiliary_position_workers.size() << "\n\n";
        std::for_each(auxiliary_position_workers.begin(), auxiliary_position_workers.end(),
                      [&fout](AuxiliaryPosition &auxiliaryPosition) { auxiliaryPosition.saveInfo(fout); });
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

void readOfficeWorker(std::vector<OfficeWorker> &office_workers) {
    try {
        std::lock_guard<std::mutex> lockGuard_office_worker(mtx_office_worker);
        std::string filename = "D:\\course project\\HR-department-automation-system\\savings_file\\office_worker.txt";
        std::ifstream fin(filename);
        int count = 0;
        fin >> count;
        for (int i = 0; i < count; i++) {
            OfficeWorker officeWorker;
            officeWorker.readInfo(fin);
            office_workers.push_back(std::move(officeWorker));
        }
    }
    catch (...) {
        std::cout << "\nСталася помилка зчитування інформації\n";
    }
}

void readAuxiliaryPosition(std::vector<AuxiliaryPosition> &auxiliary_position_workers){
    try{
        std::lock_guard<std::mutex> lockGuard_auxiliary_position(mtx_auxiliary_position);
        std::string filename = "D:\\course project\\HR-department-automation-system\\savings_file\\auxiliary_position.txt";
        std::ifstream fin (filename);
        int count = 0;
        fin >> count;
        for (int i =0; i < count; i++){
            AuxiliaryPosition auxiliaryPosition;
            auxiliaryPosition.readInfo(fin);
            auxiliary_position_workers.push_back(std::move(auxiliaryPosition));
        }
    }
    catch (...) {
        std::cout << "\nСталася помилка зчитування інформації\n";
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
