//
//  SpellResearchStatus.cpp
//  momom
//
//  Created by Sven de Ridder on 10/1/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "SpellResearchStatus.h"

namespace momom {
    
    const char* toString(SpellResearchStatus s) {
        switch(s) {
            case SpellResearchStatus::Unavailable: return "Unavailable";
            case SpellResearchStatus::EventuallyResearchable: return "Eventually researchable";
            case SpellResearchStatus::Known: return "Known";
            case SpellResearchStatus::CurrentlyResearchable: return "Currently researchable";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, SpellResearchStatus s) {
        return os << toString(s);
    }
    
}