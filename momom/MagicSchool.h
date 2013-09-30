//
//  MagicSchool.h
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_MagicSchool_h
#define momom_MagicSchool_h

#include <ostream>

namespace momom {
    
    enum class MagicSchool {
        Nature = 0,
        Sorcery = 1,
        Chaos = 2,
        Life = 3,
        Death = 4,
        Arcane = 5
    };
    
    const char* toString(MagicSchool);
    
    std::ostream& operator<<(std::ostream&, MagicSchool);
    
}

#endif
