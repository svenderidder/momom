//
//  UnitTable.cpp
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <cassert>

#include "UnitTable.h"

namespace momom {
    
    UnitTable::UnitTable(SavegameData* data)
    : data{data} {}
    
    UnitTable::~UnitTable() {
    }
    
    Unit& UnitTable::get(int unit_id) {
        // Avoid code duplication by casting away the constness of the result of the const
        // method. Not pretty, but safe.
        return const_cast<Unit&>(static_cast<const UnitTable*>(this)->get(unit_id));
    }
    
    const Unit& UnitTable::get(int unit_id) const {
        auto it = unit_cache.find(unit_id);
        if(it == unit_cache.end()) {
            std::shared_ptr<Unit> pu(createUnit(data, unit_id));
            auto r = unit_cache.insert(std::make_pair(unit_id, pu));
            assert(r.second); // equivalent key should not already exist.
            it = r.first;
        }
        return *it->second;
    }
    
}
