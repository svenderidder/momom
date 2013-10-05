//
//  HeroUnit.h
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_HeroUnit_h
#define momom_HeroUnit_h

#include "Unit.h"

namespace momom {
    
    class HeroUnit: public Unit {
    public:
        HeroUnit(SavegameData* data, int unit_id);
        
        int maxLevel() const override;
    };
    
}

#endif
