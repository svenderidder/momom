//
//  HeroData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_HeroData_h
#define momom_HeroData_h

#include <cstddef>
#include <istream>

#include "SavegameBlock.h"

namespace momom {
    
    struct HeroData {
        const static size_t HeroDataBlockSize = 12;
        const static ptrdiff_t StatusOffset = 0;
        const static ptrdiff_t AbilitiesOffset = 2;
        const static ptrdiff_t CastingSkillOffset = 6;
        const static ptrdiff_t Spell1Offset = 7;
        const static ptrdiff_t Spell2Offset = 8;
        const static ptrdiff_t Spell3Offset = 9;
        const static ptrdiff_t Spell4Offset = 10;
        SavegameBlock<HeroDataBlockSize> block;
        
        uint16_t getStatus() const { return block.getField<uint16_t>(StatusOffset); }
        uint16_t getAbilities() const { return block.getField<uint16_t>(AbilitiesOffset); }
        uint8_t getCastingSkill() const { return block.getField<uint8_t>(CastingSkillOffset); }
        uint8_t getSpell1() const { return block.getField<uint8_t>(Spell1Offset); }
        uint8_t getSpell2() const { return block.getField<uint8_t>(Spell2Offset); }
        uint8_t getSpell3() const { return block.getField<uint8_t>(Spell3Offset); }
        uint8_t getSpell4() const { return block.getField<uint8_t>(Spell4Offset); }
        
    };
    
    std::istream& operator>>(std::istream& is, HeroData& d) {
        is >> d.block;
        return is;
    }

}

#endif
