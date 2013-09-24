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
#include "WizardData.h"
#include "Wizard.h"

int main(int argc, const char * argv[])
{
    using namespace momom;
    
    std::ifstream f("/Users/sven/Emulation/DOS/mom/SAVE1.GAM", std::ios::in | std::ios::binary);
    if(!f) {
        std::cout << "Not found!\n";
    }
    
    Savegame s;
    f >> s;
    
    std::cout << "Wizards: " << s.nofWizards() << "\n";
    std::cout << "Difficulty: " << s.difficulty() << "\n";
    std::cout << "Magic Level: " << s.magicLevel() << "\n";
    std::cout << "Land Size: " << s.landSize() << "\n";
    std::cout << "Cities: " << s.nofCities() << "\n";
    std::cout << "Units: " << s.nofUnits() << "\n";
    std::cout << "Turn: " << s.turn() << "\n";
    std::cout << "Active Unit: " << s.activeUnit() << "\n";
    
    for(int i = 0; i < s.nofWizards(); ++i) {
        Wizard w = s.wizard(i);
        std::cout << "Wizard #" << i << ": " << w.name() << " (" << w.homeRace() << ")\n";
        
    }
    
}
