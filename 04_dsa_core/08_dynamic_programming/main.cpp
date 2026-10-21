#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//? DSA CORE (08. DYNAMIC PROGRAMMING: MEMOIZATION & TABULATION)
//* Dynamic Programming (DP) optimizes recursive algorithms that have:
//* 1. Overlapping Subproblems (same subproblems solved repeatedly)
//* 2. Optimal Substructure (optimal solution formed from optimal sub-solutions)
//*
//* Approaches:
//* 1. Top-Down (Memoization): Recursion + Cache
//* 2. Bottom-Up (Tabulation): Iterative table filling from base cases up

// 1. 1D DP: Climbing Stairs (Ways to reach step N taking 1 or 2 steps)
int climbStairsTabulation(int n)
{
	if (n <= 2) return n;
	int prev2 = 1; // n = 1
	int prev1 = 2; // n = 2
	for (int i = 3; i <= n; i++)
	{
		int curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1; // O(N) time, O(1) space!
}

// 2. 1D DP: Coin Change (Fewest coins needed to make amount)
int coinChange(const vector<int> &coins, int amount)
{
	vector<int> dp(amount + 1, amount + 1); // Fill with infinity
	dp[0] = 0; // Base case: 0 coins for amount 0

	for (int i = 1; i <= amount; i++)
	{
		for (int coin : coins)
		{
			if (i - coin >= 0)
			{
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
	}
	return (dp[amount] > amount) ? -1 : dp[amount];
}

// 3. 2D DP: 0/1 Knapsack Problem
int knapsack01(int W, const vector<int> &weights, const vector<int> &values, int n)
{
	vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (weights[i - 1] <= w)
			{
				// Option 1: Include item | Option 2: Exclude item
				dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
			}
			else
			{
				dp[i][w] = dp[i - 1][w]; // Cannot include item
			}
		}
	}
	return dp[n][W];
}

int main()
{
	cout << "====================================================\n";
	cout << " 08. DSA CORE: DYNAMIC PROGRAMMING (1D & 2D)        \n";
	cout << "====================================================\n\n";

	// 1. Climbing Stairs Demo
	int steps = 5;
	cout << "Ways to climb " << steps << " stairs: " 
	     << climbStairsTabulation(steps) << " ways\n\n";

	// 2. Coin Change Demo
	vector<int> coins = {1, 2, 5};
	int amount = 11;
	cout << "Min coins to make $" << amount << " using coins {1, 2, 5}: " 
	     << coinChange(coins, amount) << " coins (5 + 5 + 1)\n\n";

	// 3. 0/1 Knapsack Demo
	int maxWeight = 7;
	vector<int> weights = {1, 3, 4, 5};
	vector<int> values = {1, 4, 5, 7};
	int n = values.size();

	cout << "0/1 Knapsack (Capacity: " << maxWeight << "):\n";
	cout << "Max attainable value: $" << knapsack01(maxWeight, weights, values, n) << "\n";

	return 0;
}

