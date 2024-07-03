#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H

#include <string>

class Interface{
public:
    // methods get
    virtual void getAllInfo() = 0;
    virtual void getBriefInfo() = 0;
    [[nodiscard]] virtual int getSalary() = 0;

    // methods set
    virtual void prepareOrder() = 0;
    virtual void checkStatus() = 0;

    // methods save
    virtual void saveInfo(std::string file_name) = 0;
    virtual void readInfo(std::string file_name) = 0;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
