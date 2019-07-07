type item = [
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

module Item = {
  type t = {
    name: string,
    description: string,
    item,
  };

  let name: item => string =
    fun
    | `BFSword => "B.F. Sword"
    | `RecurveBow => "Recurve Bow"
    | `NeedlesslyLargeRod => "Needlessly Large Rod"
    | `TearOfTheGoddess => "Tear of the Goddess"
    | `ChainVest => "Chain Vest"
    | `NegatronCloak => "Negatron Cloak"
    | `GiantsBelt => "Giant's Belt"
    | `Spatula => "Spatula";

  let description: item => string =
    fun
    | `BFSword => "+20 attack damage"
    | `RecurveBow => "+15% attack speed"
    | `NeedlesslyLargeRod => "+20% spell damage"
    | `TearOfTheGoddess => "+20 mana"
    | `ChainVest => "+20 armor"
    | `NegatronCloak => "+20 magic resist"
    | `GiantsBelt => "+200 health"
    | `Spatula => "It must do something...";

  let make = item => {
    name: name(item),
    description: description(item),
    item,
  };

  let makeCombined = (~name, ~description, ~item) => {
    name,
    description,
    item,
  };
};

let base = baseItems->Belt.List.map(Item.make);

let toItem: (item, item) => Item.t =
  (first, second) => {
    let item = Item.makeCombined(~item=second);

    switch (first, second) {
    /* Combined with self */
    | (`BFSword, `BFSword) =>
      item(
        ~name="Infinity Edge",
        ~description="Critical strikes deal +100% damage",
      )
    | (`RecurveBow, `RecurveBow) =>
      item(
        ~name="Rapid Firecannon",
        ~description=
          "Wearer's attacks cannot be dodged. Attack range is doubled",
      )
    | (`NeedlesslyLargeRod, `NeedlesslyLargeRod) =>
      item(
        ~name="Rabadon's Deathcap",
        ~description="Wearer's spell damage stat is amplified by 50%",
      )
    | (`TearOfTheGoddess, `TearOfTheGoddess) =>
      item(
        ~name="Seraph's Embrace",
        ~description="Regain 20 mana each time a spell is cast",
      )
    | (`ChainVest, `ChainVest) =>
      item(
        ~name="Thornmail",
        ~description="Reflect 25% of damage taken from attacks",
      )
    | (`NegatronCloak, `NegatronCloak) =>
      item(
        ~name="Dragon's Claw",
        ~description="Gain 83% resistance to magic damage",
      )
    | (`GiantsBelt, `GiantsBelt) =>
      item(
        ~name="Warmog's Armor",
        ~description="Wearer regenerates 2.5% max health per second",
      )
    | (`Spatula, `Spatula) =>
      item(~name="Force of Nature", ~description="Gain +1 team size")
    /* BFSword */
    | (`RecurveBow, `BFSword)
    | (`BFSword, `RecurveBow) =>
      item(
        ~name="Sword of the Divine",
        ~description=
          "Each second, the wearer has a 5% change to gain 100% critical strike",
      )
    | (`NeedlesslyLargeRod, `BFSword)
    | (`BFSword, `NeedlesslyLargeRod) =>
      item(
        ~name="Hextech Gunblade",
        ~description="Heal for 25% of all damage dealt",
      )
    | (`TearOfTheGoddess, `BFSword)
    | (`BFSword, `TearOfTheGoddess) =>
      item(
        ~name="Spear of Shojin",
        ~description=
          "After casting, wearer gains 20% of its max mana per attack",
      )
    | (`ChainVest, `BFSword)
    | (`BFSword, `ChainVest) =>
      item(
        ~name="Guardian Angel",
        ~description="Wearer revives with 500 health",
      )
    | (`NegatronCloak, `BFSword)
    | (`BFSword, `NegatronCloak) =>
      item(
        ~name="The Bloodthirster",
        ~description="Attacks heal for 50% of damage",
      )
    | (`GiantsBelt, `BFSword)
    | (`BFSword, `GiantsBelt) =>
      item(
        ~name="Zeke's Herald",
        ~description="Adjacent allies gain +10% attack speed",
      )
    /* Recurve Bow */
    | (`NeedlesslyLargeRod, `RecurveBow)
    | (`RecurveBow, `NeedlesslyLargeRod) =>
      item(
        ~name="Guinsoo's Rageblade",
        ~description="Attacks grant 3% attack speed. Stacks infinitely",
      )
    | (`TearOfTheGoddess, `RecurveBow)
    | (`RecurveBow, `TearOfTheGoddess) =>
      item(
        ~name="Statikk Shiv",
        ~description="Every 3rd attack deals 100 splash magic damage",
      )
    | (`ChainVest, `RecurveBow)
    | (`RecurveBow, `ChainVest) =>
      item(
        ~name="Phantom Dancer",
        ~description="Wearer dodges all critical strikes",
      )
    | (`NegatronCloak, `RecurveBow)
    | (`RecurveBow, `NegatronCloak) =>
      item(
        ~name="Cursed Blade",
        ~description=
          "Attacks have a low change to Shrink (reduce enemy's star level by 1)",
      )
    | (`GiantsBelt, `RecurveBow)
    | (`RecurveBow, `GiantsBelt) =>
      item(
        ~name="Titanic Hydra",
        ~description=
          "Attacks deal 10% of wearer's max health as splash damage",
      )
    /* Needlessly Large Rod */
    | (`TearOfTheGoddess, `NeedlesslyLargeRod)
    | (`NeedlesslyLargeRod, `TearOfTheGoddess) =>
      item(
        ~name="Luden's Echo",
        ~description="Spells deal 100 splash damage on hit",
      )
    | (`ChainVest, `NeedlesslyLargeRod)
    | (`NeedlesslyLargeRod, `ChainVest) =>
      item(
        ~name="Locket of the Iron Solari",
        ~description=
          "On start of combat, all adjacent allies gain a shield of 200",
      )
    | (`NegatronCloak, `NeedlesslyLargeRod)
    | (`NeedlesslyLargeRod, `NegatronCloak) =>
      item(
        ~name="Ionic Spark",
        ~description="Whenever an enemy casts a spell, they take 100 damage",
      )
    | (`GiantsBelt, `NeedlesslyLargeRod)
    | (`NeedlesslyLargeRod, `GiantsBelt) =>
      item(
        ~name="Morellonomicon",
        ~description=
          "Spells deal burn damage equal to 5% of the enemy's maximum health per second",
      )
    /* Tear of the Goddess */
    | (`ChainVest, `TearOfTheGoddess)
    | (`TearOfTheGoddess, `ChainVest) =>
      item(
        ~name="Frozen Heart",
        ~description="Adjacent enemies lose 20% attack speed",
      )
    | (`NegatronCloak, `TearOfTheGoddess)
    | (`TearOfTheGoddess, `NegatronCloak) =>
      item(~name="Hush", ~description="Attacks have a high chance to silence")
    | (`GiantsBelt, `TearOfTheGoddess)
    | (`TearOfTheGoddess, `GiantsBelt) =>
      item(
        ~name="Redemption",
        ~description="On death, heal all nearby allies for 1000 health",
      )
    /* Chain vest */
    | (`NegatronCloak, `ChainVest)
    | (`ChainVest, `NegatronCloak) =>
      item(
        ~name="Sword Breaker",
        ~description="Attacks have a chance to disarm",
      )
    | (`GiantsBelt, `ChainVest)
    | (`ChainVest, `GiantsBelt) =>
      item(~name="Red Buff", ~description="Attacks deal 2.5% burn damage")
    /* Giants belt */
    | (`NegatronCloak, `GiantsBelt)
    | (`GiantsBelt, `NegatronCloak) =>
      item(
        ~name="Zephyr",
        ~description="On start of combat, banish an enemy for 5 seconds",
      )
    /* Spatula */
    | (`Spatula, `BFSword)
    | (`BFSword, `Spatula) =>
      item(
        ~name="Youmuu's Ghostblade",
        ~description="Wearer is also an Assassin",
      )
    | (`Spatula, `RecurveBow)
    | (`RecurveBow, `Spatula) =>
      item(
        ~name="Blade of the Ruined King",
        ~description="Wearer is also a Blademaster",
      )
    | (`Spatula, `NeedlesslyLargeRod)
    | (`NeedlesslyLargeRod, `Spatula) =>
      item(~name="Yuumi", ~description="Wearer is also a Sorcerer")
    | (`Spatula, `TearOfTheGoddess)
    | (`TearOfTheGoddess, `Spatula) =>
      item(~name="Darkin", ~description="Wearer is also a Demon")
    | (`Spatula, `ChainVest)
    | (`ChainVest, `Spatula) =>
      item(~name="Knight's Vow", ~description="Wearer is also a Knight")
    | (`Spatula, `NegatronCloak)
    | (`NegatronCloak, `Spatula) =>
      item(
        ~name="Runaan's Hurricane",
        ~description=
          "Attacks target 2 additional enemies. These additional attack deal 50% damage",
      )
    | (`Spatula, `GiantsBelt)
    | (`GiantsBelt, `Spatula) =>
      item(~name="Frozen Mallet", ~description="Wearer is also a Glacial")
    };
  };

let fromType = t => baseItems->Belt.List.map(toItem(t));
