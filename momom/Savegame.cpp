//
//  Savegame.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

/*
#include "Savegame.h"

namespace momom {
    
    class GeneralGameData {
    private:
        std::unique_ptr<char[]> data;
        const static size_t GeneralGameDataBlockSize = 16;
    
    public:
        GeneralGameData(): data{new char[GeneralGameDataBlockSize]} {}
        ~GeneralGameData() {}
        
    private:
        friend std::istream& operator>>(std::istream&, GeneralGameData&);
        
    };
    
    std::istream& operator>>(std::istream& is, GeneralGameData& ggd) {
        is.read(ggd.data.get(), GeneralGameData::GeneralGameDataBlockSize);
        return is;
    }
    
    class SavegameData {
        
    };
    
}

*/