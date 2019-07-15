//
//  ServiceHandler.hpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#ifndef ServiceHandler_hpp
#define ServiceHandler_hpp

#include <stdio.h>
#include <list>
#include <fstream>
#include <vector>

#include "Service.hpp"




class ServiceHandler
{
public:
    ServiceHandler(){};
    
    
    bool insert_service(Service& service);
    
    void print_services();
    void writeToFile(std::ofstream& myfile);
private:
    bool checkTime( Service& service);
    //int because in case it's effective without replacement, the return value is -2
    //if it's more efficient than one of the existing routes, the return value is the position to swap
    //if it ain't efficient, the return value is -1
    
   
    
    
    
  
    
    int count;
    std::vector<Service> timetable;
    
};

#endif /* ServiceHandler_hpp */
