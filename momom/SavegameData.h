//
//  SavegameData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_SavegameData_h
#define momom_SavegameData_h

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

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
    
    struct GlobalHeroRegion: Region<0x0000, 12, 35*5> {};
    struct HeroStatus: F<GlobalHeroRegion, uint16_t, 0x0000> {};
    struct HeroAbilities: F<GlobalHeroRegion, uint32_t, 0x0002> {};
    struct HeroCastingSkill: F<GlobalHeroRegion, uint8_t, 0x0006> {};
    struct HeroSpells: F<GlobalHeroRegion, uint32_t, 0x0008> {};
    
    struct GeneralDataRegion: Region<0x09D8, 16> {};
    struct NofWizards: F<GeneralDataRegion, uint16_t, 0x0000> {};
    struct F_LandSize: F<GeneralDataRegion, uint16_t, 0x0002> {};
    struct F_MagicLevel: F<GeneralDataRegion, uint16_t, 0x0004> {};
    struct F_GameDifficulty: F<GeneralDataRegion, uint16_t, 0x0006> {};
    struct NofCities: F<GeneralDataRegion, uint16_t, 0x0008> {};
    struct NofUnits: F<GeneralDataRegion, uint16_t, 0x000A> {};
    struct CurrentTurn: F<GeneralDataRegion, uint16_t, 0x000C> {};
    struct CurrentUnit: F<GeneralDataRegion, uint16_t, 0x000E> {};

    struct UnitRegion: Region<0xB734, 32, 1000> {};
    struct UnitLocation: F<UnitRegion, uint8_t[3], 0x0000> {};
    struct UnitOwner: F<UnitRegion, uint8_t, 0x0003> {};
    struct UnitTotalMoves: F<UnitRegion, uint8_t, 0x0004> {};
    struct F_UnitType: F<UnitRegion, uint8_t, 0x0005> {};
    struct UnitHeroSlot: F<UnitRegion, uint8_t, 0x0006> {};
    struct UnitMoved: F<UnitRegion, uint8_t, 0x0007> {};
    struct UnitRemainingMoves: F<UnitRegion, uint8_t, 0x0008> {};
    struct UnitDestinationX: F<UnitRegion, uint8_t, 0x0009> {};
    struct UnitDestinationY: F<UnitRegion, uint8_t, 0x000A> {};
    struct UnitStatus: F<UnitRegion, uint8_t, 0x000B> {};
    struct UnitLevel: F<UnitRegion, uint8_t, 0x000C> {};
    struct UnitExperience: F<UnitRegion, uint16_t, 0x000E> {};
    struct UnitLifeDrain: F<UnitRegion, uint8_t, 0x0010> {};
    struct UnitDamage: F<UnitRegion, uint8_t, 0x0011> {};
    struct UnitGrouping: F<UnitRegion, uint8_t, 0x0012> {};
    struct UnitScoutingRange: F<UnitRegion, uint8_t, 0x0016> {};
    struct UnitWeaponMutation: F<UnitRegion, uint8_t, 0x0017> {};
    struct UnitEnchantments: F<UnitRegion, uint32_t, 0x0018> {};
    struct UnitRoadLeft: F<UnitRegion, uint8_t, 0x001C> {};
    struct UnitRoadX: F<UnitRegion, uint8_t, 0x001D> {};
    struct UnitRoadY: F<UnitRegion, uint8_t, 0x001E> {};
    
    class SavegameData {
    public:
        SavegameData(const char* filename)
        : mapping(filename, boost::interprocess::read_write)
        , data(mapping, mapping.get_mode()) {}
        
        template<typename F> const typename F::value_type& get() const {
            return *reinterpret_cast<const typename F::value_type*>(
                static_cast<char*>(data.get_address())
                    + F::region::offset + F::offset);
        }
        
        template<typename F> const typename F::value_type& get(int index) const {
            using R = typename F::region;
            return *reinterpret_cast<const typename F::value_type*>(
                static_cast<char*>(data.get_address())
                    + R::offset + index * R::size + F::offset);
        }
        
        template<typename F> typename F::value_type& get(int index) {
            using R = typename F::region;
            return *reinterpret_cast<typename F::value_type*>(
                static_cast<char*>(data.get_address())
                    + R::offset + index * R::size + F::offset);
        }
        
    private:
        boost::interprocess::file_mapping mapping;
        boost::interprocess::mapped_region data;
    };
    
}

#endif
