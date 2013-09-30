//
//  GlobalEnchantment.h
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_GlobalEnchantment_h
#define momom_GlobalEnchantment_h

#include <ostream>

namespace momom {

    constexpr int TotalGlobalEnchantments = 24;

    enum class GlobalEnchantment {
        EternalNight = 0,
        EvilOmens = 1,
        ZombieMastery = 2,
        AuraOfMajesty = 3,
        WindMastery = 4,
        SuppressMagic = 5,
        TimeStop = 6,
        NatureAwareness = 7,
        NaturesWrath = 8,
        HerbMastery = 9,
        ChaosSurge = 10,
        DoomMastery = 11,
        GreatWasting = 12,
        MeteorStorm = 13,
        Armageddon = 14,
        Tranquility = 15,
        LifeForce = 16,
        Crusade = 17,
        JustCause = 18,
        HolyArms = 19,
        PlanarSeal = 20,
        CharmOfLife = 21,
        DetectMagic = 22,
        Awareness = 23
    };
    
    const char* toString(GlobalEnchantment);
    
    std::ostream& operator<<(std::ostream&, GlobalEnchantment);
    
    // Listing of all global enchantments so we can iterate over the enumeration.
    constexpr GlobalEnchantment AllGlobalEnchantments[] = {
        GlobalEnchantment::EternalNight,
        GlobalEnchantment::EvilOmens,
        GlobalEnchantment::ZombieMastery,
        GlobalEnchantment::AuraOfMajesty,
        GlobalEnchantment::WindMastery,
        GlobalEnchantment::SuppressMagic,
        GlobalEnchantment::TimeStop,
        GlobalEnchantment::NatureAwareness,
        GlobalEnchantment::NaturesWrath,
        GlobalEnchantment::HerbMastery,
        GlobalEnchantment::ChaosSurge,
        GlobalEnchantment::DoomMastery,
        GlobalEnchantment::GreatWasting,
        GlobalEnchantment::MeteorStorm,
        GlobalEnchantment::Armageddon,
        GlobalEnchantment::Tranquility,
        GlobalEnchantment::LifeForce,
        GlobalEnchantment::Crusade,
        GlobalEnchantment::JustCause,
        GlobalEnchantment::HolyArms,
        GlobalEnchantment::PlanarSeal,
        GlobalEnchantment::CharmOfLife,
        GlobalEnchantment::DetectMagic,
        GlobalEnchantment::Awareness,
    };
    
}

#endif
