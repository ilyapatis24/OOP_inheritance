#include<iostream>

using namespace std;

class Figure
{
public:
    Figure() {
        sides_count = 0;
        name = "Фигура";
    };

    int get_sides_count() { return sides_count; }
    string get_name() { return name; }

    virtual void print_info() {}
    virtual bool check() { return true; }

protected:
    int sides_count;
    string name;
};

class Triangle : public Figure
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
        sides_count = 3;
        name = "Треугольник";
    }

    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }

    void print_info() override {
        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << endl << endl;
    }
    bool check() override {
        if ((A_ + B_ + C_) == 180)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

protected:
    int a_, b_, c_, A_, B_, C_;
};

class RectangularTriangle : public Triangle
{
public:
    RectangularTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        if (Triangle::check() && C_ == 90)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        name = "Равнобедренный треугольник";
    }

    bool check() override {
        if (Triangle::check() && a_ == c_ && A_ == C_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(int a) : IsoscelesTriangle(a, a, 60, 60)
    {
        name = "Равносторонний треугольник";
    }

    bool check() override {
        if (IsoscelesTriangle::check() && a_ == b_ && A_ == B_ && A_ == 60)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


class Quadrangle : public Triangle
{
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Triangle(a, b, c, A, B, C)
    {
        d_ = d;
        D_ = D;
        sides_count = 4;
        name = "Четырёхугольник";
    };

    int get_d() { return d_; };
    int get_D() { return D_; };

    void print_info() override {

        cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << endl;
        cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << endl << endl;
    }

    bool check() override {
        if ((A_ + B_ + C_ + D_) == 360)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

protected:
    int d_, D_;
};


class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм";
    }

    bool check() override {
        if (Quadrangle::check() && a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90)
    {
        name = "Прямоугольник";
    }

    bool check() override {
        if (Parallelogram::check() && A_ == 90 && B_ == A_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
    {
        name = "Ромб";
    }

    bool check() override {
        if (Parallelogram::check() && a_ == b_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class Square : public Rhomb
{
public:
    Square(int a) : Rhomb(a, 90, 90)
    {
        name = "Квадрат";
    }

    bool check() override {
        if (Rhomb::check() && a_ == b_)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void print_info(Figure& figure)
{
    cout << endl;
    cout << figure.get_name() << ": " << endl;

    if (figure.check())
    {
        cout << "Правильная" << endl;
    }
    else
    {
        cout << "Неправильная" << endl;
    }

    cout << "Количество сторон: " << figure.get_sides_count() << endl;
    figure.print_info();
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RectangularTriangle rectangularTriangleOne(10, 20, 30, 50, 60);
    RectangularTriangle rectangularTriangleTwo(10, 20, 30, 50, 40);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);


    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);

    Rhomb rhomb(30, 30, 40);

    print_info(figure);
    print_info(triangle);
    print_info(rectangularTriangleOne);
    print_info(rectangularTriangleTwo);
    print_info(isoscelesTriangle);
    print_info(equilateralTriangle);

    print_info(quadrangle);
    print_info(rectangle);
    print_info(square);
    print_info(parallelogram);
    print_info(rhomb);
    return 0;

}