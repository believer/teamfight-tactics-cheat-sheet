type t = [
  | `BFSword
  | `RecurveBow
  | `NeedlesslyLargeRod
  | `TearOfTheGoddess
  | `ChainVest
  | `NegatronCloak
  | `GiantsBelt
  | `Spatula
];

let baseItems = [
  `BFSword,
  `RecurveBow,
  `NeedlesslyLargeRod,
  `TearOfTheGoddess,
  `ChainVest,
  `NegatronCloak,
  `GiantsBelt,
  `Spatula,
];

type item = {
  name: string,
  description: string,
  item: t,
};

let name =
  fun
  | `BFSword => "B.F. Sword"
  | `RecurveBow => "Recurve Bow"
  | `NeedlesslyLargeRod => "Needlessly Large Rod"
  | `TearOfTheGoddess => "Tear of the Goddess"
  | `ChainVest => "Chain Vest"
  | `NegatronCloak => "Negatron Cloak"
  | `GiantsBelt => "Giant's Belt"
  | `Spatula => "Spatula";

let effect: t => option(string) =
  fun
  | `BFSword => Some("+20 attack damage")
  | `RecurveBow => Some("+15% attack speed")
  | `NeedlesslyLargeRod => Some("+20% spell damage")
  | `TearOfTheGoddess => Some("+20 mana")
  | `ChainVest => Some("+20 armor")
  | `NegatronCloak => Some("+20 magic resist")
  | `GiantsBelt => Some("+200 health")
  | `Spatula => Some("It must do something...");

let base = [
  (name(`BFSword), `BFSword, effect(`BFSword)),
  (name(`RecurveBow), `RecurveBow, effect(`RecurveBow)),
  (
    name(`NeedlesslyLargeRod),
    `NeedlesslyLargeRod,
    effect(`NeedlesslyLargeRod),
  ),
  (name(`TearOfTheGoddess), `TearOfTheGoddess, effect(`TearOfTheGoddess)),
  (name(`ChainVest), `ChainVest, effect(`ChainVest)),
  (name(`NegatronCloak), `NegatronCloak, effect(`NegatronCloak)),
  (name(`GiantsBelt), `GiantsBelt, effect(`GiantsBelt)),
  (name(`Spatula), `Spatula, effect(`Spatula)),
];

