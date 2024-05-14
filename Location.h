#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
public:
    Location(std::string name, double latitude, double longitude, bool isRestaurant, int prepTime = 0);
    std::string getName() const;
    double getLatitude() const;
    double getLongitude() const;
    int getPrepTime() const;
    void setPrepTime(int time);
    bool isItRestaurant() const;

private:
    std::string name;
    double latitude;
    double longitude;
    bool isRestaurant;
    int prepTime;
};

#endif // LOCATION_H
