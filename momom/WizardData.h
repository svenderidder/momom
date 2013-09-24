//
//  WizardData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_WizardData_h
#define momom_WizardData_h

#include "SavegameBlock.h"

namespace momom {
    
    struct WizardData: SavegameBlock<0x04C8> {
        struct Portrait: Field<uint8_t, 0x0000> {};
        struct Name: Field<char[20], 0x0001> {};
        struct HomeRace: Field<uint8_t, 0x0015> {};
        struct Banner: Field<uint16_t, 0x0016> {};
        struct Personality: Field<uint16_t, 0x0018> {};
        struct Objective: Field<uint16_t, 0x001A> {};
    };
}

#endif
