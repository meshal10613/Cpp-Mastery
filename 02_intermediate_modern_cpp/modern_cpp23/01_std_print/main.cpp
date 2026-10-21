#include <print>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//? MODERN C++23 (PART 1: std::print & std::println)
//* One of the most requested features in C++ history!
//* Introduced in C++23 via the `<print>` header.
//*
//* Why is std::print better than std::cout or printf?
//* 1. Type Safe: Unlike printf, no risk of %d vs %s mismatched specifiers.
//* 2. Faster: Significantly faster than std::cout (no heavy iostream stream-buffering overhead).
//* 3. Cleaner Syntax: No messy chaining `std::cout << a << " " << b << "\n"`.
//* 4. Native UTF-8 Unicode support: Handles Unicode characters cleanly on Windows terminals.
//* 5. std::println automatically adds a newline (`\n`) and flushes cleanly.

int main()
{
	println("====================================================");
	println(" 01. MODERN C++23: std::print & std::println        ");
	println("====================================================\n");

	//? 1. BASIC USAGE
	string name = "Bro";
	int level = 99;
	double health = 87.5;

	println("Welcome back, {}! Your level is {} with {}% HP.", name, level, health);

	//? 2. FORMAT SPECIFIERS
	//* - {:>10} : Right align in 10-character width
	//* - {:<10} : Left align in 10-character width
	//* - {:^10} : Center align in 10-character width
	//* - {:.2f} : Fixed 2 decimal places
	//* - {:05d} : Pad with leading zeros up to 5 digits
	//* - {:x}   : Lowercase Hexadecimal
	//* - {:X}   : Uppercase Hexadecimal
	//* - {:b}   : Binary format!
	//* - {:B}   : Binary format with uppercase prefix

	println("\n--- Format & Alignment Specifiers ---");
	println("Right-aligned:  [{:>15}]", "C++23");
	println("Left-aligned:   [{:<15}]", "C++23");
	println("Center-aligned: [{:^15}]", "C++23");

	double pi = 3.1415926535;
	println("Pi (2 decimals): {:.2f}", pi);
	println("Pi (4 decimals): {:.4f}", pi);

	int score = 42;
	println("Zero-padded:    {:06d}", score);
	println("Hexadecimal:    0x{:x}", 255);
	println("Binary (C++23): 0b{:b}", 42);

	//? 3. POSITIONAL ARGUMENTS
	println("\n--- Positional Arguments ---");
	println("{0} loves {1}, and {1} loves {0}!", "Alice", "Bob");

	//? 4. PRINTING CONTAINERS (C++23 std::print supports ranges/containers directly!)
	println("\n--- Printing Ranges & Containers directly ---");
	vector<int> nums = {10, 20, 30, 40, 50};
	println("Vector elements: {}", nums);

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Print a formatted price table of 3 grocery items:
 *    - Column 1: Item Name (left-aligned, 15 width)
 *    - Column 2: Quantity (center-aligned, 8 width)
 *    - Column 3: Price (right-aligned with 2 decimals, 10 width)
 * 2. Print a byte value in both decimal, hex (0x..), and binary (0b..).
 */

