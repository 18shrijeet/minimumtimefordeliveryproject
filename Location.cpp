#include "Location.h"

Location::Location(std::string name, double latitude, double longitude, bool isRestaurant, int prepTime)
    : name(name), latitude(latitude), longitude(longitude), isRestaurant(isRestaurant), prepTime(prepTime) {}

std::string Location::getName() const {
    return name;
}

double Location::getLatitude() const {
    return latitude;
}

double Location::getLongitude() const {
    return longitude;
}

bool Location::isItRestaurant() const{
    return isRestaurant;
}

int Location::getPrepTime() const {
    return prepTime;
}

void Location::setPrepTime(int time) {
    prepTime = time;
}
