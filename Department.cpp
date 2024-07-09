#include "Department.h"

Department::Department(Department &&department) : workers{std::move(department.workers)},
                                                  manager{std::move(department.manager)},
                                                  income{department.income},
                                                  premium{department.premium} {
    department.income = 0;
    department.premium = 0;
}