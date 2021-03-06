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
#include "CachedLookup.h"
#include "Settlement.h"

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
        
        // Wizards
        Wizard& wizard(WizardID id);
        
        // Heroes
        Hero& hero(int wizard_id, int hero_id);
        
        // Units
        Unit& unit(int unit_id);
        
        // Settlements
        Settlement& settlement(int settlement_id);
        
    private:
        std::unique_ptr<class SavegameData> data;
        CachedLookup<WizardID, Wizard> wizards;
        CachedLookup<std::pair<WizardID, UnitType>, Hero> heroes;
        CachedLookup<int, Unit> units;
        CachedLookup<int, Settlement> settlements;
        
        friend Savegame load(const char*);
    };
    
    Savegame load(const char* filename);
    
}

#endif
