#include "DeliveryManager.h"
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

const double earthRadius = 6371.0;

double DeliveryManager::calculateDistance(const Location& loc1, const Location& loc2) const{
    double lat1 = loc1.getLatitude();
    double lon1 = loc1.getLongitude();
    double lat2 = loc2.getLatitude();
    double lon2 = loc2.getLongitude();

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c;
}

// for testing - eucledian distance 
// double DeliveryManager::calculateDistance(const Location& loc1, const Location& loc2) const{
//     double dx = loc2.getLatitude() - loc1.getLatitude();
//     double dy = loc2.getLongitude() - loc1.getLongitude();
//     return std::sqrt(dx * dx + dy * dy);
// }

double DeliveryManager::calculateTime(const Location& from, const Location& to) const{
    double distance = calculateDistance(from, to);
    return (distance / 20) * 60; // Assuming speed of 20 km/h
}

double DeliveryManager::calculateTotalTime(const std::vector<Location>& locations) {
    double total = 0;
    for (size_t i = 1; i < locations.size(); ++i) {
        total += calculateTime(locations[i - 1], locations[i]);
        if (locations[i].isItRestaurant()) {
            total += locations[i].getPrepTime();
        }
    }
    return total;
}

double DeliveryManager::calculateMinTime(const std::vector<double>& times) {
    return *std::min_element(times.begin(), times.end());
}

double DeliveryManager::routeTime(const Location& Aman, const Location& dest1, const Location& dest2,
                                   const Location& dest3, const Location& dest4) const{
    double time = 0;

    time += calculateTime(Aman, dest1);

    Location R1 = dest1;
    Location R2 = dest2.isItRestaurant() ? dest2 : dest3;

    R1.setPrepTime(std::max(0.0, R1.getPrepTime() - time));
    R2.setPrepTime(std::max(0.0, R2.getPrepTime() - time));

    time += R1.getPrepTime();

    time += calculateTime(dest1, dest2);

    R1.setPrepTime(std::max(0.0, R1.getPrepTime() - time));
    R2.setPrepTime(std::max(0.0, R2.getPrepTime() - time));

    if (!dest2.isItRestaurant()) {
        time += R2.getPrepTime();
    }

    time += calculateTime(dest2, dest3);

    R1.setPrepTime(std::max(0.0, R1.getPrepTime() - time));
    R2.setPrepTime(std::max(0.0, R2.getPrepTime() - time));

    if (!dest3.isItRestaurant()) {
        time += R2.getPrepTime();
    }

    time += calculateTime(dest3, dest4);

    return time;
}
