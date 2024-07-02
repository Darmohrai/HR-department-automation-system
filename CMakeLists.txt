cmake_minimum_required(VERSION 3.27)
project(HR_department_automation_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(HR_department_automation_system main.cpp
        Interface.cpp
        Interface.h
        Person.h
        Person.cpp)
