//
//  Plane.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Plane.h"

namespace momom {
    
    const char* toString(Plane p) {
        switch(p) {
            case Plane::Arcanus: return "Arcanus";
            case Plane::Myrror: return "Myrror";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Plane p) {
        os << toString(p);
        return os;
    }
    
}
