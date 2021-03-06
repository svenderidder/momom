//
//  UnitType.cpp
//  momom
//
//  Created by Sven de Ridder on 9/29/13.
//  Copyright (c) 2013 svenr. All rights reserved.
//

#include "UnitType.h"

namespace momom {
    
    bool isHeroUnitType(UnitType t) {
        return UnitType::HeroDwarf <= t && t <= UnitType::HeroChosen;
    }
    
    bool isRegularUnitType(UnitType t) {
        return UnitType::Trireme <= t && t <= UnitType::TrollWarMammoths;
    }
    
    bool isSummonedUnitType(UnitType t) {
        return UnitType::MagicSpirit <= t && t <= UnitType::Nagas;
    }
    
    const char* toString(UnitType t) {
        switch(t) {
        case UnitType::HeroDwarf: return "Dwarf (Hero)";
        case UnitType::HeroBarbarian: return "Barbarian (Hero)";
        case UnitType::HeroSage: return "Sage (Hero)";
        case UnitType::HeroDervish: return "Dervish (Hero)";
        case UnitType::HeroBeastmaster: return "Beastmaster (Hero)";
        case UnitType::HeroBard: return "Bard (Hero)";
        case UnitType::HeroOrcWarrior: return "Orc Warrior (Hero)";
        case UnitType::HeroHealer: return "Healer (Hero)";
        case UnitType::HeroHuntress: return "Huntress (Hero)";
        case UnitType::HeroThief: return "Thief (Hero)";
        case UnitType::HeroDruid: return "Druid (Hero)";
        case UnitType::HeroWarMonk: return "War Monk (Hero)";
        case UnitType::HeroWarriorMage: return "Warrior Mage (Hero)";
        case UnitType::HeroMagician: return "Magician (Hero)";
        case UnitType::HeroAssassin: return "Assassin (Hero)";
        case UnitType::HeroWindMage: return "Wind Mage (Hero)";
        case UnitType::HeroRanger: return "Ranger (Hero)";
        case UnitType::HeroDraconian: return "Draconian (Hero)";
        case UnitType::HeroWitch: return "Witch (Hero)";
        case UnitType::HeroGoldenOne: return "Golden One (Hero)";
        case UnitType::HeroNinja: return "Ninja (Hero)";
        case UnitType::HeroRogue: return "Rogue (Hero)";
        case UnitType::HeroAmazon: return "Amazon (Hero)";
        case UnitType::HeroWarlock: return "Warlock (Hero)";
        case UnitType::HeroUnknown: return "Unknown (Hero)";
        case UnitType::HeroIllusionist: return "Illusionist (Hero)";
        case UnitType::HeroSwordsman: return "Swordsman (Hero)";
        case UnitType::HeroPriestess: return "Priestess (Hero)";
        case UnitType::HeroPaladin: return "Paladin (Hero)";
        case UnitType::HeroBlackKnight: return "Black Knight (Hero)";
        case UnitType::HeroElvenArcher: return "Elven Archer (Hero)";
        case UnitType::HeroKnight: return "Knight (Hero)";
        case UnitType::HeroNecromancer: return "Necromancer (Hero)";
        case UnitType::HeroChaosWarrior: return "Chaos Warrior (Hero)";
        case UnitType::HeroChosen: return "Chosen (Hero)";
        case UnitType::Trireme: return "Trireme";
        case UnitType::Galley: return "Galley";
        case UnitType::Catapult: return "Catapult";
        case UnitType::Warship: return "Warship";
        case UnitType::BarbarianSpearmen: return "Barbarian Spearmen";
        case UnitType::BarbarianSwordsmen: return "Barbarian Swordsmen";
        case UnitType::BarbarianBowmen: return "Barbarian Bowmen";
        case UnitType::BarbarianCavalry: return "Barbarian Cavalry";
        case UnitType::BarbarianShaman: return "Barbarian Shaman";
        case UnitType::BarbarianSettlers: return "Barbarian Settlers";
        case UnitType::BarbarianBerserkers: return "Berserkers";
        case UnitType::BeastmanSpearmen: return "Beastman Spearmen";
        case UnitType::BeastmanSwordsmen: return "Beastman Swordsmen";
        case UnitType::BeastmanHalberdiers: return "Beastman Halberdiers";
        case UnitType::BeastmanBowmen: return "Beastman Bowmen";
        case UnitType::BeastmanPriests: return "Beastman Priests";
        case UnitType::BeastmanMagicians: return "Beastman Magicians";
        case UnitType::BeastmanEngineers: return "Beastman Engineers";
        case UnitType::BeastmanSettlers: return "Beastman Settlers";
        case UnitType::BeastmanCentaurs: return "Centaurs";
        case UnitType::BeastmanManticores: return "Manticores";
        case UnitType::BeastmanMinotaurs: return "Minotaurs";
        case UnitType::DarkElfSpearmen: return "Dark Elf Spearmen";
        case UnitType::DarkElfSwordsmen: return "Dark Elf Swordsmen";
        case UnitType::DarkElfHalberdiers: return "Dark Elf Halberdiers";
        case UnitType::DarkElfCavalry: return "Dark Elf Cavalry";
        case UnitType::DarkElfPriests: return "Dark Elf Priests";
        case UnitType::DarkElfSettlers: return "Dark Elf Settlers";
        case UnitType::DarkElfNightblades: return "Nightblades";
        case UnitType::DarkElfWarlocks: return "Dark Elf Warlocks";
        case UnitType::DarkElfNightmares: return "Nightmares";
        case UnitType::DraconianSpearmen: return "Draconian Spearmen";
        case UnitType::DraconianSwordsmen: return "Draconian Swordsmen";
        case UnitType::DraconianHalberdiers: return "Draconian Halberdiers";
        case UnitType::DraconianBowmen: return "Draconian Bowmen";
        case UnitType::DraconianShaman: return "Draconian Shaman";
        case UnitType::DraconianMagicians: return "Draconian Magicians";
        case UnitType::DraconianEngineers: return "Draconian Engineers";
        case UnitType::DraconianSettlers: return "Draconian Settlers";
        case UnitType::DraconianDoomDrakes: return "Doom Drakes";
        case UnitType::DraconianAirShip: return "Air Ship";
        case UnitType::DwarvenSwordsmen: return "Dwarven Swordsmen";
        case UnitType::DwarvenHalberdiers: return "Dwarven Halberdiers";
        case UnitType::DwarvenEngineers: return "Dwarven Engineers";
        case UnitType::DwarvenHammerhands: return "Dwarven Hammerhands";
        case UnitType::DwarvenSteamCannon: return "Dwarven Steam Cannon";
        case UnitType::DwarvenGolem: return "Golem";
        case UnitType::DwarvenSettlers: return "Dwarven Settlers";
        case UnitType::GnollSpearmen: return "Gnoll Spearmen";
        case UnitType::GnollSwordsmen: return "Gnoll Swordsmen";
        case UnitType::GnollHalberdiers: return "Gnoll Halberdiers";
        case UnitType::GnollBowmen: return "Gnoll Bowmen";
        case UnitType::GnollSettlers: return "Gnoll Settlers";
        case UnitType::GnollWolfRiders: return "Gnoll Wolf Riders";
        case UnitType::HalflingSpearmen: return "Halfling Spearmen";
        case UnitType::HalflingSwordsmen: return "Halfling Swordsmen";
        case UnitType::HalflingBowmen: return "Halfling Bowmen";
        case UnitType::HalflingShaman: return "Halfling Shaman";
        case UnitType::HalflingSettlers: return "Halfling Settlers";
        case UnitType::HalflingSlingers: return "Halfling Slingers";
        case UnitType::HighElfSpearmen: return "High Elf Spearmen";
        case UnitType::HighElfSwordsmen: return "High Elf Swordsmen";
        case UnitType::HighElfHalberdiers: return "High Elf Halberdiers";
        case UnitType::HighElfCavalry: return "High Elf Cavalry";
        case UnitType::HighElfMagicians: return "High Elf Magicians";
        case UnitType::HighElfSettlers: return "High Elf Settlers";
        case UnitType::HighElfLongbowmen: return "High Elf Longbowmen";
        case UnitType::HighElfElvenLords: return "Elven Lords";
        case UnitType::HighElfPegasai: return "Pegasai";
        case UnitType::HighManSpearmen: return "High Men Spearmen";
        case UnitType::HighManSwordsmen: return "High Men Swordsmen";
        case UnitType::HighManBowmen: return "High Men Bowmen";
        case UnitType::HighManCavalry: return "High Men Cavalry";
        case UnitType::HighManPriests: return "High Men Priests";
        case UnitType::HighManMagicians: return "High Men Magicians";
        case UnitType::HighManEngineers: return "High Men Engineers";
        case UnitType::HighManSettlers: return "High Men Settlers";
        case UnitType::HighManPikemen: return "High Men Pikemen";
        case UnitType::HighManPaladins: return "Paladins";
        case UnitType::KlackonSpearmen: return "Klackon Spearmen";
        case UnitType::KlackonSwordsmen: return "Klackon Swordsmen";
        case UnitType::KlackonHalberdiers: return "Klackon Halberdiers";
        case UnitType::KlackonEngineers: return "Klackon Engineers";
        case UnitType::KlackonSettlers: return "Klackon Settlers";
        case UnitType::KlackonStagBeetle: return "Stag Beetle";
        case UnitType::LizardmanSpearmen: return "Lizardmen Spearmen";
        case UnitType::LizardmanSwordsmen: return "Lizardmen Swordsmen";
        case UnitType::LizardmanHalberdiers: return "Lizardmen Halberdiers";
        case UnitType::LizardmanJavelineers: return "Lizardmen Javelineers";
        case UnitType::LizardmanShaman: return "Lizardmen Shaman";
        case UnitType::LizardmanSettlers: return "Lizardmen Settlers";
        case UnitType::LizardmanDragonTurtle: return "Dragon Turtle";
        case UnitType::NomadSpearmen: return "Nomad Spearmen";
        case UnitType::NomadSwordsmen: return "Nomad Swordsmen";
        case UnitType::NomadBowmen: return "Nomad Bowmen";
        case UnitType::NomadPriests: return "Nomad Priests";
        case UnitType::NomadMagicians: return "Nomad Magicians";
        case UnitType::NomadSettlers: return "Nomad Settlers";
        case UnitType::NomadHorsebowmen: return "Nomad Horsebowmen";
        case UnitType::NomadPikemen: return "Nomad Pikemen";
        case UnitType::NomadRangers: return "Rangers";
        case UnitType::NomadGriffins: return "Griffins";
        case UnitType::OrcSpearmen: return "Orc Spearmen";
        case UnitType::OrcSwordsmen: return "Orc Swordsmen";
        case UnitType::OrcHalberdiers: return "Orc Halberdiers";
        case UnitType::OrcBowmen: return "Orc Bowmen";
        case UnitType::OrcCavalry: return "Orc Cavalry";
        case UnitType::OrcShaman: return "Orc Shaman";
        case UnitType::OrcMagicians: return "Orc Magicians";
        case UnitType::OrcEngineers: return "Orc Engineers";
        case UnitType::OrcSettlers: return "Orc Settlers";
        case UnitType::OrcWyvernRiders: return "Wyvern Riders";
        case UnitType::TrollSpearmen: return "Troll Spearmen";
        case UnitType::TrollSwordsmen: return "Troll Swordsmen";
        case UnitType::TrollHalberdiers: return "Troll Halberdiers";
        case UnitType::TrollShaman: return "Troll Shaman";
        case UnitType::TrollSettlers: return "Troll Settlers";
        case UnitType::TrollWarTrolls: return "War Trolls";
        case UnitType::TrollWarMammoths: return "War Mammoths";
        case UnitType::MagicSpirit: return "Magic Spirit";
        case UnitType::Hellhounds: return "Hellhounds";
        case UnitType::Gargoyles: return "Gargoyles";
        case UnitType::FireGiant: return "Fire Giant";
        case UnitType::FireElemental: return "Fire Elemental";
        case UnitType::ChaosSpawn: return "Chaos Spawn";
        case UnitType::Chimera: return "Chimera";
        case UnitType::DoomBat: return "Doom Bat";
        case UnitType::Efreet: return "Efreet";
        case UnitType::Hydra: return "Hydra";
        case UnitType::GreatDrake: return "Great Drake";
        case UnitType::Skeletons: return "Skeletons";
        case UnitType::Ghouls: return "Ghouls";
        case UnitType::NightStalker: return "Night Stalker";
        case UnitType::Werewolves: return "Werewolves";
        case UnitType::Demon: return "Demon";
        case UnitType::Wraiths: return "Wraiths";
        case UnitType::ShadowDemons: return "Shadow Demons";
        case UnitType::DeathKnights: return "Death Knights";
        case UnitType::DemonLord: return "Demon Lord";
        case UnitType::Zombies: return "Zombies";
        case UnitType::Unicorns: return "Unicorns";
        case UnitType::GuardianSpirit: return "Guardian Spirit";
        case UnitType::Angel: return "Angel";
        case UnitType::ArchAngel: return "Arch Angel";
        case UnitType::WarBears: return "War Bears";
        case UnitType::Sprites: return "Sprites";
        case UnitType::Cockatrices: return "Cockatrices";
        case UnitType::Basilisk: return "Basilisk";
        case UnitType::GiantSpiders: return "Giant Spiders";
        case UnitType::StoneGiant: return "Stone Giant";
        case UnitType::Colossus: return "Colossus";
        case UnitType::Gorgons: return "Gorgons";
        case UnitType::EarthElemental: return "Earth Elemental";
        case UnitType::Behemoth: return "Behemoth";
        case UnitType::GreatWyrm: return "Great Wyrm";
        case UnitType::FloatingIsland: return "Floating Island";
        case UnitType::PhantomBeast: return "Phantom Beast";
        case UnitType::PhantomWarriors: return "Phantom Warriors";
        case UnitType::StormGiant: return "Storm Giant";
        case UnitType::AirElemental: return "Air Elemental";
        case UnitType::Djinn: return "Djinn";
        case UnitType::SkyDrake: return "Sky Drake";
        case UnitType::Nagas: return "Nagas";
        }
    }
    
    std::ostream& operator<<(std::ostream& os, UnitType t) {
        return os << toString(t);
    }
    
}