//
//  main.cpp
//  ttbl
//
//  Created by Ivan Radkevich on 7/15/19.
//  Copyright © 2019 Ivan Radkevich. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Time.hpp"
#include "Service.hpp"
#include "ServiceHandler.hpp"


int main(int argc, const char * argv[]) {
    
    
    //Initially, the program simply creates timetable from existing strings
    //this is not necessary, as you can see from the code, we can directly start with a file
    std::string poshstring("POSH 10:15 11:10");
    std::cout<<poshstring<<std::endl;
    Service srv1(poshstring);
    
    
    std::string grottystring("GROTTY 11:15 11:40");
    std::cout<<grottystring<<std::endl;
    Service srv2(grottystring);
   
    
    std::string str3("POSH 10:30 11:10");
    std::cout<<str3<<std::endl;
    Service srv3(str3);
    
    std::string str4("POSH 18:30 19:20");
    std::cout<<str4<<std::endl;
    Service srv4(str4);
    

    
    ServiceHandler sh;
    sh.insert_service(srv1);
    sh.insert_service(srv2);
    sh.insert_service(srv3);
    sh.insert_service(srv4);
 
    
    sh.print_services();
    
    
    
    //here we go, the file from which the program reads
    std::ifstream file("filestuff.txt");
    std::string line;
    std::vector<std::string> user_vec;
    
    while( std::getline( file, line ) ) {
        user_vec.push_back( line );
    }
    
    for(auto& aa:user_vec)
    {
        std::cout<<aa<<std::endl;
    }
     std::cout<<std::endl;
   
  
    for(int i = 0;i< user_vec.size()-1;i++)
    {
        Service srr(user_vec[i]);
        sh.insert_service(srr);
        
    }
    
    sh.print_services();
    
    std::ofstream myfile1;
    sh.writeToFile(myfile1);
    
    return 0;
}
