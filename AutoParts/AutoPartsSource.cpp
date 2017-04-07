//----------------------------------------------------------------------------//
// Name: Matthew Geller                                                       //
// Student ID: 277842                                                         //
// Assignment: #3                                                             //
//----------------------------------------------------------------------------//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#define PARTINFO_CNT 10

using namespace std;

class Car
{
public:
	//default constructor
	Car();

	//parameterized constructor
	Car(string brand, string model, int year);

	//getter for brand
	string getBrand() const;

	//getter for model
	string getModel() const;

	//getter for year
	int getYear() const;

private:
	string brand;
	string model;
	int year;
};

class Parts
{
public:
	//default constructor
	Parts();

	//parameterized constructor
	Parts(string desc, double price, string manufacturer, int qtySold);

	//getter for description
	string getDescription() const;

	//getter for price
	double getPrice() const;

	//getter for manufacturer
	string getManufacturer() const;

	//getter for qtySold
	int getQtySold() const;

protected:
	string description;
	double price;
	string manufacturer;
	int qtySold;
};

class Brakes : public Parts
{
public:
	//default constructor for Brakes
	Brakes();

	//parameterized constructor for Brakes
	Brakes(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, string material);

	//getter for material
	string getMaterial() const;

	//getter for car brand
	string getBrand() const;

	//getter for car model
	string getModel() const;

	//getter for car year
	int getYear() const;

protected:
	Car car;
	string material;

};

class Lights : public Parts
{
public:
	//default constructor for Brakes
	Lights();

	//parameterized constructor for Brakes
	Lights(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, double watts);

	//getter for watts
	double getWatts() const;

	//getter for car brand
	string getBrand() const;

	//getter for car model
	string getModel() const;

	//getter for car year
	int getYear() const;

protected:
	Car car;
	double watts;
};

class Oil : public Parts
{
public:
	//default constructor
	Oil();

	//parameterized constructor
	Oil(string description, double price, string manufacturer, int qtySold, string weight, string type, int quarts);

	//getter for weight
	string getWeight() const;

	//getter for type
	string getType() const;

	//getter for quarts
	int getQuarts() const;

protected:
	string weight;
	string type;
	int quarts;
};

class Tires : public Parts
{
public:
	//default constructor
	Tires();

	//parameterized constructor
	Tires(string description, double price, string manufacturer, int qtySold, string size, string waranty);

	//getter for size
	string getSize() const;

	//getter for waranty
	string getWaranty() const;

protected:
	string size;
	string waranty;

};

void parseLineToTokens(string lineText, string tokens[]);

int main()
{
	//open the file from which to read the data
	ifstream inFile("PartsList.txt");
	if (!inFile)
	{
		cerr << "Couldn't find a file to analyze" << endl;
		exit(1);
	}

	//call a global function to find out how many objects of each type to create

	//create arrays to contain the necessary objects

	//global function to read information from the file into the arrays of objects

	//call functions to find the best selling item for each category, output best to a file

	//close the file explicitly
}

Car::Car()
	:brand(""), model(""), year(0)
{}

Car::Car(string b, string m, int y)
	:brand(b), model(m), year(y)
{}

string Car::getBrand() const { return brand; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }

Parts::Parts()
	:description(""), price(0), manufacturer(""), qtySold(0)
{}

Parts::Parts(string description, double price, string manufacturer, int qtySold)
	:description(description), price(price), manufacturer(manufacturer), qtySold(qtySold)
{}

string Parts::getDescription() const { return description; }
double Parts::getPrice() const { return price; }
string Parts::getManufacturer() const { return manufacturer; }
int Parts::getQtySold() const { return qtySold; }

Brakes::Brakes()
	:car(), material("")
{}

Brakes::Brakes(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, string material)
	:Parts(description, price, manufacturer, qtySold), car(carBrand,carModel, carYear), material(material)
{}

string Brakes::getMaterial() const { return material; }
string Brakes::getBrand() const { return car.getBrand(); }
string Brakes::getModel() const { return car.getModel(); }
int Brakes::getYear() const { return car.getYear(); }


Lights::Lights()
	:car(), watts(0)
{}

Lights::Lights(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, double watts)
	:Parts(description, price, manufacturer, qtySold), car(carBrand, carModel, carYear), watts(watts)
{}

double Lights::getWatts() const { return watts; }
string Lights::getBrand() const { return car.getBrand(); }
string Lights::getModel() const { return car.getModel(); }
int Lights::getYear() const { return car.getYear(); }

Oil::Oil()
	:Parts(), weight(""), type(""), quarts(0)
{}

Oil::Oil(string description, double price, string manufacturer, int qtySold, string weight, string type, int quarts)
	:Parts(description, price, manufacturer, qtySold), weight(weight), type(type), quarts(quarts)
{}

string Oil::getWeight() const { return weight; }
string Oil::getType() const { return type; }
int Oil::getQuarts() const { return quarts; }

Tires::Tires()
	:Parts(), size(), waranty()
{}

Tires::Tires(string description, double price, string manufacturer, int qtySold, string size, string waranty)
	:Parts(description, price, manufacturer, qtySold), size(size), waranty(waranty)
{}

string Tires::getSize() const { return size; }
string Tires::getWaranty() const { return waranty; }

// Parse a line of text into tokens and store them in an array of strings
void parseLineToTokens(string lineText, string tokens[])
{
	int end, start;

	start = -2;
	for (int j = 0; j < PARTINFO_CNT; j++)
	{
		start = start + 3;
		end = lineText.find('"', start);
		tokens[j] = lineText.substr(start, end - start);
		start = end;
	}
}



// Notes:
//
// Example:
// To create an array of 'cnt' Books items, where 'cnt' can only be determined at the time the program is run:
//   Books *booksList;
//   booksList = new Books[cnt];
//
//
// To go back and read from the beginning of the file that was already opened and read till the EOF
//   bookFile.clear();			// reset the EOF state
//   bookFile.seekg(0, ios::beg);	// set pointer at the beginning of the file		