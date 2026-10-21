#include <iostream>
#include <vector>
#include <string>

using namespace std;

//? POLYMORPHISM (PART 2: RUN-TIME POLYMORPHISM & VIRTUAL FUNCTIONS)
//* Run-time (dynamic) polymorphism occurs when a member function call is resolved at RUNTIME
//* rather than at compile time (Dynamic Binding / Late Binding).
//* 
//* Key Ingredients:
//* 1. Inheritance hierarchy.
//* 2. Base class declares functions with the `virtual` keyword.
//* 3. Derived classes redefine the function with the `override` specifier.
//* 4. Objects are called via Base class pointers (Base*) or Base class references (Base&).
//*
//* Under the hood: The compiler creates a Virtual Table (vtable) and injects a virtual pointer (vptr)
//* into each object to look up the correct derived function address at runtime!

// Base Class
class Shape
{
protected:
	string name;

public:
	Shape(const string &name) : name(name) {}

	//? Virtual function enables dynamic dispatch
	virtual void draw() const
	{
		cout << "Drawing generic shape: " << name << "\n";
	}

	virtual double getArea() const
	{
		return 0.0;
	}

	virtual ~Shape() = default; // Always ensure base class has a virtual destructor!
};

// Derived Class 1: Circle
class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double r) : Shape("Circle"), radius(r) {}

	//? 'override' ensures you are correctly overriding an existing base virtual function
	void draw() const override
	{
		cout << "⚪ Drawing Circle with radius: " << radius << "\n";
	}

	double getArea() const override
	{
		return 3.14159 * radius * radius;
	}
};

// Derived Class 2: Rectangle
class Rectangle : public Shape
{
private:
	double width, height;

public:
	Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}

	void draw() const override
	{
		cout << "▭ Drawing Rectangle (" << width << " x " << height << ")\n";
	}

	double getArea() const override
	{
		return width * height;
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " 02. RUN-TIME POLYMORPHISM & VIRTUAL FUNCTIONS      \n";
	cout << "====================================================\n\n";

	Circle circle(5.0);
	Rectangle rect(4.0, 6.0);

	//? 1. Polymorphism using Base References
	cout << "--- Polymorphism via Base Reference ---\n";
	Shape &ref1 = circle;
	Shape &ref2 = rect;
	ref1.draw();
	cout << "Area: " << ref1.getArea() << "\n";
	ref2.draw();
	cout << "Area: " << ref2.getArea() << "\n\n";

	//? 2. Polymorphism using Base Pointers in a Collection
	//* One collection of Shape* pointers holds Circles, Rectangles, and any future shapes!
	cout << "--- Polymorphic Vector of Shapes (Shape*) ---\n";
	vector<Shape*> shapes;
	shapes.push_back(&circle);
	shapes.push_back(&rect);

	for (const Shape* s : shapes)
	{
		s->draw();
		cout << "Calculated Area: " << s->getArea() << "\n";
	}

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Add a new derived class `Triangle` inheriting from `Shape`.
 * 2. Implement `draw()` and `getArea()` (0.5 * base * height).
 * 3. Add a Triangle object to the `shapes` vector and observe polymorphic execution.
 */

