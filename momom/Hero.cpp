//
//  Hero.cpp
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

#include "Hero.h"
#include "SavegameData.h"

namespace momom {

    static constexpr int MaxWizards = 5;
    static constexpr int TotalHeroes = 35;
    static constexpr int MaxHeroSpells = 4;

    struct GlobalHeroRegion: Region<0x0000, 12, MaxWizards * TotalHeroes> {};
    struct HeroStatus: F<GlobalHeroRegion, uint16_t, 0x0000> {};
    struct HeroAbilities: F<GlobalHeroRegion, uint32_t, 0x0002> {};
    struct HeroCastingSkill: F<GlobalHeroRegion, uint8_t, 0x0006> {};
    struct HeroSpells: F<GlobalHeroRegion, uint8_t[MaxHeroSpells], 0x0007> {};
    
    struct HeroInternals {
        HeroInternals(SavegameData* data, int wizard_id, int hero_id)
        : data{data}
        , hero_index{wizard_id * TotalHeroes + hero_id}
        {
            assert(0 <= wizard_id && wizard_id < MaxWizards);
            assert(0 <= hero_id && hero_id < TotalHeroes);
        }

        template<typename F> typename F::value_type& get() {
            return data->get<F>(hero_index);
        }
        
        template<typename F> const typename F::value_type& get() const {
            return data->get<F>(hero_index);
        }
        
        bool ability(uint32_t a) const {
            return get<HeroAbilities>() & a;
        }
        
        void ability(uint32_t a, bool v) {
            if(v) get<HeroAbilities>() |= a;
            else get<HeroAbilities>() &= ~a;
        }
        
        uint8_t castingSkill() const {
            return get<HeroCastingSkill>();
        }
        
        void castingSkill(uint8_t v) {
            get<HeroCastingSkill>() = v;
        }
        
        uint8_t spell(int index) const {
            assert(0 <= index && index < MaxHeroSpells);
            return get<HeroSpells>()[index];
        }
        
        void spell(int index, uint8_t s) {
            assert(0 <= index && index < MaxHeroSpells);
            assert(0 <= s && s < (TotalSpells + 1));
            get<HeroSpells>()[index] = s;
        }

        SavegameData* const data;
        const int hero_index;
    };

    // ---------------------------------------------------------------------------------------------
    // Hero implementation
    // ---------------------------------------------------------------------------------------------
    
    Hero::Hero(SavegameData* data, int wizard_id, int hero_id)
    : hi{new HeroInternals(data, wizard_id, hero_id)} {}
    
    Hero::Hero(Hero&& moved)
    : hi(std::move(moved.hi)) {}
    
    Hero::~Hero() {}
    
    Hero& Hero::operator=(Hero&& moved) {
        hi = std::move(moved.hi);
        return *this;
    }
    
    bool Hero::ability(HeroAbility a) const {
        return hi->ability(static_cast<uint32_t>(a));
    }
    
    void Hero::ability(HeroAbility a, bool v) {
        hi->ability(static_cast<uint32_t>(a), v);
    }
    
    int Hero::castingSkill() const {
        return static_cast<int>(hi->castingSkill());
    }
    
    void Hero::castingSkill(int v) {
        assert(0 <= v && v <= 0xff);
        hi->castingSkill(static_cast<uint8_t>(v));
    }
    
    Spell Hero::spell(int index) const {
        uint8_t s = hi->spell(index);
        return s > 0 ? static_cast<Spell>(s - 1) : Spell::None;
    }
    
    void Hero::spell(int index, Spell spell) {
        uint8_t s = (spell == Spell::None) ? 0 : (static_cast<uint8_t>(spell) + 1);
        hi->spell(index, s);
    }
    
    int castingSkillToMana(int s) {
        return s > 0 ? static_cast<int>(std::floor((s+1) * 2.5f)) : 0;
    }
    
    int manaToCastingSkill(int m) {
        return m > 0 ? static_cast<int>(std::ceil(m / 2.5f) - 1) : 0;
    }
    
}
