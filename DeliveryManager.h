#ifndef DELIVERYMANAGER_H
#define DELIVERYMANAGER_H

#include <vector>
#include "Location.h"

class DeliveryManager {
public:
    double calculateDistance(const Location& loc1, const Location& loc2) const;
    double calculateTime(const Location& from, const Location& to) const;
    double calculateTotalTime(const std::vector<Location>& locations);
    double calculateMinTime(const std::vector<double>& times);
    double routeTime(const Location& Aman, const Location& dest1, const Location& dest2,
                     const Location& dest3, const Location& dest4) const;
};

#endif // DELIVERYMANAGER_H
