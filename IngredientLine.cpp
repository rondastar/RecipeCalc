#include "IngredientLine.h"

// Constructors
// Constructor for format quantity unit ingredient
IngredientLine::IngredientLine(Quantity quantity, std::string unit, std::string ingredient) 
{
	SetIngredientLine(quantity, unit, ingredient);
}

// Constructor for format quantity ingredient
IngredientLine::IngredientLine(Quantity quantity, std::string ingredient) 
{
	SetIngredientLine(quantity, ingredient);
}

// Constructor for format ingredient
IngredientLine::IngredientLine(std::string ingredient) 
{
	SetIngredientLine(ingredient);
}

// Setters
// Setter for format quantity unit ingredient
void IngredientLine::SetIngredientLine(Quantity quantity, std::string unit, std::string ingredient) 
{
	m_quantity = quantity;
	m_unit = unit;
	m_ingredient = ingredient;

}

// Setter for format quantity ingredient
void IngredientLine::SetIngredientLine(Quantity quantity, std::string ingredient)
{
	m_quantity = quantity;
	m_ingredient = ingredient;

}

// Setter for format ingredient
void IngredientLine::SetIngredientLine(std::string ingredient)
{
	m_ingredient = ingredient;

}

// Getters
Quantity IngredientLine::getQuantity() { return m_quantity; }
std::string IngredientLine::getUnit() { return m_unit; }
std::string IngredientLine::getIngredient() { return m_ingredient; }
 