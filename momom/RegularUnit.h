//
//  RegularUnit.h
//  momom
//
//  Created by Sven de Ridder on 10/4/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_RegularUnit_h
#define momom_RegularUnit_h

#include "Unit.h"

namespace momom {
    
    class RegularUnit: public Unit {
    public:
        RegularUnit(class SavegameData*, int unit_id);
        ~RegularUnit();
        
        int maxLevel() const override;
        
    };
}

#endif
