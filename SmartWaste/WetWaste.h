#pragma once
#include "Waste.h"

class WetWaste : public Waste {
public:
    enum SubType { KITCHEN, GARDEN, FOOD_WASTE };
    
private:
    SubType subType;
    bool isCompostable;
    
public:
    WetWaste(SubType subType);
    std::string getDisposalInstructions() const override;
    int calculatePoints() const override;
    
    // Wet waste specific methods
    bool getIsCompostable() const;
};