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
        Location(int x, int y, Plane plane)
        : cx{x}, cy{y}, cplane{plane} {
            const int w = 60;
            const int h = 40;
            if(x < 0 || x >= w) throw CoordinateOutOfRangeException('x', x);
            if(y < 0 || y >= h) throw CoordinateOutOfRangeException('y', y);
        }
        
        int x() const { return cx; }
        int y() const { return cy; }
        Plane plane() const { return cplane; }
        
        Location north(int steps) const { return Location(cx, cy - steps, cplane); }
        Location south(int steps) const { return north(-steps); }
        Location west(int steps) const { return Location(cx - steps, cy, cplane); }
        Location east(int steps) const { return west(-steps); }
        Location shift() const {
            return Location(cx, cy, static_cast<Plane>(1 - static_cast<int>(cplane))); }
        
    private:
        int cx, cy;
        Plane cplane;
    };
    
    bool isValidLocation(const Location&);
    
    std::ostream& operator<<(std::ostream&, const Location&);
}

#endif
