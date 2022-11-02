#pragma once

#include "Fish.h"
#include "Water.h"
#include "Bait.h"

//fish
struct DataFish {
    Crucian crucian;
    Perch perch;
    Pike pike;
};

//water
struct DataWater {
    River river;
    Lake lake;
    Reservoir reservoir;
};

//bait
struct DataBait {
    Bait bloodworm;
    Bait earthworm;
    Bait maggot;
};
                 