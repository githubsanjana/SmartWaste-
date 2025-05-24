#include <iostream>
#include <memory>
#include <iomanip>  
#include <sstream>
#include "User.h"
#include "DryWaste.h"
#include "WetWaste.h"
#include "RewardSystem.h"
#include "PickupScheduler.h"

void displayMainMenu() {
    std::cout << "\nEcoWaste Manager\n";
    std::cout << "1. New Disposal\n";
    std::cout << "2. View Rewards\n";
    std::cout << "3. View Pickup Schedule\n";
    std::cout << "4. Exit\n";
    std::cout << "Select option: ";
}

void handleWasteDisposal(User& user, PickupScheduler& scheduler, RewardSystem& rewards) {
    std::cout << "\nSelect Waste Type:\n";
    std::cout << "1. Dry Waste\n";
    std::cout << "2. Wet Waste\n";
    
    int choice;
    std::cin >> choice;
    
    std::unique_ptr<Waste> waste;
    std::string wasteType;
    
    if (choice == 1) {
        waste = std::make_unique<DryWaste>(DryWaste::PLASTIC);
        wasteType = "Dry Waste";
    } else {
        waste = std::make_unique<WetWaste>(WetWaste::KITCHEN);
        wasteType = "Wet Waste";
    }
    
    tm pickupDate = scheduler.schedulePickup(*waste);
    user.addPoints(waste->getPoints());
    
    std::cout << "\nThank you, " << user.getName() << "!\n";
    std::cout << "Your " << wasteType << " will be picked up on: " 
              << std::put_time(&pickupDate, "%A, %d %B %Y") << "\n";
    std::cout << "You earned " << waste->getPoints() << " Green Points!\n";
    
    // Update user history
    std::ostringstream record;
    record << wasteType << " | " << std::put_time(&pickupDate, "%Y-%m-%d") 
           << " | +" << waste->getPoints() << " pts";
    user.addDisposalRecord(record.str());
}

int main() {
    std::cout << "Enter your name: ";
    std::string userName;
    std::getline(std::cin, userName);
    
    User user(userName);
    PickupScheduler scheduler;
    RewardSystem rewards;
    
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                handleWasteDisposal(user, scheduler, rewards);
                break;
            case 2:
                rewards.checkRewardEligibility(user);
                break;
            case 3:
                scheduler.displayScheduledPickups();
                break;
            case 4:
                std::cout << "Thank you for using EcoWaste Manager!\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
