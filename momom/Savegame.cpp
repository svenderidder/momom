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
#include "SavegameDefinitions.h"

namespace momom {
    
    class Savegame::DataInternals {
    public:
        DataInternals(const char* filename)
        : mapping(filename, boost::interprocess::read_only)
        , data(mapping, mapping.get_mode()) {}
        
        template<typename F> const typename F::value_type& get() const {
            return *reinterpret_cast<const typename F::value_type*>(
                static_cast<char*>(data.get_address()) + F::category::offset + F::offset);
        }
        
        ~DataInternals() {}

    private:
        boost::interprocess::file_mapping mapping;
        boost::interprocess::mapped_region data;
    };
    
    Savegame load(const char* filename) {
        auto* internals = new Savegame::DataInternals(filename);
        return Savegame(filename, internals);
    }
    
    Savegame::Savegame(const char* filename, Savegame::DataInternals* internals)
    : di{internals}
    , data{new SavegameData(filename)} {}
    
    Savegame::Savegame(Savegame&& moved) {}
    
    Savegame::~Savegame() {}
    
    int Savegame::nofWizards() const {
        using f = NofWizards;
        f::value_type v = di->get<f>();
        return v;
    }

    GameDifficulty Savegame::difficulty() const {
        using f = F_GameDifficulty;
        f::value_type v = di->get<f>();
        return static_cast<GameDifficulty>(v);
    }

    LandSize Savegame::landSize() const {
        using f = F_LandSize;
        f::value_type v = di->get<f>();
        return static_cast<LandSize>(v);
    }
    
    MagicLevel Savegame::magicLevel() const {
        using f = F_MagicLevel;
        f::value_type v = di->get<f>();
        return static_cast<MagicLevel>(v);
    }

    int Savegame::nofCities() const {
        using f = NofCities;
        f::value_type v = di->get<f>();
        return v;
    }
    
    int Savegame::nofUnits() const {
        using f = NofUnits;
        f::value_type v = di->get<f>();
        return v;
    }
    
    int Savegame::turn() const {
        using f = CurrentTurn;
        f::value_type v = di->get<f>();
        return v;
    }
    
    int Savegame::activeUnit() const {
        using f = CurrentUnit;
        f::value_type v = di->get<f>();
        return v;
    }
    
    const Wizard Savegame::wizard(int index) const {
        if(index < 0 || index >= nofWizards()) {
            throw std::range_error("Wizard index out of range");
        }
        WizardData::Block_t* wd = &data->wizards[index];
        return Wizard(wd);
    }
    

}
