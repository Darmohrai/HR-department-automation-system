#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_LOGGER_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_LOGGER_H

#include <string>
#include <fstream>
#include <queue>
#include <mutex>

class Logger {
private:
    static std::queue<std::pair<std::string, std::string>> queue_log;
    static bool do_log;
    static std::mutex log_mtx;
public:
    Logger() = default;

    ~Logger() = default;

    static void make_log() {
        std::string log_file = R"(..\\log_file\\1_log_file.txt)";
        std::ofstream fout(log_file, std::ios::app);
        while (do_log or !queue_log.empty()) {
            if (!queue_log.empty()) {
                fout << "Use " << queue_log.front().first << "| in class - " << queue_log.front().second
                     << std::endl << "-------------------------------------------------------" << std::endl;
                queue_log.pop();
            }
        }
        fout.close();
    }

    static void add_log(std::string method, std::string type_class) {
        std::lock_guard<std::mutex> lockGuard(log_mtx);
        queue_log.push(std::pair<std::string, std::string>(method, type_class));
    }

    static void start_log() { do_log = true; }

    static void stop_log() { do_log = false; }
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_LOGGER_H
