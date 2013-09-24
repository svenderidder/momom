//
//  Race.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Race.h"

namespace momom {
    
    const char* toString(Race r) {
        switch(r) {
            case Race::Barbarian: return "Barbarian";
            case Race::Beastman: return "Beastman";
            case Race::DarkElf: return "Dark Elf";
            case Race::Draconian: return "Draconian";
            case Race::Dwarf: return "Dwarf";
            case Race::Gnoll: return "Gnoll";
            case Race::Halfling: return "Halfling";
            case Race::HighElf: return "High Elf";
            case Race::HighMan: return "High Man";
            case Race::Klackon: return "Klackon";
            case Race::Lizardman: return "Lizardman";
            case Race::Nomad: return "Nomad";
            case Race::Orc: return "Orc";
            case Race::Troll: return "Troll";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Race r) {
        os << toString(r);
        return os;
    }
    
}