//
//  main.cpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#include <iostream>
#include "Map.hpp"

int main() {
    
    Map *i_map = new Map(5);
    
    Place *CityA = new Place("A City");
    Place *CityB = new Place("B City");
    Place *CityC = new Place("C City");
    Place *CityD = new Place("D City");
    Place *CityE = new Place("E City");

    i_map->addNewPlace(CityA);
    i_map->addNewPlace(CityB);
    i_map->addNewPlace(CityC);
    i_map->addNewPlace(CityD);
    i_map->addNewPlace(CityE);
    
    /*
    i_map->addNewRoad(0, 1, 100, 20,"A-B");
    i_map->addNewRoad(1, 2, 2, 20,"B-C");
    i_map->addNewRoad(2, 3, 2, 20,"C-D");
    i_map->addNewRoad(3, 4, 100, 20,"D-E");
    i_map->addNewRoad(4, 0, 100, 20,"E-A");
    */
    
    
    i_map->addNewRoad(0, 1, 100, 20,"5");
    i_map->addNewRoad(1, 2 ,100, 20,"5");
    i_map->addNewRoad(2, 3, 100, 20,"5");
    i_map->addNewRoad(3, 4, 100, 20,"5");
    i_map->addNewRoad(4, 0, 100, 20,"5");
    i_map->addNewRoad(0, 2, 1, 20,"N");
    i_map->addNewRoad(0, 3, 1, 20,"N");
    i_map->addNewRoad(1, 4, 1, 20,"N");
    i_map->addNewRoad(1, 3, 1, 20,"N");
    i_map->addNewRoad(4, 2, 1000, 20,"FN");
    
    i_map->Blind_up_most_economic_plan() ;
    
  
    
    //i_map -> Print_Matrix(i_map -> m_pMatrixLength);

    //i_map->TraversePlace();
    
    
    return 0;
}
