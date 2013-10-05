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
    
    class SavegameData;
    
    class Unit {
    public:
        static Unit* create(SavegameData* data, int unit_id);

        Unit(SavegameData* data, int unit_id);
        virtual ~Unit();
        
        WizardID owner() const;
        void owner(WizardID);
        
        UnitType type() const;
        void type(UnitType type);
        
        Location location() const;
        void location(const Location&);
        
        int level() const;
        void level(int);
        
        virtual int maxLevel() const = 0;
        
    private:
        std::unique_ptr<struct UnitInternals> ui;
    };
    
    
}

#endif
