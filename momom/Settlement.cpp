//
//  Settlement.cpp
//  momom
//
//  Created by Sven de Ridder on 10/6/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Settlement.h"
#include "SavegameData.h"
#include "City.h"

namespace momom {

    static constexpr int MaxSettlements = 100;
    static constexpr size_t SettlementMaxNameSize = 14;
    
    struct SettlementRegion: Region<0x8aac, 114, MaxSettlements> {};
    struct SettlementName: F<SettlementRegion, char[SettlementMaxNameSize], 0x0000> {};

    struct SettlementInternals {
        SettlementInternals(SavegameData* data, int settlement_id)
        : data{data}
        , settlement_id{settlement_id} {
            assert(0 <= settlement_id && settlement_id < MaxSettlements);
        }
        
        template<typename F> typename F::value_type& get() {
            return data->get<F>(settlement_id);
        }
        
        template<typename F> const typename F::value_type& get() const {
            return data->get<F>(settlement_id);
        }
        
        const char* name() const {
            return &get<SettlementName>()[0];
        }
        
        void name(const char* n) {
            char* dest = &get<SettlementName>()[0];
            strncpy(dest, n, SettlementMaxNameSize - 1);
            dest[SettlementMaxNameSize-1] = '\0';
        }
        
        SavegameData* const data;
        const int settlement_id;
        
    };
    
    Settlement* Settlement::create(SavegameData* data, int settlement_id) {
        return new City(data, settlement_id);
    }
    
    Settlement::Settlement(SavegameData* data, int settlement_id)
    : si(new SettlementInternals(data, settlement_id)) {}
    
    Settlement::~Settlement() {}
    
    std::string Settlement::name() const {
        return std::string(si->name());
    }
    
    void Settlement::name(const std::string& n) {
        si->name(n.c_str());
    }
    
}
