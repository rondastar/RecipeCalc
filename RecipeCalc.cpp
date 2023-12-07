#include "Quantity.h"
#include "IngredientLine.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

void multiplyAndPrintQuantity(Quantity qty, int multiplier) {
    int productWholeNumber{ 0 };        // default 0
    int productNumerator{ 0 };          // default 0
    int productDenominator{ -1 };       // default -1
    if (qty.getWholeNumber() != 0) {    // if qty has whole number, multiply it
        productWholeNumber = (qty.getWholeNumber() * multiplier);
        if (qty.getNumerator() == 0) {  // if there is no fraction, print whole number and return.
            std::cout << productWholeNumber << std::endl;
            return;
        }
    }
    if (qty.getNumerator() != 0) {   // if qty has fraction
        productNumerator = (qty.getNumerator() * multiplier);  // multiply it
        productDenominator = qty.getDenominator();           // denominator remains the same

        // reduce fraction if possible
        if (productNumerator >= productDenominator) {
            productWholeNumber += (productNumerator / productDenominator);
            productNumerator = (productNumerator % productDenominator);
            if (productNumerator == 0) {       // prints if reduces to whole number only
                std::cout << productWholeNumber << std::endl;
                return;
            }
        }
        else if ((productNumerator % multiplier == 0) && (productDenominator % multiplier == 0)) {
            productNumerator = (productNumerator / multiplier);
            productDenominator = (productDenominator / multiplier);
        }
    }
    if (productWholeNumber == 0) {          // prints fraction
        std::cout << productNumerator << '/' << productDenominator << std::endl;
        return;
    }
    else {                                  // prints mixed number
        std::cout << productWholeNumber << ' ' << productNumerator << '/' << productDenominator << std::endl;
        return;
    }    
}
Quantity multiplyQuantity(Quantity qty, int multiplier) {
    int productWholeNumber{ 0 };        // default 0
    int productNumerator{ 0 };          // default 0
    int productDenominator{ -1 };       // default -1
    if (qty.getWholeNumber() != 0) {    // if qty has whole number, multiply it
        productWholeNumber = (qty.getWholeNumber() * multiplier);
        if (qty.getNumerator() == 0) {  // if there is no fraction return whole number quantity
            return Quantity(productWholeNumber);
        }
    }
    if (qty.getNumerator() != 0) {   // if qty has fraction
        productNumerator = (qty.getNumerator() * multiplier);   // multiply it
        productDenominator = qty.getDenominator();              // denominator remains the same

        // reduce fraction if possible
        if (productNumerator >= productDenominator) {
            productWholeNumber += (productNumerator / productDenominator);
            productNumerator = (productNumerator % productDenominator);
            if (productNumerator == 0) {       // if reduces to whole number only, returns whole number quantity
                return Quantity(productWholeNumber);
            }
        }
        else if ((productNumerator % multiplier == 0) && (productDenominator % multiplier == 0)) {
            productNumerator = (productNumerator / multiplier);
            productDenominator = (productDenominator / multiplier);
        }
    }
    if (productWholeNumber == 0) {          // returns fraction quantity
        return Quantity(productNumerator, productDenominator);
    }
    else {                                  // returns mixed number quantity
        std::cout << productWholeNumber << ' ' << productNumerator << '/' << productDenominator << std::endl;
        return Quantity(productWholeNumber, productNumerator, productDenominator);
    }
}

void prepopulateQuantities() {
    Quantity mixedNum = Quantity::Quantity(1, 2, 3);  // 1 2/3  - test mixed number
    Quantity wholeNum = Quantity::Quantity(2);        // 2      - test small int
    Quantity fraction = Quantity::Quantity(1, 4);     // 1/4    - test fraction 
    Quantity wholeNum2 = Quantity::Quantity(500);     // 500    - test larger int
    //multiplyQuantity(mixedNum, 10);   // works
    //multiplyQuantity(wholeNum, 4);    // works
    //multiplyQuantity(fraction, 2);    // works
    //multiplyQuantity(wholeNum2, 2);   // NOTE: realized I need to set unspecified members to null or null pointers, or give them values
}

void printIngredientLine(IngredientLine il) {
    // prints ingredient line
    if (il.getQuantity().getWholeNumber() != 0) {
        std::cout << il.getQuantity().getWholeNumber() << ' ';
    }
    if (il.getQuantity().getNumerator() != 0) {
        std::cout << il.getQuantity().getNumerator() 
            << "/" << il.getQuantity().getDenominator() << ' ';
    }
    if (il.getUnit() != "0") {

        std::cout << il.getUnit() << ' ';
    }
    std::cout <<  il.getIngredient() << std::endl;
 }

IngredientLine testIngredient() {
    Quantity testQty{ Quantity(3) };
    IngredientLine testIngredient{ IngredientLine(testQty, "cups", "flour") };
    return testIngredient;
}
//void getUserInput() {
//    std::string rawInput;
//    std::cout << "Enter a number, or numbers separated by a space, between 1 and 1000." << endl;
//    while (std::getline(std::cin, rawInput, ' '))
//    {
//        IngredientLine ingredientLine = ingredientLine()
//        bool isNum = true;
//        for (int i = 0; i < rawInput.length() && isNum; ++i)
//        {
//            isNum = isdigit(rawInput[i]);
//        }
//
//        if (isNum)
//        {
//            num = atoi(rawInput.c_str());
//            ...//do your stuff
//        }
//        else
//            std::cout << rawInput << " is not a number!" << endl;
//    }
//}
int main() {
    prepopulateQuantities();
    printIngredientLine(testIngredient());

    return 0;
}

