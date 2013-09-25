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

#include "WizardData.h"
#include "SavegameBlock.h"
#include "Race.h"
#include "Banner.h"
#include "Personality.h"
#include "Objective.h"

namespace momom {
    
    class Wizard {
    public:
        Wizard(WizardData::Block_t* data);
        Wizard(const Wizard& other) = default;
        Wizard(Wizard&& other);
        ~Wizard();
        
        Wizard& operator=(const Wizard& other) = default;
        Wizard& operator=(Wizard&& other);
        
        std::string name() const;
        Race homeRace() const;
        Banner banner() const;
        Personality personality() const;
        Objective objective() const;
        
    private:
        WizardData::Block_t* d;
    
    };
}

#endif
