#include <iostream>
#include <string>
using namespace std;

class Triangle
{
public:
    Triangle();
    ~Triangle();
    friend ostream& operator <<(ostream& os, const Triangle triangle);
    void SetABC(string& s);
    void TriangleMath();
    void TriangleType();
    bool TriangleValid();
private:
    float a = 0,
        b = 0,
        c = 0,
        s = 0,
        p = 0;
    string type = "Н/O";
};

Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}

ostream& operator <<(ostream& os, const Triangle triangle) {
    os << "АBC(" << triangle.a << ", " << triangle.b << ", " << triangle.c << ") P = " << triangle.p << " S = " << triangle.s << " Тип = " << triangle.type;
    return os;
}

void Triangle::SetABC(string& s) {
    try {
        float temp = 0;
        temp = stof(s);
        if (temp <= 0)
            throw 1;
        if (a == 0) {
            a = temp;
        }
        else if (b == 0) {
            b = temp;
        }
        else if (c == 0) {
            c = temp;
            TriangleMath();
            TriangleType();
            if (TriangleValid()) {
                throw 1;
            }
        }
    }
    catch (...) {
        cerr << "Стороны треугольника некорректны\n";
        exit(0);
    }


}

void Triangle::TriangleMath() {
    p = a + b + c;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Triangle::TriangleValid() {
    return (a + b < c) || (a + c < b) || (c + b < a) || a == 0 || b == 0 || c == 0;
}

void Triangle::TriangleType() {
    if (a == b && b == c) {
        type = "Равносторонний";
        return;
    }
    else if ((a == b && b != c) ||
        (a == c && c != b) ||
        (c == b && b != a)) {
        type = "Равнобедренный";
        return;
    }
    else {
        type = "Разносторонний";
        return;
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");

    Triangle triangle;

    string s;
    cout << "Введите сторону А: ";
    cin >> s;
    triangle.SetABC(s);
    cout << "Введите сторону B: ";
    cin >> s;
    triangle.SetABC(s);
    cout << "Введите сторону C: ";
    cin >> s;
    triangle.SetABC(s);

    cout << triangle;
}




