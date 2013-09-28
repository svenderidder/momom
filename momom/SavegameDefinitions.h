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
    
    template<ptrdiff_t O, size_t S, int N=1> struct Region {
        static const ptrdiff_t offset = O;
    };
    
    template<typename R, typename T, ptrdiff_t O> struct F {
        typedef R region;
        typedef T value_type;
        static const ptrdiff_t offset = O;
    };

    struct GlobalHeroRegion: Region<0x0000, 12, 35*5> {};
    struct HeroStatus: F<GlobalHeroRegion, uint16_t, 0x0000> {};
    struct HeroAbilities: F<GlobalHeroRegion, uint32_t, 0x0002> {};
    struct HeroCastingSkill: F<GlobalHeroRegion, uint8_t, 0x0006> {};
    struct HeroSpells: F<GlobalHeroRegion, uint32_t, 0x0008> {};
    
    struct GeneralDataRegion: Region<0x09D8, 16> {};
    struct NofWizards: F<GeneralDataRegion, uint16_t, 0x0000> {};
    struct F_LandSize: F<GeneralDataRegion, uint16_t, 0x0002> {};
    struct F_MagicLevel: F<GeneralDataRegion, uint16_t, 0x0004> {};
    struct F_GameDifficulty: F<GeneralDataRegion, uint16_t, 0x0006> {};
    struct NofCities: F<GeneralDataRegion, uint16_t, 0x0008> {};
    struct NofUnits: F<GeneralDataRegion, uint16_t, 0x000A> {};
    struct CurrentTurn: F<GeneralDataRegion, uint16_t, 0x000C> {};
    struct CurrentUnit: F<GeneralDataRegion, uint16_t, 0x000E> {};
    
}

#endif
