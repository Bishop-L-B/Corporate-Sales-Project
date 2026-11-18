#include <iostream>
#include <fstream>
#include "DivSales.h"
#include<iomanip>

int main()
{
    std::ifstream inputFile("Corporate_Sales_Monthly_Test_Data.txt");

    if (!inputFile)
    {
        std::cout << "Error opening sales file.\n";
        return 1;
    }

    int numberOfPeriods;

    if (!(inputFile >> numberOfPeriods) || numberOfPeriods <= 0)
    {
        std::cout << "Invalid number of sales periods.\n";
        return 1;
    }

    std::cout << "Number of sales periods: "
        << numberOfPeriods << "\n";

    const int NUM_DIVISIONS = 6;

    DivSales divisions[NUM_DIVISIONS] =
    {
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods),
        DivSales(numberOfPeriods)
    };

    DivSales::resetCorporateTotal();

    for (int division = 0; division < NUM_DIVISIONS; division++)
    {
        for (int period = 0; period < numberOfPeriods; period++)
        {
            if (!(inputFile >> divisions[division][period]))
            {
                std::cout << "Error reading sales data.\n";
                return 1;
            }

            if (divisions[division][period] <= 0)
            {
                std::cout << "Invalid sales value.\n";
                return 1;
            }
        }

        DivSales::addToCorporateTotal(
            divisions[division].getDivisionTotal());
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nCorporate Sales Report\n";

    for (int division = 0; division < NUM_DIVISIONS; division++)
    {
        std::cout << "\nDivision " << division + 1 << ":\n";

        for (int period = 0; period < numberOfPeriods; period++)
        {
            std::cout << "Period " << period + 1 << ": $"
                << divisions[division][period] << "\n";
        }

        std::cout << "Division Total: $"
            << divisions[division].getDivisionTotal() << "\n";
    }

    std::cout << "\nCorporate Total: $"
        << DivSales::getCorporateTotal() << "\n";

    inputFile.close();

    return 0;
}
