#include<iostream>
#include<math.h>

class Shape					// parent class
{
protected:
	short sideA{};			
	short sideB{};
	short sideC{};			// shapes sides

public:
	Shape(short a = 5, short b = 5, short c = 5) :
		sideA{ a },
		sideB{ b },
		sideC{ c }
	{}

	virtual void render() = 0;

	virtual short perimeter() = 0;

	virtual short square() = 0;				// clear virtual functions 
};

class Square : public Shape
{
public: 
	Square(short a = 5, short b = 5, short c = 5) : Shape(a, b, c){}

	virtual void render() override
	{
		std::cout << "Side A: " << this->sideA << std::endl;
	}

	virtual short perimeter() override
	{
		return this->sideA * 4;
	}

	virtual short square() override
	{
		return this->sideA * this->sideA;
	}
};

class Rectangle : public Square			// rectangle based on square
{
public:
	Rectangle(short a = 5, short b = 5, short c = 5) : Square(a, b, c)
	{
		this->sideB = this->sideA * 2;
	}

	virtual void render() override		// overriding
	{
		std::cout << "Side A: " << this->sideA << std::endl;
		std::cout << "Side B: " << this->sideB << std::endl;
	}

	virtual short perimeter() override
	{
		return (this->sideA * 2) + (this->sideB * 2);
	}

	virtual short square() override
	{
		return this->sideA * this->sideB;
	}
};

class Triangle : public Rectangle		// triangle based on rectangle
{
public: 
	Triangle(short a = 5, short b = 5, short c = 5) : Rectangle(a, b, c)
	{
		this->sideA += this->sideB;
		this->sideC = pow(this->sideA, 2) + pow(this->sideB, 2);
		this->sideC = sqrt(this->sideC);
	}

	virtual void render() override
	{
		std::cout << "Side A: " << this->sideA << std::endl;
		std::cout << "Side B: " << this->sideB << std::endl;
		std::cout << "Side C: " << this->sideC << std::endl;
	}

	virtual short perimeter() override
	{
		return this->sideA + this->sideB + this->sideC;
	}

	virtual short square() override
	{
		return (this->sideA * this->sideB) / 2;
	}
};

int main() {

	Rectangle a{};
	Rectangle a1{7, 5};

	Square b{ 3 };

	Triangle c{};

	Rectangle arr[2] = { a, a1 };
	for (int i{}; i < 2; ++i)
	{
		arr[i].render();
		std::cout << std::endl;
	}

	return 0;
}