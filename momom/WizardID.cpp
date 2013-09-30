//
//  WizardID.cpp
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "WizardID.h"

namespace momom {
    
    const char* toString(WizardID w) {
        switch(w) {
            case WizardID::Player: return "Player";
            case WizardID::Opponent1: return "Opponent 1";
            case WizardID::Opponent2: return "Opponent 2";
            case WizardID::Opponent3: return "Opponent 3";
            case WizardID::Opponent4: return "Opponent 4";
            case WizardID::Neutral: return "Neutral";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, WizardID w) {
        return os << toString(w);
    }

}