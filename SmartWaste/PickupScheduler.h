#pragma once
#include <vector>
#include <ctime>
#include "Waste.h"

class PickupScheduler {
    std::vector<tm> scheduledPickups;
    
public:
    tm schedulePickup(const Waste& waste);
    void displayScheduledPickups() const;
    
private:
    tm calculateNextPickupDate(const Waste& waste) const;
};