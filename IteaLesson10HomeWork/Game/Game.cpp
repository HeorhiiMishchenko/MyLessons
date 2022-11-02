#include <iostream>

class Person {
public:
    void setLife( int life ) {
        life_ = life;
    }

    int getLife() {
        return life_;
    }

    int attack() {
        return rand() % maxAttack_ + minAttack_ + weaponAttackValue_;
    }

    void getDamage( int damage ) {
        if( damage <= shieldDefenceValue_ )
            damage = 0;
        else
            damage -= shieldDefenceValue_;

        life_ -= damage;
    }

protected:
    void getWarriorWeapon() {
        int choise {};

        while( true ) {
            std::cout << "Choose you weapon: 1 - Axe, 2 - Sword. Your choise is ";
            std::cin >> choise;

            switch( choise ) {
            case Fist:
                weaponAttackValue_ = fistAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case Axe:
                weaponAttackValue_ = axeAttack_;
                std::cout << "Weapon is Axe with " << axeAttack_ << " attack bonus" << std::endl;
                return;
            case Sword:
                weaponAttackValue_ = swordAttack_;
                std::cout << "Weapon is Sword with " << swordAttack_ << " attack bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrong symbol! Please, try again!" << std::endl;
                break;
            }
        }
    }

    void getShield() {
        int choise {};

        while( true ) {
            std::cout << "Choose you shield: 1 - WoodenShield, 2 - MetalShield. Your choise is ";
            std::cin >> choise;

            switch( choise ) {
            case NoShield:
                shieldDefenceValue_ = noShieldProtection_;
                std::cout << "No shield" << std::endl;
                return;
            case WoodenShield:
                shieldDefenceValue_ = woodenShieldProtection_;
                std::cout << "Wooden Shield with " << woodenShieldProtection_ << " protect bonus" << std::endl;
                return;
            case MetalShield:
                shieldDefenceValue_ = metalShieldProtection_;
                std::cout << "Metal Shield with " << metalShieldProtection_ << " protect bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrong symbol! Please, try again!" << std::endl;
                break;
            }
        }

    }

    void getMagicWeapon() {
        int choise {};

        while( true ) {
            std::cout << "Choose you magic weapon: 1 - Spell, 2 - Magic Stick. Your choise is ";
            std::cin >> choise;

            switch( choise ) {
            case NoWeapon:
                weaponAttackValue_ = noWeaponAttack_;
                std::cout << "No weapon" << std::endl;
                return;
            case BattleSpell:
                weaponAttackValue_ = spellAttack_;
                std::cout << "Weapon is Spell with " << spellAttack_ << " attack bonus" << std::endl;
                return;
            case MagicStick:
                weaponAttackValue_ = magicStickAttack_;
                std::cout << "Weapon is Magic Stick with " << magicStickAttack_ << " attack bonus" << std::endl;
                return;
            default:
                std::cout << "You ented wrong symbol! Please, try again!" << std::endl;
                break;
            }
        }
    }

protected:
    //for all
    int weaponAttackValue_ {};
    int shieldDefenceValue_ {};
    static constexpr int minAttack_ { 1 };
    static constexpr int maxAttack_ { 10 };

    //for Warrior and Combat Sorcer
    enum WarriorWeapon {
        Fist,
        Axe,
        Sword,
    };

    enum Shield {
        NoShield,
        WoodenShield,
        MetalShield,
    };

    static constexpr int fistAttack_ { };
    static constexpr int axeAttack_ { 7 };
    static constexpr int swordAttack_ { 10 };

    static constexpr int noShieldProtection_ { };
    static constexpr int woodenShieldProtection_ { 3 };
    static constexpr int metalShieldProtection_ { 7 };

    //for Sorcerer
    enum SorcererWeapon {
        NoWeapon,
        BattleSpell,
        MagicStick,
    };

    static constexpr int noWeaponAttack_ { };
    static constexpr int spellAttack_ { 10 };
    static constexpr int magicStickAttack_ { 13 };

private:
    int life_ {};
};

class Warrior : public Person {
public:
    Warrior() {
        setLife( warriorsLife_ );
        getWarriorWeapon();
        getShield();
    }

private:
    int warriorsLife_ { 150 };
};

class Sorcerer : public Person {
public:
    Sorcerer() {
        setLife( sorcerersLife_ );
        getMagicWeapon();
    }

private:
    int sorcerersLife_ { 100 };
};

class CombatSorcerer : public Person {
public:
    CombatSorcerer() {
        setLife( combatSorcerersLife_ );
        getCombatSorcererWeapon();
        getShield();
    }

    void getCombatSorcererWeapon() {
        int choise {};

        while( true ) {
            std::cout << "Do you want Warrior's weapon or Magic weapon? 1 - Warrior's weapon, 2 - Magic weapon. Your choise is ";
            std::cin >> choise;
            switch( choise ) {
            case 1:
                getWarriorWeapon();
                return;
            case 2:
                getMagicWeapon();
                return;
            default:
                std::cout << "You ented wrong symbol! Please, try again!" << std::endl;
                break;
            }

        }
    }

private:
    int combatSorcerersLife_ { 90 };
};


int main() {
    srand( time( nullptr ) );

    std::cout << "Choose the equipment for your Hero" << std::endl;
    CombatSorcerer hero;
    std::cout << std::endl;

    std::cout << "Choose the equipment for antagonist" << std::endl;
    Sorcerer antagonist;
    std::cout << std::endl;

    while( true ) {
        int heroAttack { hero.attack() };
        std::cout << "Hero attacks is " << heroAttack << std::endl;

        antagonist.getDamage( heroAttack );

        if( antagonist.getLife() <= 0 ) {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Antagonist is dead. Hero won!!!" << std::endl;

            return 0;
        }

        std::cout << "Antagonist's health after damage is " << antagonist.getLife() << std::endl;

        std::cout << std::endl;

        int antagonistAttack { antagonist.attack() };

        std::cout << "Antagonist attack is " << antagonistAttack << std::endl;

        hero.getDamage( antagonistAttack );

        if( hero.getLife() <= 0 ) {
            std::cout << std::endl << "------------------------------------------------" << std::endl;
            std::cout << "Hero is dead. Antagonist won!!!" << std::endl;

            return 0;
        }

        std::cout << "Hero's health after damage is " << hero.getLife() << std::endl;

        std::cout << std::endl;
        system( "pause" );
        std::cout << std::endl;
    }

    return 0;
}
