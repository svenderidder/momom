//
//  Plane.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Plane_h
#define momom_Plane_h

#include <ostream>

namespace momom {
    
    enum class Plane {
        Arcanus = 0,
        Myrror = 1
    };
    
    const char* toString(Plane);
    
    std::ostream& operator<<(std::ostream&, Plane);
    
}

#endif
