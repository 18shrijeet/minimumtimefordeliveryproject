#include <iostream>
#include <vector>
#include <algorithm> 
#include "Location.h"
#include "DeliveryManager.h"

int main() {
    DeliveryManager manager;

    int n_restaurants, n_customers;
    std::cout << "Enter number of restaurants and number of customers: ";
    std::cin >> n_restaurants >> n_customers;

    std::vector<Location> locations;
    double x, y;
    int prepTime;

    for (int i = 0; i < n_restaurants; ++i) {
        std::cout << "Enter location (x, y), and preparation time for restaurant " << i + 1 << ": ";
        std::cin >> x >> y >> prepTime;
        locations.emplace_back("Restaurant", x, y, true, prepTime);
    }

    for (int i = 0; i < n_customers; ++i) {
        std::cout << "Enter location (x, y) for customer " << i + 1 << ": ";
        std::cin >> x >> y;
        locations.emplace_back("Customer", x, y, false);
    }

    double Ax, Ay;
    std::cout << "Enter location (x, y) for Aman: ";
    std::cin >> Ax >> Ay;
    Location Aman("Aman", Ax, Ay, false);

    // Define the locations
    Location R1 = locations[0];
    Location R2 = locations[1];
    Location C1 = locations[2];
    Location C2 = locations[3];

    // Vector to store times for each route
    std::vector<double> allTimes;

    // R1->C1->R2->C2
    double timeTaken = manager.routeTime(Aman, R1, C1, R2, C2);
    allTimes.push_back(timeTaken);

    // R2->C2->R1->C1
    timeTaken = manager.routeTime(Aman, R2, C2, R1, C1);
    allTimes.push_back(timeTaken);

    // R1->R2->C1->C2
    timeTaken = manager.routeTime(Aman, R1, R2, C1, C2);
    allTimes.push_back(timeTaken);

    // R1->R2->C2->C1
    timeTaken = manager.routeTime(Aman, R1, R2, C2, C1);
    allTimes.push_back(timeTaken);

    // R2->R1->C1->C2
    timeTaken = manager.routeTime(Aman, R2, R1, C1, C2);
    allTimes.push_back(timeTaken);

    // R2->R1->C2->C1
    timeTaken = manager.routeTime(Aman, R2, R1, C2, C1);
    allTimes.push_back(timeTaken);

    // Find the shortest time
    double min_time = *std::min_element(allTimes.begin(), allTimes.end());

    std::cout << "Shortest time taken by Aman to make all deliveries: " << min_time << std::endl;

    return 0;
}
