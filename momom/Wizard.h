//
//  Wizard.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Wizard_h
#define momom_Wizard_h

#include <string>

#include "Race.h"
#include "Banner.h"
#include "Personality.h"
#include "Objective.h"

namespace momom {
    
    class SavegameData;
    
    class Wizard {
    public:
        Wizard(SavegameData* data, int wizard_id);
        
        std::string name() const;
        Race homeRace() const;
        Banner banner() const;
        Personality personality() const;
        Objective objective() const;
        
    private:
        SavegameData* data;
        int wizard_id;
    
    };
}

#endif
