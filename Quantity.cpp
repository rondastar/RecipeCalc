#include "Quantity.h"

// Constructors
// Constructor for whole numbers
Quantity::Quantity(int wholeNumber) 
{
	SetQuantity(wholeNumber);
}

// Constructor for fractions
Quantity::Quantity(int numerator, int denominator)
{
	SetQuantity(numerator, denominator);
}

// Constructor for mixed numbers
Quantity::Quantity(int wholeNumber, int numerator, int denominator)
{
	SetQuantity(wholeNumber, numerator, denominator);
}

// Setters
// Setter for whole numbers
void Quantity::SetQuantity(int wholeNumber) 
{
	m_wholeNumber = wholeNumber;
}

// Setter for fractions
void Quantity::SetQuantity(int numerator, int denominator)
{
	m_numerator = numerator;
	m_denominator = denominator;
}

// Setter for mixed numbers
void Quantity::SetQuantity(int wholeNumber, int numerator, int denominator)
{
	m_wholeNumber = wholeNumber;
	m_numerator = numerator;
	m_denominator = denominator;
}

// Getters
int Quantity::getWholeNumber() { return m_wholeNumber; }
int Quantity::getNumerator() { return m_numerator; }
int Quantity::getDenominator() { return m_denominator; }