#include<iostream>

using namespace std;


class Triangle
{
public:
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        a_ = a;
        b_ = b;
        c_ = c;
        A_ = A;
        B_ = B;
        C_ = C;
        name = "Треугольник";
    }

    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    string get_name() { return name; };

    virtual void print_info()
    {
        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << endl << endl;
    }

protected:
    string name;
    int a_, b_, c_, A_, B_, C_;
};

class RectangularTriangle : public Triangle 
{
public:
    RectangularTriangle(int a, int b, int c, int A, int B): Triangle(a, b, c, A, B, 90) 
    {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public IsoscelesTriangle
{
public: 
    EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};


class Quadrangle
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
        A_ = A;
        B_ = B;
        C_ = C;
        D_ = D;
        name = "Четырехугольник";
    }

    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_d() { return d_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    int get_D() { return D_; }
    string get_name() { return name; };

    virtual void print_info()
    {
        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << endl;
    }

protected:
    string name;
    int a_, b_, c_, d_, A_, B_, C_, D_;
};


class Parallelogram: public Quadrangle 
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90)
    {
        name = "Прямоугольник";
    }
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
    {
        name = "Ромб";
    }
};

class Square : public Rhomb
{
public:
    Square(int a) : Rhomb(a, 90, 90)
    {
        name = "Квадрат";
    }
};

void print_info(Triangle& figure)
{
    std::cout << figure.get_name() << ": " << std::endl;
    figure.print_info();
};

void print_info_quad(Quadrangle& figure)
{
    std::cout << figure.get_name() << ": " << std::endl;
    figure.print_info();
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RectangularTriangle rectangularTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhomb rhomb(30, 30, 40);

    print_info(triangle);
    print_info(rectangularTriangle);
    print_info(isoscelesTriangle);
    print_info(equilateralTriangle);
    print_info_quad(quadrangle);
    print_info_quad(rectangle);
    print_info_quad(square);
    print_info_quad(parallelogram);
    print_info_quad(rhomb);
    return 0;

}