//
//  Wizard.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Wizard.h"
#include "SavegameData.h"

namespace momom {
    
    Wizard::Wizard(SavegameData* data, int wizard_id)
    : data{data}
    , wizard_id{wizard_id} {}
    
    std::string Wizard::name() const {
        using f = Name;
        const char* p = &data->get<f>(wizard_id)[0];
        return std::string(p);
    }
    
    Race Wizard::homeRace() const {
        using f = HomeRace;
        f::value_type v = data->get<f>(wizard_id);
        return static_cast<Race>(v);
    }

    Banner Wizard::banner() const {
        using f = F_Banner;
        f::value_type v = data->get<f>(wizard_id);
        return static_cast<Banner>(v);
    }
    
    Personality Wizard::personality() const {
        using f = F_Personality;
        f::value_type v = data->get<f>(wizard_id);
        return static_cast<Personality>(v);
    }
    
    Objective Wizard::objective() const {
        using f = F_Objective;
        f::value_type v = data->get<f>(wizard_id);
        return static_cast<Objective>(v);
    }


}
