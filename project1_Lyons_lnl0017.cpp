//Lauren Lyons
//project1_Lyons_lnl0017.cpp
//lnl0017

//MinGW G++ Compiler
//g++ -std=c++11 project1_Lyons_lnl0017.cpp -o project1.out
//./project1.out


//Piazza answered my question on which functions 
//          to use to acknowledge non-numerical inputs
//Jessica provided me with the certain parameter that 
//          I was missing in cin.ignore()

#include <iostream>
using namespace std;

int main()
{
    float balance, payment, rate, totalInterest=0, principal, tempInt, startB;
    int month = 0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "\nLoan Amount: ";
    cin >> balance;
    while (balance < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(20, '\n');
        cout << "\nEnter a valid Loan Amount: ";
        cin >> balance;
    }

    cout << "Interest Rate (% per year): ";
    cin >> rate;
    while (rate < 0|| cin.fail())
    {
        cin.clear();
        cin.ignore(20, '\n');
        cout << "\nEnter a valid Interest Rate: ";
        cin >> rate;
    }
    rate /= 12;
    rate /= 100;

    cout << "Monthly Payments: ";
    cin >> payment;
    //cout << "\n\n" << payment << "\t" << balance*rate;
    //cout << "\n\n" << (payment == balance*rate);
    //cout << "\n\n" << payment-(balance*rate) << "\n\n" << (payment-(balance*rate) < 0.01) << "\n\n";
    //payment <= (balance*rate) && (          || (payment-(balance*rate) > 0.01)
    while (payment < 0 || (payment-(balance*rate) < 0.01 )|| cin.fail())
    {
        cin.clear();
        cin.ignore(20, '\n'); 
        cout << "\nEnter a valid Monthly Payment: ";
        cin >> payment;
    }

    cout << "********************************************************\n";
    cout << "\tAmortization Table\n";
    cout << "********************************************************\n";
    cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrinicipal\n";
    cout << "0\t$" << balance << "\tN/A\tN/A\tN/A\t\tN/A\n";

    while (balance > 0)
    {
        if(balance*(1 + rate) < payment)
        {
            tempInt = balance*rate;
            totalInterest += tempInt;
            payment = balance + tempInt;
            principal = balance;
            balance -= principal;
        }
        else
        {
            principal = payment - (balance*rate);
            tempInt = balance*rate;
            totalInterest += tempInt;
            balance -= principal;
        }
        cout << ++month << "\t$" << balance;
        if (balance < 1000) cout << "\t";
        cout << "\t$" << payment << "\t" << (rate*100) << "\t$" << tempInt << "\t\t$" << principal << "\n"; 
    }

    cout << "********************************************************\n";
    cout << "\nIt takes " << month << " months to pay off the loan.\n";
    cout << "Total interest paid is: $" << totalInterest;
    cout << endl << endl;
    return 0;
}