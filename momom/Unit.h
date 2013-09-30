//
//  Unit.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Unit_h
#define momom_Unit_h

#include "WizardID.h"
#include "UnitType.h"
#include "Location.h"

namespace momom {
    
    class SavegameData;
    
    class Unit {
    public:
        Unit(SavegameData* data, int unit_id);
        
        WizardID owner() const;
        UnitType type() const;
        void type(UnitType type);
        
        Location location() const;
        
    private:
        SavegameData* data;
        const int unit_id;
    };
    
}

#endif
