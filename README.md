How to take inputs:
- Run the main executable.
- Follow the prompts to enter the number of restaurants and customers, their locations, and preparation times.

How to compile:
- Run `make all` to compile both the main program and the tests.
- Alternatively, compile manually with `g++ -o main main.cpp DeliveryManager.cpp Location.cpp` and `g++ -o test test.cpp DeliveryManager.cpp Location.cpp -lgtest -lgtest_main -pthread`.

How to run the executable:
- Run `./main` to execute the main program.
- Run `./test` to execute the test cases.

How to analyze with a sample input:
- After running the main program, it will output the shortest time taken by Aman to make all deliveries.
- Use the test cases to ensure the correctness of the implemented functionalities.
