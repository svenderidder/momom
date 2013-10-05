//
//  RegularUnit.cpp
//  momom
//
//  Created by Sven de Ridder on 10/4/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "RegularUnit.h"

namespace momom {
    
    RegularUnit::RegularUnit(class SavegameData* data, int unit_id)
    : Unit(data, unit_id) {}
    
    RegularUnit::~RegularUnit() {}
    
    int RegularUnit::maxLevel() const {
        return 5;
    }
    
}
