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
#include "MagicSchool.h"
#include "Retort.h"
#include "GlobalEnchantment.h"
#include "Spell.h"
#include "SpellResearchStatus.h"

namespace momom {
    
    struct InvalidWizardIDException: virtual std::logic_error {
        InvalidWizardIDException(int id)
        : std::logic_error("Invalid wizard ID")
        , id{id} {}
        int id;
    };
    
    struct InvalidTomeSchoolException: virtual std::logic_error {
        InvalidTomeSchoolException(int id)
        : std::logic_error("Invalid magic school for tome")
        , id{id} {}
        int id;
    };
    
    class Wizard {
    public:
        Wizard(class SavegameData* data, int wizard_id);
        Wizard(Wizard&& moved);
        ~Wizard();
        Wizard& operator=(Wizard&& moved);
        
        WizardID id() const;
        
        std::string name() const;
        void name(const std::string&);
        
        Race race() const;
        Banner banner() const;
        
        Personality personality() const;
        void personality(Personality);
        
        Objective objective() const;
        void objective(Objective);
        
        int fame() const;
        void fame(int);
        
        int gold() const;
        void gold(int);
        
        int mana() const;
        void mana(int);
        
        int tomes() const;
        int tomes(MagicSchool) const;
        void tomes(MagicSchool, int);
        
        bool retort(Retort) const;
        void retort(Retort, bool);
        
        bool globalEnchantment(GlobalEnchantment) const;
        void globalEnchantment(GlobalEnchantment, bool);
        
        SpellResearchStatus spellResearchStatus(Spell) const;
        void spellResearchStatus(Spell, SpellResearchStatus);
        
    private:
        std::unique_ptr<class WizardInternals> wi;
        
    };
}

#endif
