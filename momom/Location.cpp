//
//  Location.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Location.h"

namespace momom {
    
    bool isValidLocation(const Location& l) {
        const int w = 60;
        const int h = 40;
        return 0 <= l.x() && l.x() < w
            && 0 <= l.y() && l.y() < h;
    }
    
    std::ostream& operator<<(std::ostream& os, const Location& l) {
        os << l.plane() << ":" << l.x() << "," << l.y() << "\n";
        return os;
    }

}