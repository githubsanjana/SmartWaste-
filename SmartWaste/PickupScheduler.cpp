#include "PickupScheduler.h"
#include <iostream>
#include <iomanip>

tm PickupScheduler::schedulePickup(const Waste& waste) {
    tm pickupDate = calculateNextPickupDate(waste);
    scheduledPickups.push_back(pickupDate);
    return pickupDate;
}

void PickupScheduler::displayScheduledPickups() const {
    std::cout << "\nUpcoming Pickups:\n";
    for (const auto& date : scheduledPickups) {
        std::cout << std::put_time(&date, "%A, %d %B %Y") << "\n";
    }
}

tm PickupScheduler::calculateNextPickupDate(const Waste& waste) const {
    time_t now = time(0);
    tm date = *localtime(&now);
    
    // Business logic: Dry waste on Mondays, Wet waste on Thursdays
    int daysToAdd = (waste.getType() == "Dry") ? 
        (8 - date.tm_wday) % 7 :  // Next Monday
        (3 - date.tm_wday + 7) % 7; // Next Thursday
    
    date.tm_mday += daysToAdd;
    mktime(&date);
    
    return date;
}