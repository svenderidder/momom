//
//  Hero.cpp
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Hero.h"

namespace momom {
    
    Hero::Hero(): stats{new HeroStats} {}
    
    std::vector<Hero::Ability> Hero::getAbilities() const {
        
        // There's no convenient way to iterate over an enum, so just list all of the abilities here
        // and iterate over this collection.
        const static std::vector<Hero::Ability> allAbilities = {
            Hero::Ability::Agility,
            Hero::Ability::Noble,
            Hero::Ability::Charmed,
            Hero::Ability::Lucky,
            Hero::Ability::Agility_Star,
            Hero::Ability::Prayermaster_Star,
            Hero::Ability::Prayermaster,
            Hero::Ability::Sage_Star,
            Hero::Ability::Sage,
            Hero::Ability::ArcanePower_Star,
            Hero::Ability::ArcanePower,
            Hero::Ability::Might_Star,
            Hero::Ability::Might,
            Hero::Ability::Constitution_Star,
            Hero::Ability::Constitution,
            Hero::Ability::Armsmaster_Star,
            Hero::Ability::Armsmaster,
            Hero::Ability::Blademaster_Star,
            Hero::Ability::Blademaster,
            Hero::Ability::Legendary_Star,
            Hero::Ability::Legendary,
            Hero::Ability::Leader_Star,
            Hero::Ability::Leader
        };
        
        std::vector<Hero::Ability> r;
        const HeroStats& hs = *stats.get();
        std::copy_if(allAbilities.begin(), allAbilities.end(),
                     std::back_insert_iterator<std::vector<Hero::Ability>>(r),
                     [&hs](Hero::Ability a){ return hs.hasAbility(a); });
        return r;
    }
    
    std::istream& operator>>(std::istream& is, Hero& h) {
        HeroStats& hs = *h.stats.get();
        is >> hs;
        return is;
    }

    const ptrdiff_t STATUS_OFFSET = 0;
    const ptrdiff_t ABILITIES_OFFSET = 2;
    
    const char* toString(Hero::Ability ability) {
        switch(ability) {
            case Hero::Ability::Agility: return "Agility";
            case Hero::Ability::Noble: return "Noble";
            case Hero::Ability::Charmed: return "Charmed";
            case Hero::Ability::Lucky: return "Lucky";
            case Hero::Ability::Agility_Star: return "Super Agility";
            case Hero::Ability::Prayermaster_Star: return "Super Prayermaster";
            case Hero::Ability::Prayermaster: return "Prayermaster";
            case Hero::Ability::Sage_Star: return "Super Sage";
            case Hero::Ability::Sage: return "Sage";
            case Hero::Ability::ArcanePower_Star: return "Super Arcane Power";
            case Hero::Ability::ArcanePower: return "Arcane Power";
            case Hero::Ability::Might_Star: return "Super Might";
            case Hero::Ability::Might: return "Might";
            case Hero::Ability::Constitution_Star: return "Super Constitution";
            case Hero::Ability::Constitution: return "Constitution";
            case Hero::Ability::Armsmaster_Star: return "Super Armsmaster";
            case Hero::Ability::Armsmaster: return "Armsmaster";
            case Hero::Ability::Blademaster_Star: return "Super Blademaster";
            case Hero::Ability::Blademaster: return "Blademaster";
            case Hero::Ability::Legendary_Star: return "Super Legendary";
            case Hero::Ability::Legendary: return "Legendary";
            case Hero::Ability::Leader_Star: return "Super Leadership";
            case Hero::Ability::Leader: return "Leadership";
        }
        std::ostringstream oss;
        oss << "Unknown ability: " << std::hex << static_cast<uint32_t>(ability);
        throw std::invalid_argument(oss.str());
    }
    
    std::ostream& operator<<(std::ostream& os, Hero::Ability ability) {
        os << toString(ability);
        return os;
    }
    
    bool HeroStats::hasAbility(Hero::Ability ability) const {
        return getAbilitiesField() & static_cast<uint32_t>(ability);
    }
    
    uint16_t HeroStats::getStatusField() const {
        return *reinterpret_cast<uint16_t*>(data.get() + STATUS_OFFSET);
    }
    
    uint32_t HeroStats::getAbilitiesField() const {
        return *reinterpret_cast<uint32_t*>(data.get() + ABILITIES_OFFSET);
    }

    std::istream& operator>>(std::istream& str, momom::HeroStats& h) {
        str.read(h.getData(), momom::HeroStatsBlockSize);
        return str;
    }
}