let toItem: (t, t) => item =
  (first, second) =>
    switch (first, second) {
    /* Combined with self */
    | (`BFSword, `BFSword as item) => {
        name: "Infinity Edge",
        description: "Critical strikes deal +100.0% damage",
        item,
      }
    | (`RecurveBow, `RecurveBow as item) => {
        name: "Rapid Firecannon",
        description: "Wearer's attacks cannot be dodged. Attack range is doubled",
        item,
      }
    | (`NeedlesslyLargeRod, `NeedlesslyLargeRod as item) => {
        name: "Rabadon's Deathcap",
        description: "Wearer's spell damage stat is amplified by 50.0%",
        item,
      }
    | (`TearOfTheGoddess, `TearOfTheGoddess as item) => {
        name: "Seraph's Embrace",
        description: "Regain 20.0 mana each time a spell is cast",
        item,
      }
    | (`ChainVest, `ChainVest as item) => {
        name: "Thornmail",
        description: "Reflect 25% of damage taken from attacks",
        item,
      }
    | (`NegatronCloak, `NegatronCloak as item) => {
        name: "Dragon's Claw",
        description: "Gain 83% resistance to magic damage",
        item,
      }
    | (`GiantsBelt, `GiantsBelt as item) => {
        name: "Warmog's Armor",
        description: "Wearer regenerates 2.5% max health per second",
        item,
      }
    | (`Spatula, `Spatula as item) => {
        name: "Force of Nature",
        description: "Gain +1 team size",
        item,
      }
    /* BFSword */
    | (`RecurveBow, `BFSword as item)
    | (`BFSword, `RecurveBow as item) => {
        name: "Sword of the Divine",
        description: "Each second, the wearer has a 5.0% change to gain 100% critical strike",
        item,
      }
    | (`NeedlesslyLargeRod, `BFSword as item)
    | (`BFSword, `NeedlesslyLargeRod as item) => {
        name: "Hextech Gunblade",
        description: "Heal for 25.0% of all damage dealt",
        item,
      }
    | (`TearOfTheGoddess, `BFSword as item)
    | (`BFSword, `TearOfTheGoddess as item) => {
        name: "Spear of Shojin",
        description: "After casting, wearer gains 20.0% of its max mana per
          attack",
        item,
      }
    | (`ChainVest, `BFSword as item)
    | (`BFSword, `ChainVest as item) => {
        name: "Guardian Angel",
        description: "Wearer revives with 300.0 health",
        item,
      }
    | (`NegatronCloak, `BFSword as item)
    | (`BFSword, `NegatronCloak as item) => {
        name: "The Bloodthirster",
        description: "Attacks heal for % of damage",
        item,
      }
    | (`GiantsBelt, `BFSword as item)
    | (`BFSword, `GiantsBelt as item) => {
        name: "Zeke's Herald",
        description: "Adjacent allies gain +20.0% attack speed",
        item,
      }
    /* Recurve Bow */
    | (`NeedlesslyLargeRod, `RecurveBow as item)
    | (`RecurveBow, `NeedlesslyLargeRod as item) => {
        name: "Guinsoo's Rageblade",
        description: "Attacks grant 3.0% attack speed. Stacks infinitely",
        item,
      }
    | (`TearOfTheGoddess, `RecurveBow as item)
    | (`RecurveBow, `TearOfTheGoddess as item) => {
        name: "Statikk Shiv",
        description: "Every 3rd attack deals 100 splash magic damage",
        item,
      }
    | (`ChainVest, `RecurveBow as item)
    | (`RecurveBow, `ChainVest as item) => {
        name: "Phantom Dancer",
        description: "Wearer doges all critical strikes",
        item,
      }
    | (`NegatronCloak, `RecurveBow as item)
    | (`RecurveBow, `NegatronCloak as item) => {
        name: "Cursed Blade",
        description: "Attacks have a low change to Shrink (reduce enemy's star
          level by 1)",
        item,
      }
    | (`GiantsBelt, `RecurveBow as item)
    | (`RecurveBow, `GiantsBelt as item) => {
        name: "Titanic Hydra",
        description: "Attacks deal 10% of wearer's max health as splash damage",
        item,
      }
    /* Needlessly Large Rod */
    | (`TearOfTheGoddess, `NeedlesslyLargeRod as item)
    | (`NeedlesslyLargeRod, `TearOfTheGoddess as item) => {
        name: "Luden's Echo",
        description: "Spells deal 100 splash damage on hit",
        item,
      }
    | (`ChainVest, `NeedlesslyLargeRod as item)
    | (`NeedlesslyLargeRod, `ChainVest as item) => {
        name: "Locket of the Iron Solari",
        description: "On start of combat, all adjacent allies gain a shield of
          200",
        item,
      }
    | (`NegatronCloak, `NeedlesslyLargeRod as item)
    | (`NeedlesslyLargeRod, `NegatronCloak as item) => {
        name: "Ionic Spark",
        description: "Whenever an enemy casts a spell, they take 100 damage",
        item,
      }
    | (`GiantsBelt, `NeedlesslyLargeRod as item)
    | (`NeedlesslyLargeRod, `GiantsBelt as item) => {
        name: "Morellonomicon",
        description: "Spells deal burn damage equal to 5% of the enemy's maximum
          health per second",
        item,
      }
    /* Tear of the Goddess */
    | (`ChainVest, `TearOfTheGoddess as item)
    | (`TearOfTheGoddess, `ChainVest as item) => {
        name: "Frozen Heart",
        description: "Adjacent enemies lose 20% attack speed",
        item,
      }
    | (`NegatronCloak, `TearOfTheGoddess as item)
    | (`TearOfTheGoddess, `NegatronCloak as item) => {
        name: "Hush",
        description: "Attacks have a high chance to silence",
        item,
      }
    | (`GiantsBelt, `TearOfTheGoddess as item)
    | (`TearOfTheGoddess, `GiantsBelt as item) => {
        name: "Redemption",
        description: "On death, heal all nearby allies for 1000 health",
        item,
      }
    /* Chain vest */
    | (`NegatronCloak, `ChainVest as item)
    | (`ChainVest, `NegatronCloak as item) => {
        name: "Sword Breaker",
        description: "Attacks have a chance to disarm",
        item,
      }
    | (`GiantsBelt, `ChainVest as item)
    | (`ChainVest, `GiantsBelt as item) => {
        name: "Red Buff",
        description: "Attacks deal 2.5% burn damage",
        item,
      }
    /* Giants belt */
    | (`NegatronCloak, `GiantsBelt as item)
    | (`GiantsBelt, `NegatronCloak as item) => {
        name: "Zephyr",
        description: "On start of combat, banish an enemy for 5 seconds",
        item,
      }
    /* Spatula */
    | (`Spatula, `BFSword as item)
    | (`BFSword, `Spatula as item) => {
        name: "Youmuu's Ghostblade",
        description: "Wearer is also an Assassin",
        item,
      }
    | (`Spatula, `RecurveBow as item)
    | (`RecurveBow, `Spatula as item) => {
        name: "Blade of the Ruined King",
        description: "Wearer is also a Blademaster",
        item,
      }
    | (`Spatula, `NeedlesslyLargeRod as item)
    | (`NeedlesslyLargeRod, `Spatula as item) => {
        name: "Yuumi",
        description: "Wearer is also a Sorcerer",
        item,
      }
    | (`Spatula, `TearOfTheGoddess as item)
    | (`TearOfTheGoddess, `Spatula as item) => {
        name: "Darkin",
        description: "Wearer is also a Demon",
        item,
      }
    | (`Spatula, `ChainVest as item)
    | (`ChainVest, `Spatula as item) => {
        name: "Knight's Vow",
        description: "Wearer is also a Knight",
        item,
      }
    | (`Spatula, `NegatronCloak as item)
    | (`NegatronCloak, `Spatula as item) => {
        name: "Runaan's Hurricane",
        description: "Attacks target 2 additional enemies. These additional
          attack deal 50% damage",
        item,
      }
    | (`Spatula, `GiantsBelt as item)
    | (`GiantsBelt, `Spatula as item) => {
        name: "Frozen Mallet",
        description: "Wearer is also a Glacial",
        item,
      }
    };

let fromType: t => list(item) =
  fun
  | `BFSword as t => baseItems->Belt.List.map(toItem(t))
  | `RecurveBow as t => baseItems->Belt.List.map(toItem(t))
  | `NeedlesslyLargeRod as t => baseItems->Belt.List.map(toItem(t))
  | `TearOfTheGoddess as t => baseItems->Belt.List.map(toItem(t))
  | `GiantsBelt as t => baseItems->Belt.List.map(toItem(t))
  | `NegatronCloak as t => baseItems->Belt.List.map(toItem(t))
  | `Spatula as t => baseItems->Belt.List.map(toItem(t))
  | `ChainVest as t => baseItems->Belt.List.map(toItem(t));
