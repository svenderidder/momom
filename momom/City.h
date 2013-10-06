//
//  City.h
//  momom
//
//  Created by Sven de Ridder on 10/6/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_City_h
#define momom_City_h

#include "Settlement.h"

namespace momom {
    
    class City: public Settlement {
    public:
        City(SavegameData*, int settlement_id);
    };
}

#endif
