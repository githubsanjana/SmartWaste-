#pragma once
#include <string>
#include <vector>

class User {
    std::string name;
    std::string userId;
    int totalPoints;
    std::vector<std::string> disposalHistory;
    
public:
    User(const std::string& userName);
    
    // Getters
    std::string getName() const;
    std::string getUserId() const;
    int getTotalPoints() const;
    std::vector<std::string> getHistory() const;
    
    // Methods
    void addDisposalRecord(const std::string& record);
    void addPoints(int points);
    
private:
    std::string generateUserId() const;
};