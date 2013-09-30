//
//  Wizard.cpp
//  momom
//
//  Created by Sven de Ridder on 9/24/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include <algorithm>

#include "Wizard.h"
#include "SavegameData.h"

namespace momom {

    struct WizardRegion: Region<0x09E8, 1224, 5> {};
    struct Portrait: F<WizardRegion, uint8_t, 0x0000> {};
    struct WizardName: F<WizardRegion, char[20], 0x0001> {};
    struct WizardRace: F<WizardRegion, uint8_t, 0x0015> {};
    struct WizardBanner: F<WizardRegion, uint16_t, 0x0016> {};
    struct WizardPersonality: F<WizardRegion, uint16_t, 0x0018> {};
    struct WizardObjective: F<WizardRegion, uint16_t, 0x001A> {};
    struct WizardFame: F<WizardRegion, uint16_t, 0x0024> {};
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
    struct WizardTomes: F<WizardRegion, uint16_t[5], 0x005A> {};
    struct WizardRetorts: F<WizardRegion, uint8_t[18], 0x0064> {};
    struct HiredHeroData: F<WizardRegion, char[28*6], 0x0066> {};
    struct BankedItems: F<WizardRegion, uint16_t[4], 0x0120> {};
    struct WizardsContacted: F<WizardRegion, uint8_t[6], 0x0128> {};
    struct WizardRelationScores: F<WizardRegion, uint8_t[6], 0x0152> {};
    struct WizardRelations: F<WizardRegion, uint8_t[6], 0x0158> {};
    struct ResearchLeft: F<WizardRegion, uint16_t, 0x025A> {};
    struct WizardMana: F<WizardRegion, uint16_t, 0x025C> {};
    struct CastingSkillSq: F<WizardRegion, uint32_t, 0x025E> {};
    struct CurrentSpellRes: F<WizardRegion, uint16_t, 0x0262> {};
    struct SpellStatus: F<WizardRegion, uint8_t[214], 0x0264> {};
    struct Defeated: F<WizardRegion, uint16_t, 0x0354> {};
    struct WizardGold: F<WizardRegion, uint16_t, 0x0356> {};
    struct AstMagicPower: F<WizardRegion, uint16_t, 0x035A> {};
    struct AstResearch: F<WizardRegion, uint16_t, 0x035C> {};
    struct AstStrength: F<WizardRegion, uint16_t, 0x035E> {};
    struct AstPower: F<WizardRegion, uint16_t, 0x0360> {};
    struct Historian: F<WizardRegion, uint8_t[288], 0x0362> {};
    struct Enchantments: F<WizardRegion, uint8_t[24], 0x0482> {};
    struct PersonalSchool: F<WizardRegion, uint16_t, 0x04C4> {};

    struct WizardInternals {
        WizardInternals(SavegameData* data, int wizard_id)
        : data{data}
        , wizard_id{wizard_id} {}
        
        template<typename F> typename F::value_type& get() {
            return data->get<F>(wizard_id);
        }
        
        template<typename F> const typename F::value_type& get() const {
            return data->get<F>(wizard_id);
        }
        
        const char* name() const { return &get<WizardName>()[0]; }
        int race() const { return get<WizardRace>(); }
        int banner() const { return get<WizardBanner>(); }
        int personality() const { return get<WizardPersonality>(); }
        void personality(int p) { get<WizardPersonality>() = p; }
        int objective() const { return get<WizardObjective>(); }
        void objective(int o) { get<WizardObjective>() = o; }
        int fame() const { return get<WizardFame>(); }
        void fame(int f) { get<WizardFame>() = f; }
        int gold() const { return get<WizardGold>(); }
        void gold(int g) { get<WizardGold>() = g; }
        int mana() const { return get<WizardMana>(); }
        void mana(int m) { get<WizardMana>() = m; }
        int tomes(int s) const { return get<WizardTomes>()[s]; }
        void tomes(int s, int n) { get<WizardTomes>()[s] = n; }
        
        SavegameData* data;
        int wizard_id;
    };

    static constexpr std::size_t MaxNameSize = 19; // 20 characters, but including '\0'.
    static constexpr int MaxFame = 30000;
    static constexpr int MaxGold = 30000;
    static constexpr int MaxMana = 30000;
    static constexpr int MaxTomesPerSchool = 13;

    Wizard::Wizard(SavegameData* data, int wizard_id)
    : wi{new WizardInternals(data, wizard_id)} {}
    
    Wizard::Wizard(Wizard&& moved)
    : wi(std::move(moved.wi)) {}

    Wizard::~Wizard() {}

    Wizard& Wizard::operator=(Wizard&& moved) {
        wi = std::move(moved.wi);
        return *this;
    }

    WizardID Wizard::id() const {
        return static_cast<WizardID>(wi->wizard_id);
    }
    
    std::string Wizard::name() const {
        return std::string(wi->name());
    }
    
    Race Wizard::race() const {
        return static_cast<Race>(wi->race());
    }

    Banner Wizard::banner() const {
        return static_cast<Banner>(wi->banner());
    }
    
    Personality Wizard::personality() const { return static_cast<Personality>(wi->personality()); }
    void Wizard::personality(Personality p) { wi->personality(static_cast<int>(p)); }
    Objective Wizard::objective() const { return static_cast<Objective>(wi->objective()); }
    void Wizard::objective(Objective o) { wi->objective(static_cast<int>(o)); }
    int Wizard::fame() const { return wi->fame(); }
    void Wizard::fame(int f) { wi->fame(std::max(0, std::min(MaxFame, f))); }
    int Wizard::gold() const { return wi->gold(); }
    void Wizard::gold(int g) { wi->gold(std::max(0, std::min(MaxGold, g))); }
    int Wizard::mana() const { return wi->mana(); }
    void Wizard::mana(int m) { wi->mana(std::max(0, std::min(MaxMana, m))); }
    
    int Wizard::tomes(MagicSchool s) const {
        if(s >= MagicSchool::Arcane) {
            throw InvalidTomeSchoolException(static_cast<int>(s));
        }
        return wi->tomes(static_cast<int>(s));
    }
    
    void Wizard::tomes(MagicSchool s, int n) {
        if(s >= MagicSchool::Arcane) {
            throw InvalidTomeSchoolException(static_cast<int>(s));
        }
        wi->tomes(static_cast<int>(s), std::max(0, std::min(MaxTomesPerSchool, n)));
    }

}
