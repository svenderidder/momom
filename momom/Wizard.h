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

namespace momom {
    
    class WizardData;
    
    class Wizard {
    private:
        WizardData* d;
        
    public:
        Wizard(WizardData* data);
        Wizard(const Wizard& other) = default;
        Wizard(Wizard&& other);
        ~Wizard();
        
        Wizard& operator=(const Wizard& other) = default;
        Wizard& operator=(Wizard&& other);
        
        std::string name() const;
        Race homeRace() const;
        
    };
}

#endif
