#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H

#include <thread>
#include <mutex>

std::mutex mtx_for_database;

// declaration
void clear_file(std::string &filename);

void readDepartmentWorkers(std::vector<OfficeWorker> &office_workers,
                           std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing,
                           Legal &legal,
                           Executive &executive);


template<typename T_s>
void saveWorkerInfo(std::vector<T_s> &vector_obj, std::string &filename);

template<typename T_r>
void readWorkerInfo(std::vector<T_r> &vector_obj, std::string &filename);


void threadsSaveInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees);

void threadsReadInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees);


template<typename T_s>
void saveDepartment(T_s &obj, std::string &filename);

void threadsSaveDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive);

template<typename T_r>
void readDepartmentInfo(T_r &obj, std::string &filename);

void threadsReadDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive,
                               std::vector<OfficeWorker> &office_workers,
                               std::vector<AuxiliaryPosition> &auxiliary_position_workers);


// definition
void clear_file(std::string &filename) {
    std::ofstream fclear(filename, std::ios::trunc | std::ios::out);
    fclear.close();
}


template<typename T_s>
void saveWorkerInfo(std::vector<T_s> &vector_obj, std::string &filename) {
    clear_file(filename);
    try {
        std::ofstream fout(filename, std::ios::in);
        fout << vector_obj.size() << "\n\n";
        std::for_each(vector_obj.begin(), vector_obj.end(), [&fout](T_s &obj) {
            obj.saveInfo(fout);
        });
        fout.close();
    }
    catch (...) {
        std::cout << "\nСталася помилка збереження інформації\n";
    }
}

template<typename T_r>
void readWorkerInfo(std::vector<T_r> &vector_obj, std::string &filename) {
    try {
        std::ifstream fin(filename);
        if(!fin.is_open()) return;
        int count = 0;
        std::string reader;
        std::getline(fin, reader);
        count = std::stoi(reader);
        for (int i = 0; i < count; i++) {
            T_r obj;
            obj.readInfo(fin);
            vector_obj.push_back(std::move(obj));
        }
        fin.close();
    }
    catch (...) {
        std::cout << "\nСталася помилка зчитування інформації\n";
    }
}


void threadsSaveInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees) {
    try {
        std::lock_guard<std::mutex> save_lockGuard(mtx_for_database);

        std::string filename_manager =
                R"(..\\savings_file\\manager.txt)";
        std::string filename_office_worker =
                R"(..\\savings_file\\office_worker.txt)";
        std::string filename_auxiliary_position =
                R"(..\\savings_file\\auxiliary_position.txt)";
        std::string filename_trainee =
                R"(..\\savings_file\\trainee.txt)";


        std::thread save_manager_info(saveWorkerInfo<Manager>, std::ref(managers), std::ref(filename_manager));
        std::thread save_office_worker_info(saveWorkerInfo<OfficeWorker>, std::ref(office_workers),
                                            std::ref(filename_office_worker));
        std::thread save_auxiliary_position(saveWorkerInfo<AuxiliaryPosition>, std::ref(auxiliary_position_workers),
                                            std::ref(filename_auxiliary_position));
        std::thread save_trainee(saveWorkerInfo<Trainee>, std::ref(trainees), std::ref(filename_trainee));
        save_manager_info.join();
        save_office_worker_info.join();
        save_auxiliary_position.join();
        save_trainee.join();
    }
    catch (...) {
        std::cerr << "\nСталася помилка збереження інформації\n";
    }
}

void threadsReadInfo(std::vector<Manager> &managers, std::vector<OfficeWorker> &office_workers,
                     std::vector<AuxiliaryPosition> &auxiliary_position_workers, std::vector<Trainee> &trainees) {
    try {
        std::lock_guard<std::mutex> read_lockGuard(mtx_for_database);

        std::string filename_manager =
                R"(..\\savings_file\\manager.txt)";
        std::string filename_office_worker =
                R"(..\\savings_file\\office_worker.txt)";
        std::string filename_auxiliary_position =
                R"(..\\savings_file\\auxiliary_position.txt)";
        std::string filename_trainee =
                R"(..\\savings_file\\trainee.txt)";

        std::thread read_manager_info(readWorkerInfo<Manager>, std::ref(managers), std::ref(filename_manager));
        std::thread read_office_worker_info(readWorkerInfo<OfficeWorker>, std::ref(office_workers),
                                            std::ref(filename_office_worker));
        std::thread read_auxiliary_position_info(readWorkerInfo<AuxiliaryPosition>,
                                                 std::ref(auxiliary_position_workers),
                                                 std::ref(filename_auxiliary_position));
        std::thread read_trainee_info(readWorkerInfo<Trainee>, std::ref(trainees), std::ref(filename_trainee));

        read_manager_info.join();
        read_office_worker_info.join();
        read_auxiliary_position_info.join();
        read_trainee_info.join();
    }
    catch (...) {
        std::cerr << "\nСталася помилка зчитування інформації\n";
    }
}

