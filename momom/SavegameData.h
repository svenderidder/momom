//
//  SavegameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameData_h
#define momom_SavegameData_h

#include <memory>

#include <iostream>

namespace momom {

    template<ptrdiff_t O, size_t S, int N=1> struct Region {
        static const ptrdiff_t offset = O;
        static const size_t size = S;
        static const int entries = N;
    };
    
    template<typename R, typename T, ptrdiff_t O> struct F {
        typedef R region;
        typedef T value_type;
        static const ptrdiff_t offset = O;
    };
    
    struct GeneralDataRegion: Region<0x09D8, 16> {};
    struct NofWizards: F<GeneralDataRegion, uint16_t, 0x0000> {};
    struct F_LandSize: F<GeneralDataRegion, uint16_t, 0x0002> {};
    struct F_MagicLevel: F<GeneralDataRegion, uint16_t, 0x0004> {};
    struct F_GameDifficulty: F<GeneralDataRegion, uint16_t, 0x0006> {};
    struct NofCities: F<GeneralDataRegion, uint16_t, 0x0008> {};
    struct NofUnits: F<GeneralDataRegion, uint16_t, 0x000A> {};
    struct CurrentTurn: F<GeneralDataRegion, uint16_t, 0x000C> {};
    struct CurrentUnit: F<GeneralDataRegion, uint16_t, 0x000E> {};

    class SavegameData {
    public:
        SavegameData(char* raw, size_t sz): base{raw}, size{sz} {}
        ~SavegameData() {}
        
        SavegameData(SavegameData&& moved): base{std::move(moved.base)}, size{moved.size} {
            moved.base = nullptr;
        }
        
        template<typename F> const typename F::value_type& get() const {
            return *reinterpret_cast<const typename F::value_type*>(&base[F::region::offset + F::offset]);
        }
        
        template<typename F> const typename F::value_type& get(int index) const {
            using R = typename F::region;
            return *reinterpret_cast<const typename F::value_type*>(
                &base[R::offset + index * R::size + F::offset]);
        }
        
        template<typename F> typename F::value_type& get(int index) {
            using R = typename F::region;
            return *reinterpret_cast<typename F::value_type*>(
                &base[R::offset + index * R::size + F::offset]);
        }
        
    private:
        std::unique_ptr<char[]> base;
        size_t size;
    };
    
}

#endif
