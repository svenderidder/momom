//
//  Outpost.h
//  momom
//
//  Created by Sven de Ridder on 10/6/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Outpost_h
#define momom_Outpost_h

#include "Settlement.h"

namespace momom {
    
    class Outpost: public Settlement {
    public:
        Outpost(SavegameData*, int settlement_id);
    };

}

#endif
