#include "WetWaste.h"

WetWaste::WetWaste(SubType subType) 
    : Waste("Wet"), subType(subType) {
    isCompostable = true; // All wet waste is compostable in this example
    points = calculatePoints();
}

std::string WetWaste::getDisposalInstructions() const {
    switch(subType) {
        case KITCHEN: return "Use biodegradable bags";
        case GARDEN: return "Mix with dry leaves for composting";
        case FOOD_WASTE: return "Store in airtight container";
        default: return "General wet waste instructions";
    }
}

int WetWaste::calculatePoints() const {
    // More points for kitchen waste (higher composting value)
    return subType == KITCHEN ? 12 : 8;
}

bool WetWaste::getIsCompostable() const { return isCompostable; }