#include <iostream>

using namespace std;

//? DSA CORE (02. LINKED LISTS & IN-PLACE REVERSAL & CYCLE DETECTION)
//* A Linked List is a linear collection of nodes connected via pointers.
//* Unlike vectors, elements are non-contiguous in memory.
//* 
//* Core Algorithms:
//* 1. Reversing a Linked List in-place (O(N) time, O(1) space)
//* 2. Floyd's Cycle-Finding Algorithm (Tortoise & Hare: slow moves 1 step, fast moves 2 steps)

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 1. In-Place Reversal of a Linked List
ListNode* reverseList(ListNode *head)
{
	ListNode *prev = nullptr;
	ListNode *curr = head;

	while (curr != nullptr)
	{
		ListNode *nextTemp = curr->next; // Save next node
		curr->next = prev;               // Reverse link
		prev = curr;                     // Move prev forward
		curr = nextTemp;                 // Move curr forward
	}
	return prev; // New head of reversed list
}

// 2. Floyd's Cycle Detection (Tortoise and Hare)
bool hasCycle(ListNode *head)
{
	if (!head || !head->next) return false;

	ListNode *slow = head;
	ListNode *fast = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;          // 1 step
		fast = fast->next->next;    // 2 steps

		if (slow == fast)
		{
			return true; // Cycle detected!
		}
	}
	return false;
}

void printList(ListNode *head)
{
	ListNode *curr = head;
	while (curr != nullptr)
	{
		cout << curr->val << " -> ";
		curr = curr->next;
	}
	cout << "nullptr\n";
}

int main()
{
	cout << "====================================================\n";
	cout << " 02. DSA CORE: LINKED LISTS & FLOYD'S ALGORITHM     \n";
	cout << "====================================================\n\n";

	// Create list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	cout << "Original List:\n";
	printList(head);

	// 1. Reverse Demo
	head = reverseList(head);
	cout << "\nAfter In-Place Reversal:\n";
	printList(head);

	// 2. Cycle Detection Demo
	cout << "\nCycle Check on normal list: " 
	     << (hasCycle(head) ? "Cycle detected!" : "No cycle") << "\n";

	// Create artificial cycle: connect tail to head->next
	head->next->next->next->next->next = head->next; // Cycle created
	cout << "Cycle Check after creating loop: " 
	     << (hasCycle(head) ? "Cycle detected!" : "No cycle") << "\n";

	// Break cycle before exiting to prevent memory leaks / infinite loops
	head->next->next->next->next->next = nullptr;

	// Free memory
	while (head != nullptr)
	{
		ListNode *temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}

