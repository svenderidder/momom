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
#include <istream>

#include "SavegameData.h"
#include "GameDifficulty.h"
#include "LandSize.h"
#include "MagicLevel.h"

namespace momom {
    
    class Savegame {
    private:
        std::unique_ptr<class SavegameData> data;
    
    public:
        const static int NumberOfHeroes = 35;
        const static int MaxWizards = 5;
        
        Savegame();
        ~Savegame();
        
        // General game data.
        int nofWizards() const;
        GameDifficulty difficulty() const;
        LandSize landSize() const;
        MagicLevel magicLevel() const;
        int nofCities() const;
        int nofUnits() const;
        int turn() const;
        int activeUnit() const;
        
        
        friend std::istream& operator>>(std::istream&, Savegame&);
    };
    
    std::istream& operator>>(std::istream& is, Savegame& game);
    
}

#endif
