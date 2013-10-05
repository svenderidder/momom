//
//  UnitTable.h
//  momom
//
//  Created by Sven de Ridder on 10/5/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_UnitTable_h
#define momom_UnitTable_h

#include <map>
#include <memory>

#include "Unit.h"

namespace momom {
    
    class SavegameData;
    
    class UnitTable {
    public:
        UnitTable(SavegameData* data);
        ~UnitTable();
        
        Unit& get(int unit_id);
        const Unit& get(int unit_id) const;
        
    private:
        typedef std::map<int, std::shared_ptr<Unit>> UnitCache;
        mutable UnitCache unit_cache;
        SavegameData* const data;
        
    };
    
}

#endif
