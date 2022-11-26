 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


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
    //Energy save mode
    bool energyMode = true;
    //indicate whether milk requested
    bool milkRequested = false;
    //type of coffee (espresso/cappuccino/etc)
    std::string typeOfCoffee = "espresso";
    //amount of water remaining in reservoir in mls
    float waterRemaining = 500;

    struct Cup
    {
        //cup volume in mls
        float volume = 250;
        //cup material
        std::string material = "glass";
        //cup height in cm
        float height = 12;
        //cup colour
        std::string colour = "black";
        //indicate whether cup clean
        bool clean = true;

        //fill cup
        void setCupVolume(float volume);
        //get fill status
        bool getCleanStatus(bool clean); //indcates whether cup clean or not
        //set fill status
        void setCupColour(std::string colour);
    };

    //heat water
    void heatWater();
    //return requested type of coffee
    std::string coffeeType();
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
        std::string name = "Mary";
        //person age in years
        int age = 35;
        //person gender
        std::string gender = "female";
        //personInsuranceCompany 
        std::string insuranceCompany = "No Insurance";
        //date of last check (ddmmyyyy)
        int dateOfLastCheck = 01112022;

        //return patient's insurance company
        std::string getInsuranceCompany(std::string insuranceCompany); //returns name of patient's insurance company
        //dental treatment deemed necessary
        int dateOfNextDentalAppointment(int dateOfLastCheck); //returns month when next check will be
        //cost of work undertaken
        float costOfDentalTreatment(); //returns cost of treatment
    };

    //treat patient
    void treatPatient(Person name, std::string treatmentClassification);
    //charge patient fee for service
    float feeForService(std::string treatmentClassification); //returns cost in dollars of treatment
    //pay staff wages
    float payStaff(std::string name); //returns staff member's salary

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
    double height = 2.4;
    //Width in metres (float)
    double width = 1.2;
    //Speed of movement in metres per second
    double speedOfMovement = 0.5;
    //Colour (std::string)
    std::string colour = "grey";
    //Whether door is closed (false) or open (true)
    bool closureStatus = false;

    //Open
    void open();
    //Close 
    void close();
    //Get status (open or closed)
    bool status(bool closureStatus); //returns true or false according to whether door closed/open
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
    float area = 450;
    //Material
    std::string material = "aluminium";
    //Number of buttons
    int numButtons = 24;
    //Diameter of individual buttons in mm
    float buttonDiameter = 10;
    //Brightness of backlighting on scale 1 to 10
    int backlightBrightness = 4; 

    //Choose panel size
    float setSize(int nunmPanelButtons, float buttonSize);  //returns panel size for fixed button number/button size
    //Choose number of buttons
    int setNumberOfControlButtons(float area); //returns number of control buttons for specified panel size
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
    Cabin cabin;
    //Make new Door
    Door leftDoor, rightDoor;
    //Make new Panel
    Panel panel;
    //Make new Control
    Control control;
    //Make new Motor
    Motor motor;

    //Move up and down
    void elevatorAscend(int requestedFloor, double elevatorAcceleration);
    //Open and close
    void openDoor();
    //Remember floor chosen by user
    void storeRequestedFloor(int requestedFloor);
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
