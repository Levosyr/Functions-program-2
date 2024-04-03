#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getInput(double& currentPrice, double& priceOneYearAgo, double& priceTwoYearsAgo);
// PRECONDITION: None.
// POSTCONDITION: Modifies currentPrice, priceOneYearAgo, and priceTwoYearsAgo with user input.

void calculateInflation(double currentPrice, double priceOneYearAgo, double priceTwoYearsAgo, double& inflationRate1, double& inflationRate2);
// PRECONDITION: currentPrice, priceOneYearAgo, and priceTwoYearsAgo are real numbers representing the current price and prices from one and two years ago respectively.
// POSTCONDITION: Calculates the inflation rates for two successive years and modifies inflationRate1 and inflationRate2.

void outputResults(double inflationRate1, double inflationRate2);
// PRECONDITION: inflationRate1 and inflationRate2 are real numbers representing the inflation rates for two successive years.
// POSTCONDITION: Outputs the inflation rates and the trend (increasing or decreasing).

int main() {
    double currentPrice, priceOneYearAgo, priceTwoYearsAgo;
    double inflationRate1, inflationRate2;

    getInput(currentPrice, priceOneYearAgo, priceTwoYearsAgo);

    calculateInflation(currentPrice, priceOneYearAgo, priceTwoYearsAgo, inflationRate1, inflationRate2);

    outputResults(inflationRate1, inflationRate2);

    return 0;
}

// Function definitions
void getInput(double& currentPrice, double& priceOneYearAgo, double& priceTwoYearsAgo) {
    cout << "Enter the current price of the item: ";
    cin >> currentPrice;
    cout << "Enter the price of the item one year ago: ";
    cin >> priceOneYearAgo;
    cout << "Enter the price of the item two years ago: ";
    cin >> priceTwoYearsAgo;
}

void calculateInflation(double currentPrice, double priceOneYearAgo, double priceTwoYearsAgo, double& inflationRate1, double& inflationRate2) {
    inflationRate1 = (currentPrice - priceOneYearAgo) / priceOneYearAgo;
    inflationRate2 = (priceOneYearAgo - priceTwoYearsAgo) / priceTwoYearsAgo;
}

void outputResults(double inflationRate1, double inflationRate2) {
    cout << fixed << setprecision(2);
    cout << "Inflation rate for the first year: " << (inflationRate1 > 0 ? "+" : "") << (inflationRate1 * 100) << "%" << endl;
    cout << "Inflation rate for the second year: " << (inflationRate2 > 0 ? "+" : "") << (inflationRate2 * 100) << "%" << endl;

    if (inflationRate1 > inflationRate2) {
        cout << "Inflation trend: Decreasing" << endl;
    }
    else if (inflationRate1 < inflationRate2) {
        cout << "Inflation trend: Increasing" << endl;
    }
    else {
        cout << "Inflation trend: Stable" << endl;
    }
}
