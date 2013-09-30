//
//  GlobalEnchantment.cpp
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "GlobalEnchantment.h"

namespace momom {
    
    const char* toString(GlobalEnchantment e) {
        switch(e) {
        case GlobalEnchantment::EternalNight: return "Eternal Night";
        case GlobalEnchantment::EvilOmens: return "Evil Omens";
        case GlobalEnchantment::ZombieMastery: return "Zombie Mastery";
        case GlobalEnchantment::AuraOfMajesty: return "Aura of Majesty";
        case GlobalEnchantment::WindMastery: return "Wind Mastery";
        case GlobalEnchantment::SuppressMagic: return "Suppress Magic";
        case GlobalEnchantment::TimeStop: return "Time Stop";
        case GlobalEnchantment::NatureAwareness: return "Nature Awareness";
        case GlobalEnchantment::NaturesWrath: return "Nature's Wrath";
        case GlobalEnchantment::HerbMastery: return "Herb Mastery";
        case GlobalEnchantment::ChaosSurge: return "Chaos Surge";
        case GlobalEnchantment::DoomMastery: return "Doom Mastery";
        case GlobalEnchantment::GreatWasting: return "Great Wasting";
        case GlobalEnchantment::MeteorStorm: return "Meteor Storm";
        case GlobalEnchantment::Armageddon: return "Armageddon";
        case GlobalEnchantment::Tranquility: return "Tranquility";
        case GlobalEnchantment::LifeForce: return "Life Force";
        case GlobalEnchantment::Crusade: return "Crusade";
        case GlobalEnchantment::JustCause: return "Just Cause";
        case GlobalEnchantment::HolyArms: return "Holy Arms";
        case GlobalEnchantment::PlanarSeal: return "Planar Seal";
        case GlobalEnchantment::CharmOfLife: return "Charm of Life";
        case GlobalEnchantment::DetectMagic: return "Detect Magic";
        case GlobalEnchantment::Awareness: return "Awareness";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, GlobalEnchantment e) {
        return os << toString(e);
    }
    
}
