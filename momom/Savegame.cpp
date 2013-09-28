//
//  Savegame.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <stdexcept>
#include "Savegame.h"
#include "SavegameData.h"

namespace momom {
    
    Savegame load(const char* filename) {
        auto* data = new SavegameData(filename);
        return Savegame(filename, data);
    }
    
    Savegame::Savegame(const char* filename, SavegameData* data)
    : data{data} {}
    
    Savegame::Savegame(Savegame&& moved) {}
    
    Savegame::~Savegame() {}
    
    int Savegame::nofWizards() const {
        using f = NofWizards;
        f::value_type v = data->get<f>();
        return v;
    }

    GameDifficulty Savegame::difficulty() const {
        using f = F_GameDifficulty;
        f::value_type v = data->get<f>();
        return static_cast<GameDifficulty>(v);
    }

    LandSize Savegame::landSize() const {
        using f = F_LandSize;
        f::value_type v = data->get<f>();
        return static_cast<LandSize>(v);
    }
    
    MagicLevel Savegame::magicLevel() const {
        using f = F_MagicLevel;
        f::value_type v = data->get<f>();
        return static_cast<MagicLevel>(v);
    }

    int Savegame::nofCities() const {
        using f = NofCities;
        f::value_type v = data->get<f>();
        return v;
    }
    
    int Savegame::nofUnits() const {
        using f = NofUnits;
        f::value_type v = data->get<f>();
        return v;
    }
    
    int Savegame::turn() const {
        using f = CurrentTurn;
        f::value_type v = data->get<f>();
        return v;
    }
    
    int Savegame::activeUnit() const {
        using f = CurrentUnit;
        f::value_type v = data->get<f>();
        return v;
    }
    
    const Hero Savegame::hero(int wizard_id, int hero_id) const {
        return Hero(data.get(), wizard_id, hero_id);
    }
    
    /*
    const Wizard Savegame::wizard(int index) const {
        if(index < 0 || index >= nofWizards()) {
            throw std::range_error("Wizard index out of range");
        }
        WizardData::Block_t* wd = &data->wizards[index];
        return Wizard(wd);
    }
    */
    

}
