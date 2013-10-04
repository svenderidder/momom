//
//  Location.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Location_h
#define momom_Location_h

#include <sstream>

#include "Plane.h"

namespace momom {
    
    struct CoordinateOutOfRangeException: virtual std::logic_error {
        char which;
        int v;
        CoordinateOutOfRangeException(char which, int v)
        : std::logic_error("Coordinate out of range")
        , which{which}
        , v{v} {}
    };
    
    class Location {
    public:
        Location(int x, int y, Plane plane);
        
        int xpos() const;
        int ypos() const;
        Plane plane() const;
        
        Location north(int steps = 1) const;
        Location south(int steps = 1) const;
        Location west(int steps = 1) const;
        Location east(int steps = 1) const;
        Location shift() const;
        
    private:
        int cx, cy;
        Plane cplane;
    };
    
    std::ostream& operator<<(std::ostream&, const Location&);

}

#endif
