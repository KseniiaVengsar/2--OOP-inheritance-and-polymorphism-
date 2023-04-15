// 2_FIGURES_PART_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Figure {
private:
	std::string figure_type;

public:
	
	virtual void getType() {
		
	}	
	virtual void print_sides_count() {	
		
	}	
};
void print_info(Figure* figure) {
	figure->getType();
	figure->print_sides_count();
}
// /////////////////////////////////////////////////////////////////////////////////
class Triangle :public Figure {
//Треугольник:
protected:
int a; int b; int c;
int A; int B; int C;
public:
	
	Triangle(int a_,int b_,int c_, int A_, int B_, int C_):Figure(){
		a = a_; 
		b = b_;
		c = c_;
		A = A_; 
		B = B_; 
		C = C_;
	}	
	 void getType() override {
		 std::cout << "Треугольник:" << std::endl;

	}
	void print_sides_count() override {
		
		std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c  << std::endl;
		std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
	}
};
class Right_triangle :public Triangle {
//Прямоугольный треугольник:
public:
	Right_triangle( int a_, int b_, int c_, int A_, int B_,int C_):Triangle( a_, b_,c_, A_, B_, C_){
		
	}
	void getType() override {
		std::cout << "Прямоугольный треугольник:" << std::endl;

	}
};
class Isosceles_triangle :public Triangle {
//Равнобедренный треугольник////////равнобедренный треугольник (стороны a = c равны, углы A = C равны);a_, b_, b_, A_, B_, B_
public:
	Isosceles_triangle(int a_, int b_, int A_, int B_) :Triangle( a_, b_, b_, A_, B_, B_) {
		
	}
	void getType() override {
		std::cout << "Равнобедренный треугольник:" << std::endl;

	}
	
};
class Equilateral_triangle :public Triangle {
//Равносторонний треугольник
public:
	Equilateral_triangle( int a_,int A_) :Triangle( a_, a_, a_, A_, A_, A_) {
	
	}
	void getType() override {
		std::cout << "Равносторонний треугольник:" << std::endl;

	}
};

////////////////////////////////////////////////////////////////////////////////
class Quadrangle :public Figure {
protected:
//Четырёхугольник:
	int a; int b; int c; int d;
	int A; int B; int C; int D;
public:
	Quadrangle(int a_,int b_, int c_, int d_, int A_, int B_, int C_, int D_) :Figure(){
		a = a_;
		b = b_;
		c = c_;
		d = d_;
		A = A_;
		B = B_;
		C = C_;
		D = D_;
	}
	void print_sides_count() override {
		std::cout << "Стороны: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
		std::cout << "Углы: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
	}
	void getType() override {
		std::cout << "Четырёхугольник:" << std::endl;

	}
};
class Rectangle :public Quadrangle {
	//Прямоугольник:
public:
	Rectangle( int a_, int b_, int A_) :Quadrangle( a_, b_, a_, b_, A_, A_, A_, A_) {

	}
	void getType() override {
		std::cout << "Прямоугольник:" << std::endl;

	}

};
class Square :public Quadrangle {
	//Квадрат 
public:
	Square( int a_,int A_) :Quadrangle( a_, a_, a_, a_, A_, A_, A_, A_) {
	
	}
	void getType() override {
		std::cout << "Квадрат:" << std::endl;

	}
};
class Parallelogram :public Quadrangle {
	//Параллелограмм
public:
	Parallelogram( int a_, int b_,  int A_, int B_) :Quadrangle( a_, b_, a_, b_, A_, B_, A_, B_) {

	}
	void getType() override {
		std::cout << "Параллелограмм:" << std::endl;

	}
};
class Rhombus :public Quadrangle {
	//Ромб 
public:
	Rhombus( int a_, int A_, int B_) :Quadrangle( a_, a_, a_, a_, A_, B_, A_, B_) {
	}
	void getType() override {
		std::cout << "Ромб:" << std::endl;

	}
};

////////////////////////////////////////////////////////////////////////////////
	int main() {
		setlocale(LC_ALL, "RU");

		Triangle* triangle = new Triangle( 1, 2, 3, 4, 5, 6);
		print_info(triangle);
		std::cout << std::endl;

		Right_triangle* right_triangle = new Right_triangle( 1, 2, 3, 4, 5, 6);
		print_info(right_triangle);
		std::cout << std::endl;

		Isosceles_triangle* isosceles_triangle = new Isosceles_triangle(1, 2, 3, 4);
		print_info(isosceles_triangle);
		std::cout << std::endl;

		Equilateral_triangle* equilateral_triangle = new Equilateral_triangle( 1, 2);
		print_info(equilateral_triangle);
		std::cout << std::endl;

		Quadrangle* quadrangle = new Quadrangle( 1, 2, 3, 4, 5, 6, 7, 8);
		print_info(quadrangle);
		std::cout << std::endl;

		Rectangle* rectangle = new Rectangle( 1, 2, 3);
		print_info(rectangle);
		std::cout << std::endl;

		Square* square = new Square( 1, 2);
		print_info(square);
		std::cout << std::endl;

		Parallelogram* parallelogram = new Parallelogram( 1, 2, 3, 4);
		print_info(parallelogram);
		std::cout << std::endl;

		// Очистка памяти
		//delete figure;
		delete triangle;
		delete right_triangle;
		delete isosceles_triangle;
		delete equilateral_triangle;
		delete quadrangle;
		delete rectangle;
		delete square;
		delete parallelogram;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// 
//В классе Figure у вас добавлено 8 членов класса int - 4 стороны и 4 угла.
//Но например в треугольнике две из этих переменных не используются, и будут просто висеть в памяти мертвым грузом.
//Или например, в будущем мы сделаем фигуру - круг, у которой вообще не будет сторон и углов.
//Получается излишний расход памяти.Чтобы так не было,
// вам следует убрать стороны и углы из Figure, 
//и переместить их только в те классы, где они реально используются.
//То есть в треугольнике будет 3 стороны и 3 угла, в четырехугольнике - 4 стороны и 4 угла.
//А в Figure не будет ни того ни другого.

