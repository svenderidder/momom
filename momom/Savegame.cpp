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
        std::map<int, std::shared_ptr<Unit>> units;
    };
    
    Savegame load(const char* filename) {
        auto* data = new SavegameData(filename);
        return Savegame(filename, data);
    }
    
    Savegame::Savegame(const char* filename, SavegameData* data)
    : data{data}
    , units(data, Unit::create)
    , heroes(data, Hero::create)
    , wizards(data, Wizard::create)
    , settlements(data, Settlement::create) {}
    
    Savegame::Savegame(Savegame&& moved)
    : data{std::move(moved.data)}
    , units(data.get(), Unit::create)
    , heroes(data.get(), Hero::create)
    , wizards(data.get(), Wizard::create)
    , settlements(data.get(), Settlement::create) {}
    
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
    
    Hero& Savegame::hero(int wizard_id, int hero_id) {
        return heroes.get(std::make_pair(static_cast<WizardID>(wizard_id), static_cast<UnitType>(hero_id)));
    }
    
    Wizard& Savegame::wizard(WizardID id) {
        return wizards.get(id);
    }
    
    Unit& Savegame::unit(int unit_id) {
        return units.get(unit_id);
    }
    
    Settlement& Savegame::settlement(int settlement_id) {
        return settlements.get(settlement_id);
    }
    

}
