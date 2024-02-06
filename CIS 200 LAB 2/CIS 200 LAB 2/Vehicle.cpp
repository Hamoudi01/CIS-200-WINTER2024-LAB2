#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Vehicle {
private:
	string make;
	string model;
	string color;
	double kilometersPerLiter;
	double tankCapacityInLiters;
	double litersInTank;

public:

	// Constructor - sets object parameters with object creation
	Vehicle(string make, string model, string color, double kilometersPerLiter,
		double tankCapacityInLiters, double litersInTank) {
		this->make = make;
		this->model = model;
		this->color = color;
		this->kilometersPerLiter = kilometersPerLiter;
		this->tankCapacityInLiters = tankCapacityInLiters;
		this->litersInTank = 0;
	}

	// getter methods
	string getMake() {
		return this->make;
	}

	string getModel() {
		return this->model;
	}

	// setter for color
	void setColor(string color) {
		this->color = color;
	}

	string getColor() {
		return this->color;
	}

	double getKilometersPerLiter() {
		return this->kilometersPerLiter;
	}

	double getTankCapacityInLiters() {
		return this->tankCapacityInLiters;
	}

	double getLiterInTank() {
		return this->litersInTank;
	}

	// Method to drive vehicle
	void drive(double kilometers) {
		double maxDistance = litersInTank * kilometersPerLiter;
		if (kilometers > maxDistance) {
			throw logic_error("Not enough fuel to cover distance.");
		}
		else {
			// Reduce amount of gas in tank
			double usedLiters = kilometers / kilometersPerLiter;
			litersInTank -= usedLiters;
			cout << "Drove " << kilometers << " kilometers. Remaining fuel: "
				<< litersInTank << " liters." << endl;
		}
	}

	// Method to add gas to tank
	void addGas(double liters) {
		if (litersInTank + liters > tankCapacityInLiters) {
			throw logic_error("Tank overflowing. Cannot add more gas. ");
		}
		else {
			// Add specified amount of gas to tank
			litersInTank += liters;
			cout << "Added " << liters << " ltters of gas. Total fuel: "
				<< litersInTank << " litters. " << endl;
		}

	}
};

int main() {
	// Example usage of the Vehicle class
	Vehicle myCar("Ford", "F-150", "Black", 37.5, 130, 0);

	cout << "Make: " << myCar.getMake() << endl;
	cout << "Model: " << myCar.getModel() << endl;
	cout << "Color: " << myCar.getColor() << endl;
	cout << "Kilometers per liter: " << myCar.getKilometersPerLiter() << endl;
	cout << "Tank capacity in liters: " << myCar.getTankCapacityInLiters() << endl;
	cout << "Liters in tank: " << myCar.getLiterInTank() << endl;



	myCar.addGas(100.0);

	try {
		myCar.drive(87.0);
	}
	catch (logic_error exception) {
		cout << exception.what() << endl;
	}

	myCar.setColor("Black");

	return 0;
}



