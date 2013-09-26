//
//  WizardData.h
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_WizardData_h
#define momom_WizardData_h

#include "SavegameRegion.h"

namespace momom {
    
    namespace WizardData {
        typedef SavegameRegion<1224> Block_t;
        
        struct Portrait: Field<uint8_t, 0x0000> {};
        struct Name: Field<char[20], 0x0001> {};
        struct HomeRace: Field<uint8_t, 0x0015> {};
        struct Banner: Field<uint16_t, 0x0016> {};
        struct Personality: Field<uint16_t, 0x0018> {};
        struct Objective: Field<uint16_t, 0x001A> {};
        struct Fame: Field<uint16_t, 0x0024> {};
        struct PowerBase: Field<uint16_t, 0x0026> {};
        struct ResearchPct: Field<uint8_t, 0x002A> {};
        struct ManaPct: Field<uint8_t, 0x002B> {};
        struct SkillPct: Field<uint8_t, 0x002C> {};
        struct VolcanoMP: Field<uint8_t, 0x002D> {};
        struct SumCircleX: Field<uint16_t, 0x002E> {};
        struct SumCircleY: Field<uint16_t, 0x0030> {};
        struct SumCircleP: Field<uint16_t, 0x0032> {};
        struct ResearchSpells: Field<uint16_t[8], 0x0034> {};
        struct GarrisonAvgStr: Field<uint16_t, 0x0048> {};
        struct SkillCombat: Field<uint16_t, 0x004C> {};
        struct SpellLeft: Field<uint16_t, 0x004E> {};
        struct SpellInitial: Field<uint16_t, 0x0050> {};
        struct CurrentSpell: Field<uint16_t, 0x0052> {};
        struct TurnUnusedMana: Field<uint16_t, 0x0054> {};
        struct TurnNominalMana: Field<uint16_t, 0x0056> {};
        struct TaxRate: Field<uint16_t, 0x0058> {};
        struct SpellBooks: Field<uint16_t[5], 0x005A> {};
        struct Retorts: Field<uint8_t[18], 0x0064> {};
        struct HiredHeroData: Field<char[28*6], 0x0066> {};
        struct BankedItems: Field<uint16_t[4], 0x0120> {};
        struct WizardsContacted: Field<uint8_t[6], 0x0128> {};
        struct WizardRelationScores: Field<uint8_t[6], 0x0152> {};
        struct WizardRelations: Field<uint8_t[6], 0x0158> {};
        struct ResearchLeft: Field<uint16_t, 0x025A> {};
        struct CurrentMana: Field<uint16_t, 0x025C> {};
        struct CastingSkillSq: Field<uint32_t, 0x025E> {};
        struct CurrentSpellRes: Field<uint16_t, 0x0262> {};
        struct SpellStatus: Field<uint8_t[214], 0x0264> {};
        struct Defeated: Field<uint16_t, 0x0354> {};
        struct CurrentGold: Field<uint16_t, 0x0356> {};
        struct AstMagicPower: Field<uint16_t, 0x035A> {};
        struct AstResearch: Field<uint16_t, 0x035C> {};
        struct AstStrength: Field<uint16_t, 0x035E> {};
        struct AstPower: Field<uint16_t, 0x0360> {};
        struct Historian: Field<uint8_t[288], 0x0362> {};
        struct Enchantments: Field<uint8_t[24], 0x0482> {};
        struct PersonalSchool: Field<uint16_t, 0x04C4> {};
    };
}

#endif
