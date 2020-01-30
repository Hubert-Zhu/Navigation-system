//
//  Map.hpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Place.hpp"
#include "Map.hpp"
#include "Road.hpp"
#include "Function.hpp"
#include <vector>

class Map{
public:
    //基本操作
    Map(std::size_t capacity);
    ~Map();
    
    //定点更新
    bool addNewPlace(Place *pPlace);
    void ResetPlace();
    
    //道路（新系统）
    bool addNewRoad(const std::size_t Departure,const std::size_t Destination,
                    const std::size_t Length,const std::size_t Fee,
                    const std::string RoadName);//费用先废除
    
    
    //
    
    //检查工具
    void Print_Matrix(std::size_t *m_Matrix);//debug tool
    void TraversePlace(std::size_t PlaceIndex = 0);//debug tool
    bool Do_the_Road_Exist(std::size_t Departure, std::size_t Destination);//debug tool
    
    //预期的功能
    void Blind_up_most_economic_plan();//PrimTree
    void shortest_distance();//findshortest distance
    void most_econmic_plan();//findshortest distance 变形：把权值 = 路程 * 油费 + 过路费；
    
private:
    std::size_t m_iCapacity;//我现在的承受城市的数量
    std::size_t m_iPlaceCount;//我现在已经有多少城市
    Place *m_pPlaceArray;//存放城市的集合
    Road *m_pRoad;//存放路的集合 代替 2x2 道路系统和收费系统
    std::size_t *m_pMatrixLength;//2x2道路系统
    std::size_t *m_pMatrixFee;//2x2收费系统废置
};
#endif /* Map_hpp */
