#include "Quantity.h"
#include "IngredientLine.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

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

void printQuantity(Quantity qty) {
    // prints quantity (no endline)
    if (qty.getWholeNumber() != 0) {
        std::cout << qty.getWholeNumber() << ' ';
    }
    if (qty.getNumerator() != 0) {
        std::cout << qty.getNumerator()
            << "/" << qty.getDenominator() << ' ';
    }
}

void prepopulateQuantities() {      // for testing functions
    Quantity mixedNum = Quantity::Quantity(1, 2, 3);  // 1 2/3  - test mixed number
    Quantity wholeNum = Quantity::Quantity(2);        // 2      - test small int
    Quantity fraction = Quantity::Quantity(1, 4);     // 1/4    - test fraction 
    Quantity wholeNum2 = Quantity::Quantity(500);     // 500    - test larger int

    // testing functions using quantities
    printQuantity(multiplyQuantity(mixedNum, 10));   // works
    printQuantity(multiplyQuantity(wholeNum, 4));    // works
    printQuantity(multiplyQuantity(fraction, 2));    // works
    printQuantity(multiplyQuantity(wholeNum2, 2));   // NOTE: realized I need to initialize all variables
}

void printIngredientLine(IngredientLine il) {
    // prints ingredient line
    printQuantity(il.getQuantity());
    if (il.getUnit() != "0") {

        std::cout << il.getUnit() << ' ';
    }
    std::cout <<  il.getIngredient() << std::endl;
 }

IngredientLine testIngredient() {       // for testing functions
    Quantity testQty{ Quantity(3) };
    IngredientLine testIngredient{ IngredientLine(testQty, "cups", "flour") };
    return testIngredient;
}

void parseQuantityString() {
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::string first_on_line;
        std::string second_on_line;
        std::string third_on_line;
        if (iss >> first_on_line >> second_on_line >> third_on_line);
            
    }

    //Quantity q = Quantity();
    //    std::string rawInput;
    //    std::cout << "Enter a whole number, mixed number, or fraction" << std::endl;
    //    
    //    while (std::getline(std::cin, rawInput, ' ')) {
    //        int int1{ 0 };
    //        int int2{ 0 };
    //        int int3{ 0 };
    //        //std::string str1{ "0" };
    //        //std::string str2{ "0" };
    //        //std::string str3{ "0" };
    //        bool isNum{ true };

    //        for (int i = 0; 1 < rawInput.length(); ++i) {
    //            if (isNum) {
    //                isNum = isdigit(rawInput[i]);
    //                if (int1 == 0) {
    //                    int1 = isdigit(rawInput[i]);
    //                    break;
    //                }
    //                else if (int2 == 0) {
    //                    int2 = isdigit(rawInput[i]);
    //                    break;
    //                }
    //                else if (int3 == 0) {
    //                    int3 = isdigit(rawInput[i]);
    //                    break;
    //                }
    //                else {
    //                    std::cout << "Please enter recipe line in format quantity"
    //                        << "(whole number, fraction, or mixed number) unit ingredient." << std::endl;
    //                    break;
    //                }
    //                //}
    //                //else (is)
    //                break;
    //            }
    //        } 

    //        std::cout << "int1 is " << int1 << "\nint2 is" << int2 << "\nint3 is" << int3 << std::endl;
    //    }

}

int main() {
    //prepopulateQuantities();
    //printIngredientLine(testIngredient());
    parseQuantityString();

    return 0;
}

