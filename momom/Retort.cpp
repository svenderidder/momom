//
//  Retort.cpp
//  momom
//
//  Created by Sven de Ridder on 9/30/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Retort.h"

namespace momom {
    
    const char* toString(Retort r) {
        switch(r) {
        case Retort::Alchemy: return "Alchemy";
        case Retort::Warlord: return "Warlord";
        case Retort::ChaosMaster: return "Chaos Master";
        case Retort::NatureMaster: return "Nature Master";
        case Retort::SorceryMaster: return "Sorcery Master";
        case Retort::InfernalPower: return "Infernal Power";
        case Retort::DivinePower: return "Divine Power";
        case Retort::SageMaster: return "Sage Master";
        case Retort::Channeler: return "Channeler";
        case Retort::Myrran: return "Myrran";
        case Retort::Archmage: return "Archmage";
        case Retort::ManaFocusing: return "Mana Focusing";
        case Retort::NodeMastery: return "Node Mastery";
        case Retort::Famous: return "Famous";
        case Retort::Runemaster: return "Runemaster";
        case Retort::Conjurer: return "Conjurer";
        case Retort::Charismatic: return "Charismatic";
        case Retort::Artificer: return "Artificer";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Retort r) {
        return os << toString(r);
    }
    
}