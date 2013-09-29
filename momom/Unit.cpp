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
    
    int Unit::type() const {
        using f = UnitType;
        f::value_type v = data->get<f>(unit_id);
        return static_cast<int>(v);
    }
    
    void Unit::type(int type) {
        using f = UnitType;
        f::value_type& v = data->get<f>(unit_id);
        v = static_cast<typename f::value_type>(type);
    }
    
}
