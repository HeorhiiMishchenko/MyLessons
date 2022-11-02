#pragma once
#include <string>

class Bait {
public:
    int getCatchBonus();
    std::string getBaitName();
    void setBaitName( const std::string& name );
    void setCatchBonus( int bonus );

protected:
    int catchBonus_ {};
    std::string baitName_ {};
};
