#pragma once
#include <string>


class Water {
public:
    std::string getWaterName();

    int getCatchingFishChance();

    void setWaterName( const std::string& name );

    void setcatchingFishChance( int chance );

    virtual bool fishPresence( std::string fishName ) = 0;

protected:
    int catchingFishChance_ {};
    std::string waterName_ {};
};

class River :public Water {
public:
    bool fishPresence( const std::string fishName ) override;
};

class Lake : public Water {
public:
    bool fishPresence( const std::string fishName ) override;
};

class Reservoir : public Water {
public:
    bool fishPresence( const std::string fishName [[maybe_unused]] ) override;
};