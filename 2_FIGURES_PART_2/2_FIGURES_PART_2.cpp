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
//�����������:
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
		 std::cout << "�����������:" << std::endl;

	}
	void print_sides_count() override {
		
		std::cout << "�������: " << "a = " << a << " " << "b = " << b << " " << "c = " << c  << std::endl;
		std::cout << "����: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << std::endl;
	}
};
class Right_triangle :public Triangle {
//������������� �����������:
public:
	Right_triangle( int a_, int b_, int c_, int A_, int B_,int C_):Triangle( a_, b_,c_, A_, B_, C_){
		
	}
	void getType() override {
		std::cout << "������������� �����������:" << std::endl;

	}
};
class Isosceles_triangle :public Triangle {
//�������������� �����������////////�������������� ����������� (������� a = c �����, ���� A = C �����);a_, b_, b_, A_, B_, B_
public:
	Isosceles_triangle(int a_, int b_, int A_, int B_) :Triangle( a_, b_, b_, A_, B_, B_) {
		
	}
	void getType() override {
		std::cout << "�������������� �����������:" << std::endl;

	}
	
};
class Equilateral_triangle :public Triangle {
//�������������� �����������
public:
	Equilateral_triangle( int a_,int A_) :Triangle( a_, a_, a_, A_, A_, A_) {
	
	}
	void getType() override {
		std::cout << "�������������� �����������:" << std::endl;

	}
};

////////////////////////////////////////////////////////////////////////////////
class Quadrangle :public Figure {
protected:
//��������������:
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
		std::cout << "�������: " << "a = " << a << " " << "b = " << b << " " << "c = " << c << " " << "d = " << d << std::endl;
		std::cout << "����: " << "A = " << A << " " << "B = " << B << " " << "C = " << C << " " << "D = " << D << std::endl;
	}
	void getType() override {
		std::cout << "��������������:" << std::endl;

	}
};
class Rectangle :public Quadrangle {
	//�������������:
public:
	Rectangle( int a_, int b_, int A_) :Quadrangle( a_, b_, a_, b_, A_, A_, A_, A_) {

	}
	void getType() override {
		std::cout << "�������������:" << std::endl;

	}

};
class Square :public Quadrangle {
	//������� 
public:
	Square( int a_,int A_) :Quadrangle( a_, a_, a_, a_, A_, A_, A_, A_) {
	
	}
	void getType() override {
		std::cout << "�������:" << std::endl;

	}
};
class Parallelogram :public Quadrangle {
	//��������������
public:
	Parallelogram( int a_, int b_,  int A_, int B_) :Quadrangle( a_, b_, a_, b_, A_, B_, A_, B_) {

	}
	void getType() override {
		std::cout << "��������������:" << std::endl;

	}
};
class Rhombus :public Quadrangle {
	//���� 
public:
	Rhombus( int a_, int A_, int B_) :Quadrangle( a_, a_, a_, a_, A_, B_, A_, B_) {
	}
	void getType() override {
		std::cout << "����:" << std::endl;

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

		// ������� ������
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
//� ������ Figure � ��� ��������� 8 ������ ������ int - 4 ������� � 4 ����.
//�� �������� � ������������ ��� �� ���� ���������� �� ������������, � ����� ������ ������ � ������ ������� ������.
//��� ��������, � ������� �� ������� ������ - ����, � ������� ������ �� ����� ������ � �����.
//���������� �������� ������ ������.����� ��� �� ����,
// ��� ������� ������ ������� � ���� �� Figure, 
//� ����������� �� ������ � �� ������, ��� ��� ������� ������������.
//�� ���� � ������������ ����� 3 ������� � 3 ����, � ���������������� - 4 ������� � 4 ����.
//� � Figure �� ����� �� ���� �� �������.

