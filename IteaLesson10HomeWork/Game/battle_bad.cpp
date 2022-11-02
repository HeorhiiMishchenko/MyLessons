#include <iostream>

class Person {
public:
    enum Item{
        Sword = 0,
        Armor,
        firstAidKit,
        Count
    };

    void getItem() {
        Item item { static_cast< Item > ( rand() % Item::Count ) };
        const auto sizeOfItem{ rand() % maxSizeOfItem + 1 };

        itemPair = { item, sizeOfItem };
    }

    std::pair< Item, int > getItemPair() {
        return itemPair;
    }

    int getLife() {
        return life;
    }

protected:
    std::pair< Item, int > itemPair;
    int life = 100;
    int maxAttack = 10;

private:
    static constexpr int maxSizeOfItem = 5;
};

class Hero : public Person{
public:
    int attack()
    {
        int addAttack{ itemPair.first == Item::Sword ? itemPair.second : 0 };
        int attackValue{ rand() % (maxAttack + 1) + addAttack };
        return attackValue;
    }

    void takeDamage( int damage )                                                   
    {
        if (rand() % 3 == 0) {                                              //33% dodge chance is Hero's bonus
            std::cout << "Hero dodged!" << std::endl;
            return;
        }                                                            


        if ( itemPair.first == Item::Armor ) {

            if (damage <= itemPair.second)                                  //if Armor's value is bigger than damage - damage completely blocked
                damage = 0;
            else
                damage -= itemPair.second;

            std::cout << "Damage to Hero is " << damage << std::endl;

            life -=  damage;

            std::cout << "Hero's health after damage is " << life << std::endl;
            return;
        }

        std::cout << "Damage to Hero is " << damage << std::endl;

        life -= damage;

        if(life < 0)
            std::cout << "Hero's health after damage is 0" << std::endl;
        else
            std::cout << "Hero's health after damage is " << life << std::endl;

        if (itemPair.first == firstAidKit && life > 0) {                    //firstAidKit works if hero has it and he is alive
            life += itemPair.second;
            std::cout << "Hero's health after healing is " << life << std::endl;
        }
    }   
};

class Monster : public Person{
public:
    int attack()
    {
        int attackValue{ rand() % maxAttack++ + 1 };                        //Moster's max attack becomes more by 1 after every attack - Moster's bonus 
        std::cout << "Monster attack is " << attackValue << std::endl;
        return attackValue;
    }

    void takeDamage( int damage )
    {
        if ( itemPair.first == Item::Armor )
        {
            if (damage <= itemPair.second)                                  //if Armor's value is bigger than damage - damage completely blocked 
                damage = 0;
            else
                damage -= itemPair.second;
            std::cout << "Damage to Monster is " << damage << std::endl;

            life -= damage;

            std::cout << "Monster's health after damage is " << life << std::endl;

            return;
        }

        std::cout << "Damage to Monster is " << damage << std::endl;

        life -= damage;

        if (life < 0)
            std::cout << "Monster's health after damage is 0" << std::endl;
        else
            std::cout << "Monster's health after damage is " << life << std::endl;
    }
};

int main()
{
    srand( time( nullptr ) );

    Hero hero;
    Monster monster;

    hero.getItem();
    monster.getItem();

    const std::pair< Hero::Item, int > heroItem{ hero.getItemPair() };
    const std::pair< Monster::Item, int > monsterItem{ monster.getItemPair() };

    switch (heroItem.first) {
    case Hero::Item::Sword:
        std::cout << "Hero's item is Sword with " << heroItem.second << " attack bonus" << std::endl;
        break;
    case Hero::Item::Armor:
        std::cout << "Hero's item is Armor with " << heroItem.second << " defence bonus" << std::endl;
        break;
    case Hero::Item::firstAidKit:
        std::cout << "Hero's item is First Aid Kit with " << heroItem.second << " healing bonus" << std::endl;
        break;
    default:
        std::cout << "Hero hasn't item" << std::endl;
        break;
    }

    if (monsterItem.first == Monster::Item::Armor)
        std::cout << "Monster's item is Armor with " << monsterItem.second << " defence bonus" << std::endl;
    else
        std::cout << "Monster hasn't item" << std::endl;

    std::cout << std::endl;
    system("pause");
    std::cout << std::endl;

    while (true)
    {
        int heroAttack{ hero.attack() };

        std::cout << "Hero attack is " << heroAttack << std::endl;

        monster.takeDamage(heroAttack);

        if( monster.getLife() <=0 )
        {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Hero is win!!!" << std::endl;

            return 0;
        }

        std::cout << std::endl;

        hero.takeDamage( monster.attack() );

        if( hero.getLife() <=0 )
        {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Monster is win!!!" << std::endl;

            return 0;
        }

        std::cout << std::endl;
        system("pause");
        std::cout << std::endl;
    }

    return 0;
}
