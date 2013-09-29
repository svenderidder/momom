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

    struct WizardRegion: Region<0x09E8, 1224, 5> {};
    struct Portrait: F<WizardRegion, uint8_t, 0x0000> {};
    struct Name: F<WizardRegion, char[20], 0x0001> {};
    struct HomeRace: F<WizardRegion, uint8_t, 0x0015> {};
    struct F_Banner: F<WizardRegion, uint16_t, 0x0016> {};
    struct F_Personality: F<WizardRegion, uint16_t, 0x0018> {};
    struct F_Objective: F<WizardRegion, uint16_t, 0x001A> {};
    struct Fame: F<WizardRegion, uint16_t, 0x0024> {};
    struct PowerBase: F<WizardRegion, uint16_t, 0x0026> {};
    struct ResearchPct: F<WizardRegion, uint8_t, 0x002A> {};
    struct ManaPct: F<WizardRegion, uint8_t, 0x002B> {};
    struct SkillPct: F<WizardRegion, uint8_t, 0x002C> {};
    struct VolcanoMP: F<WizardRegion, uint8_t, 0x002D> {};
    struct SumCircleX: F<WizardRegion, uint16_t, 0x002E> {};
    struct SumCircleY: F<WizardRegion, uint16_t, 0x0030> {};
    struct SumCircleP: F<WizardRegion, uint16_t, 0x0032> {};
    struct ResearchSpells: F<WizardRegion, uint16_t[8], 0x0034> {};
    struct GarrisonAvgStr: F<WizardRegion, uint16_t, 0x0048> {};
    struct SkillCombat: F<WizardRegion, uint16_t, 0x004C> {};
    struct SpellLeft: F<WizardRegion, uint16_t, 0x004E> {};
    struct SpellInitial: F<WizardRegion, uint16_t, 0x0050> {};
    struct CurrentSpell: F<WizardRegion, uint16_t, 0x0052> {};
    struct TurnUnusedMana: F<WizardRegion, uint16_t, 0x0054> {};
    struct TurnNominalMana: F<WizardRegion, uint16_t, 0x0056> {};
    struct TaxRate: F<WizardRegion, uint16_t, 0x0058> {};
    struct SpellBooks: F<WizardRegion, uint16_t[5], 0x005A> {};
    struct Retorts: F<WizardRegion, uint8_t[18], 0x0064> {};
    struct HiredHeroData: F<WizardRegion, char[28*6], 0x0066> {};
    struct BankedItems: F<WizardRegion, uint16_t[4], 0x0120> {};
    struct WizardsContacted: F<WizardRegion, uint8_t[6], 0x0128> {};
    struct WizardRelationScores: F<WizardRegion, uint8_t[6], 0x0152> {};
    struct WizardRelations: F<WizardRegion, uint8_t[6], 0x0158> {};
    struct ResearchLeft: F<WizardRegion, uint16_t, 0x025A> {};
    struct CurrentMana: F<WizardRegion, uint16_t, 0x025C> {};
    struct CastingSkillSq: F<WizardRegion, uint32_t, 0x025E> {};
    struct CurrentSpellRes: F<WizardRegion, uint16_t, 0x0262> {};
    struct SpellStatus: F<WizardRegion, uint8_t[214], 0x0264> {};
    struct Defeated: F<WizardRegion, uint16_t, 0x0354> {};
    struct CurrentGold: F<WizardRegion, uint16_t, 0x0356> {};
    struct AstMagicPower: F<WizardRegion, uint16_t, 0x035A> {};
    struct AstResearch: F<WizardRegion, uint16_t, 0x035C> {};
    struct AstStrength: F<WizardRegion, uint16_t, 0x035E> {};
    struct AstPower: F<WizardRegion, uint16_t, 0x0360> {};
    struct Historian: F<WizardRegion, uint8_t[288], 0x0362> {};
    struct Enchantments: F<WizardRegion, uint8_t[24], 0x0482> {};
    struct PersonalSchool: F<WizardRegion, uint16_t, 0x04C4> {};

    struct UnitRegion: Region<0xB734, 32, 1000> {};
    struct UnitX: F<UnitRegion, uint8_t, 0x0000> {};
    struct UnitY: F<UnitRegion, uint8_t, 0x0001> {};
    struct UnitP: F<UnitRegion, uint8_t, 0x0002> {};
    struct UnitOwner: F<UnitRegion, uint8_t, 0x0003> {};
    struct UnitTotalMoves: F<UnitRegion, uint8_t, 0x0004> {};
    struct UnitType: F<UnitRegion, uint8_t, 0x0005> {};
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
