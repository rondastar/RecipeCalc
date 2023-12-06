#ifndef INGREDIENT_LINE_H
#define INGREDIENT_LINE_H

#include "Quantity.h"
#include <string>

class IngredientLine
{
private:
	Quantity m_quantity;
	std::string m_unit;
	std::string m_ingredient;

public:
	// Constructors
	// Constructor for format quantity unit ingredient
	IngredientLine(Quantity, std::string, std::string);	

	// Constructor for format quantity ingredient
	IngredientLine(Quantity, std::string);

	// Constructor for format ingredient
	IngredientLine(std::string);

	// Setters
	// Setter for format quantity unit ingredient
	void SetIngredientLine(Quantity, std::string, std::string);	

	// Setter for format quantity ingredient
	void SetIngredientLine(Quantity, std::string);	

	// Setter for format ingredient
	void SetIngredientLine(std::string);

	// Getters
	Quantity getQuantity();
	std::string getUnit();
	std::string getIngredient();
};
#endif
