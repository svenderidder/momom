//
//  LandSize.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "LandSize.h"

namespace momom {
    
    const char* toString(LandSize s) {
        switch(s) {
            case LandSize::Small: return "Small";
            case LandSize::Medium: return "Medium";
            case LandSize::Large: return "Large";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, LandSize s) {
        return os << toString(s);
    }
    
}