#include "Waste.h"
#include <stdexcept>

Waste::Waste(const std::string& wasteType) : type(wasteType) {
    points = 0;
    time_t now = time(0);
    disposalDate = *localtime(&now);
}

std::string Waste::getType() const { return type; }
tm Waste::getDisposalDate() const { return disposalDate; }
int Waste::getPoints() const { return points; }

void Waste::setDisposalDate(const tm& date) {
    if (date.tm_year < 0 || date.tm_mon < 0 || date.tm_mday < 1) {
        throw std::invalid_argument("Invalid date");
    }
    disposalDate = date;
}