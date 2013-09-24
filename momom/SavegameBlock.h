//
//  SavegameBlock.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameBlock_h
#define momom_SavegameBlock_h

#include <istream>
#include <cassert>

namespace momom {
    
    template<typename T, size_t O>
    struct Field {
        typedef T value_type;
        const static size_t offset = O;
    };
    
    template<size_t Sz> struct SavegameBlock {
        const static size_t blocksize = Sz;
        char data[Sz];
    
        template<typename T> T& getField(ptrdiff_t offset) {
            assert(offset + sizeof(T) <= blocksize);
            return *reinterpret_cast<T*>(&data[0] + offset);
        }
        template<typename T> const T& getField(ptrdiff_t offset) const {
            assert(offset + sizeof(T) <= blocksize);
            return *reinterpret_cast<const T*>(&data[0] + offset);
        }
        
        template<typename F> const typename F::value_type& get() const {
            return *reinterpret_cast<const typename F::value_type*>(&data[0] + F::offset);
        }
    
    };
    
    template<size_t Sz> std::istream& operator>>(std::istream& is, SavegameBlock<Sz>& b) {
        is.read(&b.data[0], b.blocksize);
        return is;
    }

}

#endif
