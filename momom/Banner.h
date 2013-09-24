//
//  Banner.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Banner_h
#define momom_Banner_h

#include <ostream>

namespace momom {
    
    enum class Banner {
        Blue = 0,
        Green = 1,
        Purple = 2,
        Red = 3,
        Yellow = 4
    };
    
    const char* toString(Banner);
    
    std::ostream& operator<<(std::ostream&, Banner);
    
}

#endif
