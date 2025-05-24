#include "RewardSystem.h"
#include <iostream>

RewardSystem::RewardSystem() {
    initializeRewards();
}

void RewardSystem::initializeRewards() {
    rewardTiers = {
        {100, "10% discount at eco-store"},
        {250, "Reusable shopping bag"},
        {500, "Solar-powered charger"},
        {1000, "VIP composting workshop"}
    };
}

void RewardSystem::checkRewardEligibility(const User& user) const {
    int points = user.getTotalPoints();
    std::cout << "\nReward Progress:\n";
    
    for (const auto& tier : rewardTiers) {
        std::cout << tier.first << " pts: " << tier.second 
                  << (points >= tier.first ? " [✓]" : "") 
                  << "\n";
    }
}

std::string RewardSystem::getCurrentReward(const User& user) const {
    int points = user.getTotalPoints();
    std::string reward;
    
    for (const auto& tier : rewardTiers) {
        if (points >= tier.first) {
            reward = tier.second;
        }
    }
    
    return reward.empty() ? "No reward yet" : reward;
}

void RewardSystem::displayAllRewards() const {
    std::cout << "\nAvailable Rewards:\n";
    for (const auto& tier : rewardTiers) {
        std::cout << tier.first << " pts: " << tier.second << "\n";
    }
}