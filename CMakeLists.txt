cmake_minimum_required(VERSION 3.27)
project(HR_department_automation_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(HR_department_automation_system main.cpp
        Interface.cpp
        Interface.h
        Person.h
        Person.cpp
        Trainee.h
        Trainee.cpp
        Employee.h
        Employee.cpp
        Manager.h
        Manager.cpp
        OfficeWorker.h
        OfficeWorker.cpp
        AuxiliaryPosition.h
        AuxiliaryPosition.cpp
        Department.h
        Department.cpp
        Executive.cpp
        Executive.h
        Legal.h
        Legal.cpp
        Marketing.h
        Marketing.cpp
        addEmployee_functions.h
        Trainee_functions.h
        Save&Read_functions.h
)
