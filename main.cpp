/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct CoffeeMaker
{   
    float maxWaterTemp;
    CoffeeMaker() : maxWaterTemp(75) { }
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
        bool clean;

        void setCupVolume(float vol);
        bool getCleanStatus(); 
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
    clean = true;
}

void CoffeeMaker::Cup::setCupVolume(float vol)
{
    volume = vol;
    std::cout << "Cup volume set: " << volume << std::endl;
}

bool CoffeeMaker::Cup::getCleanStatus()
{
    //clean = cln;
    std::cout << "Clean status: " << clean << std::endl;
    return clean;
    
}

void CoffeeMaker::Cup::setCupColour(std::string col)
{
    colour = col;
    std::cout << "Colour set as: " << colour << std::endl;
}


void CoffeeMaker::heatWater()
{
    switchedOn = true;
    std::cout << "Water heating..." << switchedOn << " Up to temp: " << maxWaterTemp << std::endl;
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
    Dentist() : numPatients(8), numStaff(20)  { }
    int numPatients;
    int maxPatientsPerWeek = 40;
    int costDisposableEquipment = 2000;
    int profitPerWeek = 20000;
    int numStaff;

    struct Person
    {
        Person();
        std::string name;
        int age;
        std::string gender;
        
        std::string insuranceCompany = "No Insurance";
        int dateOfLastCheck = 112022;

        std::string getInsuranceCompany(std::string insurance); 
        int dateOfNextDentalAppointment(int lastCheck); 
        std::string getGender(); 
    };

    int returnLastCheck(std::string name);
    float feeForService(std::string treatmentClassification);
    int payStaff(); 

    Person newPatient;
};

Dentist::Person::Person()
{
    name = "Mary ";
    age = 35;
    gender = "female";
}

std::string Dentist::Person::getInsuranceCompany(std::string insurance)
{
    insuranceCompany = insurance;
    std::cout <<  name << ": Insurance Company: " << insuranceCompany << std::endl;
    return insuranceCompany;
}

int Dentist::Person::dateOfNextDentalAppointment(int lastCheck)
{
    dateOfLastCheck = lastCheck;
    std::cout << name << ": Next routine appointment due " << lastCheck + 1 << std::endl;
    return dateOfLastCheck + 1;
}

std::string Dentist::Person::getGender()
{
    std::cout << name << ": Gender: " << gender << std::endl;
    return gender;
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

    AutomaticPublicToilet() : volumeOfCleaningReservoir(20) { }
    float volumeOfCistern = 5;
    float volumeOfCleaningReservoir;
    int numberOfFlushesPerDay = 40;
    int brightnessOfLights = 4;
    float volumeOfWaterPerFlush = 2;

    void flushToilet();
    void changeBrightness(int requestedBrightness);
    void clean();

};


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
    std::cout << "Volume of cleaning reservoir: " << volumeOfCleaningReservoir << std::endl;
}



struct ATM
{
    ATM();
    double currentAmountAvailable;
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
    //std::cout << "Constructing ATM!" << std::endl;
    currentAmountAvailable = 20000;
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
    std::cout << "Current amount available " << currentAmountAvailable << std::endl;
}



struct Cabin
{
    Cabin() : volumeOfElevatorCabin(8), floorArea(4), numLights(4), wallColour("white"), capacityInPersons(12) { }
    int volumeOfElevatorCabin;
    int floorArea;
    int numLights;
    std::string wallColour;
    int capacityInPersons;

    int setCapacityOfCabin(int vol); 
    int setNumberOfLights(int maxBrightness); 
    int getCapacity(); 
};


int Cabin::setCapacityOfCabin(int vol)
{
    volumeOfElevatorCabin = vol;
    capacityInPersons = volumeOfElevatorCabin / floorArea; 
    std::cout << "Capacity in persons: " << capacityInPersons << std::endl;
    return capacityInPersons;
}

int Cabin::setNumberOfLights(int maxBrightness)
{
    std::cout << "Number of lights: " << maxBrightness / floorArea << std::endl;
    return maxBrightness / floorArea;
}

int Cabin::getCapacity()
{
    std::cout << "Capacity in persons: " << capacityInPersons << std::endl;
    return capacityInPersons;
}


struct Door
{
    Door();
    double height = 2.4;
    double width = 1.2;
    double speedOfMovement;
    std::string colour;
    bool closureStatus = false;

    void open();
    void close();
    bool status(); 
};

Door::Door()
{
    colour = "blue";
    speedOfMovement = 0.5;
    std::cout << "Constructing Door!" << std::endl;
    std::cout <<  "Door colour: " << colour << std::endl;
}

void Door::open()
{
    std::cout << "Door status: opening at " << speedOfMovement << " m/s" << std::endl;
}

void Door::close()
{
    std::cout << "Door status: closing at " << speedOfMovement << " m/s" <<std::endl;
}

bool Door::status()
{
    std::cout << "Closure status " << closureStatus << std::endl;
    return closureStatus;
}


struct Panel
{
    Panel() : buttonDiameter(10) { }
    float area = 450;
    std::string material = "aluminium";
    int numButtons = 24;
    int buttonDiameter;
    int backlightBrightness = 4; 

    int setSize(int numPanelButtons, int buttonSize); 
    int setNumberOfControlButtons(int a); 
    float calculateButtonArea(float diam); 
};

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
    Control() : alarmActivated(false) { }
    int currentFloor = 1;
    int requestedFloor = 1;
    int maximumFloor = 12;
    int minimumFloor = -1;
    bool alarmActivated;

    int getRequestedFloorNumber(int reqFloor); 
    bool alarmStatus();
    void setMaximumFloor(int max);
};

int Control::getRequestedFloorNumber(int reqFloor)
{
    requestedFloor = reqFloor;
    std::cout << "Floor requested: " << requestedFloor << std::endl;
    return requestedFloor;
}

bool Control::alarmStatus()
{
    std::cout << "Alarm status: " << alarmActivated << std::endl;
    return alarmActivated;
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
    double elevatorAcceleration;
    double elevatorDeceleration;
    std::string direction = "up"; 
    int passengerWeight = 600;

    double elevatorAccelerate();
    double elevatorDecelerate();
    double getWeightOfPassengers(int numberOfPassengers, int AverageWeight); 
};

Motor::Motor()
{
    elevatorAcceleration = 0.8;
    elevatorDeceleration = 0.8;
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

    void setDirection(int requested);
    void openDoor();
    void storeRequestedFloor(int requestedFloor);
};


Elevator::Elevator()
{
    control.currentFloor = 2;
    std::cout << "Constructing Elevator!" << std::endl;
}


void Elevator::setDirection(int requested)
{
    //control.currentFloor = current;
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
    cup.getCleanStatus();
    cup.setCupColour("Green");

    Dentist::Person person;
    person.name = "Mary";
    person.getInsuranceCompany("Axis");
    person.dateOfNextDentalAppointment(112022);
    person.getGender();

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
    cabin.getCapacity();
    cabin.setCapacityOfCabin(1000);
    cabin.setNumberOfLights(40);
    

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
    control.alarmStatus();
    control.setMaximumFloor(24);

    Motor motor;
    motor.elevatorAccelerate();
    motor.elevatorDecelerate();
    motor.getWeightOfPassengers(12, 70);

    Elevator elevator;
    elevator.setDirection(12);
    elevator.openDoor();
    elevator.storeRequestedFloor(8);

    std::cout << "good to go!" << std::endl;
}
