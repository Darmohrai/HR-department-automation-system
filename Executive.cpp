#include "Executive.h"

Executive::Executive(std::string &manager, int income, int premium, int project_quantity, int average_time)
        : Department(manager, income, premium), project_quantity{project_quantity}, average_time{average_time} {}

Executive::Executive(Executive &&executive) : Department(std::move(executive)),
                                              project_quantity{executive.project_quantity},
                                              average_time{executive.average_time} {
    executive.project_quantity = 0;
    executive.average_time = 0;
}