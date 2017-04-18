//----------------------------------------------------------------------------//
// Name: Matthew Geller                                                       //
// Student ID: 277842                                                         //
// Assignment: #3                                                             //
//----------------------------------------------------------------------------//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#define PARTINFO_CNT 15
#define PARTTYPES_CNT 4

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

	//returns the gross sum for the product
	double getGrossSum() const;

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

//overload for << operator and Brakes
ostream& operator<<(ostream &os, const Brakes &brakes);

//counts the number of various car parts passed in from a file, and returns the number of each of them found
void countParts(ifstream &inFile, int *counterArray);

//reads information in from a file into properly sized arrays of objects
void populatePartArrays(ifstream &inFile, Brakes* brakesArray, Lights* lightsArray, Oil* oilArray, Tires* TiresArray, int* counts);

//finds the best brakes in an array of brakes
Brakes& findBestBrakes(Brakes* brakeArray, int count);

//finds the best lights in an array of lights
Lights& findBestLights(Lights* lightArray, int count);

//finds the best oil in an array of oil
Oil& findBestOil(Oil* oilArray, int count);

//find the best tires in an array of tires
Tires& findBestTires(Tires* tiresArray, int count);

//finds the best (highest grossing) part when an array of parts and the length of that array are passed in
template <class T>
T& findBestPart(T* partArray, int count)
{
	T &bestPart = partArray[0];
	for (int i = 1; i < count; i++)
	{
		if (partArray[i].getGrossSum() > bestPart.getGrossSum())
		{
			bestPart = partArray[i];
		}
	}
	return bestPart;
}

//Brakes& findBestBrakes(Brakes* brakeArray, int count)
//{
//	cout << "In findBestBrakes()" << endl << endl;
//	Brakes &bestBrakes = brakeArray[0];
//	for (int i = 1; i < count; i++)
//	{
//		if (brakeArray[i].getGrossSum() > bestBrakes.getGrossSum())
//		{
//			bestBrakes = brakeArray[i];
//		}
//	}
//	return bestBrakes;
//}

//takes in one of each part and prints their info to a file
void printPartsToFile(Brakes brakes, Lights lights, Oil oil, Tires tires);

void parseLineToTokens(string lineText, string tokens[]);

int main()
{
	//open the file from which to read the data
	ifstream inFile;
	inFile.open("Parts_List.txt");
	if (!inFile)
	{
		cerr << "Couldn't find a file to analyze" << endl;
		exit(1);
	}

	string rawDataTokens[PARTINFO_CNT];

	//call a global function to find out how many objects of each type to create
	int myCounts[4]; //0=Brakes  1=Lights  2=Oil  3=Tires
	countParts(inFile, myCounts);

	//create arrays to contain the necessary objects
	Brakes* brakesArray = new Brakes[myCounts[0]];
	Lights* lightsArray = new Lights[myCounts[1]];
	Oil* oilArray = new Oil[myCounts[2]];
	Tires* tiresArray = new Tires[myCounts[3]];

	//global function to read information from the file into the arrays of objects
	populatePartArrays(inFile, brakesArray, lightsArray, oilArray, tiresArray, myCounts);

	//call functions to find the best selling item for each category, output best to a file
	//Brakes &bestBrakes = findBestBrakes(brakesArray, myCounts[0]);
	Brakes &bestBrakes = findBestPart(brakesArray, myCounts[0]);
	//Lights &bestLights = findBestLights(lightsArray, myCounts[1]);
	//Oil &bestOil = findBestOil(oilArray, myCounts[2]);
	//Tires &bestTires = findBestTires(tiresArray, myCounts[3]);

	//printPartsToFile(bestBrakes, bestLights, bestOil, bestTires);

	//close the file explicitly
	inFile.close();
}


Car::Car()
	:brand(""), model(""), year(0)
{}

Car::Car(string b, string m, int y)
	: brand(b), model(m), year(y)
{}

string Car::getBrand() const { return brand; }
string Car::getModel() const { return model; }
int Car::getYear() const { return year; }

Parts::Parts()
	:description(""), price(0), manufacturer(""), qtySold(0)
{}

Parts::Parts(string description, double price, string manufacturer, int qtySold)
	: description(description), price(price), manufacturer(manufacturer), qtySold(qtySold)
{}

string Parts::getDescription() const { return description; }
double Parts::getPrice() const { return price; }
string Parts::getManufacturer() const { return manufacturer; }
int Parts::getQtySold() const { return qtySold; }
double Parts::getGrossSum() const { return (price * qtySold); }

Brakes::Brakes()
	:car(), material("")
{}

