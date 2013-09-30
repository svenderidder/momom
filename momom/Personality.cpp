//
//  Personality.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Personality.h"

namespace momom {
    
    const char* toString(Personality p) {
        switch(p) {
            case Personality::Maniacal: return "Maniacal";
            case Personality::Ruthless: return "Ruthless";
            case Personality::Aggressive: return "Aggressive";
            case Personality::Chaotic: return "Chaotic";
            case Personality::Lawful: return "Lawful";
            case Personality::Peaceful: return "Peaceful";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Personality p) {
        return os << toString(p);
    }
    
}
