//
//  Time.hpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <iostream>
#include <stdio.h>
#include <string>

class Time
{
public:
    Time(){};
    Time(const Time& tm);
    
    Time& operator=(const Time& time)
    {
        this->hrs = time.hrs;
        this->min = time.min;
        return *this;
    };
    Time(const std::string& time);
    

    void printTime();
    int getHrs();
    int getMin();
    int get_all_in_min();
    
private:
    int hrs;
    int min;
};
#endif /* Time_hpp */
