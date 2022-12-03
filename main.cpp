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
    CoffeeMaker();
    float maxWaterTemp = 75;
    bool switchedOn = false;
    bool milkRequested = false;
    std::string typeOfCoffee = "espresso";
    float waterRemaining = 500;

    struct Cup
    {
        Cup();
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

CoffeeMaker::Cup::Cup()
{
    std::cout << "Cup being constructed!" << std::endl;
}

void CoffeeMaker::Cup::setCupVolume(float vol)
{
    volume = vol;
    std::cout << "Cup volume set: " << volume << std::endl;
}

bool CoffeeMaker::Cup::getCleanStatus(bool cln)
{
    clean = cln;
    std::cout << "Clean status: " << clean << std::endl;
    return clean;
    
}

void CoffeeMaker::Cup::setCupColour(std::string col)
{
    colour = col;
    std::cout << "Colour set as: " << colour << std::endl;
}

CoffeeMaker::CoffeeMaker()
{
    std::cout << "CoffeeMaker being constructed!" << std::endl;
}

void CoffeeMaker::heatWater()
{
    switchedOn = true;
    std::cout << "Water heating..." << switchedOn << std::endl;
}

std::string CoffeeMaker::coffeeType()
{
    std::cout << "Type of coffee: " << typeOfCoffee << std::endl;
    return typeOfCoffee;
}

void CoffeeMaker::switchOff()
{
    //switchedOn = false;
    std::cout << "Power: " << switchedOn << std::endl;
}




struct Dentist 
{
    Dentist();
    int numPatients = 8;
    int maxPatientsPerWeek = 40;
    int costDisposableEquipment = 2000;
    int profitPerWeek = 20000;
    int numStaff = 20;

    struct Person
    {
        Person();
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

Dentist::Person::Person()
{
    std::cout << "Person being constructed!" << std::endl;
}

std::string Dentist::Person::getInsuranceCompany(std::string insurance)
{
    insuranceCompany = insurance;
    std::cout <<  name << " Insurance Company: " << insuranceCompany << std::endl;
    return insuranceCompany;
}

int Dentist::Person::dateOfNextDentalAppointment(int lastCheck)
{
    dateOfLastCheck = lastCheck;
    std::cout << name << " Next routine appointment due " << lastCheck + 1 << std::endl;
    return dateOfLastCheck + 1;
}

void Dentist::Person::setGender(std::string gen)
{
    gender = gen;
    std::cout << name << " Gender: " << gender << std::endl;
}

Dentist::Dentist()
{
    std::cout << "Dentist being constructed!" << std::endl;
}

int Dentist::returnLastCheck(std::string name)
{
    newPatient.name = name;
    std::cout << "Determining last dental appt for: " << name << std::endl;
    return newPatient.dateOfLastCheck;
}

float Dentist::feeForService(std::string treatmentClassification)
{
    if( treatmentClassification == "check up" )
    {
        std::cout << "Cost of work: £500" << std::endl;
        return 500;
    }
    std::cout << "Cost of work: £1000" << std::endl;
    return 1000;   
}

int Dentist::payStaff()
{
    int amountPerEmployee = (profitPerWeek - costDisposableEquipment)/ numStaff;
    std::cout << "Employee salary: " << amountPerEmployee << std::endl;
    return (profitPerWeek - costDisposableEquipment)/ numStaff; 
}



struct AutomaticPublicToilet
{

    AutomaticPublicToilet();
    float volumeOfCistern = 5;
    float volumeOfCleaningReservoir = 20;
    int numberOfFlushesPerDay = 40;
    int brightnessOfLights = 4;
    float volumeOfWaterPerFlush = 2;

    void flushToilet();
    void changeBrightness(int requestedBrightness);
    void clean();

};

AutomaticPublicToilet::AutomaticPublicToilet()
{
    std::cout << "Constructing Automatic Public Toilet!" << std::endl;
}

void AutomaticPublicToilet::flushToilet()
{
    std::cout << "Toilet flushed" << std::endl;
}

void AutomaticPublicToilet::changeBrightness(int requestedBrightness)
{
    brightnessOfLights = requestedBrightness;
    std::cout << "Brightness set at level: " << brightnessOfLights << std::endl; 
}

void AutomaticPublicToilet::clean()
{
    std::cout << "Initiating clean " << std::endl;
}



struct ATM
{
    ATM();
    double currentAmountAvailable = 20000;
    double maxAmountAvailable = 40000;
    int numCustomers = 200;
    int accountNumCurrentCustomer = 12345678;
    int pinNumCurrentCustomer = 1234;

    void dispenseCash();
    int displayBalance(int accountNum); 
    void dispenseReceipt(double amountWithdrawn);
};

ATM::ATM()
{
    std::cout << "Constructing ATM!" << std::endl;
}

void ATM::dispenseCash()
{
    std::cout << "Dispensing cash... " << std::endl;
}

int ATM::displayBalance(int accountNum)
{
    accountNumCurrentCustomer = accountNum;
    std::cout << "Displaying balance for accout: " << accountNumCurrentCustomer << std::endl;
    return accountNumCurrentCustomer;
}

void ATM::dispenseReceipt(double amountWithdrawn)
{
    currentAmountAvailable -= amountWithdrawn;
    std::cout << "Dispensing receipt... " << std::endl;
}



struct Cabin
{
    Cabin();
    int volumeOfElevatorCabin = 8;
    int floorArea = 3;
    int numLights = 4;
    std::string wallColour = "white";
    int capacityInPersons = 8;

    int setCapacityOfCabin(int flrArea, int vol); 
    int setNumberOfLights(int flrArea, int maxBrightness); 
    int getCapacity(); 
};

Cabin::Cabin()
{
    std::cout << "Constructing Cabin!" << std::endl;
}

int Cabin::setCapacityOfCabin(int flrArea, int vol)
{
    volumeOfElevatorCabin = vol;
    floorArea = flrArea;
    int capacity = volumeOfElevatorCabin / floorArea; 
    std::cout << "Capacity: " << capacity << std::endl;
    return capacity;
}

int Cabin::setNumberOfLights(int flrArea, int maxBrightness)
{
    std::cout << "Number of lights: " << maxBrightness / flrArea << std::endl;
    return maxBrightness / flrArea;
}

int Cabin::getCapacity()
{
    std::cout << "Capacity in person: " << capacityInPersons << std::endl;
    return capacityInPersons;
}


struct Door
{
    Door();
    double height = 2.4;
    double width = 1.2;
    double speedOfMovement = 0.5;
    std::string colour = "grey";
    bool closureStatus = false;

    void open();
    void close();
    bool status(); 
};

Door::Door()
{
    std::cout << "Constructing Door!" << std::endl;
}

void Door::open()
{
    std::cout << "Door status: opening" << std::endl;
}

void Door::close()
{
    std::cout << "Door status: closing" << std::endl;
}

bool Door::status()
{
    std::cout << "Closure status " << closureStatus << std::endl;
    return closureStatus;
}


struct Panel
{
    Panel();
    float area = 450;
    std::string material = "aluminium";
    int numButtons = 24;
    int buttonDiameter = 10;
    int backlightBrightness = 4; 

    int setSize(int numPanelButtons, int buttonSize); 
    int setNumberOfControlButtons(int a); 
    float calculateButtonArea(float diam); 
};

Panel::Panel()
{
    std::cout << "Constructing Panel!" << std::endl;
}


int Panel::setSize(int numPanelButtons, int buttonSize)
{
    std::cout << "Panel size: " << numPanelButtons * buttonSize * 4 << std::endl;
    return numPanelButtons * buttonSize * 4; 
}

int Panel::setNumberOfControlButtons(int a)
{
    std::cout << "Number of buttons: " <<  a / buttonDiameter << std::endl;
    return a / buttonDiameter; 
}

float Panel::calculateButtonArea(float diam)
{
    float buttonArea;
    buttonArea =  3.14f * (diam / 2) * (diam / 2);
    std::cout << "Button area: " << buttonArea << std::endl;
    return buttonArea;
}


struct Control
{
    Control();
    int currentFloor = 1;
    int requestedFloor = 1;
    int maximumFloor = 12;
    int minimumFloor = -1;
    bool alarmActivated = false;

    int getRequestedFloorNumber(int reqFloor); 
    void activateAlarm(bool almActivated);
    void setMaximumFloor(int max);
};

Control::Control()
{
    std::cout << "Constructing Control!" << std::endl;
}

int Control::getRequestedFloorNumber(int reqFloor)
{
    requestedFloor = reqFloor;
    std::cout << "Floor requested: " << requestedFloor << std::endl;
    return requestedFloor;
}

void Control::activateAlarm(bool almActivated)
{
    alarmActivated = almActivated;
    std::cout << "Alarm status: " << alarmActivated << std::endl;
}

void Control::setMaximumFloor(int max)
{
    maximumFloor = max;
    std::cout << "Top floor: " << maximumFloor << std::endl;
}


struct Motor
{
    Motor();
    double speedOfElevator = 4.3;
    double elevatorAcceleration = 0.8;
    double elevatorDeceleration = 0.8;
    std::string direction = "up"; 
    int passengerWeight = 600;

    double elevatorAccelerate();
    double elevatorDecelerate();
    double getWeightOfPassengers(int numberOfPassengers, int AverageWeight); 
};

Motor::Motor()
{
    std::cout << "Constructing Motor!" << std::endl;
}

double Motor::elevatorAccelerate()
{
    std::cout << "Acceleration: " << elevatorAcceleration << std::endl;
    return elevatorAcceleration;
}

double Motor::elevatorDecelerate()
{
    std::cout << "Deceleration: " << elevatorDeceleration << std::endl;
    return elevatorDeceleration;
}

double Motor::getWeightOfPassengers(int numberOfPassengers, int weight)
{
    passengerWeight = weight;
    std::cout << "Weight of passengers: " << numberOfPassengers * passengerWeight << std::endl;
    return numberOfPassengers * passengerWeight;
}


struct Elevator
{
    Elevator();
    Cabin cabin;
    Door leftDoor, rightDoor;
    Panel panel;
    Control control;
    Motor motor;

    void setDirection(int requested, int current);
    void openDoor();
    void storeRequestedFloor(int requestedFloor);
};

Elevator::Elevator()
{
    std::cout << "Constructing Elevator!" << std::endl;
}

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
    std::cout << "Direction of travel: " << motor.direction << std::endl;
}

void Elevator::openDoor()
{
    std::cout << "Door opening... " << std::endl;
}

void Elevator::storeRequestedFloor(int reqFloor)
{
    control.requestedFloor = reqFloor;
    std::cout << "Requested floor: " << control.requestedFloor << std::endl;
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
    
    CoffeeMaker coffeemaker;
    coffeemaker.heatWater();
    coffeemaker.coffeeType();
    coffeemaker.switchedOn = true;
    coffeemaker.switchOff();

    CoffeeMaker::Cup cup;
    cup.setCupVolume(250);
    cup.getCleanStatus(true);
    cup.setCupColour("Green");

    Dentist::Person person;
    person.name = "Mary";
    person.getInsuranceCompany("Axis");
    person.dateOfNextDentalAppointment(112022);
    person.setGender("female");

    Dentist dentist;
    dentist.returnLastCheck("Mary");
    dentist.feeForService("bridge work");
    dentist.payStaff();

    AutomaticPublicToilet toilet;
    toilet.flushToilet();
    toilet.changeBrightness(4);
    toilet.clean();

    ATM atm;
    atm.dispenseCash();
    atm.displayBalance(12345678);
    atm.dispenseReceipt(250);

    Cabin cabin;
    cabin.setCapacityOfCabin(100, 1000);
    cabin.setNumberOfLights(4, 40);
    cabin.getCapacity();

    Door door;
    door.open();
    door.close();
    door.status();

    Panel panel;
    panel.setSize(12, 2);
    panel.setNumberOfControlButtons(100);
    panel.calculateButtonArea(1.f);

    Control control;
    control.getRequestedFloorNumber(10);
    control.activateAlarm(true);
    control.setMaximumFloor(24);

    Motor motor;
    motor.elevatorAccelerate();
    motor.elevatorDecelerate();
    motor.getWeightOfPassengers(12, 70);

    Elevator elevator;
    elevator.setDirection(12, 2);
    elevator.openDoor();
    elevator.storeRequestedFloor(8);

    std::cout << "good to go!" << std::endl;
}
