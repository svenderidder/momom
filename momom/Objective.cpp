//
//  Objective.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Objective.h"

namespace momom {

    const char* toString(Objective o) {
        switch(o) {
            case Objective::Pragmatist: return "Pragmatist";
            case Objective::Militarist: return "Militarist";
            case Objective::Theurgist: return "Theurgist";
            case Objective::Perfectionist: return "Perfectionist";
            case Objective::Expansionist: return "Expansionist";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Objective o) {
        return os << toString(o);
    }

}
