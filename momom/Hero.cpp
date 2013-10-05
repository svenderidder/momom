//
//  Hero.cpp
//  momom
//
//  Created by Sven de Ridder on 9/23/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <cmath>

#include "Hero.h"
#include "SavegameData.h"

namespace momom {

    static constexpr int MaxWizards = 5;
    static constexpr int TotalHeroes = 35;
    static constexpr int MaxHeroSpells = 4;
    static constexpr int MinHeroLevel = 1;
    static constexpr int MaxHeroLevel = 9;
    static constexpr int16_t HeroHiredMarker = 0xffec;

    struct GlobalHeroRegion: Region<0x0000, 12, MaxWizards * TotalHeroes> {};
    struct HeroStatus: F<GlobalHeroRegion, int16_t, 0x0000> {};
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
        
        bool hired() const {
            return get<HeroStatus>() == HeroHiredMarker;
        }
        
        int16_t hire() {
            int16_t& current = get<HeroStatus>();
            assert(current != HeroHiredMarker);
            int16_t previous = current;
            current = HeroHiredMarker;
            return previous;
        }
        
        void unhire(int16_t next) {
            int16_t& current = get<HeroStatus>();
            assert(current == HeroHiredMarker);
            current = next;
        }
        
        bool alive() const {
            int16_t current = get<HeroStatus>();
            assert(current != HeroHiredMarker);
            return current > 0;
        }
        
        void alive(bool v) {
            int16_t& current = get<HeroStatus>();
            assert(current != HeroHiredMarker);
            current = v ? abs(current) : -abs(current);
        }
        
        int level() const {
            int16_t current = get<HeroStatus>();
            assert(current != HeroHiredMarker);
            return abs(current);
        }
        
        void level(int l) {
            int16_t& current = get<HeroStatus>();
            assert(current != HeroHiredMarker);
            assert(1 <= MinHeroLevel && l <= MaxHeroLevel);
            current = current > 0 ? l : -l;
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
    
    Hero* Hero::create(SavegameData* data, std::pair<WizardID, UnitType> id) {
        return new Hero(data, static_cast<int>(id.first), static_cast<int>(id.second));
    }
    
    Hero::Hero(SavegameData* data, int wizard_id, int hero_id)
    : hi{new HeroInternals(data, wizard_id, hero_id)} {}
    
    Hero::~Hero() {}
    
    bool Hero::hired() const {
        return hi->hired();
    }
    
    std::pair<bool, int> Hero::hire() {
        int16_t previous = hi->hire();
        return std::make_pair(previous > 0, abs(previous));
    }
    
    void Hero::unhire(bool alive, int level) {
        int16_t current = alive ? level : -level;
        hi->unhire(current);
    }
    
    bool Hero::alive() const {
        return hi->alive();
    }
    
    void Hero::alive(bool v) {
        hi->alive(v);
    }
    
    int Hero::level() const {
        return hi->level();
    }
    
    void Hero::level(int l) {
        hi->level(l);
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
