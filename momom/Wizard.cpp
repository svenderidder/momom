//
//  Wizard.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Wizard.h"
#include "WizardData.h"

namespace momom {
    
    Wizard::Wizard(WizardData* data): d{data} {}
    
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
        const char* p = &d->get<WizardData::Name>()[0];
        return std::string(p);
    }
}
