#include "DivSales.h"
#include <stdexcept>

double DivSales::corporateTotal = 0.0;

DivSales::DivSales(int numberOfPeriods)
{
    if (numberOfPeriods <= 0)
    {
        throw std::invalid_argument("Number of periods must be greater than zero.");
    }

    this->numberOfPeriods = numberOfPeriods;

    sales = new double[numberOfPeriods];

    for (int i = 0; i < numberOfPeriods; i++)
    {
        sales[i] = 0.0;
    }
}

DivSales::DivSales(const DivSales& other)
{
    numberOfPeriods = other.numberOfPeriods;

    sales = new double[numberOfPeriods];

    for (int i = 0; i < numberOfPeriods; i++)
    {
        sales[i] = other.sales[i];
    }
}

DivSales::~DivSales()
{
    delete[] sales;
}

DivSales& DivSales::operator=(const DivSales& other)
{
    if (this != &other)
    {
        delete[] sales;

        numberOfPeriods = other.numberOfPeriods;

        sales = new double[numberOfPeriods];

        for (int i = 0; i < numberOfPeriods; i++)
        {
            sales[i] = other.sales[i];
        }
    }

    return *this;
}

double& DivSales::operator[](int index)
{
    if (index < 0 || index >= numberOfPeriods)
    {
        throw std::out_of_range("Invalid sales index.");
    }

    return sales[index];
}

const double& DivSales::operator[](int index) const
{
    if (index < 0 || index >= numberOfPeriods)
    {
        throw std::out_of_range("Invalid sales index.");
    }

    return sales[index];
}

int DivSales::getNumberOfPeriods() const
{
    return numberOfPeriods;
}

double DivSales::getDivisionTotal() const
{
    double total = 0.0;

    for (int i = 0; i < numberOfPeriods; i++)
    {
        total += sales[i];
    }

    return total;
}

double DivSales::getCorporateTotal()
{
    return corporateTotal;
}

void DivSales::resetCorporateTotal()
{
    corporateTotal = 0.0;
}

void DivSales::addToCorporateTotal(double amount)
{
    corporateTotal += amount;
}
