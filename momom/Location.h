//
//  Location.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Location_h
#define momom_Location_h

#include "Plane.h"

namespace momom {
    
    class Location {
    public:
        Location(int x, int y, Plane plane)
        : cx{x}, cy{y}, cplane{plane} {}
        
        int x() const { return cx; }
        int y() const { return cy; }
        Plane plane() const { return cplane; }
        
    private:
        int cx, cy;
        Plane cplane;
    };
    
    std::ostream& operator<<(std::ostream&, const Location&);
}

#endif
