#include<iostream>

using namespace std;

class Figure 
{
public: 
    Figure() 
    {
        sides_count = 0;
        name = "Фигура";
    }

    int get_sides_count() { return sides_count; }
    string get_name() { return name; }

protected:
    int sides_count = 0;
    string name = "Figure";
};

class Triangle: public Figure 
{
public:
    Triangle() 
    { 
        sides_count = 3;
        name = "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle() {
        sides_count = 4;
        name = "Четырёхугольник";
    };

};


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    cout << "Количество сторон:" << endl;
    cout << figure.get_name() << ": " << figure.get_sides_count() << endl;
    cout << triangle.get_name() << ": " << triangle.get_sides_count() << endl;
    cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << endl;
    return 0;
}