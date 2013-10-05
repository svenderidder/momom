//
//  UnitType.h
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#ifndef momom_UnitType_h
#define momom_UnitType_h

#include <ostream>

namespace momom {
    
    enum class UnitType {
        
        // Heroes
        HeroDwarf = 0,
        HeroBarbarian = 1,
        HeroSage = 2,
        HeroDervish = 3,
        HeroBeastmaster = 4,
        HeroBard = 5,
        HeroOrcWarrior = 6,
        HeroHealer = 7,
        HeroHuntress = 8,
        HeroThief = 9,
        HeroDruid = 10,
        HeroWarMonk = 11,
        HeroWarriorMage = 12,
        HeroMagician = 13,
        HeroAssassin = 14,
        HeroWindMage = 15,
        HeroRanger = 16,
        HeroDraconian = 17,
        HeroWitch = 18,
        HeroGoldenOne = 19,
        HeroNinja = 20,
        HeroRogue = 21,
        HeroAmazon = 22,
        HeroWarlock = 23,
        HeroUnknown = 24,
        HeroIllusionist = 25,
        HeroSwordsman = 26,
        HeroPriestess = 27,
        HeroPaladin = 28,
        HeroBlackKnight = 29,
        HeroElvenArcher = 30,
        HeroKnight = 31,
        HeroNecromancer = 32,
        HeroChaosWarrior = 33,
        HeroChosen = 34,
        
        // General units
        Trireme = 35,
        Galley = 36,
        Catapult = 37,
        Warship = 38,
        
        // Barbarian units
        BarbarianSpearmen = 39,
        BarbarianSwordsmen = 40,
        BarbarianBowmen = 41,
        BarbarianCavalry = 42,
        BarbarianShaman = 43,
        BarbarianSettlers = 44,
        BarbarianBerserkers = 45,
        
        // Beastman units
        BeastmanSpearmen = 46,
        BeastmanSwordsmen = 47,
        BeastmanHalberdiers = 48,
        BeastmanBowmen = 49,
        BeastmanPriests = 50,
        BeastmanMagicians = 51,
        BeastmanEngineers = 52,
        BeastmanSettlers = 53,
        BeastmanCentaurs = 54,
        BeastmanManticores = 55,
        BeastmanMinotaurs = 56,
        
        // Dark Elf units
        DarkElfSpearmen = 57,
        DarkElfSwordsmen = 58,
        DarkElfHalberdiers = 59,
        DarkElfCavalry = 60,
        DarkElfPriests = 61,
        DarkElfSettlers = 62,
        DarkElfNightblades = 63,
        DarkElfWarlocks = 64,
        DarkElfNightmares = 65,
        
        // Draconian units
        DraconianSpearmen = 66,
        DraconianSwordsmen = 67,
        DraconianHalberdiers = 68,
        DraconianBowmen = 69,
        DraconianShaman = 70,
        DraconianMagicians = 71,
        DraconianEngineers = 72,
        DraconianSettlers = 73,
        DraconianDoomDrakes = 74,
        DraconianAirShip = 75,
        
        // Dwarven units
        DwarvenSwordsmen = 76,
        DwarvenHalberdiers = 77,
        DwarvenEngineers = 78,
        DwarvenHammerhands = 79,
        DwarvenSteamCannon = 80,
        DwarvenGolem = 81,
        DwarvenSettlers = 82,
        
        // Gnoll units
        GnollSpearmen = 83,
        GnollSwordsmen = 84,
        GnollHalberdiers = 85,
        GnollBowmen = 86,
        GnollSettlers = 87,
        GnollWolfRiders = 88,
        
        // Halfling units
        HalflingSpearmen = 89,
        HalflingSwordsmen = 90,
        HalflingBowmen = 91,
        HalflingShaman = 92,
        HalflingSettlers = 93,
        HalflingSlingers = 94,
        
