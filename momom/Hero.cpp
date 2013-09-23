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
    
    // ---------------------------------------------------------------------------------------------
    // HeroStats implementation
    // ---------------------------------------------------------------------------------------------

    const std::vector<Hero::Ability>& getAllAbilities() {
        // There's no convenient way to iterate over an enum, so just list all of the abilities
        // here. This collection can then be used for iteration.
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
        return allAbilities;
    }
    
    class HeroStats {
    private:
        std::unique_ptr<char[]> data;
        const static ptrdiff_t StatusOffset = 0;
        const static ptrdiff_t AbilitiesOffset = 2;
        const static ptrdiff_t CastingSkillOffset = 6;
        const static size_t HeroStatsBlockSize = 12;
        
    public:
        HeroStats(): data{new char[HeroStatsBlockSize]} {}
        
        std::vector<Hero::Ability> getAbilities() const {
            std::vector<Hero::Ability> r;
            uint32_t f = getField<uint32_t>(AbilitiesOffset);
            std::copy_if(getAllAbilities().begin(), getAllAbilities().end(),
                         std::back_insert_iterator<std::vector<Hero::Ability>>(r),
                         [f](Hero::Ability a){ return f & static_cast<uint32_t>(a); });
            return r;
        }
        
        int getCastingSkill() const {
            int v = getField<uint8_t>(CastingSkillOffset);
            return static_cast<int>((v+1) * 2.5);
        }
        
    private:
        template<typename T> const T& getField(ptrdiff_t offset) const {
            return *reinterpret_cast<T*>(data.get() + offset);
        }
        
        friend std::istream& operator>>(std::istream&, HeroStats&);
    };
    
    std::istream& operator>>(std::istream& is, HeroStats& hs) {
        is.read(hs.data.get(), HeroStats::HeroStatsBlockSize);
        return is;
    }

    // ---------------------------------------------------------------------------------------------
    // Hero implementation
    // ---------------------------------------------------------------------------------------------
    
    Hero::Hero(): stats{new HeroStats} {}
    
    Hero::~Hero() {}
    
    std::vector<Hero::Ability> Hero::getAbilities() const {
        const HeroStats& hs = *stats.get();
        return hs.getAbilities();
    }
    
    std::istream& operator>>(std::istream& is, Hero& h) {
        HeroStats& hs = *h.stats.get();
        is >> hs;
        return is;
    }

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
    
}
