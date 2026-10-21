#include <iostream>
#include <string>

using namespace std;

//? DSA BRIDGE (03. RECURSION, CALL STACK & TRACE)
//* Every recursive call pushes a new "Stack Frame" onto the program's Call Stack.
//* A stack frame contains:
//* 1. Local variables
//* 2. Parameter arguments
//* 3. Return address (where to resume execution when this call completes)
//*
//* The 2 Fundamental Rules of Recursion:
//* 1. BASE CASE: The terminating condition that stops recursion. (Missing base case = Stack Overflow!)
//* 2. RECURSIVE STEP: Moving one step closer to the base case.

void traceRecursion(int depth, int n)
{
	string indent(depth * 3, ' ');
	cout << indent << "➡️ ENTER: func(n=" << n << ", depth=" << depth << ")\n";

	// Base Case
	if (n <= 1)
	{
		cout << indent << "🛑 BASE CASE REACHED: return 1\n";
		cout << indent << "⬅️ EXIT: func(n=" << n << ")\n";
		return;
	}

	// Recursive Step
	traceRecursion(depth + 1, n - 1);

	cout << indent << "⬅️ EXIT: func(n=" << n << ") (stack unwinding)\n";
}

int main()
{
	cout << "====================================================\n";
	cout << " 03. DSA BRIDGE: RECURSIVE CALL STACK VISUALIZER    \n";
	cout << "====================================================\n\n";

	cout << "Tracing Call Stack execution for n = 4:\n\n";
	traceRecursion(0, 4);

	cout << "\nNotice how calls grow downwards (Push), and then unwind upwards (Pop) like a stack (LIFO)!\n";

	return 0;
}

