#include <iostream>
#include <string>
#include <vector>

using namespace std;

//? PROJECT 05: PIECE TABLE TEXT BUFFER ENGINE (STARTER SKELETON)
//* Follow the TODOs below to implement your Piece Table buffer engine!

enum class BufferType
{
	Original,
	Add
};

struct Piece
{
	BufferType source;
	size_t offset;
	size_t length;
};

class PieceTable
{
private:
	string originalBuffer;
	string addBuffer;
	vector<Piece> pieces;

public:
	PieceTable(const string &initialText) : originalBuffer(initialText)
	{
		if (!initialText.empty())
		{
			pieces.push_back({BufferType::Original, 0, initialText.length()});
		}
	}

	// TODO: Step 1 - Insert text at logical character position
	void insert(size_t pos, const string &text)
	{
		if (text.empty()) return;
		size_t addOffset = addBuffer.length();
		addBuffer += text;

		// TODO: Find the piece containing pos, split it, and insert the new Add piece
	}

	// TODO: Step 2 - Delete length characters starting from logical pos
	void deleteText(size_t pos, size_t length)
	{
		// TODO: Adjust piece boundaries or erase pieces within the range
	}

	// TODO: Step 3 - Reconstruct full text from pieces sequence
	string getText() const
	{
		string fullText = "";
		for (const auto &piece : pieces)
		{
			const string &sourceBuf = (piece.source == BufferType::Original) 
			                          ? originalBuffer : addBuffer;
			fullText += sourceBuf.substr(piece.offset, piece.length);
		}
		return fullText;
	}
};

int main()
{
	cout << "====================================================\n";
	cout << " PROJECT 05: PIECE TABLE TEXT BUFFER SKELETON       \n";
	cout << "====================================================\n\n";

	PieceTable editor("Hello World!");
	cout << "Initial Text: " << editor.getText() << "\n";
	cout << "Ready for implementation! Follow the instructions in README.md.\n";

	return 0;
}

