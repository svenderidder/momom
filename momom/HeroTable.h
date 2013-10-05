//
//  HeroTable.h
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_HeroTable_h
#define momom_HeroTable_h

#include <map>
#include <memory>

#include "WizardID.h"
#include "UnitType.h"
#include "Hero.h"

namespace momom {
    
    class SavegameData;
    
    class HeroTable {
    public:
        HeroTable(SavegameData* data);
        virtual ~HeroTable();
        
        Hero& get(WizardID wizard, UnitType heroType);
        const Hero& get(WizardID wizard, UnitType heroType) const;
        
    private:
        typedef std::pair<WizardID, UnitType> KeyType;
        typedef std::map<KeyType, std::shared_ptr<Hero>> HeroCache;
        mutable HeroCache hero_cache;
        SavegameData* const data;
    };
}

#endif
