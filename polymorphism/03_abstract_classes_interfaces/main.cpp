#include <iostream>
#include <vector>
#include <string>

using namespace std;

//? POLYMORPHISM (PART 3: ABSTRACT CLASSES & PURE VIRTUAL INTERFACES)
//* An Abstract Class is a class designed specifically to be used as a base class.
//* An Abstract Class CANNOT be instantiated directly on its own (cannot create `new Base()`).
//* 
//* Pure Virtual Function:
//* - A virtual function declared with `= 0`:
//*   virtual void execute() = 0;
//* - Any derived class MUST implement all pure virtual functions, otherwise it also remains abstract.
//*
//* Pure Interface:
//* In C++, an interface is an abstract class with ONLY pure virtual functions and no data members.

// Pure Interface: IPaymentMethod
class IPaymentMethod
{
public:
	//? Pure virtual functions
	virtual void pay(double amount) = 0;
	virtual string getPaymentName() const = 0;

	// Virtual destructor to ensure proper cleanup of derived types
	virtual ~IPaymentMethod() = default;
};

// Derived Implementation 1: CreditCard
class CreditCardPayment : public IPaymentMethod
{
private:
	string cardNumber;

public:
	CreditCardPayment(const string &num) : cardNumber(num) {}

	void pay(double amount) override
	{
		cout << "💳 Processed $" << amount << " using Credit Card ending in " 
		     << cardNumber.substr(cardNumber.length() - 4) << "\n";
	}

	string getPaymentName() const override
	{
		return "Credit Card";
	}
};

// Derived Implementation 2: PayPal
class PayPalPayment : public IPaymentMethod
{
private:
	string email;

public:
	PayPalPayment(const string &mail) : email(mail) {}

	void pay(double amount) override
	{
		cout << "🅿️  Processed $" << amount << " via PayPal account: " << email << "\n";
	}

	string getPaymentName() const override
	{
		return "PayPal";
	}
};

// Derived Implementation 3: Crypto
class CryptoPayment : public IPaymentMethod
{
private:
	string walletAddress;

public:
	CryptoPayment(const string &addr) : walletAddress(addr) {}

	void pay(double amount) override
	{
		cout << "₿  Processed $" << amount << " using Crypto Wallet: " 
		     << walletAddress.substr(0, 6) << "..." << "\n";
	}

	string getPaymentName() const override
	{
		return "Cryptocurrency";
	}
};

// Function taking the abstract interface - Decoupled Architecture!
void processCheckout(IPaymentMethod &payment, double total)
{
	cout << "Initiating checkout with " << payment.getPaymentName() << "...\n";
	payment.pay(total);
	cout << "Checkout complete!\n\n";
}

int main()
{
	cout << "====================================================\n";
	cout << " 03. ABSTRACT CLASSES & INTERFACES                  \n";
	cout << "====================================================\n\n";

	// IPaymentMethod invalid; // ❌ COMPILER ERROR: cannot declare variable of abstract type!

	CreditCardPayment cc("1234567890123456");
	PayPalPayment paypal("user@example.com");
	CryptoPayment crypto("0x71C...894");

	processCheckout(cc, 89.99);
	processCheckout(paypal, 24.50);
	processCheckout(crypto, 250.00);

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Define an interface `IVehicle` with pure virtual methods `startEngine()` and `stopEngine()`.
 * 2. Implement derived classes `Car` and `Motorcycle`.
 * 3. Write a global function `serviceVehicle(IVehicle &v)` that tests both actions.
 */

