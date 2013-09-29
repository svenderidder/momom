//
//  Unit.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Unit_h
#define momom_Unit_h

namespace momom {
    
    class SavegameData;
    
    class Unit {
    public:
        Unit(SavegameData* data, int unit_id);
        
        int owner() const;
        int type() const;
        void type(int type);
        
    private:
        SavegameData* data;
        const int unit_id;
    };
    
}

#endif
