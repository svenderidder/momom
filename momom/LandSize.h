//
//  LandSize.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_LandSize_h
#define momom_LandSize_h

#include <ostream>

namespace momom {
    
    enum class LandSize {
        Small = 0,
        Medium = 1,
        Large = 2
    };

    const char* toString(LandSize);
    
    std::ostream& operator<<(std::ostream&, LandSize);

}

#endif
