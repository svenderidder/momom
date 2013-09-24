//
//  Personality.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Personality_h
#define momom_Personality_h

#include <ostream>

namespace momom {
    
    enum class Personality {
        Maniacal = 0,
        Ruthless = 1,
        Aggressive = 2,
        Chaotic = 3,
        Lawful = 4,
        Peaceful = 5
    };
    
    const char* toString(Personality);
    
    std::ostream& operator<<(std::ostream&, Personality);
    
}

#endif
