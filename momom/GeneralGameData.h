//
//  GeneralGameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_GeneralGameData_h
#define momom_GeneralGameData_h

#include <boost/interprocess/mapped_region.hpp>
#include <cstdint>

#include "SavegameRegion.h"

namespace momom {
    
    namespace GeneralGameData {
        typedef SavegameRegion<16> Block_t;
        struct NofWizards: Field<uint16_t, 0> {};
        struct LandSize: Field<uint16_t, 2> {};
        struct MagicLevel: Field<uint16_t, 4> {};
        struct GameDifficulty: Field<uint16_t, 6> {};
        struct NofCities: Field<uint16_t, 8> {};
        struct NofUnits: Field<uint16_t, 10> {};
        struct CurrentTurn: Field<uint16_t, 12> {};
        struct CurrentUnit: Field<uint16_t, 14> {};
    }
    
}

#endif
