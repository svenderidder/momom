//
//  Settlement.h
//  momom
//
//  Created by Sven de Ridder on 10/6/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_Settlement_h
#define momom_Settlement_h

#include <memory>
#include <string>

namespace momom {
    
    class SavegameData;
    
    class Settlement {
    public:
        static Settlement* create(SavegameData*, int settlement_id);
        
        Settlement(SavegameData*, int settlement_id);
        virtual ~Settlement();
        
        std::string name() const;
        void name(const std::string&);
        
    private:
        std::unique_ptr<struct SettlementInternals> si;
        
    };
}

#endif
