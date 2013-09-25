//
//  SavegameBlock.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameBlock_h
#define momom_SavegameBlock_h

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstddef>

namespace momom {
    
    template<typename T_, size_t Offset_>
    struct Field {
        typedef T_ T;
        enum { offset = Offset_ };
    };
    
    template<size_t Sz> class SavegameBlock {
    public:
        enum { blocksize = Sz };
    
        SavegameBlock() {}
        ~SavegameBlock() {}
        
        char* init(
                   boost::interprocess::file_mapping& mapping,
                   boost::interprocess::offset_t offset) {
            rgn = boost::interprocess::mapped_region(mapping, mapping.get_mode(), offset, Sz);
            return addr(0);
        }

        template<typename F> const typename F::T& get() const {
            static_assert(F::offset + sizeof(typename F::T) <= Sz,
                          "Field outside of bounds");
            return *reinterpret_cast<const typename F::T*>(addr(F::offset));
        }
        
    private:
        boost::interprocess::mapped_region rgn;
        
        inline char* addr(ptrdiff_t offset) const {
            return static_cast<char*>(rgn.get_address()) + offset;
        }
    
    };
    
}

#endif
