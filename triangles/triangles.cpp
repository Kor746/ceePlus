#include <iostream>

using namespace std;



class Triangle {
	private: 
	
		double base;
		double height;
		static int numTriangles;
		static int count;
		
		
	public: 
		
		void setBase(double b) {
			base = b;
		}
		double getBase()
		{
			return base;
		}
		void setHeight(double h) {
			height = h;
		}
		double getHeight() {
			return height;
		}
		
		void getArea();
		
		static int getNumTriangles() { return numTriangles;}
		
		Triangle(double, double);
		Triangle();
		~Triangle();
		
		
};
int Triangle::numTriangles = 0;
int Triangle::count = 0;
Triangle::Triangle(double base, double height) {
	this -> base = base;
	this -> height = height;
	Triangle::numTriangles++;
	
	
	
}

Triangle::~Triangle() {
	cout << "A triangle with the base of " << this -> base << " and a height of " << this -> height 
	<< " has been destroyed"<< endl;
}

Triangle::Triangle() {
	Triangle::numTriangles++;
	
	
}

void Triangle::getArea() {
	Triangle::count++;
	cout << "The area of triangle " << Triangle::count << " is "  << (this -> base * this -> height) / 2 << endl;
}


int main() {
	//reference pointer
	
	
	Triangle triangle1(432,34);
	Triangle triangle2(43,43);
	Triangle triangle3(12,43);
	Triangle triangle4(56,43);
	
	
	triangle1.getArea();
	triangle2.getArea();
	triangle3.getArea();
	triangle4.getArea();
	cout << "The number of triangles that were created was " << Triangle::getNumTriangles() << endl;
	
}