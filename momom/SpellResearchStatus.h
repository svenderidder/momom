//
//  SpellResearchStatus.h
//  momom
//
//  Created by Sven de Ridder on 10/1/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SpellResearchStatus_h
#define momom_SpellResearchStatus_h

#include <ostream>

namespace momom {
    
    enum class SpellResearchStatus {
        Unavailable = 0,
        EventuallyResearchable = 1,
        Known = 2,
        CurrentlyResearchable = 3
    };
    
    const char* toString(SpellResearchStatus);
    
    std::ostream& operator<<(std::ostream&, SpellResearchStatus);
    
}

#endif
