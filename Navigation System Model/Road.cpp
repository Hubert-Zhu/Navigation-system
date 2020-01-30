//
//  Road.cpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#include "Road.hpp"

Road::Road(std::size_t Departure, std::size_t Destination, std::size_t Roadlength, std::size_t RoadFee, std::string RoadName, bool Seleted){
    m_iDeparture = Departure;
    m_iDestination = Destination;
    m_iRoadlength = Roadlength;
    m_iRoadFee = RoadFee;
    m_iRoadName = RoadName;
    m_bSeleted = Seleted;
}
