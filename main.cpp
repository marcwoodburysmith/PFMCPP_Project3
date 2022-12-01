/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.






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
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
