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
        const static size_t GeneralGameDataBlockSize = 16;
        const static ptrdiff_t NofWizardsOffset = 0;
        const static ptrdiff_t LandSizeOffset = 2;
        const static ptrdiff_t MagicLevelOffset = 4;
        const static ptrdiff_t GameDifficultyOffset = 6;
        const static ptrdiff_t NofCitiesOffset = 8;
        const static ptrdiff_t NofUnitsOffset = 10;
        const static ptrdiff_t CurrentTurnOffset = 12;
        const static ptrdiff_t CurrentUnitOffset = 14;
        SavegameBlock<GeneralGameDataBlockSize> block;
        
        uint16_t getNofWizards() const { return block.getField<uint16_t>(NofWizardsOffset); }
        uint16_t getLandSize() const { return block.getField<uint16_t>(LandSizeOffset); }
        uint16_t getMagicLevel() const { return block.getField<uint16_t>(MagicLevelOffset); }
        uint16_t getGameDifficulty() const { return block.getField<uint16_t>(GameDifficultyOffset); }
        uint16_t getNofCities() const { return block.getField<uint16_t>(NofCitiesOffset); }
        uint16_t getNofUnits() const { return block.getField<uint16_t>(NofUnitsOffset); }
        uint16_t getCurrentTurn() const { return block.getField<uint16_t>(CurrentTurnOffset); }
        uint16_t getCurrentUnit() const { return block.getField<uint16_t>(CurrentUnitOffset); }
        
    };
    
    std::istream& operator>>(std::istream& is, GeneralGameData& ggd) {
        is >> ggd.block;
        return is;
    }

}

#endif
