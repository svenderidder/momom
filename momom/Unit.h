//
//  Unit.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Unit_h
#define momom_Unit_h

#include <memory>

#include "WizardID.h"
#include "UnitType.h"
#include "Location.h"

namespace momom {
    
    class Unit {
    public:
        Unit(class SavegameData* data, int unit_id);
        Unit(Unit&& moved);
        ~Unit();
        Unit& operator=(Unit&& moved);
        
        WizardID owner() const;
        void owner(WizardID);
        
        UnitType type() const;
        void type(UnitType type);
        
        Location location() const;
        void location(const Location&);
        
    private:
        std::unique_ptr<struct UnitInternals> ui;
    };
    
}

#endif
