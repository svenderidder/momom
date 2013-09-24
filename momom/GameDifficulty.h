//
//  GameDifficulty.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_GameDifficulty_h
#define momom_GameDifficulty_h

#include <ostream>

namespace momom {
    
    enum class GameDifficulty {
        Intro = 0,
        Easy = 1,
        Normal = 2,
        Hard = 3,
        Impossible = 4
    };
    
    const char* toString(GameDifficulty);
    
    std::ostream& operator<<(std::ostream&, GameDifficulty);

}

#endif
