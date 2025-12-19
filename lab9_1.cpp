#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double loan, ratePercent, payPerYear;

    cout << "Enter initial loan: ";
    cin >> loan;

    cout << "Enter interest rate per year (%): ";
    cin >> ratePercent;

    cout << "Enter amount you can pay per year: ";
    cin >> payPerYear;

    // Header
    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    cout << fixed << setprecision(2);

    int year = 1;
    double prevBalance = loan;

    while (prevBalance > 0.0) {
        double interest = prevBalance * (ratePercent / 100.0);
        double total = prevBalance + interest;

        double payment = (total < payPerYear) ? total : payPerYear;

        double newBalance = total - payment;

        
        if (newBalance < 0.005) newBalance = 0.0;

        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        prevBalance = newBalance;
        year++;
    }

    return 0;
}
