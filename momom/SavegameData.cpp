//
//  SavegameData.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "SavegameData.h"

namespace momom {
    
    SavegameData::SavegameData(const char* filename)
    : mapped(filename, boost::interprocess::read_only) {
        for(int w = 0; w < 5; ++w) {
            for(int h = 0; h < 35; ++h) {
                int i = w*35 + h;
                heroes[i].init(mapped, 0x0000 + i * HeroData::Block_t::blocksize);
            }
        }
        general.init(mapped, 0x09D8);
        for(int w = 0; w < 5; ++w) {
            wizards[w].init(mapped, 0x09E8 + w * WizardData::Block_t::blocksize);
        }
    }
    
    SavegameData::~SavegameData() {}
    
}
