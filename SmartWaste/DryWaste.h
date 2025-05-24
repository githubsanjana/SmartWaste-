#pragma once
#include "Waste.h"

class DryWaste : public Waste {
public:
    enum SubType { PLASTIC, PAPER, METAL, GLASS };
    
private:
    SubType subType;
    bool isRecyclable;
    
public:
    DryWaste(SubType subType);
    std::string getDisposalInstructions() const override;
    int calculatePoints() const override;
    
    // Dry waste specific methods
    bool getIsRecyclable() const;
};