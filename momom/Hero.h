//
//  Hero.h
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Hero_h
#define momom_Hero_h

#include <memory>

#include "HeroAbility.h"
#include "Spell.h"
#include "WizardID.h"
#include "UnitType.h"

namespace momom {
    
    class SavegameData;
    
    class Hero {
        
    public:
        static Hero* create(SavegameData* data, std::pair<WizardID, UnitType>);
        
        Hero(SavegameData* data, int wizard_id, int hero_id);
        Hero(Hero&& moved);
        ~Hero();
        Hero& operator=(Hero&& moved);
        
        bool hired() const;
        std::pair<bool, int> hire();
        void unhire(bool alive, int level);
        
        bool alive() const;
        void alive(bool);
        
        int level() const;
        void level(int);
        
        bool ability(HeroAbility) const;
        void ability(HeroAbility, bool);
        
        int castingSkill() const;
        void castingSkill(int);
        
        Spell spell(int index) const;
        void spell(int index, Spell);
        
    private:
        std::unique_ptr<struct HeroInternals> hi;
    };
    
    int castingSkillToMana(int s);
    int manaToCastingSkill(int m);
    
}

#endif
