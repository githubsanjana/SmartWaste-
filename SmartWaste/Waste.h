#pragma once
#include <string>
#include <ctime>

class Waste {
protected:
    std::string type;
    tm disposalDate;
    int points;
    
public:
    Waste(const std::string& wasteType);
    virtual ~Waste() = default;
    
    // Pure virtual functions (must be implemented by derived classes)
    virtual std::string getDisposalInstructions() const = 0;
    virtual int calculatePoints() const = 0;
    
    // Getters
    std::string getType() const;
    tm getDisposalDate() const;
    int getPoints() const;
    
    // Setters
    void setDisposalDate(const tm& date);
};