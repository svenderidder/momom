//
//  Unit.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "Unit.h"
#include "HeroUnit.h"
#include "RegularUnit.h"
#include "SummonedUnit.h"
#include "SavegameData.h"

namespace momom {
    
    static constexpr int MaxUnits = 1000;

    struct UnitRegion: Region<0xB734, 32, MaxUnits> {};
    struct UnitXPos: F<UnitRegion, uint8_t, 0x0000> {};
    struct UnitYPos: F<UnitRegion, uint8_t, 0x0001> {};
    struct UnitPlane: F<UnitRegion, uint8_t, 0x0002> {};
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

    struct UnitInternals {
        UnitInternals(SavegameData* data, int unit_id)
        : data(data)
        , unit_id(unit_id) {
            assert(0 <= unit_id && unit_id < MaxUnits);
        }

        template<typename F> typename F::value_type& get() {
            return data->get<F>(unit_id);
        }
        
        template<typename F> const typename F::value_type& get() const {
            return data->get<F>(unit_id);
        }
        
        int xpos() const {
            return get<UnitXPos>();
        }
        
        void xpos(int x) {
            assert(0 <= x && x <= 60);
            get<UnitXPos>() = x;
        }

        int ypos() const {
            return get<UnitYPos>();
        }
        
        void ypos(int y) {
            assert(0 <= y && y <= 40);
            get<UnitYPos>() = y;
        }
        
        int plane() const {
            return get<UnitPlane>();
        }

        void plane(int p) {
            assert(p == 0 || p == 1);
            get<UnitPlane>() = p;
        }

        int owner() const {
            return get<UnitOwner>();
        }
        
        void owner(int owner) {
            assert(0 <= owner && owner <= 5);
            get<UnitOwner>() = owner;
        }
        
        int type() const {
            return get<F_UnitType>();
        }
        
        void type(int t) {
            assert(0 <= t && t < 198);
            get<F_UnitType>() = t;
        }
        
        int level() const {
            return get<UnitLevel>();
        }
        
        void level(int l) {
            assert(0 < l && l <= 8);
            get<UnitLevel>() = l;
        }
        
        SavegameData* const data;
        int unit_id;
    };

    Unit* Unit::create(SavegameData* data, int unit_id) {
        UnitType type = static_cast<UnitType>(data->get<F_UnitType>(unit_id));
        if(isHeroUnitType(type)) {
            return new HeroUnit(data, unit_id);
        }
        else if(isRegularUnitType(type)) {
            return new RegularUnit(data, unit_id);
        }
        else if(isSummonedUnitType(type)) {
            return new SummonedUnit(data, unit_id);
        }
        assert(false);
        return nullptr;
    }

    Unit::Unit(SavegameData* data, int unit_id)
    : ui(new UnitInternals(data, unit_id)) {}
    
    Unit::~Unit() {}
    
    WizardID Unit::owner() const {
        return static_cast<WizardID>(ui->owner());
    }
    
    void Unit::owner(WizardID wizard) {
        ui->owner(static_cast<int>(wizard));
    }
    
    UnitType Unit::type() const {
        return static_cast<UnitType>(ui->type());
    }
    
    void Unit::type(UnitType type) {
        ui->type(static_cast<int>(type));
    }
    
    Location Unit::location() const {
        return Location(ui->xpos(), ui->ypos(), static_cast<Plane>(ui->plane()));
    }
    
    void Unit::location(const Location& l) {
        ui->xpos(l.xpos());
        ui->ypos(l.ypos());
        ui->plane(static_cast<int>(l.plane()));
    }
    
    int Unit::level() const {
        return ui->level() + 1;
    }
    
    void Unit::level(int l) {
        ui->level(l - 1);
    }
    
    
}
