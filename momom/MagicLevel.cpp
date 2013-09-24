//
//  MagicLevel.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "MagicLevel.h"

namespace momom {
    
    const char* toString(MagicLevel l) {
        switch(l) {
            case MagicLevel::Weak: return "Weak";
            case MagicLevel::Normal: return "Normal";
            case MagicLevel::Powerful: return "Powerful";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, MagicLevel l) {
        os << toString(l);
        return os;
    }
   
}