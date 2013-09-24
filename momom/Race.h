//
//  Race.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Race_h
#define momom_Race_h

#include <ostream>

namespace momom {
    
    enum class Race {
        Barbarian = 0,
        Beastman = 1,
        DarkElf = 2,
        Draconian = 3,
        Dwarf = 4,
        Gnoll = 5,
        Halfling = 6,
        HighElf = 7,
        HighMan = 8,
        Klackon = 9,
        Lizardman = 10,
        Nomad = 11,
        Orc = 12,
        Troll = 13
    };
    
    const char* toString(Race);
    
    std::ostream& operator<<(std::ostream&, Race);

}

#endif
