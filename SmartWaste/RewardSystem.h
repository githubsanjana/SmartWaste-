#pragma once
#include "User.h"
#include <map>

class RewardSystem {
    std::map<int, std::string> rewardTiers;
    
public:
    RewardSystem();
    
    void checkRewardEligibility(const User& user) const;
    std::string getCurrentReward(const User& user) const;
    void displayAllRewards() const;
    
private:
    void initializeRewards();
};