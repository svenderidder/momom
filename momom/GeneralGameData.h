//
//  GeneralGameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_GeneralGameData_h
#define momom_GeneralGameData_h

#include <boost/interprocess/mapped_region.hpp>
#include <cstdint>

#include "SavegameBlock.h"

namespace momom {
    
    class GeneralGameData { //: public SavegameBlock<16> {
    private:
        boost::interprocess::mapped_region raw;
        const static size_t Sz = 16;
    public:
        GeneralGameData(
            boost::interprocess::file_mapping& mapping,
            boost::interprocess::mode_t mode,
            boost::interprocess::offset_t offset)
        : raw(mapping, mode, offset, Sz) {}
        
        struct NofWizards: Field<uint16_t, 0> {};
        struct LandSize: Field<uint16_t, 2> {};
        struct MagicLevel: Field<uint16_t, 4> {};
        struct GameDifficulty: Field<uint16_t, 6> {};
        struct NofCities: Field<uint16_t, 8> {};
        struct NofUnits: Field<uint16_t, 10> {};
        struct CurrentTurn: Field<uint16_t, 12> {};
        struct CurrentUnit: Field<uint16_t, 14> {};
        
        template<typename F> const typename F::value_type& get() const {
            static_assert(F::offset + sizeof(typename F::value_type) <= Sz,
                          "Field outside of bounds");
            return *reinterpret_cast<const typename F::value_type*>(addr(F::offset));
        }
        
    private:
        inline char* addr(ptrdiff_t offset) const {
            return static_cast<char*>(raw.get_address()) + offset;
        }
        
    };
    
}

#endif
