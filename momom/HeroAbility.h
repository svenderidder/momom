//
//  HeroAbilities.h
//  momom
//
//  Created by Sven de Ridder on 10/4/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_HeroAbility_h
#define momom_HeroAbility_h

#include <ostream>

namespace momom {
    
    enum class HeroAbility {
        Agility =           1 << 31,
        Noble =             1 << 29,
        Charmed =           1 << 28,
        Lucky =             1 << 27,
        Agility_Star =      1 << 26,
        Prayermaster_Star = 1 << 25,
        Prayermaster =      1 << 24,
        Sage_Star =         1 << 22,
        Sage =              1 << 21,
        ArcanePower_Star =  1 << 20,
        ArcanePower =       1 << 18,
        Might_Star =        1 << 16,
        Might =             1 << 15,
        Constitution_Star = 1 << 13,
        Constitution =      1 << 12,
        Armsmaster_Star =   1 << 10,
        Armsmaster =        1 << 9,
        Blademaster_Star =  1 << 7,
        Blademaster =       1 << 6,
        Legendary_Star =    1 << 4,
        Legendary =         1 << 3,
        Leader_Star =       1 << 1,
        Leader =            1 << 0
    };
    
    const char* toString(HeroAbility a);
    
    std::ostream& operator<<(std::ostream&, HeroAbility);

    constexpr HeroAbility AllHeroAbilities[] = {
        HeroAbility::Agility,
        HeroAbility::Noble,
        HeroAbility::Charmed,
        HeroAbility::Lucky,
        HeroAbility::Agility_Star,
        HeroAbility::Prayermaster_Star,
        HeroAbility::Prayermaster,
        HeroAbility::Sage_Star,
        HeroAbility::Sage,
        HeroAbility::ArcanePower_Star,
        HeroAbility::ArcanePower,
        HeroAbility::Might_Star,
        HeroAbility::Might,
        HeroAbility::Constitution_Star,
        HeroAbility::Constitution,
        HeroAbility::Armsmaster_Star,
        HeroAbility::Armsmaster,
        HeroAbility::Blademaster_Star,
        HeroAbility::Blademaster,
        HeroAbility::Legendary_Star,
        HeroAbility::Legendary,
        HeroAbility::Leader_Star,
        HeroAbility::Leader
    };
}

#endif
