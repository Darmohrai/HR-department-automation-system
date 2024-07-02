#ifndef HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
#define HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H


class Interface{
public:
    // methods get
    virtual void getAllInfo() = 0;
    virtual void getBriefInfo() = 0;
    virtual int getSalary() = 0;

    // methods set
    virtual void setInfo() = 0;
    virtual void prepareOrder() = 0;
    virtual bool changeStatus() = 0;

    // methods save
    virtual void saveInfo() = 0;
};


#endif //HR_DEPARTMENT_AUTOMATION_SYSTEM_INTERFACE_H
