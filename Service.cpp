//
//  Service.cpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include "Service.hpp"

Service::Service(std::string myService)
{
    this->company = myService.substr(0, myService.find(' '));
    int pos = myService.find(' ')+1;
    //I assume, as it is written in the task, that no incorrect input is suggested
    //hence I ain't ought to test against it
    
       
        
    
       
   
    setDeparture(Time(myService.substr(pos, myService.find(' ',pos))));
        
        
    pos = myService.find(' ',pos)+1;
        
        
    setArrival(Time(myService.substr(pos, myService.find(' ', pos))));
    
   
};

std::string  Service::getCompany()
{
    
    return this->company;
};

Time Service::getDeparture()
{
    
    return this->departure;
};



Time  Service::getArrival()
{
    
    return this->arrival;
};



void Service::setDeparture(const Time& time)
{
    this->departure = time;
    
   
   
    
};




void Service::setArrival(const Time& time)
{
    this->arrival = time;
    
};


void Service::printService()
{
    std::cout<<(this->getDeparture()).getHrs()<<":";
    std::cout<<(this->getDeparture()).getMin()<<" ";
    
    std::cout<<(this->getArrival()).getHrs()<<":";
    std::cout<<(this->getArrival()).getMin()<<" ";
    
    std::cout<<this->getCompany()<<std::endl;
}



