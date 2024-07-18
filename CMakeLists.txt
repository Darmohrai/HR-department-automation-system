cmake_minimum_required(VERSION 3.27)
project(HR_department_automation_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(HR_department_automation_system main.cpp
        Worker_classes/Interface.cpp
        Worker_classes/Interface.h
        Worker_classes/Person.h
        Worker_classes/Person.cpp
        Worker_classes/Trainee.h
        Worker_classes/Trainee.cpp
        Worker_classes/Employee.h
        Worker_classes/Employee.cpp
        Worker_classes/Manager.h
        Worker_classes/Manager.cpp
        Worker_classes/OfficeWorker.h
        Worker_classes/OfficeWorker.cpp
        Worker_classes/AuxiliaryPosition.h
        Worker_classes/AuxiliaryPosition.cpp
        Department_classes/Department.h
        Department_classes/Department.cpp
        Department_classes/Executive.cpp
        Department_classes/Executive.h
        Department_classes/Legal.h
        Department_classes/Legal.cpp
        Department_classes/Marketing.h
        Department_classes/Marketing.cpp
        functions/addEmployee_functions.h
        functions/Trainee_functions.h
        functions/Save&Read_functions.h
        functions/Department_functions.h
)
