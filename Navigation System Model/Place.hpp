//
//  Place.hpp
//  Navigation System Model
//
//  Created by Bolin ZHu on 2020-01-08.
//  Copyright © 2020 Bolin Zhu (Hubert Zhu). All rights reserved.
//

#ifndef Place_hpp
#define Place_hpp

#include <stdio.h>
#include <iostream>

class Place{
public:
    Place(std::string Place = "N/A");
    std::string PlaceName;
    bool m_IsVisited;
};

#endif /* Place_hpp */
