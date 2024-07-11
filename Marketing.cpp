#include "Marketing.h"

Marketing::Marketing(std::string &manager, int income, int premium, int ad_success_rate) :
        Department(manager, income, premium), ad_success_rate{ad_success_rate} {}

Marketing::Marketing(Marketing &&marketing) : Department(std::move(marketing)),
                                              ad_success_rate{marketing.ad_success_rate} {
    marketing.ad_success_rate = 0;
}