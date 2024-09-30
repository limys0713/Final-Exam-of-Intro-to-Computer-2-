#ifndef Block_H
#define Block_H
#include <fstream>
using namespace std;

class Block {
public:
	Block() {}
	Block(float, float, float, float, float, float) {}
	Block(const Block &);
	~Block() {}
	void rotate(int, bool);
	float interVolumn(float, float, float, float, float, float);
	virtual void shift(int, float) = 0;
	float x1, y1, z1, x2, y2, z2;
};

#endif