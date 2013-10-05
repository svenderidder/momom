//
//  HeroUnit.cpp
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "HeroUnit.h"

namespace momom {
    
    HeroUnit::HeroUnit(SavegameData* data, int unit_id)
    : Unit(data, unit_id) {}
    
    int HeroUnit::maxLevel() const {
        return 9;
    }
    
}
