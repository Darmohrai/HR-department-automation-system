#include "Legal.h"

Legal::Legal(std::string &manager, int income, int premium, int court_cases, int win_cases) :
        Department(manager, income, premium), court_cases{court_cases}, win_cases{win_cases} {}

Legal::Legal(Legal &&legal) noexcept: Department(std::move(legal)), court_cases{legal.court_cases},
                                      win_cases{legal.win_cases} {
    legal.court_cases = 0;
    legal.win_cases = 0;
}