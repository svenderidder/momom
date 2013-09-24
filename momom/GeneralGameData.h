//
//  GeneralGameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_GeneralGameData_h
#define momom_GeneralGameData_h

#include <cstddef>
#include <istream>

#include "SavegameBlock.h"

namespace momom {
    
    struct GeneralGameData {
        struct NofWizards: Field<uint16_t, 0> {};
        struct LandSize: Field<uint16_t, 2> {};
        struct MagicLevel: Field<uint16_t, 4> {};
        struct GameDifficulty: Field<uint16_t, 6> {};
        struct NofCities: Field<uint16_t, 8> {};
        struct NofUnits: Field<uint16_t, 10> {};
        struct CurrentTurn: Field<uint16_t, 12> {};
        struct CurrentUnit: Field<uint16_t, 14> {};
        SavegameBlock<16> block;
        
        template<typename F> typename F::value_type get() const { return block.get<F>(); }
    };
    
    std::istream& operator>>(std::istream& is, GeneralGameData& ggd) {
        is >> ggd.block;
        return is;
    }

}

#endif
