#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>

using namespace std;

//? PROJECT 01: HUFFMAN FILE COMPRESSOR & DECOMPRESSOR
//* Complete the TODOs below to build your custom file compression tool!

// 1. Huffman Tree Node
struct HuffmanNode
{
	unsigned char ch;
	int freq;
	HuffmanNode *left;
	HuffmanNode *right;

	HuffmanNode(unsigned char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
	HuffmanNode(int f, HuffmanNode *l, HuffmanNode *r) : ch(0), freq(f), left(l), right(r) {}

	bool isLeaf() const
	{
		return (left == nullptr && right == nullptr);
	}
};

// Min-Heap comparator for HuffmanNode pointers
struct CompareNode
{
	bool operator()(const HuffmanNode *a, const HuffmanNode *b)
	{
		return a->freq > b->freq; // Lowest frequency gets highest priority
	}
};

class HuffmanCompressor
{
public:
	// TODO: Step 1 - Count frequencies of every byte in input file
	unordered_map<unsigned char, int> buildFrequencyTable(const string &inputFilePath)
	{
		unordered_map<unsigned char, int> freqMap;
		// TODO: Open file in binary mode and count byte frequencies
		return freqMap;
	}

	// TODO: Step 2 - Build Huffman Tree using priority_queue
	HuffmanNode* buildHuffmanTree(const unordered_map<unsigned char, int> &freqMap)
	{
		priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> minHeap;
		// TODO: Push all character nodes into minHeap
		// TODO: Loop while minHeap.size() > 1, pop two, combine them, push parent
		return nullptr; // Return root of tree
	}

	// TODO: Step 3 - Generate binary prefix codes by traversing tree (0 for left, 1 for right)
	void generateCodes(HuffmanNode *root, const string &code, unordered_map<unsigned char, string> &codeMap)
	{
		if (!root) return;
		if (root->isLeaf())
		{
			codeMap[root->ch] = code;
			return;
		}
		generateCodes(root->left, code + "0", codeMap);
		generateCodes(root->right, code + "1", codeMap);
	}

	// TODO: Step 4 - Compress file
	bool compress(const string &inputFile, const string &outputFile)
	{
		cout << "[Compressor] Compressing: " << inputFile << " -> " << outputFile << "...\n";
		// TODO: Implement file compression workflow
		return true;
	}

	// TODO: Step 5 - Decompress file
	bool decompress(const string &inputFile, const string &outputFile)
	{
		cout << "[Compressor] Decompressing: " << inputFile << " -> " << outputFile << "...\n";
		// TODO: Implement file decompression workflow
		return true;
	}
};

int main(int argc, char *argv[])
{
	cout << "====================================================\n";
	cout << " PROJECT 01: HUFFMAN COMPRESSION SKELETON           \n";
	cout << "====================================================\n";
	cout << "Usage:\n";
	cout << "  Compress:   ./main -c <input_file> <output_file.huff>\n";
	cout << "  Decompress: ./main -d <input_file.huff> <output_file>\n\n";

	HuffmanCompressor compressor;
	cout << "Ready for implementation! Follow the instructions in README.md.\n";

	return 0;
}

