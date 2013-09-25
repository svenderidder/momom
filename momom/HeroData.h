//
//  HeroData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_HeroData_h
#define momom_HeroData_h

#include <cstdint>

#include "SavegameBlock.h"

namespace momom {
    
    struct HeroData: SavegameBlock<12> {
        struct Status: Field<uint16_t, 0> {};
        struct Abilities: Field<uint32_t, 2> {};
        struct CastingSkill: Field<uint8_t, 6> {};
        struct Spells: Field<uint32_t, 8> {};
    };
    
}

#endif
