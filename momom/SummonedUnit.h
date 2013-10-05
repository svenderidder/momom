//
//  SummonedUnit.h
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SummonedUnit_h
#define momom_SummonedUnit_h

#include "Unit.h"

namespace momom {
    
    class SummonedUnit: public Unit {
    public:
        SummonedUnit(SavegameData* data, int unit_id);
        
        int maxLevel() const override;
    };
    
}

#endif
