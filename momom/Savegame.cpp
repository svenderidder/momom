//
//  Savegame.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <map>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <stdexcept>
#include "Savegame.h"
#include "SavegameData.h"
#include "RegularUnit.h"

namespace momom {
    
    struct SavegameHandles {
        std::map<int, Unit*> units;
    };
    
    Savegame load(const char* filename) {
        auto* data = new SavegameData(filename);
        return Savegame(filename, data);
    }
    
    Savegame::Savegame(const char* filename, SavegameData* data)
    : data{data}
    , handles(new SavegameHandles()) {}
    
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
    
    Hero Savegame::hero(int wizard_id, int hero_id) {
        return std::move(Hero(data.get(), wizard_id, hero_id));
    }
    
    Wizard Savegame::wizard(WizardID id) {
        int wizard_id = static_cast<int>(id);
        if(wizard_id < 0 || wizard_id >= nofWizards()) {
            throw InvalidWizardIDException(wizard_id);
        }
        return std::move(Wizard(data.get(), wizard_id));
    }
    
    Unit& Savegame::unit(int unit_id) {
        auto it = handles->units.find(unit_id);
        if(it == handles->units.end()) {
            Unit* pu = new RegularUnit(data.get(), unit_id);
            handles->units[unit_id] = pu;
            return *pu;
        }
        return *it->second;
    }
    

}