void readDepartmentWorkers(std::vector<OfficeWorker> &office_workers,
                           std::vector<AuxiliaryPosition> &auxiliary_position_workers, Marketing &marketing,
                           Legal &legal,
                           Executive &executive) {
    std::for_each(office_workers.begin(), office_workers.end(),
                  [&marketing, &legal, &executive](OfficeWorker &officeWorker) {
                      if (officeWorker.getDepartment() == "Marketing") marketing.setWorker(officeWorker);
                      else if (officeWorker.getDepartment() == "Legal") legal.setWorker(officeWorker);
                      else if (officeWorker.getDepartment() == "Executive") executive.setWorker(officeWorker);
                  });

    std::for_each(auxiliary_position_workers.begin(), auxiliary_position_workers.end(),
                  [&marketing, &legal, &executive](AuxiliaryPosition &auxiliaryPosition) {
                      if (auxiliaryPosition.getDepartment() == "Marketing") marketing.setWorker(auxiliaryPosition);
                      else if (auxiliaryPosition.getDepartment() == "Legal") legal.setWorker(auxiliaryPosition);
                      else if (auxiliaryPosition.getDepartment() == "Executive") executive.setWorker(auxiliaryPosition);
                  });
}


template<typename T_s>
void saveDepartment(T_s &obj, std::string &filename) {
    clear_file(filename);
    try {
        std::ofstream fout(filename, std::ios::in);
        obj.saveInfo(fout);
        fout.close();
    }
    catch (...) {
        std::cout << "\nСталася помилка збереження інформації\n";
    }
}

void threadsSaveDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive) {
    try {
        std::lock_guard<std::mutex> lockGuard(mtx_for_database);
        std::string marketing_filename =
                R"(..\\savings_file\\marketing_department.txt)";
        std::string legal_filename =
                R"(..\\savings_file\\legal_department.txt)";
        std::string executive_filename =
                R"(..\\savings_file\\executive_department.txt)";

        std::thread save_marketing_info(saveDepartment<Marketing>, std::ref(marketing),
                                        std::ref(marketing_filename));
        std::thread save_legal_info(saveDepartment<Legal>, std::ref(legal),
                                    std::ref(legal_filename));
        std::thread save_executive_info(saveDepartment<Executive>, std::ref(executive),
                                        std::ref(executive_filename));

        save_marketing_info.join();
        save_legal_info.join();
        save_executive_info.join();
    }
    catch (...) {
        std::cerr << "\nСталася помилка збереження інформації\n";
    }
}

template<typename T_r>
void readDepartmentInfo(T_r &obj, std::string &filename) {
    try {
        std::ifstream fin(filename);
        if(!fin.is_open()) return;
        obj.readInfo(fin);
    }
    catch (...) {
        std::cout << "\nСталася помилка зчитування інформації\n";
    }
}

void threadsReadDepartmentInfo(Marketing &marketing, Legal &legal, Executive &executive,
                               std::vector<OfficeWorker> &office_workers,
                               std::vector<AuxiliaryPosition> &auxiliary_position_workers) {
    try {
        std::lock_guard<std::mutex> read_lockGuard(mtx_for_database);

        std::string marketing_filename =
                R"(..\\savings_file\\marketing_department.txt)";
        std::string legal_filename =
                R"(..\\savings_file\\legal_department.txt)";
        std::string executive_filename =
                R"(..\\savings_file\\executive_department.txt)";

        std::thread read_marketing_info(readDepartmentInfo<Marketing>, std::ref(marketing),
                                        std::ref(marketing_filename));
        std::thread read_legal_info(readDepartmentInfo<Legal>, std::ref(legal),
                                    std::ref(legal_filename));
        std::thread read_executive_info(readDepartmentInfo<Executive>, std::ref(executive),
                                        std::ref(executive_filename));
        std::thread read_department_workers(readDepartmentWorkers, std::ref(office_workers),
                                            std::ref(auxiliary_position_workers), std::ref(marketing), std::ref(legal),
                                            std::ref(executive));

        read_marketing_info.join();
        read_legal_info.join();
        read_executive_info.join();
        read_department_workers.join();
    }
    catch (...) {
        std::cerr << "\nСталася помилка зчитування інформації\n";
    }
}

#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_SAVE_READ_FUNCTIONS_H
