//
//  Hero.h
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Hero_h
#define momom_Hero_h

#include <cstdint>
#include <memory>
#include <ostream>
#include <vector>

namespace momom {
    
    class Hero {
    private:
        std::unique_ptr<class HeroStats> stats;
        
    public:
        enum class Ability {
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
        
        Hero();
        
        std::vector<Ability> getAbilities() const;
        
        friend std::istream& operator>>(std::istream&, Hero&);
    };
    
    const char* toString(Hero::Ability ability);
    std::ostream& operator<<(std::ostream& os, Hero::Ability ability);
    
    std::istream& operator>>(std::istream& str, Hero& h);
    
    const size_t HeroStatsBlockSize = 12;
    
    class HeroStats {
    private:
        std::unique_ptr<char> data;
        
    public:
        HeroStats(): data{new char[HeroStatsBlockSize]} {}
        ~HeroStats() {}
        
        char* getData() { return data.get(); }
        const char* getData() const { return data.get(); }
        
        bool hasAbility(Hero::Ability ability) const;
        
    private:
        std::uint16_t getStatusField() const;
        std::uint32_t getAbilitiesField() const;
    };
    
    std::istream& operator>>(std::istream& str, momom::HeroStats& h);

}

#endif
