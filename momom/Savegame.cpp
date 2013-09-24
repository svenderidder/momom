//
//  Savegame.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Savegame.h"

namespace momom {
    
    Savegame::Savegame(): data{new SavegameData} {}
    
    Savegame::~Savegame() {}

    std::istream& operator>>(std::istream& is, Savegame& game) {
        SavegameData& data = *game.data.get();
        is >> data;
        return is;
    }

}
