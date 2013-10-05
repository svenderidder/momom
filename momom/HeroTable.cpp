//
//  HeroTable.cpp
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <cassert>

#include "HeroTable.h"

namespace momom {
    
    HeroTable::HeroTable(SavegameData* data)
    : data{data} {}
    
    HeroTable::~HeroTable() {}
    
    Hero& HeroTable::get(WizardID wizard, UnitType heroType) {
        // Avoid code duplication by casting away the constness of the result of the const
        // method. Not pretty, but safe.
        return const_cast<Hero&>(static_cast<const HeroTable*>(this)->get(wizard, heroType));
    }
    
    const Hero& HeroTable::get(WizardID wizard, UnitType heroType) const {
        auto it = hero_cache.find(std::make_pair(wizard, heroType));
        if(it == hero_cache.end()) {
            std::shared_ptr<Hero> ph(new Hero(data, static_cast<int>(wizard), static_cast<int>(heroType)));
            auto r = hero_cache.insert(std::make_pair(std::make_pair(wizard, heroType), ph));
            assert(r.second); // equivalent key should not already exist.
            it = r.first;
        }
        return *it->second;
        
    }
    
    
}