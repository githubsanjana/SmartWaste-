#include "DryWaste.h"

DryWaste::DryWaste(SubType subType) 
    : Waste("Dry"), subType(subType) {
    isRecyclable = (subType != PLASTIC); // Example logic
    points = calculatePoints();
}

std::string DryWaste::getDisposalInstructions() const {
    switch(subType) {
        case PLASTIC: return "Rinse and dry before disposal";
        case PAPER: return "Flatten and bundle";
        case METAL: return "Separate ferrous/non-ferrous";
        case GLASS: return "Wrap in newspaper";
        default: return "General dry waste instructions";
    }
}

int DryWaste::calculatePoints() const {
    // More points for more recyclable materials
    return isRecyclable ? 15 : 10;
}

bool DryWaste::getIsRecyclable() const { return isRecyclable; }