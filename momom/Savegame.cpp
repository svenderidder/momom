//
//  Savegame.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <stdexcept>
#include "Savegame.h"

namespace momom {
    
    Savegame::Savegame(const char* filename): data{new SavegameData(filename)} {}
    
    Savegame::~Savegame() {}
    
    int Savegame::nofWizards() const {
        using f = GeneralGameData::NofWizards;
        f::T v = data->general.get<f>();
        return v;
    }

    GameDifficulty Savegame::difficulty() const {
        using f = GeneralGameData::GameDifficulty;
        f::T v = data->general.get<f>();
        return static_cast<GameDifficulty>(v);
    }

    LandSize Savegame::landSize() const {
        using f = GeneralGameData::LandSize;
        f::T v = data->general.get<f>();
        return static_cast<LandSize>(v);
    }
    
    MagicLevel Savegame::magicLevel() const {
        using f = GeneralGameData::MagicLevel;
        f::T v = data->general.get<f>();
        return static_cast<MagicLevel>(v);
    }

    int Savegame::nofCities() const {
        using f = GeneralGameData::NofCities;
        f::T v = data->general.get<f>();
        return v;
    }
    
    int Savegame::nofUnits() const {
        using f = GeneralGameData::NofUnits;
        f::T v = data->general.get<f>();
        return v;
    }
    
    int Savegame::turn() const {
        using f = GeneralGameData::CurrentTurn;
        f::T v = data->general.get<f>();
        return v;
    }
    
    int Savegame::activeUnit() const {
        using f = GeneralGameData::CurrentUnit;
        f::T v = data->general.get<f>();
        return v;
    }
    
    const Wizard Savegame::wizard(int index) const {
        if(index < 0 || index >= nofWizards()) {
            throw std::range_error("Wizard index out of range");
        }
        WizardData::Block_t* wd = &data->wizards[index];
        return Wizard(wd);
    }
    
    Savegame load(const char* filename) {
        return Savegame(filename);
    }

}
