/**
 * @file forestry.h
 * 
 * @brief Provides functions for math. utilities
 */

#ifndef FORESTRY_H
#define FORESTRY_H

#include "../../utility/header/commonTypes.h"

namespace Coruh
{
    namespace Forestry
    {
        /**
            @class Forestry
            @brief Provides Basic functions for various operations.
        */
        class Forestry
        {
        public:
            /**
             * Adds two numbers.
             * @param a First operand.
             * @param b Second operand.
             * @return The sum of a and b.
             */
            static double add(double a, double b);

            /**
             * Subtracts the second number from the first.
             * @param a Minuend.
             * @param b Subtrahend.
             * @return The result of a - b.
             */
            static double subtract(double a, double b);

            /**
             * Multiplies two numbers.
             * @param a First operand.
             * @param b Second operand.
             * @return The product of a and b.
             */
            static double multiply(double a, double b);

            /**
             * Divides the first number by the second.
             * Throws std::invalid_argument if the second number is zero.
             * @param a Dividend.
             * @param b Divisor.
             * @return The result of a / b.
             * @throws std::invalid_argument If b is zero.
             */
            static double divide(double a, double b);


        };
    }
}

#endif // FORESTRY_H