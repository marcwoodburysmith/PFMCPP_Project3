/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

/*

Thing 1) Coffee maker
5 properties:
    1) maximum water temperature (float)
    2) cup size (int)
    3) whether cup full (bool)
    4) type of coffee (espesso/cappuccino/etc) (std::string)
    5) amount of water remaining in reservoir (float)
3 things it can do:
    1) heat water
    2) deliver correct quantity of heated water
    3) beep when pouring complete
 */

struct CoffeeMaker
{
    //maximum water temperature in F
    float maxWaterTemp = 75;
    //cup size in mls
    int cupSize = 200;
    //indicate whether cup full
    bool cupFull = false;
    //type of coffee (espresso/cappuccino/etc)
    std::string typeOfCoffee = "espresso";
    //amount of water remaining in reservoir in mls
    float waterRemaining = 500;

    struct Cup
    {
        //cup volume in mls
        float cupVolume = 250;
        //cup material
        std::string material = "glass";
        //cup height in cm
        float cupHeight = 12;
        //cup colour
        std::string cupColour = "black";
        //indicate whether cup clean
        bool cupClean = true;

        //fill cup
        void setCupVolume(float cupVolume);
        //get fill status
        bool getCleanStatus(bool cupClean); //indcates whether cup clean or not
        //set fill status
        void setCupColour(std::string cupColour);
    };

    //heat water
    void heatWater();
    //deliver correct quantity of heated water
    void fillCup(int cupSize);
    //beep when pouring complete
    void beepWhenCupFull(bool cupFull);

    Cup customerCup;

};

/*
Thing 2) Dentist
5 properties:
    1) number of patients per day (int)
    2) maximum number of patients per week (int)
    3) disposable equipment costs per week (float)
    4) profit per week (float)
    5) number of staff (int)
3 things it can do:
    1) treat patient
    2) charge patient fee for service
    3) pay staff wages
 */

struct Dentist 
{
    
    //number of patients per day
    int numPatients = 8;
    //maximum number of patients per week
    int maxPatientsPerWeek = 40;
    //disposable equipment costs per week
    double costDisposableEquipment = 2000;
    //profit per week (float)
    double profitPerWeek = 20000;
    //number of staff (int)
    int numStaff = 20;

    struct Person
    {
    //personName
    std::string personName = "Mary";
    //person age in years
    int personAge = 35;
    //person gender
    std::string personGender = "female";
    //personInsuranceCompany 
    std::string personInsuranceCompany = "No Insurance";
    //date of last check (ddmmyyyy)
    int dateOfLastCheck = 01112022;

    //return patient's insurance company
    std::string getInsuranceCompany(std::string personInsuranceCompany); //returns name of patient's insurance company
    //dental treatment deemed necessary
    int dateOfNextDentalAppointment(int dateOfLastCheck); //returns month when next check will be
    //cost of work undertaken
    float costOfDentalTreatment(); //returns cost of treatment
    };

    //treat patient
    void treatPatient(Person personName, std::string treatmentClassification);
    //charge patient fee for service
    float feeForService(std::string treatmentClassification); //returns cost in dollars of treatment
    //pay staff wages
    float payStaff(std::string staffName); //returns staff member's salary

    Person newPatient;
};

/*
Thing 3) Automatic public toilet
5 properties:
    1) volume of cistern (float)
    2) volume of cleaning solution reservoir (float)
    3) number of uses per day (int)
    4) brightness of lights (int)
    5) amount of water per flush (float)
3 things it can do:
    1) flush
    2) illuminate
    3) clean
 */
struct AutomaticPublicToilet
{

    //volume of cistern in litres 
    float volumeOfCistern = 5;
    //volume of cleaning reservoir in litres
    float volumeOfCleaningReservoir = 20;
    //number of uses per day
    int numberOfFlushesPerDay = 40;
    //brightness of lights sclaaled 1 to 10
    int brightnessOfLights = 4;
    //amount of water per flush in litres
    float volumeOfWaterPerFlush = 2;

    //flush
    void flushToilet();
    //illuminate
    void changeBrightness(int requestedBrightness);
    //clean
    void clean();

};


/*
Thing 4) ATM
5 properties:
    1) current amount in machine in dollars (float)
    2) maximum amount machine can hold in dollars (float)
    3) number of customers per day (int)
    4) customer account number (int)
    5) customer pin number (int)
3 things it can do:
    1) dispense cash
    2) display balance
    3) dispense receipt
 */

struct ATM
{

    //current amount in machine in dollars
    double currentAmountAvailable = 20000;
    //maximum amount machine can hold in dollars
    double maxAmountAvailable = 40000;
    //number of customers per day
    int numCustomers = 200;
    //customer account number
    int accountNumCurrentCustomer = 12345678;
    //customer pin number
    int pinNumCurrentCustomer = 1234;

    //dispense cash
    void dispenseCash();
    //display balance
    float displayBalance(int accountNumCurrentCustomer); //returns the customer's balance
    //dispense receipt
    void dispenseReceipt(int accountNumCurrentCustomer, double amountWithdrawn);
};


/*
Thing 5) Cabin
5 properties:
    1) Volume in m^3 (float)
    2) Floor area in cm^2 (float)
    3) Number of lights (int)
    4) Wall colour (std::string)
    5) Capacity in persons (int)
3 things it can do:
    1) set size
    2) set weight
    3) set capacity
 */

