//
//  SavegameDefinitions.h
//  momom
//
//  Created by Sven de Ridder on 9/27/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameDefinitions_h
#define momom_SavegameDefinitions_h

namespace momom {
    
    template<ptrdiff_t O, size_t S, int N=1> struct Category {
        static const ptrdiff_t offset = O;
    };
    
    template<typename C, typename T, ptrdiff_t O> struct F {
        typedef C category;
        typedef T value_type;
        static const ptrdiff_t offset = O;
    };

    struct GlobalHeroData: Category<0x0000, 12, 35*5> {};
    struct HeroStatus: F<GlobalHeroData, uint16_t, 0x0000> {};
    struct HeroAbilities: F<GlobalHeroData, uint32_t, 0x0002> {};
    struct HeroCastingSkill: F<GlobalHeroData, uint8_t, 0x0006> {};
    struct HeroSpells: F<GlobalHeroData, uint32_t, 0x0008> {};
    
    struct GeneralData: Category<0x09D8, 16> {};
    struct NofWizards: F<GeneralData, uint16_t, 0x0000> {};
    struct F_LandSize: F<GeneralData, uint16_t, 0x0002> {};
    struct F_MagicLevel: F<GeneralData, uint16_t, 0x0004> {};
    struct F_GameDifficulty: F<GeneralData, uint16_t, 0x0006> {};
    struct NofCities: F<GeneralData, uint16_t, 0x0008> {};
    struct NofUnits: F<GeneralData, uint16_t, 0x000A> {};
    struct CurrentTurn: F<GeneralData, uint16_t, 0x000C> {};
    struct CurrentUnit: F<GeneralData, uint16_t, 0x000E> {};
    
}

#endif
