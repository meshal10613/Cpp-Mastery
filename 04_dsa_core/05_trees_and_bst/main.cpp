#include <iostream>
#include <queue>

using namespace std;

//? DSA CORE (05. TREES, BST & TRAVERSALS)
//* 1. Tree Node Structure: val, left pointer, right pointer.
//* 2. BFS (Breadth-First Search / Level-Order): Process level-by-level using a queue.
//* 3. DFS (Depth-First Search): In-order (Left-Root-Right), Pre-order, Post-order.
//* 4. Binary Search Tree (BST): Left subtree < Root < Right subtree. O(log N) average search.

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert into BST
TreeNode* insertBST(TreeNode *root, int val)
{
	if (root == nullptr) return new TreeNode(val);
	if (val < root->val) root->left = insertBST(root->left, val);
	else root->right = insertBST(root->right, val);
	return root;
}

// In-order Traversal (Produces sorted sequence for BST)
void inOrderTraversal(TreeNode *root)
{
	if (root == nullptr) return;
	inOrderTraversal(root->left);
	cout << root->val << " ";
	inOrderTraversal(root->right);
}

// Level-Order Traversal (BFS)
void levelOrderTraversal(TreeNode *root)
{
	if (root == nullptr) return;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		int levelSize = q.size();
		for (int i = 0; i < levelSize; i++)
		{
			TreeNode *node = q.front();
			q.pop();
			cout << node->val << " ";

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		cout << "| "; // Level separator
	}
}

// Lowest Common Ancestor (LCA) in a BST
TreeNode* lowestCommonAncestorBST(TreeNode* root, int p, int q)
{
	if (!root) return nullptr;
	if (p < root->val && q < root->val) return lowestCommonAncestorBST(root->left, p, q);
	if (p > root->val && q > root->val) return lowestCommonAncestorBST(root->right, p, q);
	return root; // Split point is the LCA!
}

int main()
{
	cout << "====================================================\n";
	cout << " 05. DSA CORE: TREES, BST & TRAVERSALS              \n";
	cout << "====================================================\n\n";

	// Construct BST: 50, 30, 70, 20, 40, 60, 80
	TreeNode *root = nullptr;
	int values[] = {50, 30, 70, 20, 40, 60, 80};
	for (int v : values) root = insertBST(root, v);

	cout << "In-Order Traversal (Sorted):   ";
	inOrderTraversal(root);
	cout << "\n";

	cout << "Level-Order Traversal (BFS):   ";
	levelOrderTraversal(root);
	cout << "\n\n";

	// Lowest Common Ancestor
	int p = 20, q = 40;
	TreeNode *lca = lowestCommonAncestorBST(root, p, q);
	cout << "Lowest Common Ancestor of " << p << " & " << q << ": " 
	     << (lca ? to_string(lca->val) : "None") << "\n";

	return 0;
}

