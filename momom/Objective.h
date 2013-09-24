//
//  Objective.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Objective_h
#define momom_Objective_h

#include <ostream>

namespace momom {
    
    enum class Objective {
        Pragmatist = 0,
        Militarist = 1,
        Theurgist = 2,
        Perfectionist = 3,
        Expansionist = 4
    };
    
    const char* toString(Objective);
    
    std::ostream& operator<<(std::ostream&, Objective);
    
}

#endif
