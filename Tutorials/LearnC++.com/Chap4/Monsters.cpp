#include <iostream>
#include <string>


enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANTSPIDER,
    SLIME
};


struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

void printMonster(Monster monster)
{
    std::cout << "This "; 
    if (monster.type == MonsterType::OGRE)
        std::cout << "Ogre";
    else if (monster.type == MonsterType::DRAGON)
        std::cout << "Dragon";
    else if (monster.type == MonsterType::ORC)
        std::cout << "Orc";
    else if (monster.type == MonsterType::GIANTSPIDER)
        std::cout << "Giant Spider";
    else if (monster.type == MonsterType::SLIME)
        std::cout << "Slime";
    std::cout << " is named " << monster.name << " and has " << monster.health << " health.\n";
}


int main()
{
    Monster monster1 = {MonsterType::OGRE, "Torg", 145};
    Monster monster2 = {MonsterType::SLIME, "Blurp", 23};
    printMonster(monster1);
    printMonster(monster2);
    
    return 0;
}
