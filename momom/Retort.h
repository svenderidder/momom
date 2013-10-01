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

    static constexpr int TotalRetorts = 18;

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

    // Listing of all retorts so we can iterate over the enumeration.
    constexpr Retort AllRetorts[] = {
        Retort::Alchemy,
        Retort::Warlord,
        Retort::ChaosMaster,
        Retort::NatureMaster,
        Retort::SorceryMaster,
        Retort::InfernalPower,
        Retort::DivinePower,
        Retort::SageMaster,
        Retort::Channeler,
        Retort::Myrran,
        Retort::Archmage,
        Retort::ManaFocusing,
        Retort::NodeMastery,
        Retort::Famous,
        Retort::Runemaster,
        Retort::Conjurer,
        Retort::Charismatic,
        Retort::Artificer,
    };

}

#endif
