//
//  Wizard.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Wizard.h"

namespace momom {
    
    Wizard::Wizard(WizardData::Block_t* data): d{data} {}
    
    // Wizard::Wizard(const Wizard& other): d{other.d} {}
        
    Wizard::Wizard(Wizard&& other) {
        other.d = nullptr;
    }
    
    Wizard::~Wizard() {}
    
//    Wizard& Wizard::operator=(const Wizard& other) {
//        d = other.d;
//        return *this;
//    }
    
    Wizard& Wizard::operator=(Wizard&& other) {
        other.d = nullptr;
        return *this;
    }
    
    std::string Wizard::name() const {
        using f = WizardData::Name;
        const char* p = &d->get<f>()[0];
        return std::string(p);
    }
    
    Race Wizard::homeRace() const {
        using f = WizardData::HomeRace;
        f::T v = d->get<f>();
        return static_cast<Race>(v);
    }

    Banner Wizard::banner() const {
        using f = WizardData::Banner;
        f::T v = d->get<f>();
        return static_cast<Banner>(v);
    }
    
    Personality Wizard::personality() const {
        using f = WizardData::Personality;
        f::T v = d->get<f>();
        return static_cast<Personality>(v);
    }
    
    Objective Wizard::objective() const {
        using f = WizardData::Objective;
        f::T v = d->get<f>();
        return static_cast<Objective>(v);
    }


}
