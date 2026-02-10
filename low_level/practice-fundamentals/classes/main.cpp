#include <iostream>

// Vehicle class
class vehicle
{
        int _num_tires, _num_doors;
    public:
        void set_val(int, int);
        int get_tires(), get_doors();
};

void vehicle::set_val(int num_tires, int num_doors)
{
    _num_doors = num_doors;
    _num_tires = num_tires;
}
int vehicle::get_doors() { return _num_doors; }
int vehicle::get_tires() { return _num_tires; }

// ----------------------------
// Truck class
class Truck : vehicle
{
     std::string _bed_type;
     std::string _fuel_type;
    public:
        void set_val(std::string, std::string);
        std::string get_bed(), get_fuel();
};

void Truck::set_val(std::string bed_type, std::string fuel_type)
{
    _bed_type = bed_type;
    _fuel_type = fuel_type;
}
std::string Truck::get_bed() { return _bed_type; } 
std::string Truck::get_fuel() { return _fuel_type; }

// ----------------------------
// Sedan class
class Sedan : vehicle
{
        int _mpg;
        int _cost;
    public:
        void set_val(int, int);
        int get_mpg(), get_cost();
};
void Sedan::set_val(int mpg, int cost)
{
    _mpg = mpg;
    _cost = cost;
}
int Sedan::get_mpg() { return _mpg; }
int Sedan::get_cost() { return _cost; }

// -----------------------------

int main (int argc, char* argv[])
{
    int user_type;

    vehicle v1;
    int door, tires;

    Truck small_truck;
    std::string bed, fuel;

    Sedan small_sedan;
    int mpg, cost;

    std::cout << "Enter the amount of doors in your vehicle: " ;
    std::cin >> door;
    std::cout << "Enter the amount of tires in your vehicle: " ;
    std::cin >> tires;

    v1.set_val(door, tires);

    
    std::cout << "What type of vehicle do you have (truck = 1 or sedan = 2)? ";
    std::cin >> user_type;

    if (user_type == 1)
    {
        std::cout << "Enter the bed type of your truck: " ;
        std::cin >> bed;
        std::cout << "Enter the fuel type of your truck: " ;
        std::cin >> fuel;
        small_truck.set_val(bed, fuel);

        std::cout << "Number of doors: " << v1.get_doors() << std::endl;
        std::cout << "Number of tires: " << v1.get_tires() << std::endl;

        std::cout << "Bed type: " << small_truck.get_bed() << std::endl;
        std::cout << "Fuel type: " << small_truck.get_fuel() << std::endl;
    }
    else if (user_type == 2)
    {
        std::cout << "Enter the average city mpg for your sedan: " ;
        std::cin >> mpg;
        std::cout << "Enter the cost for you sedan: " ;
        std::cin >> cost;
        small_sedan.set_val(mpg, cost);

        std::cout << "Number of doors: " << v1.get_doors() << std::endl;
        std::cout << "Number of tires: " << v1.get_tires() << std::endl;

        std::cout << "MPG: " << small_sedan.get_mpg() << std::endl;
        std::cout << "Cost type: " << small_sedan.get_cost() << std::endl;
    }
    else 
    {
        std::cout << "Error, try again.\n";
    }

    return 0;
}