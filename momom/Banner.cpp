//
//  Banner.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Banner.h"

namespace momom {
    
    const char* toString(Banner b) {
        switch(b) {
            case Banner::Blue: return "Blue";
            case Banner::Green: return "Green";
            case Banner::Purple: return "Purple";
            case Banner::Red: return "Red";
            case Banner::Yellow: return "Yellow";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Banner b) {
        return os << toString(b);
    }
    
}