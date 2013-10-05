//
//  SummonedUnit.cpp
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "SummonedUnit.h"

namespace momom {
    
    SummonedUnit::SummonedUnit(SavegameData* data, int unit_id)
    : Unit(data, unit_id) {}
    
    int SummonedUnit::maxLevel() const {
        return 0;
    }
    
}
