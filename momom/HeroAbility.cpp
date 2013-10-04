//
//  HeroAbility.cpp
//  momom
//
//  Created by Sven de Ridder on 10/4/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "HeroAbility.h"

namespace momom {
    
    const char* toString(HeroAbility a) {
        switch(a) {
            case HeroAbility::Agility: return "Agility";
            case HeroAbility::Noble: return "Noble";
            case HeroAbility::Charmed: return "Charmed";
            case HeroAbility::Lucky: return "Lucky";
            case HeroAbility::Agility_Star: return "Super Agility";
            case HeroAbility::Prayermaster_Star: return "Super Prayermaster";
            case HeroAbility::Prayermaster: return "Prayermaster";
            case HeroAbility::Sage_Star: return "Super Sage";
            case HeroAbility::Sage: return "Sage";
            case HeroAbility::ArcanePower_Star: return "Super Arcane Power";
            case HeroAbility::ArcanePower: return "Arcane Power";
            case HeroAbility::Might_Star: return "Super Might";
            case HeroAbility::Might: return "Might";
            case HeroAbility::Constitution_Star: return "Super Constitution";
            case HeroAbility::Constitution: return "Constitution";
            case HeroAbility::Armsmaster_Star: return "Super Armsmaster";
            case HeroAbility::Armsmaster: return "Armsmaster";
            case HeroAbility::Blademaster_Star: return "Super Blademaster";
            case HeroAbility::Blademaster: return "Blademaster";
            case HeroAbility::Legendary_Star: return "Super Legendary";
            case HeroAbility::Legendary: return "Legendary";
            case HeroAbility::Leader_Star: return "Super Leadership";
            case HeroAbility::Leader: return "Leadership";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, HeroAbility a) {
        return os << toString(a);
    }
    
}