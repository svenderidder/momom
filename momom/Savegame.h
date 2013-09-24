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

namespace momom {
    
    class Savegame {
    private:
        std::unique_ptr<SavegameData> data;
    
    public:
        const static int NumberOfHeroes = 35;
        const static int MaxWizards = 5;
        
        Savegame();
        ~Savegame();
        
        friend std::istream& operator>>(std::istream&, Savegame&);
    };
    
    std::istream& operator>>(std::istream& is, Savegame& game);
    
}

#endif
