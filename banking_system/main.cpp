
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

// Function declarations
void showMenu();
void showBalance(double balance);
double deposit();
double withdraw(double balance);
void printLine(char symbol = '=', int width = 42);

int main()
{
    double balance = 12.27;
    int choice = 0;

    // Professional currency formatting
    cout << fixed << setprecision(2);

    do
    {
        showMenu();

        cout << "  Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "\n  [!] Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n  Press Enter to continue...";
            cin.get();
            continue;
        }

        cout << '\n';

        switch (choice)
        {
            case 1:
                showBalance(balance);
                break;

            case 2:
            {
                double amount = deposit();

                if (amount > 0)
                {
                    balance += amount;
                    cout << "\n  [SUCCESS] Deposit completed!\n";
                    showBalance(balance);
                }
                break;
            }

            case 3:
            {
                double amount = withdraw(balance);

                if (amount > 0)
                {
                    balance -= amount;
                    cout << "\n  [SUCCESS] Withdrawal completed!\n";
                    showBalance(balance);
                }
                break;
            }

            case 4:
                printLine('=');
                cout << "  Thank you for banking with us!\n";
                cout << "  Have a wonderful day. Goodbye!\n";
                printLine('=');
                break;

            default:
                cout << "  [!] Invalid choice. Select 1 - 4.\n";
        }

        if (choice != 4)
        {
            cout << "\n  Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 4);

    return 0;
}

// Print a decorative line
void printLine(char symbol, int width)
{
    cout << "  ";
    for (int i = 0; i < width; i++)
        cout << symbol;
    cout << '\n';
}

// Display the main menu
void showMenu()
{
    cout << "\n\n";
    printLine('=');
    cout << "       WELCOME TO NOVA BANK\n";
    cout << "        ATM BANKING SYSTEM\n";
    printLine('=');

    cout << "  [1]  Check Account Balance\n";
    cout << "  [2]  Deposit Money\n";
    cout << "  [3]  Withdraw Money\n";
    cout << "  [4]  Exit Banking System\n";

    printLine('-');
}

// Display the current balance
void showBalance(double balance)
{
    printLine('-');
    cout << "  ACCOUNT BALANCE\n";
    printLine('-');
    cout << "  Available Balance : $" << balance << '\n';
    printLine('-');
}

// Deposit money
double deposit()
{
    double amount;

    cout << "  Enter deposit amount: $";

    if (!(cin >> amount))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n  [ERROR] Please enter a valid number.\n";
        return 0;
    }

    if (amount <= 0)
    {
        cout << "\n  [ERROR] Deposit must be greater than $0.00.\n";
        return 0;
    }

    return amount;
}

// Withdraw money
double withdraw(double balance)
{
    double amount;

    cout << "  Enter withdrawal amount: $";

    if (!(cin >> amount))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n  [ERROR] Please enter a valid number.\n";
        return 0;
    }

    if (amount <= 0)
    {
        cout << "\n  [ERROR] Withdrawal must be greater than $0.00.\n";
        return 0;
    }

    if (amount > balance)
    {
        cout << "\n  [ERROR] Insufficient funds!\n";
        cout << "  Available balance: $" << balance << '\n';
        return 0;
    }

    return amount;
}
