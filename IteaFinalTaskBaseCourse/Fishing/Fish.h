#pragma once

#include <string>

class Fish {
public:
    unsigned int getFishWeight();
    std::string getFishName();
    void setFishName( const std::string& name );
    void setMinMaxFishWeight( int min, int max );
    virtual bool baitPreferenses( std::string baitName ) = 0;

protected:
    std::string fishName_ {};
    int minFishWeight_ {};
    int maxFishWeight_ {};
};

class Crucian : public Fish {
public:
    bool baitPreferenses( const std::string baitName ) override;
};

class Perch : public Fish {
public:
    bool baitPreferenses( const std::string baitName ) override;
};

class Pike : public Fish {
public:
    bool baitPreferenses( const std::string baitName [[maybe_unused]] ) override;
};
