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
        : raw_data(filename, boost::interprocess::read_only) {}
    
    SavegameData::~SavegameData() {}
    
    std::istream& operator>>(std::istream& is, SavegameData& d) {
        for(int w = 0; w < 5; ++w) {
            for(int h = 0; h < 35; ++h) {
                is >> d.herodata[w*35 + h];
            }
        }
        
        is >> d.unknown;
        
        is >> d.general;
        
        for(int i = 0; i < 5; ++i) {
            is >> d.wizards[i];
        }
        
        return is;
    }

}
