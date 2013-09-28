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
    
    class SavegameData;
    
    class Hero {
        
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
        
        Hero(SavegameData* data, int wizard_id, int hero_id);
        
        std::vector<Ability> getAbilities() const;
        
    private:
        class SavegameData* data;
        int wizard_id;
        int hero_id;
        
        int hero_index() const { return wizard_id * 35 + hero_id; }
    };
    
    const char* toString(Hero::Ability ability);
    std::ostream& operator<<(std::ostream& os, Hero::Ability ability);
    
}

#endif
