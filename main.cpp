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

struct Limb
{
    
    float sizeOfStep = 1;
    float limbPosition = 0;
    bool startWithLeftFoot = true;

    float stepForward();
    float stepSize();

};

float Limb::stepForward()
{
    limbPosition += 1;
    return limbPosition;
}

float Limb::stepSize()
{
    return sizeOfStep;
}

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTraveled = 0.0f;

    float run(float howFast, bool startWithLeftFoot);

    Limb leftFoot, rightFoot;
};

float Person::run( float howFast, bool startWithLeftFoot )
{
    float leftDistance;
    float rightDistance;
    if (startWithLeftFoot == true)
    {
        leftDistance = leftFoot.stepForward() * howFast;
        rightDistance = rightFoot.stepForward() * howFast;
    }
    else
    {
        rightDistance = rightFoot.stepForward() * howFast;
        leftDistance = leftFoot.stepForward() * howFast;
    }
    distanceTraveled = leftDistance + rightDistance;
    return distanceTraveled;
}


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






struct CoffeeMaker
{   
    float maxWaterTemp = 75;
    bool switchedOn = false;
    bool milkRequested = false;
    std::string typeOfCoffee = "espresso";
    float waterRemaining = 500;

    struct Cup
    {
        
        float volume = 250;
        std::string material = "glass";
        float height = 12;
        std::string colour = "black";
        bool clean = true;

        void setCupVolume(float vol);
        bool getCleanStatus(bool cln); 
        void setCupColour(std::string col);
    };

    void heatWater();
    std::string coffeeType();
    void switchOff();

    Cup customerCup;

};


void CoffeeMaker::Cup::setCupVolume(float vol)
{
    volume = vol;
}

bool CoffeeMaker::Cup::getCleanStatus(bool cln)
{
    clean = cln;
    return clean;
}

void CoffeeMaker::Cup::setCupColour(std::string col)
{
    colour = col;
}

void CoffeeMaker::heatWater()
{
    switchedOn = true;
}

std::string CoffeeMaker::coffeeType()
{
    return typeOfCoffee;
}

void CoffeeMaker::switchOff()
{
   switchedOn = false;
}




struct Dentist 
{
    
    int numPatients = 8;
    int maxPatientsPerWeek = 40;
    int costDisposableEquipment = 2000;
    int profitPerWeek = 20000;
    int numStaff = 20;

    struct Person
    {
        std::string name = "Mary";
        int age = 35;
        std::string gender = "female";
        std::string insuranceCompany = "No Insurance";
        int dateOfLastCheck = 112022;

        std::string getInsuranceCompany(std::string insurance); 
        int dateOfNextDentalAppointment(int lastCheck); 
        void setGender(std::string gen); 
    };

    int returnLastCheck(std::string name);
    float feeForService(std::string treatmentClassification);
    int payStaff(); 

    Person newPatient;
};


std::string Dentist::Person::getInsuranceCompany(std::string insurance)
{
    insuranceCompany = insurance;
    return insuranceCompany;
}

int Dentist::Person::dateOfNextDentalAppointment(int lastCheck)
{
    dateOfLastCheck = lastCheck;
    return dateOfLastCheck + 1;
}

void Dentist::Person::setGender(std::string gen)
{
    gender = gen;
}

int Dentist::returnLastCheck(std::string name)
{
    newPatient.name = name;
    return newPatient.dateOfLastCheck;
}

float Dentist::feeForService(std::string treatmentClassification)
{
    if( treatmentClassification == "check up" )
    {
        return 500;
    }
    return 1000;   
}

int Dentist::payStaff()
{
    return (profitPerWeek - costDisposableEquipment)/ numStaff; 
}



struct AutomaticPublicToilet
{

    float volumeOfCistern = 5;
    float volumeOfCleaningReservoir = 20;
    int numberOfFlushesPerDay = 40;
    int brightnessOfLights = 4;
    float volumeOfWaterPerFlush = 2;

    void flushToilet();
    void changeBrightness(int requestedBrightness);
    void clean();

};

void AutomaticPublicToilet::flushToilet()
{
    
}

void AutomaticPublicToilet::changeBrightness(int requestedBrightness)
{
    brightnessOfLights = requestedBrightness;
}

void AutomaticPublicToilet::clean()
{
    
}



struct ATM
{
    double currentAmountAvailable = 20000;
    double maxAmountAvailable = 40000;
    int numCustomers = 200;
    int accountNumCurrentCustomer = 12345678;
    int pinNumCurrentCustomer = 1234;

