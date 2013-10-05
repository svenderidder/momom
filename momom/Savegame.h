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
#include "Hero.h"
#include "WizardID.h"
#include "Wizard.h"
#include "Unit.h"
#include "GameDifficulty.h"
#include "LandSize.h"
#include "MagicLevel.h"

namespace momom {
    
    class Savegame {
    
    public:
        const static int NumberOfHeroes = 35;
        const static int MaxWizards = 5;
        
        Savegame(const char* filename, SavegameData* data);
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
        
        // Heroes
        Hero hero(int wizard_id, int hero_id);
        
        // Wizards
        Wizard wizard(WizardID id);
        
        Unit& unit(int unit_id);
        
    private:
        std::unique_ptr<class SavegameData> data;
        std::unique_ptr<struct SavegameHandles> handles;
        
        friend Savegame load(const char*);
    };
    
    Savegame load(const char* filename);
    
}

#endif
