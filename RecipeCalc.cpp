#include "Quantity.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

void multiplyQuantity(Quantity qty, int multiplier) {
    int productWholeNumber{ 0 };  // default 0
    int productNumerator{ 0 };      // default 0
    int productDenominator{ -1 };  // default -1
    if (qty.getWholeNumber() != 0) {  // if qty has whole number, multiply it
        productWholeNumber = (qty.getWholeNumber() * multiplier);
        if (qty.getNumerator() == 0) { // if there is no fraction, print whole number and return.
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
void prepopulateQuantities() {
    Quantity mixedNum = Quantity::Quantity(1, 2, 3);  // 1 1/2  - test converting mixed number
    Quantity wholeNum = Quantity::Quantity(2);        // 2      - test converting small int
    Quantity fraction = Quantity::Quantity(1, 4);     // 3/4    - test converting fraction only
    Quantity wholeNum2 = Quantity::Quantity(500);       // 500    - test converting larger number
    multiplyQuantity(mixedNum, 10); // works
    multiplyQuantity(wholeNum, 4); // works
    multiplyQuantity(fraction, 2); // needs to be reduced
    multiplyQuantity(wholeNum2, 2); // NOTE: realized I need to set unspecified members to null or null pointers, or give them values
}
int main() {
    prepopulateQuantities();

    return 0;
}
