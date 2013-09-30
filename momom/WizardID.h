//
//  WizardID.h
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_WizardID_h
#define momom_WizardID_h

#include <ostream>

namespace momom {
    
    enum class WizardID {
        Player = 0,
        Opponent1 = 1,
        Opponent2 = 2,
        Opponent3 = 3,
        Opponent4 = 4,
        Neutral = 5
    };
    
    const char* toString(WizardID);
    
    std::ostream& operator<<(std::ostream&, WizardID);
    
}

#endif
