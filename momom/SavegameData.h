//
//  SavegameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameData_h
#define momom_SavegameData_h

#include <istream>

#include "SavegameBlock.h"
#include "HeroData.h"
#include "GeneralGameData.h"

namespace momom {
    
    struct SavegameData {
        HeroData herodata[35*5];
        SavegameBlock<420> unknown;
        GeneralGameData ggd;
    };
    
    std::istream& operator>>(std::istream& is, SavegameData& d) {
        for(int w = 0; w < 5; ++w) {
            for(int h = 0; h < 35; ++h) {
                is >> d.herodata[w*35 + h];
            }
        }
        
        is >> d.unknown;
        
        is >> d.ggd;
        
        return is;
    }
    
}

#endif
