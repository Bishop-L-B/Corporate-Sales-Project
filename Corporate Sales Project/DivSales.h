#ifndef DIVSALES_H
#define DIVSALES_H

class DivSales
{
private:
    double* sales;
    int numberOfPeriods;
    static double corporateTotal;

public:
    DivSales(int numberOfPeriods);
    ~DivSales();
    DivSales(const DivSales& other);
    DivSales& operator=(const DivSales& other);
    double& operator[](int index);
    const double& operator[](int index) const;
    int getNumberOfPeriods() const;
    double getDivisionTotal() const;
    static double getCorporateTotal();
    static void resetCorporateTotal();
    static void addToCorporateTotal(double amount);

};



#endif