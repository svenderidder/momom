//
//  Savegame.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Savegame_h
#define momom_Savegame_h

#include <memory>
#include <vector>

#include "SavegameData.h"
#include "Wizard.h"
#include "GameDifficulty.h"
#include "LandSize.h"
#include "MagicLevel.h"

namespace momom {
    
    class Savegame {
        class DataInternals;
    
    public:
        const static int NumberOfHeroes = 35;
        const static int MaxWizards = 5;
        
        Savegame(const char* filename, DataInternals* internals);
        Savegame(Savegame&& moved);
        ~Savegame();
        
        Savegame& operator=(Savegame&& moved) { return *this; }
        
        // General game data.
        int nofWizards() const;
        GameDifficulty difficulty() const;
        LandSize landSize() const;
        MagicLevel magicLevel() const;
        int nofCities() const;
        int nofUnits() const;
        int turn() const;
        int activeUnit() const;
        
        // Wizards
        const Wizard wizard(int index) const;
        
    private:
        std::unique_ptr<class SavegameData> data;
        std::unique_ptr<DataInternals> di;
        
        friend Savegame load(const char*);
    };
    
    Savegame load(const char* filename);
    
}

#endif
