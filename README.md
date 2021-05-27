## Directories

### `./include`
#### *contains the header files (`.h`) for implementation*
### `./src`
#### *contains the source files (`.cpp`) for implementation*
### `./test`
#### *contains the source (`.cpp`) and header (`.h`) files for test applications*

## Files

### In `./include`
1. `Date.h`
2. `Station.h`
3. `Railways.h`
4. `Booking.h`
5. `BookingClasses.h`
6. `BookingCategory.h`
7. `Divyaang.h`
8. `Concessions.h`
9. `GeneralConcession.h`
10. `LadiesConcession.h`
11. `SeniorCitizenConcession.h`
12. `DivyaangConcession.h`
13. `Passenger.h`
14. `Name.h`
15. `Gender.h`
16. `Exceptions.h`
### In `./src`
1. `Date.cpp`
2. `Station.cpp`
3. `Railways.cpp`
4. `Booking.cpp`
5. `BookingClasses.cpp`
6. `BookingCategory.cpp`
7. `Divyaang.cpp`
10. `Concessions.cpp`
11. `Passenger.cpp`
12. `Name.cpp`
13. `Gender.cpp`
14. `Makefile`
### In `./test`
1. `Application.cpp`

    For running custom made application test

2. `UnitTest.cpp`

    For running custom made unit tests for all classes 

4. `Test.h`

    Contains the declaration of the testing functions

## Compiler
- `G++ v8.1.0`
- Options during compilation:
    - `-o test` : creates the executable in the `src` directory
    - `-I ../include` : includes the path to the `include` directory which contains all the header files 

## Running Tests
-  Run commandline in the project directory and change directory to `src` using `cd src`
   OR  Run commandline in the directory - `./src`

-  Two kinds of tests can be ran:
    - UNIT TEST:
        - Compile using `make unit`
        - Run the executable using `.\test`
        - Output gets written to `./outputs/UnitTestOut.txt`
    - APPLICATION TEST:
        - Uncomment all `#define _DEBUG` statements in the header files
        - Compile using `make app`
        - Run the executable using `.\test`
        - Output gets written to `./outputs/ApplicationOut.txt`
