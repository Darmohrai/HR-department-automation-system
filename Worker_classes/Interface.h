#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H

#include <string>

class Interface {
public:
    // methods get
    virtual void getAllInfo() = 0;

    virtual void getBriefInfo() = 0;

    [[nodiscard]] virtual int getSalary() = 0;


    // methods set
    [[nodiscard]] virtual bool prepareOrder() = 0;

    [[nodiscard]] virtual bool checkStatus() = 0;


    // methods save
    virtual void saveInfo(std::ofstream &fout) = 0;

    virtual void readInfo(std::ifstream &fin) = 0;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
