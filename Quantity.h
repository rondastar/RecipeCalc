#ifndef QUANTITY_H
#define QUANTITY_H

class Quantity
{
private: 
	int m_wholeNumber;
	int m_numerator;
	int m_denominator;

public:
	// Constructors
	Quantity();					// Default constructor; required to make Quantity a field in IngredientLine class
	Quantity(int);				// Constructor for whole numbers
	Quantity(int, int);			// Constructor for fractions (numerator, denominator)
	Quantity(int, int, int);	// Constructor for mixed numbers (whole, numerator, denominator)

	// Setters
	void SetQuantity(int);			// Setter for whole numbers
	void SetQuantity(int, int);		// Setter for fractions
	void SetQuantity(int, int, int);// Setter for mixed numbers

	// Getters
	int getWholeNumber();
	int getNumerator();
	int getDenominator();
};
#endif