        // High Elf units
        HighElfSpearmen = 95,
        HighElfSwordsmen = 96,
        HighElfHalberdiers = 97,
        HighElfCavalry = 98,
        HighElfMagicians = 99,
        HighElfSettlers = 100,
        HighElfLongbowmen = 101,
        HighElfElvenLords = 102,
        HighElfPegasai = 103,
        
        // High Man units
        HighManSpearmen = 104,
        HighManSwordsmen = 105,
        HighManBowmen = 106,
        HighManCavalry = 107,
        HighManPriests = 108,
        HighManMagicians = 109,
        HighManEngineers = 110,
        HighManSettlers = 111,
        HighManPikemen = 112,
        HighManPaladins = 113,
        
        // Klackon units
        KlackonSpearmen = 114,
        KlackonSwordsmen = 115,
        KlackonHalberdiers = 116,
        KlackonEngineers = 117,
        KlackonSettlers = 118,
        KlackonStagBeetle = 119,
        
        // Lizardman units
        LizardmanSpearmen = 120,
        LizardmanSwordsmen = 121,
        LizardmanHalberdiers = 122,
        LizardmanJavelineers = 123,
        LizardmanShaman = 124,
        LizardmanSettlers = 125,
        LizardmanDragonTurtle = 126,
        
        // Nomad units
        NomadSpearmen = 127,
        NomadSwordsmen = 128,
        NomadBowmen = 129,
        NomadPriests = 130,
        NomadMagicians = 131,
        NomadSettlers = 132,
        NomadHorsebowmen = 133,
        NomadPikemen = 134,
        NomadRangers = 135,
        NomadGriffins = 136,
        
        // Orc units
        OrcSpearmen = 137,
        OrcSwordsmen = 138,
        OrcHalberdiers = 139,
        OrcBowmen = 140,
        OrcCavalry = 141,
        OrcShaman = 142,
        OrcMagicians = 143,
        OrcEngineers = 144,
        OrcSettlers = 145,
        OrcWyvernRiders = 146,
        
        // Troll units
        TrollSpearmen = 147,
        TrollSwordsmen = 148,
        TrollHalberdiers = 149,
        TrollShaman = 150,
        TrollSettlers = 151,
        TrollWarTrolls = 152,
        TrollWarMammoths = 153,
        
        // Arcane units
        MagicSpirit = 154,
        
        // Chaos units
        Hellhounds = 155,
        Gargoyles = 156,
        FireGiant = 157,
        FireElemental = 158,
        ChaosSpawn = 159,
        Chimera = 160,
        DoomBat = 161,
        Efreet = 162,
        Hydra = 163,
        GreatDrake = 164,
        
        // Death units
        Skeletons = 165,
        Ghouls = 166,
        NightStalker = 167,
        Werewolves = 168,
        Demon = 169,
        Wraiths = 170,
        ShadowDemons = 171,
        DeathKnights = 172,
        DemonLord = 173,
        Zombies = 174,
        
        // Life units
        Unicorns = 175,
        GuardianSpirit = 176,
        Angel = 177,
        ArchAngel = 178,
        
        // Nature units
        WarBears = 179,
        Sprites = 180,
        Cockatrices = 181,
        Basilisk = 182,
        GiantSpiders = 183,
        StoneGiant = 184,
        Colossus = 185,
        Gorgons = 186,
        EarthElemental = 187,
        Behemoth = 188,
        GreatWyrm = 189,
        
        // Sorcery units
        FloatingIsland = 190,
        PhantomBeast = 191,
        PhantomWarriors = 192,
        StormGiant = 193,
        AirElemental = 194,
        Djinn = 195,
        SkyDrake = 196,
        Nagas = 197
    };
    
    bool isHeroUnitType(UnitType);
    bool isRegularUnitType(UnitType);
    bool isSummonedUnitType(UnitType);
    
    const char* toString(UnitType);
    
    std::ostream& operator<<(std::ostream&, UnitType);
    
}

#endif