struct Cabin
{

    //Volume in cubic metres
    double volumeOfElevatorCabin = 8;
    //Floor area in squared metres
    double floorArea = 3.3;
    //Number of lights
    int numLights = 4;
    //Wall colour
    std::string wallColour = "white";
    //Capacity in persons
    int capacityInPersons = 8;

    //set size of cabin
    double setVolumeOfCabin(double floorArea, int capacityInPersons); //returns volume of cabin
    //set number of lights
    int setNumberOfLights(float floorArea, int maxBrightness); //returns number of lights required
    //get capacity in number of persons
    int getCapacity(float volumeOfElevatorCabin); //returns maximum capacity for set size
};


/*
Thing 6) Door
5 properties:
    1) Height in cm (float)
    2) Width in cm (float)
    3) Speed of movement (float)
    4) Colour (std::string)
    5) Status open vs closed (bool)
3 things it can do:
    1) Open
    2) Close 
    3) Get status (open or closed)
 */
struct Door
{

    //Height in metres
    double doorHeight = 2.4;
    //Width in metres (float)
    double doorWidth = 1.2;
    //Speed of movement in metres per second
    double speedOfDoorMovement = 0.5;
    //Colour (std::string)
    std::string doorColour = "grey";
    //Whether door is closed (false) or open (true)
    bool doorClosureStatus = false;

    //Open
    void openDoor();
    //Close 
    void closeDoor();
    //Get status (open or closed)
    bool doorStatus(bool doorClosureStatus); //returns true or false according to whether door closed/open
};


/*
Thing 7) Panel
5 properties:
    1) Area in cm^2 (int)
    2) Material (std::string)
    3) Number of buttons (int)
    4) Size of buttons (int)
    5) Brightness of backlighting (int)
3 things it can do:
    1) Choose panel size
    2) Choose number of buttons
    3) Change size of buttons
 */

struct Panel
{

    //Area in squared cm
    float areaOfControlPanel = 450;
    //Material
    std::string panelMaterial = "aluminium";
    //Number of buttons
    int numPanelButtons = 24;
    //Diameter of individual buttons in mm
    float buttonDiameter = 10;
    //Brightness of backlighting on scale 1 to 10
    int panelBacklightBrightness = 4; 

    //Choose panel size
    float setPanelSize(int nunmPanelButtons, float buttonSize);  //returns panel size for fixed button number/button size
    //Choose number of buttons
    int setNumberOfControlButtons(float areaOfControlPanel); //returns number of control buttons for specified panel size
    //Change size of buttons
    float calculateButtonArea(float buttonDiameter); //calculate area from diameter
    
};



/*
Thing 8) Control
5 properties:
    1) current floor number (int)
    2) requested floor number (int)
    3) maximum floor number (int)
    4) minimum floor number (int)
    5) alarm on (bool)
3 things it can do:
    1) choose floor number
    2) raise alarm
    3) call assistance
 */

struct Control
{

    //current floor number
    int currentFloor = 1;
    //requested floor number
    int requestedFloor = 1;
    //maximum floor number
    int maximumFloor = 12;
    //minimum floor number
    int minimumFloor = -1;
    //alarm activation status
    bool alarmActivated = false;

    //choose floor number
    int getRequestedFloorNumber(int requestedFloor); //returns requested floor number
    //activate alarm
    void activateAlarm(bool alarmActivated, bool buttonPressed);
    //set maximum floor
    void setMaximumFloor(int maximumFloor);
};


/*
Thing 9) Motor
5 properties:
    1) speed of movement (float)
    2) acceleration (float)
    3) deceleration (float)
    4) distance between floors (float)
    5) weight of passengers (float)
3 things it can do:
    1) move up
    2) move down
    3) stop
 */
struct Motor
{

    //speed of movement in metres per second
    double speedOfElevator = 4.3;
    //acceleration (float)
    double elevatorAcceleration = 0.8;
    //deceleration (float)
    double elevatorDeceleration = 0.8;
    //distance between floors
    double distanceBetweenFloors = 3.6;
    //weight of passengers 
    double passengerWeight = 600;

    //Elevator accelerate
    void elevatorAccelerate();
    //Elevator decelerate
    void elevatorDecelerate();
    //Get weight of passengers
    double getWeightOfPassengers(int numberOfPassengers, int AverageWeight); //returns current weight of passengers
};



/*
Thing 10) Elevator
5 properties:
    1) Cabin
    2) Door
    3) Panel
    4) Control
    5) Motor
3 things it can do:
    1) Move up and down
    2) Open and close
    3) Remember floor chosen by user
 */
struct Elevator
{

    //Make new Cabin
    Cabin lobbyElevatorCabinOne;
    //Make new Door
    Door lobbyElevatorDoor_one, lobbyElevatorDoor_two;
    //Make new Panel
    Panel lobbyElevatorPanel;
    //Make new Control
    Control lobbyElevatorControl;
    //Make new Motor
    Motor lobbyElevatorMotor;

    //Move up and down
    void elevatorAscend(Control requestedFloor, Motor elevatorAcceleration);
    //Open and close
    void openDoor(Door doorClosureStatus, Door speedOfDoorMovement);
    //Remember floor chosen by user
    void storeRequestedFloor(Control requestedFloor);
};



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
