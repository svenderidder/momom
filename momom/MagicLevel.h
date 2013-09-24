//
//  MagicLevel.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_MagicLevel_h
#define momom_MagicLevel_h

#include <ostream>

namespace momom {
    
    enum class MagicLevel {
        Weak = 0,
        Normal = 1,
        Powerful = 2
    };

    const char* toString(MagicLevel);
    
    std::ostream& operator<<(std::ostream&, MagicLevel);
}

#endif
