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

#include "WizardID.h"
#include "Race.h"
#include "Banner.h"
#include "Personality.h"
#include "Objective.h"

namespace momom {
    
    struct InvalidWizardIDException: virtual std::logic_error {
        InvalidWizardIDException(int id)
        : std::logic_error("Invalid wizard ID")
        , id{id} {}
        int id;
    };
    
    class Wizard {
    public:
        static constexpr std::size_t MaxNameSize = 19; // 20 characters, but including '\0'.
        
        Wizard(class SavegameData* data, int wizard_id);
        Wizard(Wizard&& moved);
        ~Wizard();
        Wizard& operator=(Wizard&& moved);
        
        WizardID id() const;
        std::string name() const;
        Race race() const;
        Banner banner() const;
        
        Personality personality() const;
        void personality(Personality);
        
        Objective objective() const;
        void objective(Objective);
        
    private:
        std::unique_ptr<class WizardInternals> wi;
    };
}

#endif
