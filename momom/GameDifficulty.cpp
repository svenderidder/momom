//
//  GameDifficulty.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "GameDifficulty.h"

namespace momom {
    
    const char* toString(GameDifficulty d) {
        switch(d) {
            case GameDifficulty::Intro: return "Intro";
            case GameDifficulty::Easy: return "Easy";
            case GameDifficulty::Normal: return "Normal";
            case GameDifficulty::Hard: return "Hard";
            case GameDifficulty::Impossible: return "Impossible";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, GameDifficulty d) {
        os << toString(d);
        return os;
    }
    
}