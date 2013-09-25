//
//  SavegameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameData_h
#define momom_SavegameData_h

#include <boost/interprocess/file_mapping.hpp>
#include <istream>

#include "SavegameBlock.h"
#include "HeroData.h"
#include "GeneralGameData.h"
#include "WizardData.h"

namespace momom {
    
    class SavegameData {
    private:
        boost::interprocess::file_mapping raw_data;
        
    public:
        SavegameData(const char* filename);
        ~SavegameData();
        
        HeroData herodata[35*5];
        SavegameBlock<420> unknown;
        GeneralGameData general;
        WizardData wizards[5];
    };
    
    std::istream& operator>>(std::istream&, SavegameData&);
    
}

#endif
