//
//  Unit.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Unit.h"
#include "SavegameData.h"

namespace momom {
    
    Unit::Unit(SavegameData* data, int unit_id)
    : data{data}
    , unit_id{unit_id} {}
    
    int Unit::owner() const {
        using f = UnitOwner;
        f::value_type v = data->get<f>(unit_id);
        return static_cast<int>(v);
    }
    
    UnitType Unit::type() const {
        using f = F_UnitType;
        f::value_type v = data->get<f>(unit_id);
        return static_cast<UnitType>(v);
    }
    
    void Unit::type(UnitType type) {
        using f = F_UnitType;
        f::value_type& v = data->get<f>(unit_id);
        v = static_cast<typename f::value_type>(type);
    }
    
}
