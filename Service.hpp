//
//  Service.hpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#ifndef Service_hpp
#define Service_hpp

#include <stdio.h>
#include <string>

#include "Time.hpp"


class Service
{
public:
    Service(){};
    Service(std::string myService);
    std::string getCompany();
    Time getDeparture();
    Time getArrival();
    void setDeparture(const Time& time);
    void setArrival(const Time& time);
    void printService();
private:
    std::string company;
    Time arrival;
    Time departure;

};
#endif /* Service_hpp */
