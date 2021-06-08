#pragma once
//Teleport Potion - T
const int teleportPotionDamage = 0;
const string name = "Teleport potion";
const string teleportPotionDescription = "Moves Alice 3 fields forward, or to the first free field. If the exit portal is less than 3 fields away - stay at current position";
const char teleportSign = 'T'; 
//Potion drink me - P
const int potionDrinkMeDamage = 10;
const string potionDrinkMeName = "Potion - Drink me ";
const string potionDrinkMeDescription = "Decreases Alice's damage";
const char potionDrinkMeSign = 'P'; 
//Cookie eat me - C
const int cookieEatMeDamage = 40;
const string cookieEatMeName = "Cookie - eat me ";
const string cookieEatMeDescription = "Increases Alice's damage";
const char cookieEatMeSign = 'C';
//Magic fan - M 
const int magicFanDamage = 35;
const string magicFanName = "Magic Fan";
const string magicFanDescription = "Decreases enemy and gives Alice advantage";
const char magicFanSign = 'M';
//Invisible hat - I
const int invisibleHatDamage = 0;
const string invisibleHatName = "Invisible Hat";
const string invisibleHatDescription = "Makes Alice invisible - she moves 2 fields forward, automatically defeating the rival.";
const char invisibleHatSign = 'I';

//Take a rose - R
const int defaultValue = 0;
const string takeARoseName = "Toss a rose";
const string takeARoseDescription = "Alice tosses a rose. Red - 40 damage, White - 10 damage";
const char takeARoseSign = 'R';

//--------------Enemies----------------
const int initialHp = 100; 


//Cheshire Cat - K(otka)
const const int caeshireCatDamage = 0;
const string caeshireCatName = "Caeshire Cat";
const char caeshireCatSign = 'K';

//Queen of Hearts - Q
const const int queenOfHeartsDamage = 20;
const string queenOfHeartsName = "Queen of hearts";
const char queenOfHeartsSign = 'Q';

//White rabbit - W
const const int whiteRabbitDamage = 25;
const string whiteRabbitName = "White rabbit";
const char whiteRabbitSign = 'W';

//Crazy hatter - H
const const int crazyHatterDamage = defaultValue;
const string crazyHatterName = "Crazy hatter";
const char crazyHatterSign = 'H';
