#include "Bait.h"

    int Bait::getCatchBonus() {
        return catchBonus_;
    }

    std::string Bait::getBaitName() {
        return baitName_;
    }

    void Bait::setBaitName( const std::string& name ) {
        baitName_ = name;
    }

    void Bait::setCatchBonus( int bonus ) {
        catchBonus_ = bonus;
    }