Brakes::Brakes(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, string material)
	: Parts(description, price, manufacturer, qtySold), car(carBrand, carModel, carYear), material(material)
{}

string Brakes::getMaterial() const { return material; }
string Brakes::getBrand() const { return car.getBrand(); }
string Brakes::getModel() const { return car.getModel(); }
int Brakes::getYear() const { return car.getYear(); }

ostream& operator <<(ostream &os, const Brakes &brakes)
{
	os << "**Brakes**" << endl; // figure out if you're doing this right
	return os;
}

Lights::Lights()
	:car(), watts(0)
{}

Lights::Lights(string description, double price, string manufacturer, int qtySold, string carBrand, string carModel, int carYear, double watts)
	: Parts(description, price, manufacturer, qtySold), car(carBrand, carModel, carYear), watts(watts)
{}

double Lights::getWatts() const { return watts; }
string Lights::getBrand() const { return car.getBrand(); }
string Lights::getModel() const { return car.getModel(); }
int Lights::getYear() const { return car.getYear(); }

Oil::Oil()
	:Parts(), weight(""), type(""), quarts(0)
{}

Oil::Oil(string description, double price, string manufacturer, int qtySold, string weight, string type, int quarts)
	: Parts(description, price, manufacturer, qtySold), weight(weight), type(type), quarts(quarts)
{}

string Oil::getWeight() const { return weight; }
string Oil::getType() const { return type; }
int Oil::getQuarts() const { return quarts; }

Tires::Tires()
	:Parts(), size(), waranty()
{}

Tires::Tires(string description, double price, string manufacturer, int qtySold, string size, string waranty)
	: Parts(description, price, manufacturer, qtySold), size(size), waranty(waranty)
{}

string Tires::getSize() const { return size; }
string Tires::getWaranty() const { return waranty; }


void countParts(ifstream &inFile, int *countArray)
{
	for (int i = 0; i < PARTTYPES_CNT; i++)
	{
		countArray[i] = 0;
	}
	//0=Brakes  1=Lights  2=Oil  3=Tires

	while (inFile.good())
	{
		string myString = "";
		getline(inFile, myString);
		myString = myString.substr(1, myString.find(',') - 2);
		if (myString == "Brakes")
		{
			countArray[0]++;
			cout << "counted a brake!\n";
		}

		else if (myString == "Lights")
		{
			countArray[1]++;
			cout << "counted lights!\n";
		}

		else if (myString == "Oil")
		{
			countArray[2]++;
			cout << "counted oil!\n";
		}

		else if (myString == "Tires")
		{
			countArray[3]++;
			cout << "counted tires!\n";
		}
	}

	inFile.clear();
	inFile.seekg(0, ios::beg);
}

void populatePartArrays(ifstream &inFile, Brakes* brakesArray, Lights* lightsArray, Oil* oilArray, Tires* TiresArray, int* counts)
{

	int brakesCounter = 0;
	int lightsCounter = 0;
	int oilCounter = 0;
	int tiresCounter = 0;

	string tokens[15];
	while (inFile.good())
	{
		string wholeLine = "";
		getline(inFile, wholeLine);
		parseLineToTokens(wholeLine, tokens);
		if (tokens[0] == "Brakes")
		{
			Brakes temp(tokens[1], stod(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5], tokens[6], stoi(tokens[7]), tokens[8]);
			brakesArray[brakesCounter++] = temp;
		}

		if (tokens[0] == "Lights")
		{
			Lights temp(tokens[1], stod(tokens[2]), tokens[3], stoi(tokens[4]), tokens[5], tokens[6], stoi(tokens[7]), stod(tokens[9]));
			lightsArray[lightsCounter++] = temp;
		}

		if (tokens[0] == "Oil")
		{
			Oil temp(tokens[1], stod(tokens[2]), tokens[3], stoi(tokens[4]), tokens[10], tokens[11], stoi(tokens[12]));
			oilArray[oilCounter++] = temp;
		}

		if (tokens[0] == "Tires")
		{
			Tires temp(tokens[1], stod(tokens[2]), tokens[3], stoi(tokens[4]), tokens[13], tokens[14]);
			TiresArray[tiresCounter++] = temp;
		}

	}

}

Brakes& findBestBrakes(Brakes* brakeArray, int count)
{
	cout << "In findBestBrakes()" << endl << endl;
	Brakes &bestBrakes = brakeArray[0];
	for (int i = 1; i < count; i++)
	{
		if (brakeArray[i].getGrossSum() > bestBrakes.getGrossSum())
		{
			bestBrakes = brakeArray[i];
		}
	}
	return bestBrakes;
}



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