//
//  Time.cpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include "Time.hpp"

Time::Time(const std::string& time)
{
   
    this->hrs = std::stoi(time.substr(0,time.find(":")));
    int pos = time.find(":")+1;
    
    this->min = std::stoi(time.substr(3,time.find(":", pos)));
    
}

Time::Time(const Time& tm)
{
    *this = tm ;
}

void Time::printTime()
{
    std::cout<<this->hrs<<' '<<this->min<<std::endl;
}


int Time::getHrs()
{
    return this->hrs;
}


int Time::getMin()
{
    return this->min;
}


int Time::get_all_in_min()
{
    return this->hrs*60 + this->min;
}
