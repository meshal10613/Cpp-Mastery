#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//? 2D VECTORS (VECTOR OF VECTORS)
//* A 2D vector is a dynamic matrix: std::vector<std::vector<T>>
//* Benefits over 2D raw arrays:
//* 1. Dynamic dimensions (rows and columns can be resized at runtime).
//* 2. Jagged arrays (each row can have a different number of columns!).
//* 3. Automatic memory management (no manual delete[] needed).

int main()
{
	cout << "========================================\n";
	cout << "         03. C++ 2D VECTORS            \n";
	cout << "========================================\n\n";

	//? 1. INITIALIZATION: Fixed Size Grid (3 rows, 4 columns, all initialized to 0)
	int rows = 3;
	int cols = 4;
	vector<vector<int>> grid(rows, vector<int>(cols, 0));

	// Assigning values
	grid[0][1] = 5;
	grid[1][2] = 9;
	grid[2][3] = 7;

	cout << "--- 3x4 Grid ---\n";
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << setw(3) << grid[r][c] << " ";
		}
		cout << "\n";
	}

	//? 2. JAGGED ARRAYS (Rows with different column lengths)
	cout << "\n--- Jagged 2D Vector (Pascal-like structure) ---\n";
	vector<vector<int>> jagged;

	// Row 0 has 1 element
	jagged.push_back({1});
	// Row 1 has 2 elements
	jagged.push_back({1, 1});
	// Row 2 has 3 elements
	jagged.push_back({1, 2, 1});
	// Row 3 has 4 elements
	jagged.push_back({1, 3, 3, 1});

	// Iterating through jagged vector using modern range-based for
	for (size_t r = 0; r < jagged.size(); r++)
	{
		cout << "Row " << r << " (len " << jagged[r].size() << "): ";
		for (int val : jagged[r])
		{
			cout << val << " ";
		}
		cout << "\n";
	}

	//? 3. PRACTICAL MINI-PROJECT: Seating Chart
	cout << "\n--- Airplane Seating Chart ---\n";
	vector<vector<char>> seats = {
		{'A', 'B', 'C', 'D'},
		{'A', 'B', 'C', 'D'},
		{'A', 'B', 'C', 'D'}
	};

	// Book seat at Row 1, Col 'B' (index [0][1])
	seats[0][1] = 'X'; // X means booked
	seats[2][3] = 'X';

	for (size_t r = 0; r < seats.size(); r++)
	{
		cout << "Row " << (r + 1) << " | ";
		for (size_t c = 0; c < seats[r].size(); c++)
		{
			cout << seats[r][c] << " ";
		}
		cout << "\n";
	}

	return 0;
}

/*
 * 📝 PRACTICE CHALLENGE:
 * 1. Create a 3x3 Tic-Tac-Toe board initialized with spaces ' ' using a 2D vector.
 * 2. Write a function to display the board with boundary lines (| and ---).
 * 3. Place 'X' at row 1, col 1, and 'O' at row 0, col 2.
 */

