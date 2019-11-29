using namespace std;
class Point {
	public:
	int r;
	int c;

	Point(){ r=0; c=0; }

	Point(int row, int col){
		r = row;
		c = col;
	}

	void set(int row, int col){
		r = row;
		c = col;
	}

};
