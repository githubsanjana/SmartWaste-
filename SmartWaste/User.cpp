#include "User.h"
#include <ctime>
#include <sstream>
#include <iomanip>

User::User(const std::string& userName) 
    : name(userName), totalPoints(0) {
    userId = generateUserId();
}

std::string User::getName() const { return name; }
std::string User::getUserId() const { return userId; }
int User::getTotalPoints() const { return totalPoints; }
std::vector<std::string> User::getHistory() const { return disposalHistory; }

void User::addDisposalRecord(const std::string& record) {
    disposalHistory.push_back(record);
}

void User::addPoints(int points) {
    if (points > 0) {
        totalPoints += points;
    }
}

std::string User::generateUserId() const {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    
    std::ostringstream oss;
    oss << "USER_" << std::put_time(&tm, "%Y%m%d_%H%M%S");
    return oss.str();
}