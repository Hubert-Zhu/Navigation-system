//
//  Map.cpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#include "Map.hpp"

Map::Map(std::size_t capacity){
    m_iCapacity = capacity;
    m_iPlaceCount = 0;
    m_pPlaceArray = new Place[capacity];
    m_pRoad = new Road[capacity*capacity]{};

    m_pMatrixLength = new std::size_t [capacity*capacity]{};
    m_pMatrixFee = new std::size_t [capacity* capacity]{};
   
}

Map::~Map(){
    delete []m_pPlaceArray;
    delete []m_pMatrixLength;
    delete []m_pMatrixFee;
    delete []m_pRoad;
}

bool Map::addNewPlace(Place *pPlace){
    if(m_iPlaceCount == m_iCapacity){
        std::cout << "sorry the data base is full, please delete some place";
        return false;
    }
    m_pPlaceArray[m_iPlaceCount].PlaceName = pPlace->PlaceName;
    m_iPlaceCount++;
    return true;
}

void Map::ResetPlace(){
    for(std::size_t i=0; i<m_iPlaceCount; i++){
        m_pPlaceArray[i].m_IsVisited = false;
    }
}

bool Map::addNewRoad(const std::size_t Departure,const std::size_t Destination,
                     const std::size_t Length,const std::size_t Fee,
                     const std::string RoadName){
    
    if(Departure < 0 || Departure >= m_iCapacity){
        std::cout << "out of scope, row error";
        return false;
    }
    if(Destination < 0 || Destination >= m_iCapacity){
        std::cout << "out of scope, col error";
        return false;
    }
    
    m_pMatrixLength[Departure * m_iCapacity +  Destination] = Length;
    m_pMatrixLength[Destination* m_iCapacity + Departure] = Length;
    m_pMatrixFee[Departure * m_iCapacity +  Destination] = Fee;
    m_pMatrixFee[ Destination * m_iCapacity + Departure] = Fee;
    
    Road tem(Departure,Destination,Length,Fee,RoadName);
    m_pRoad[Destination * m_iCapacity + Departure] = tem;
    m_pRoad[Departure * m_iCapacity + Destination] = tem;

    return true;
}

void Map::Print_Matrix(std::size_t *m_Matrix){
     for(int i{0}; i<m_iCapacity; i++){
            for(int k{0}; k<m_iCapacity; k++){
                std::cout << m_Matrix[i * m_iCapacity + k] << " ";
            }
        std::cout << std::endl;
    }
}

void Map::TraversePlace(std::size_t PlaceIndex){
    for(std::size_t i{0}; i < m_iPlaceCount; i++){
        std::cout << m_pPlaceArray[i].PlaceName << " ";
    }
    std::cout << std::endl;
}

bool Map::Do_the_Road_Exist(std::size_t Departure, std::size_t Destination){
    return m_pMatrixLength[Departure * m_iCapacity + Destination];
}



void Map::Blind_up_most_economic_plan(){
    
    std::size_t size = 0;
    
    //找到一个以最短路径链接的点 //路的长度不能为0啊！！！！
    Road The_shortest_road = m_pRoad[1*m_iCapacity + 0];
    
    if (The_shortest_road.m_iRoadlength == 0) {
        for(std::size_t i{0}; i < m_iCapacity; i++){
               for(std::size_t j{0}; j < i; j++){
                   if(m_pRoad[i * m_iCapacity + j].m_iRoadlength != 0){
                       The_shortest_road =m_pRoad[i * m_iCapacity + j];
                       break;
                   }
               }
            if(The_shortest_road.m_iRoadlength != 0){
                break;
           }
        }
    }
    
    //找到长度最短而缺没有被选择过的路
    for(std::size_t i{0}; i < m_iCapacity; i++){
        for(std::size_t j{0}; j < i; j++){
            if(The_shortest_road.m_iRoadlength  > m_pRoad[i * m_iCapacity + j].m_iRoadlength && m_pRoad[i * m_iCapacity + j].m_iRoadlength != 0)
                The_shortest_road =m_pRoad[i * m_iCapacity + j];
        }
    }
    
    std::cout << The_shortest_road.m_iDeparture << std::endl;
    
    //创建一个堆
    std::vector<Road> counter{};
    Road *list= new Road [m_iCapacity-1]{};
    
  
    
    while(size < m_iCapacity-1){
       
        std::cout << std::endl;
        if(size == 0){
           for(std::size_t i{0};i < m_iCapacity; i++){
               if( (m_pRoad[The_shortest_road.m_iDeparture * m_iCapacity + i].m_iRoadlength != 0) &&
                   (!m_pRoad[The_shortest_road.m_iDeparture * m_iCapacity + i].m_bSeleted) ){
                   counter.push_back(m_pRoad[The_shortest_road.m_iDeparture * m_iCapacity + i]);
                   m_pRoad[The_shortest_road.m_iDeparture * m_iCapacity + i].m_bSeleted = true;
                   m_pRoad[i * m_iCapacity + The_shortest_road.m_iDeparture].m_bSeleted = true;
               }
           }
        }else{
             for(std::size_t i{0};i < m_iCapacity; i++){
                    if( (m_pRoad[The_shortest_road.m_iDestination * m_iCapacity + i].m_iRoadlength != 0) &&
                        (!m_pRoad[The_shortest_road.m_iDestination* m_iCapacity + i].m_bSeleted) ){
                        counter.push_back(m_pRoad[The_shortest_road.m_iDestination* m_iCapacity + i]);
                        m_pRoad[The_shortest_road.m_iDestination * m_iCapacity + i].m_bSeleted = true;
                        m_pRoad[i * m_iCapacity + The_shortest_road.m_iDestination].m_bSeleted = true;
                    }
             }
        }
        
        std::cout << "before pop:";
        for(std::size_t i{0}; i < counter.size(); i++){
                   std::cout << counter[i].m_iRoadName << " ";
        }
         
        The_shortest_road = counter[0];
        
        std::size_t index = 0;
        //找到最短边
        for(std::size_t i{0}; i < counter.size(); i++ ){
            if(The_shortest_road.m_iRoadlength > counter[i].m_iRoadlength){
                The_shortest_road = counter[i];
                index = i;
            }
        }
        
        if( m_pPlaceArray[counter[index].m_iDeparture].m_IsVisited == false ||
            m_pPlaceArray[counter[index].m_iDestination].m_IsVisited == false ){
            
            m_pPlaceArray[counter[index].m_iDeparture].m_IsVisited = true;
            m_pPlaceArray[counter[index].m_iDestination].m_IsVisited = true;
            list[size] = The_shortest_road;
            size++;
        }
           
        //删除元素
        for(std::size_t i = index; i < counter.size(); i++){
            counter[i] = counter [i+1];
        }
        counter.pop_back();
        
        
        std::cout << std::endl << "after pop:";
           for(std::size_t i{0}; i < counter.size(); i++){
                      std::cout << counter[i].m_iRoadName << " ";
        }
           
    }

    std::cout << std::endl;
    for(std::size_t i{0}; i < m_iCapacity-1; i++){
               std::cout << "Departur:" <<list[i].m_iDeparture << ' '
                         << "Road:" << list[i].m_iRoadName << ' '
                         << "Destination:"<<list[i].m_iDestination << ' '
                         << list[i].m_iRoadlength << std::endl;
    }
    
    ResetPlace();
}

