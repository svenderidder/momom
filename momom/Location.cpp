//
//  Location.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Location.h"

namespace momom {
    
    std::ostream& operator<<(std::ostream& os, const Location& l) {
        os << l.plane() << ":" << l.x() << "," << l.y() << "\n";
        return os;
    }

}