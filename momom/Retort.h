//
//  Retort.h
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Retort_h
#define momom_Retort_h

#include <ostream>

namespace momom {
    
    enum class Retort {
        Alchemy = 0,
        Warlord = 1,
        ChaosMaster = 2,
        NatureMaster = 3,
        SorceryMaster = 4,
        InfernalPower = 5,
        DivinePower = 6,
        SageMaster = 7,
        Channeler = 8,
        Myrran = 9,
        Archmage = 10,
        ManaFocusing = 11,
        NodeMastery = 12,
        Famous = 13,
        Runemaster = 14,
        Conjurer = 15,
        Charismatic = 16,
        Artificer = 17
    };
    
    const char* toString(Retort);
    
    std::ostream& operator<<(std::ostream&, Retort);
    
}

#endif
