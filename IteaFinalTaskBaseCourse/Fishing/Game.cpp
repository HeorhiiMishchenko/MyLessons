#include "Game.h"

    void Game::paidTime() {
        int coins {};

        std::cout << "The game ends as soon as you catch more fish than you paid for or if time runs out" << std::endl;
        std::cout << "1 minute of fishing costs 10 coins. " << std::endl;
        std::cout << "The maximum weight of fish that you can catch is equivalent to the number of coins." << std::endl << std::endl;;
        std::cout << "Please enter the number of coins you have deposited for the game" << std::endl << std::endl;
        std::cout << "Your coins: ";
        std::cin >> coins;
        fishingTime_ = coins / 10;
        paidFishWeight_ = coins;
        std::cout << "You deposited " << coins << " coins. Game time - " << fishingTime_ << " minutes." << std::endl;
        std::cout << "You can catch no more than " << coins << " kg of fish" << std::endl;
        std::cout << "Have a good game!" << std::endl << std::endl;
    }

    void Game::chooseFish( int& currentFishWeight, std::string& currentFishName, bool& baitPreferenses ) {

        enum Fishes {
            CrucianFish,
            PerchFish,
            PikeFish,
        };

        int choiseFish = rand() % 3;

        switch( choiseFish ) {
            case CrucianFish:
                currentFishName = crucian_.getFishName();
                currentFishWeight = crucian_.getFishWeight();
                baitPreferenses = crucian_.baitPreferenses( nameBait_ );
                break;
            case PerchFish:
                currentFishName = perch_.getFishName();
                currentFishWeight = perch_.getFishWeight();
                baitPreferenses = perch_.baitPreferenses( nameBait_ );
                break;
            case PikeFish:
                currentFishName = pike_.getFishName();
                currentFishWeight = pike_.getFishWeight();
                baitPreferenses = pike_.baitPreferenses( nameBait_ );
                break;
            default:
                std::cout << "choiseFish fault";
                break;
        }
    }

    Game::Game( DataFish& fish, DataWater& water, DataBait& bait )
        : river_ { water.river },
        lake_ { water.lake },
        reservoir_ { water.reservoir },
        crucian_ { fish.crucian },
        perch_ { fish.perch },
        pike_ { fish.pike },
        bloodworm_ { bait.bloodworm },
        earthworm_ { bait.earthworm },
        maggot_ { bait.maggot }

    {
        paidTime();
        chooseWater();
        chooseBait();
    }

    int Game::getPaidFishWeight() {
        return paidFishWeight_;
    }

    int Game::getCurrentFishWeight() {
        return totalFishWeight_;
    }

    int Game::getCurrentFishingTime() {
        return fishingTime_;
    }

    void Game::checkCurrentCatch() {
        std::cout << "Your current catch:" << std::endl;
        for( auto& i : currentCatch_ ) {
            std::cout << i.second << ", " << i.first << " kilograms" << std::endl;
        }
    }

    std::vector <std::pair <int, std::string>> Game::getCurrentCatch() {
        return currentCatch_;
    }

    void Game::chooseWater() {
        int chooseWater {};
        enum Water {
            RiverWater = 1,
            LakeWater,
            ReservoirWater
        };
        std::cout << "Please, choose water what you want to fish: 1 - River, 2 - Lake, 3 - Reservoir" << std::endl;
        while( true ) {
            std::cin >> chooseWater;

            switch( chooseWater ) {
                case RiverWater:
                    std::cout << "You will fish in the river" << std::endl;
                    catchingFishChance_ = river_.getCatchingFishChance();
                    nameWater_ = river_.getWaterName();

                    return;
                case LakeWater:
                    std::cout << "You will fish in the lake" << std::endl;
                    catchingFishChance_ = lake_.getCatchingFishChance();
                    nameWater_ = lake_.getWaterName();
                    return;
                case ReservoirWater:
                    std::cout << "You will fish in the reservoir" << std::endl;
                    catchingFishChance_ = reservoir_.getCatchingFishChance();
                    nameWater_ = reservoir_.getWaterName();
                    return;
                default:
                    std::cout << "You enter wront number! Please try again!" << std::endl;
                    break;
            }
        }
    }

    void Game::chooseBait() {
        int chooseBait {};
        enum Bait {
            BloodwormBait = 1,
            EarthwormBait,
            MaggotBait
        };
        std::cout << "Please, choose bait what you want to use: 1 - Bloodworm, 2 - Earthworm, 3 - Maggot" << std::endl;
        while( true ) {
            std::cin >> chooseBait;

            switch( chooseBait ) {
                case BloodwormBait:
                    std::cout << "You will fish with bloodworm" << std::endl;
                    nameBait_ = bloodworm_.getBaitName();
                    catchBonus_ = bloodworm_.getCatchBonus();
                    return;
                case EarthwormBait:
                    std::cout << "You will fish with earthworm" << std::endl;
                    nameBait_ = earthworm_.getBaitName();
                    catchBonus_ = earthworm_.getCatchBonus();
                    return;
                case MaggotBait:
                    std::cout << "You will fish with maggot" << std::endl;
                    nameBait_ = maggot_.getBaitName();
                    catchBonus_ = maggot_.getCatchBonus();
                    return;
                default:
                    std::cout << "You enter wront number! Please try again!" << std::endl;
                    break;
            }
        }
    }

    void Game::catching() {
        auto waitTime = std::chrono::milliseconds( 2000 );
        const int maybeCatched { 50 };
        const int catched { 70 };
        int currentFishWeight;
        std::string currentFishName;
        bool baitPreferenses {};
        bool fishPresence {};

        if( nameWater_ == "River" ) {
            fishPresence = river_.fishPresence( currentFishName );
        } else if( nameWater_ == "Lake" ) {
            fishPresence = lake_.fishPresence( currentFishName );
        } else if( nameWater_ == "Reservoir" ) {
            fishPresence = reservoir_.fishPresence( currentFishName );
        } else {
            std::cout << "fishPresence definition fault" << std::endl;
        }

        for( int i {}; i < 3; i++ ) {
            int catching {};
            chooseFish( currentFishWeight, currentFishName, baitPreferenses );

            if( baitPreferenses && fishPresence ) {
                catching = rand() % 101 + catchingFishChance_ + catchBonus_;
            } else {
                catching = 0;
            }

            std::cout << "Press any key to cast your line" << std::endl;
            system( "pause" );

            std::this_thread::sleep_for( waitTime );

            if( catching < maybeCatched ) {
                std::cout << "The fish are not biting, recast the bait" << std::endl;
            } else if( catching >= maybeCatched && catching < catched ) {
                std::cout << "You caught a fish! Press any key to pull it out!" << std::endl;
                system( "pause" );
                if( rand() % 100 < 50 ) {
                    std::cout << "Ohh, the fish is off the hook, recast the bait" << std::endl;
                } else {
                    std::cout << "Congratulation! You caught " << currentFishName << "! ";
                    std::cout << "It's weight is " << currentFishWeight << std::endl;
                    totalFishWeight_ += currentFishWeight;
                    currentCatch_.emplace_back( currentFishWeight, currentFishName );

                    std::cout << "Total weight of your fish is " << totalFishWeight_ << std::endl;
                    return;
                }
            } else {
                std::cout << "You caught a fish! Press any key to pull it out!" << std::endl;
                system( "pause" );
                std::cout << "Congratulation! You caught " << currentFishName << "! ";
                std::cout << "It's weight is " << currentFishWeight << std::endl;

                totalFishWeight_ += currentFishWeight;
                currentCatch_.emplace_back( currentFishWeight, currentFishName );

                std::cout << "Total weight of your fish is " << totalFishWeight_ << std::endl;
                return;
            }
        }
    }
