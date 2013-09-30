//
//  MagicSchool.cpp
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "MagicSchool.h"

namespace momom {
    
    const char* toString(MagicSchool s) {
        switch(s) {
            case MagicSchool::Nature: return "Nature";
            case MagicSchool::Sorcery: return "Sorcery";
            case MagicSchool::Chaos: return "Chaos";
            case MagicSchool::Life: return "Life";
            case MagicSchool::Death: return "Death";
            case MagicSchool::Arcane: return "Arcane";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, MagicSchool s) {
        return os << toString(s);
    }
    
}
