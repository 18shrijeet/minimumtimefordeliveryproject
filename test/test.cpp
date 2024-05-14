#include <gtest/gtest.h>
#include "DeliveryManager.h"

TEST(DeliveryManagerTest, CalculateDistance) {
    DeliveryManager manager;
    Location loc1("Loc1", 0, 0, false);
    Location loc2("Loc2", 1, 1, false);
    double expectedDistance = 156.89; // Approximate distance in km
    double distance = manager.calculateDistance(loc1, loc2);
    ASSERT_NEAR(distance, expectedDistance, 0.01);
}

TEST(DeliveryManagerTest, CalculateTime) {
    DeliveryManager manager;
    Location from("From", 0, 0, false);
    Location to("To", 1, 1, false);
    double expectedTime = 4.71; // Approximate time in minutes
    double time = manager.calculateTime(from, to);
    ASSERT_NEAR(time, expectedTime, 0.01);
}

TEST(DeliveryManagerTest, RouteTime) {
    DeliveryManager manager;
    Location Aman("Aman", 0, 0, false);
    Location R1("R1", 1, 1, true, 10);
    Location C1("C1", 2, 2, false);
    Location R2("R2", 3, 3, true, 15);
    Location C2("C2", 4, 4, false);
    double expectedTime = 51.45; // Approximate time in minutes
    double time = manager.routeTime(Aman, R1, C1, R2, C2);
    ASSERT_NEAR(time, expectedTime, 0.01);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
