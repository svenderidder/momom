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
    
    int Savegame::nofWizards() const {
        using f = GeneralGameData::NofWizards;
        f::value_type v = data->general.get<f>();
        return v - 1;
    }

    GameDifficulty Savegame::difficulty() const {
        using f = GeneralGameData::GameDifficulty;
        f::value_type v = data->general.get<f>();
        return static_cast<GameDifficulty>(v);
    }

    LandSize Savegame::landSize() const {
        using f = GeneralGameData::LandSize;
        f::value_type v = data->general.get<f>();
        return static_cast<LandSize>(v);
    }
    
    MagicLevel Savegame::magicLevel() const {
        using f = GeneralGameData::MagicLevel;
        f::value_type v = data->general.get<f>();
        return static_cast<MagicLevel>(v);
    }

    std::istream& operator>>(std::istream& is, Savegame& game) {
        SavegameData& data = *game.data.get();
        is >> data;
        return is;
    }

}
