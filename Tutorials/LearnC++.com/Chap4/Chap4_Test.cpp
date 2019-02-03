#include <iostream>

enum class MonsterType{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct Monster
{
	MonsterType type;	
	std::string name;
	int health;
};

std::string getMonsterTypeString(Monster monster)
{
	if (monster.type == MonsterType::OGRE)
		return "Ogre";
	else if (monster.type == MonsterType::DRAGON)
		return "Dragon";
	else if (monster.type == MonsterType::SLIME)
		return "Slime";

	return "Unknown";
};

void printMonster(Monster monster)
{ 
	std::cout << "This " << getMonsterTypeString(monster) << " is named " << monster.name << " and has " << monster.health << " health.\n";	
};

int main () 
{

	Monster ogre = {MonsterType::OGRE, "Torg", 145};
	Monster slime = {MonsterType::SLIME, "Blurp", 23};
	
	printMonster(ogre);
	printMonster(slime);

	return 0;
}