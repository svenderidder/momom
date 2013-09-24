//
//  main.cpp
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iomanip>

// #include "Hero.h"
#include "Savegame.h"

int main(int argc, const char * argv[])
{
    using namespace momom;
    
    std::ifstream f("/Users/sven/Emulation/DOS/mom/SAVE1.GAM", std::ios::in | std::ios::binary);
    if(!f) {
        std::cout << "Not found!\n";
    }
    
    /*
    for(int i = 0; i < 35; ++i) {
        Hero h;
        f >> h;
        std::cout << "#" << i << ": ";
        for(Hero::Ability a: h.getAbilities()) {
            std::cout << a << " ";
        }
        std::cout << "\n";
    }
    
    f.seekg(0x09D8);
    GeneralGameData ggd;
    f >> ggd;
    
    std::cout << ggd.getNofWizards() << "\n";
    */
    
    Savegame s;
    f >> s;
    
    std::cout << "Wizards: " << s.nofWizards() << "\n";
    std::cout << "Difficulty: " << s.difficulty() << "\n";
    std::cout << "Magic Level: " << s.magicLevel() << "\n";
    std::cout << "Land Size: " << s.landSize() << "\n";
    
//    std::cout << d.ggd.get<GeneralGameData::NofWizards>() << "\n";
//    std::cout << d.ggd.get<GeneralGameData::LandSize>() << "\n";
//    std::cout << sizeof(d) << "\n";
//    
    
}
