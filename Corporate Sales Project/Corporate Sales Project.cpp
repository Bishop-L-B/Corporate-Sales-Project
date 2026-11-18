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

    std::cout << "\nCopy Constructor Test\n";

    DivSales copiedDivision(divisions[0]);

    std::cout << "Original Sales: $"
        << divisions[0][0] << "\n";

    std::cout << "Copied Sales: $"
        << copiedDivision[0] << "\n";

    copiedDivision[0] = 10000.00;

    std::cout << "After changing the copy:\n";

    std::cout << "Original Sales: $"
        << divisions[0][0] << "\n";

    std::cout << "Copied Sales: $"
        << copiedDivision[0] << "\n";

    std::cout << "\nCopy Assignment Test\n";

    DivSales assignedDivision(4);

    assignedDivision = divisions[0];

    std::cout << "Original Period Count: "
        << divisions[0].getNumberOfPeriods() << "\n";

    std::cout << "Assigned Period Count: "
        << assignedDivision.getNumberOfPeriods() << "\n";

    std::cout << "Original Sales: $"
        << divisions[0][0] << "\n";

    std::cout << "Assigned Sales: $"
        << assignedDivision[0] << "\n";

    assignedDivision[0] = 20000.00;

    std::cout << "After changing the assigned object:\n";

    std::cout << "Original Sales: $"
        << divisions[0][0] << "\n";

    std::cout << "Assigned Sales: $"
        << assignedDivision[0] << "\n";

    assignedDivision = assignedDivision;

    std::cout << "After self-assignment: $"
        << assignedDivision[0] << "\n";

    return 0;
}
