Problem Statement: 

Imagine a delivery executive called Aman standing idle in Koramangala somewhere when suddenly his phone rings and notifies that he’s just been assigned a batch of 2 orders meant to be delivered in the shortest possible timeframe.

<img width="592" alt="Screenshot 2024-05-14 at 6 08 20 PM" src="https://github.com/18shrijeet/minimumtimefordeliveryproject/assets/40976061/172147b6-9d30-4cd8-9699-799b47053a2d">

Approach: 

Assumptions: Aman is not returning to his starting point after delivering all orders 
Consideration in approach : 
1. There are 2 restaurants and 2 customers
2. Customer1 orders from Restaurant 1 and Customer2 orders from Restaurant 2
3. Customer can never be visited before picking order from its corresponding Restaurant.
4. PrepTime for both the restaurants keeps decreasing after time 0 while Aman is travelling
5. Wait Time for each restaurant will be prepTime - (time taken to reach that restaurant)
6. Minimum time will be in minutes

Observations: 
1. First visited location will always be a restaurant
2. Last visited location will always be a customer

Permutations:

This leaves us with only these below 6 valid permutational sequence of routes 
1. Aman -> R1->R2->C1->C2
2. Aman -> R1->R2->C2->C1
3. Aman -> R1->C1->R2->C2
4. Aman -> R2->R1->C1->C2
5. Aman -> R2->R1->C2->C1
6. Aman -> R2->C2->R1->C1

Here Aman denotes the initial location of Aman 
R1 -> Restaurant 1
R2 -> Restaurant 2
C1 -> Customer 1
C2 -> Customer 2

Inputs :
How to take inputs:
- Run the main executable. (**./main**  , there is a precompiled binary added in the project )
- Follow the prompts to enter the number of restaurants and customers, their locations, and preparation times.



Build: 
How to compile:
- Run `cmake .` to generate makefile
- Run `make all` to compile both the main program and the tests.
- Similarly Run `cmake .` and `make all` in test directory to generate test executable to run UTs
- Alternatively, compile manually with `g++ -o main main.cpp DeliveryManager.cpp Location.cpp` and `g++ -o test test.cpp DeliveryManager.cpp Location.cpp -lgtest -lgtest_main -pthread`.

How to run the executable:
- Run `./main` to execute the main program.
- Run `./test` to execute the test cases.

How to analyze with a sample input:
- After running the main program, it will output the shortest time taken by Aman to make all deliveries.
- Use the test cases to ensure the correctness of the implemented functionalities.

Analyse with a sample: 

Taken Eucledian distance to analyse properly on a 2D coordinates for easy understanding 
Restaurant 1 : {2,0} - prep time = 10 minutes 
Restaurant 2 : {0,4} - prep time = 20 minutes 
Customer 1 : {0,2}
Customer 2 : {4,0}
Aman's location : {0,0}
**Shortest time taken by Aman to make all deliveries: 41.4558**

Outputs for all valid permutations are as below 
1. timetaken : **41.4558**
2. timetaken : 51.4558
3. timetaken : 42.8328
4. timetaken : 53.8034
5. timetaken : 55.3181
6. timetaken : 52.8328

Using haversine , the ask of the problem 
The output is 
```
Enter number of restaurants and number of customers: 2 2
Enter location (x, y), and preparation time for restaurant 1: 2 0 10
Enter location (x, y), and preparation time for restaurant 2: 0 4 20
Enter location (x, y) for customer 1: 0 2
Enter location (x, y) for customer 2: 4 0
Enter location (x, y) for Aman: 0 0
Shortest time taken by Aman to make all deliveries: 109326
```

Also written a sample GTK UI to take in the coordinates and calculate the shortest time 
<img width="1005" alt="Screenshot 2024-05-14 at 6 29 11 PM" src="https://github.com/18shrijeet/minimumtimefordeliveryproject/assets/40976061/96b5bcec-9a58-4f2f-9f6e-3d732feeb493">
The GTK has many dependencies to be installed on the system.


