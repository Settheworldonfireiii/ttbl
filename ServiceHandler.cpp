//
//  ServiceHandler.cpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include "ServiceHandler.hpp"
#define MODE 2
//MODE 1 - add only efficient in strict sense, MODE 2 - add everything that is not explicitly inefficient



bool ServiceHandler::checkTime(Service &service) 
{
    int arriv = (service.getArrival()).getHrs()*60 + (service.getArrival()).getMin();
    int depart = (service.getDeparture()).getHrs()*60 + (service.getDeparture()).getMin();
    if(arriv-depart > 60)
    {
        return false;
    }
    else{
        return true;
    }
};



bool ServiceHandler::insert_service( Service &service)
{
    if(checkTime(service) == false)
    {
        return 0;
    }
    for(int i = 0; i<timetable.size();i++)
    {

            if((timetable[i].getDeparture()).get_all_in_min() <= (service.getDeparture()).get_all_in_min())
        {
            
            if((timetable[i].getArrival()).get_all_in_min() >= (service.getArrival()).get_all_in_min())
            {
                if(((timetable[i].getDeparture()).get_all_in_min()==(service.getDeparture()).get_all_in_min())
            &&((timetable[i].getArrival()).get_all_in_min() == (service.getArrival()).get_all_in_min()))
                {
                    if(timetable[i].getCompany()=="POSH" && service.getCompany()=="GROTTY")
                    {
                        return 0;
                    }
                    else if(timetable[i].getCompany()=="GROTTY" && service.getCompany()=="POSH")
                    {
                        timetable[i] = service;
                        return 1;
                    }
                    else
                    {
                    
                        
                        return 0;
                    }
                }
                
                timetable[i] = service;
               
                return 1;
            }
        }
        if(MODE == 1)
        {
            return 0;
        }
        if((timetable[i].getDeparture()).get_all_in_min() == (service.getDeparture()).get_all_in_min())
        {
            if((timetable[i].getArrival()).get_all_in_min() < (service.getArrival()).get_all_in_min())
            {
                return 0;
            }
        }
        else if((timetable[i].getArrival()).get_all_in_min() == (service.getArrival()).get_all_in_min())
        {
            if((timetable[i].getDeparture()).get_all_in_min() > (service.getDeparture()).get_all_in_min())
            {
                return 0;
            }
        }
  //another perk, to insert a record into a correct position at first
   if((timetable[i].getDeparture()).get_all_in_min() > (service.getDeparture()).get_all_in_min())
   {
       timetable.insert(timetable.begin() + i, service);
       return 1;
   }
        
    }
    timetable.push_back(service);
    return 1;
};



void ServiceHandler::print_services()
{
    for(auto& srv : timetable)
    {
        std::cout<<(srv.getDeparture()).getHrs()<<":";
        std::cout<<(srv.getDeparture()).getMin()<<" ";

        std::cout<<(srv.getArrival()).getHrs()<<":";
        std::cout<<(srv.getArrival()).getMin()<<" ";
        
        std::cout<<srv.getCompany()<<std::endl;
    }
}


void ServiceHandler::writeToFile(std::ofstream& myfile)
{
    myfile.open ("output.txt");
    for(auto& srv : timetable)
    {
        myfile<<srv.getCompany()<<" ";
        if((srv.getDeparture()).getHrs()<10)
        {
            myfile<<'0'<<(srv.getDeparture()).getHrs()<<":";
        }
        else
        {
            myfile<<(srv.getDeparture()).getHrs()<<":";
        }
        if((srv.getDeparture()).getMin()<10)
        {
            myfile<<'0'<<(srv.getDeparture()).getMin()<<" ";
        }
        else
        {
            myfile<<(srv.getDeparture()).getMin()<<" ";
        }
        
        
        if((srv.getArrival()).getHrs()<10)
        {
            myfile<<'0'<<(srv.getArrival()).getHrs()<<":";
        }
        else
        {
            myfile<<(srv.getArrival()).getHrs()<<":";
        }
        if((srv.getArrival()).getMin()<10)
        {
            myfile<<'0'<<(srv.getArrival()).getMin()<<" ";
        }
        else
        {
            myfile<<(srv.getArrival()).getMin()<<" ";
        }
        
        
        myfile<<std::endl;
        
    }
    
    
    myfile.close();
}
