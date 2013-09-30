//
//  Location.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Location.h"

namespace momom {

    Location::Location(int x, int y, Plane plane)
    : cx{x}
    , cy{y}
    , cplane{plane} {
        const int w = 60;
        const int h = 40;
        if(x < 0 || x >= w) throw CoordinateOutOfRangeException('x', x);
        if(y < 0 || y >= h) throw CoordinateOutOfRangeException('y', y);
    }
    
    int Location::x() const { return cx; }
    int Location::y() const { return cy; }
    Plane Location::plane() const { return cplane; }
    
    Location Location::north(int steps) const {
        return Location(cx, cy - steps, cplane);
    }
    Location Location::south(int steps) const {
        return north(-steps);
    }
    Location Location::west(int steps) const {
        return Location(cx - steps, cy, cplane);
    }
    Location Location::east(int steps) const {
        return west(-steps);
    }
    Location Location::shift() const {
        return Location(cx, cy, static_cast<Plane>(1 - static_cast<int>(cplane)));
    }

    std::ostream& operator<<(std::ostream& os, const Location& l) {
        return os << l.plane() << ":" << l.x() << "," << l.y();
    }

}