    void dispenseCash();
    int displayBalance(int accountNum); 
    void dispenseReceipt(double amountWithdrawn);
};

void ATM::dispenseCash()
{
    
}

int ATM::displayBalance(int accountNum)
{
    accountNumCurrentCustomer = accountNum;
    return accountNumCurrentCustomer;
}

void ATM::dispenseReceipt(double amountWithdrawn)
{
    currentAmountAvailable -= amountWithdrawn;
}



struct Cabin
{
    int volumeOfElevatorCabin = 8;
    int floorArea = 3;
    int numLights = 4;
    std::string wallColour = "white";
    int capacityInPersons = 8;

    int setCapacityOfCabin(int flrArea, int vol); 
    int setNumberOfLights(int flrArea, int maxBrightness); 
    int getCapacity(); 
};

int Cabin::setCapacityOfCabin(int flrArea, int vol)
{
    volumeOfElevatorCabin = vol;
    floorArea = flrArea;
    int capacity = volumeOfElevatorCabin / floorArea; 
    return capacity;
}

int Cabin::setNumberOfLights(int flrArea, int maxBrightness)
{
    return maxBrightness / flrArea;
}

int Cabin::getCapacity()
{
    return capacityInPersons;
}


struct Door
{
    double height = 2.4;
    double width = 1.2;
    double speedOfMovement = 0.5;
    std::string colour = "grey";
    bool closureStatus = false;

    void open();
    void close();
    bool status(); 
};

void Door::open()
{
    
}

void Door::close()
{
    
}

bool Door::status()
{
    return closureStatus;
}


struct Panel
{
    float area = 450;
    std::string material = "aluminium";
    int numButtons = 24;
    int buttonDiameter = 10;
    int backlightBrightness = 4; 

    int setSize(int numPanelButtons, int buttonSize); 
    int setNumberOfControlButtons(int a); 
    float calculateButtonArea(float diam); 
    
};

int Panel::setSize(int numPanelButtons, int buttonSize)
{
    return numPanelButtons * buttonSize; 
}

int Panel::setNumberOfControlButtons(int a)
{
    return a / buttonDiameter; 
}

float Panel::calculateButtonArea(float diam)
{
    float buttonArea;
    buttonArea =  3.14f * (diam / 2) * (diam / 2);
    return buttonArea;
}


struct Control
{
    int currentFloor = 1;
    int requestedFloor = 1;
    int maximumFloor = 12;
    int minimumFloor = -1;
    bool alarmActivated = false;

    int getRequestedFloorNumber(int reqFloor); 
    void activateAlarm(bool almActivated);
    void setMaximumFloor(int max);
};

int Control::getRequestedFloorNumber(int reqFloor)
{
    requestedFloor = reqFloor;
    return requestedFloor;
}

void Control::activateAlarm(bool almActivated)
{
    alarmActivated = almActivated;
}

void Control::setMaximumFloor(int max)
{
    maximumFloor = max;
}


struct Motor
{
    double speedOfElevator = 4.3;
    double elevatorAcceleration = 0.8;
    double elevatorDeceleration = 0.8;
    std::string direction = "up"; 
    int passengerWeight = 600;

    double elevatorAccelerate();
    double elevatorDecelerate();
    double getWeightOfPassengers(int numberOfPassengers, int AverageWeight); 
};

double Motor::elevatorAccelerate()
{
    return elevatorAcceleration;
}

double Motor::elevatorDecelerate()
{
    return elevatorDeceleration;
}

double Motor::getWeightOfPassengers(int numberOfPassengers, int weight)
{
    passengerWeight = weight;
    return numberOfPassengers * passengerWeight;
}


struct Elevator
{
    Cabin cabin;
    Door leftDoor, rightDoor;
    Panel panel;
    Control control;
    Motor motor;

    void setDirection(int requested, int current);
    void openDoor();
    void storeRequestedFloor(int requestedFloor);
};


void Elevator::setDirection(int requested, int current)
{
    control.currentFloor = current;
    control.requestedFloor = requested;
    
    if( control.currentFloor > control.requestedFloor)
    {
        motor.direction = "up";
    }
    else
    {
        motor.direction = "down";
    }
}

void Elevator::openDoor()
{
    
}

void Elevator::storeRequestedFloor(int reqFloor)
{
    control.requestedFloor = reqFloor;
}

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
