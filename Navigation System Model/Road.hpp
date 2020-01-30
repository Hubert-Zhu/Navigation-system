//
//  Road.hpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include <iostream>

class Road{
public:
    Road(std::size_t Departure = 0, std::size_t Destination = 0, std::size_t Roadlength = 0, std::size_t RoadFee = 0, std::string RoadName = "N/A", bool Seleted = 0);
    
    std::size_t m_iDeparture;
    std::size_t m_iDestination;
    std::size_t m_iRoadlength;
    std::size_t m_iRoadFee;
    bool m_bSeleted;
    std::string m_iRoadName;
    
private:
    
};

#endif /* Road_hpp */
