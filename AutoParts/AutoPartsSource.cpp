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
};

class Lights : public Parts
{
};

class Oil : public Parts
{
};

class Tires : public Parts
{
};

void parseLineToTokens(string lineText, string tokens[]);

int main()
{
	//open the file from which to read the data

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