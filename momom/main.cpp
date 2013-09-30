//
//  main.cpp
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <fstream>
#include <iostream>

#include "Savegame.h"
#include "Wizard.h"
#include "Hero.h"
#include "UnitType.h"

int main(int argc, const char * argv[])
{
    using namespace momom;
    
    const char* filename = "/Users/sven/Emulation/DOS/mom/SAVE1.GAM";
    
    Savegame s = load(filename);
    
    std::cout << "Wizards: " << s.nofWizards() << "\n";
    std::cout << "Difficulty: " << s.difficulty() << "\n";
    std::cout << "Magic Level: " << s.magicLevel() << "\n";
    std::cout << "Land Size: " << s.landSize() << "\n";
    std::cout << "Cities: " << s.nofCities() << "\n";
    std::cout << "Units: " << s.nofUnits() << "\n";
    std::cout << "Turn: " << s.turn() << "\n";
    std::cout << "Active Unit: " << s.activeUnit() << "\n";
    
//    for(int w = 0; w < s.nofWizards(); ++w) {
//        for(int h = 0; h < 35; ++h) {
//            Hero hero = s.hero(w, h);
//            for(Hero::Ability a: hero.getAbilities()) {
//                std::cout << a << " ";
//            }
//            std::cout << "\n";
//        }
//    }
//    
    for(int i = 0; i < s.nofWizards(); ++i) {
        Wizard w = s.wizard(static_cast<WizardID>(i));
        std::cout << w.banner() << ": " << w.name() << " (" << w.personality() <<
            "/" << w.objective() << ")\n";
        
    }
    
    for(int u = 0; u < s.nofUnits(); ++u) {
        Unit unit = s.unit(u);
        std::cout << u << ": " << unit.type() << "(" << unit.owner()
            << " " << unit.location() << ")\n";
    }
    
    s.unit(0).type(UnitType::SkyDrake);
    s.unit(5).type(UnitType::GreatWyrm);
    
}
