//
//  main.cpp
//  ExtendedKalmanFilter
//
//  Created by Karan on 4/6/18.
//  Copyright © 2018 Karan. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <forward_list>
#include "fusion.hpp"
#include "parameterReader.hpp"

DataPoint GenDataPoint( std::forward_list<std::string> *inToken ) {
    // Sample Data set format:
    // 0     1    2     3  4  5   6       7         8       9    10    11   12    13     14       15       16       17   18   19   20  21   22        23   24               25
    // date,time,millis,ax,ay,az,rollrate,pitchrate,yawrate,roll,pitch,yaw,speed,course,latitude,longitude,altitude,pdop,hdop,vdop,epe,fix,satellites_view,satellites_used,temp
    int pMap[6] = {2, 14, 15, 13, 12, 11};

}



int main(int argc, const char * argv[])
{
    std::ifstream ip("../data/Data.csv");
    if(!ip.is_open())
    {
        std::cerr << "Failed to open the data file";
        std::exit(EXIT_FAILURE);
    }
    
    std::string timestamp;
    std::string ax;
    std::string yaw_rate;
    std::string yaw;
    std::string course;
    std::string lat;
    std::string lon;
    
    std::string str;
    std::getline(ip, str); // Skip the first line
    std::forward_list<DataPoint> DataList;    
    while(std::getline(ip, str))
    {
        std::istringstream iss(str);
        std::string token;
        std::int16_t tcount = 0;
        std::forward_list<std::string> inToken;
        std::forward_list<std::string>::iterator it;
        while (std::getline(iss, token, ','))
        {
            // process each token
            tcount++;
            inToken.emplace_front(token);
        }
        inToken.reverse();
        for (auto& x: inToken) {
            std::cout << x << ",";
        }
        std::cout << endl;
        // Generate data point from input.
        DataList.emplace_front(GenDataPoint(&inToken));

    }
    ip.close();

    // Call read parameters
    ParameterReader *pread = new ParameterReader();
    //pread->getData()

    

    
    return 0;
}
