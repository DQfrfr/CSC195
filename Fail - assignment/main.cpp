#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main() {
    vector<Shape*> shapes;

    Circle* c = new Circle(3.0f);
    Rectangle* r = new Rectangle(4.0f, 5.0f);
    shapes.push_back(c);
    shapes.push_back(r);

    for (int i = 0; i <= shapes.size() - 1; i++)
    {
		cout << "Shape #" << i + 1 << endl;
        cout << "Area: " << shapes[i]->Area() << endl;

        if (Circle* d = dynamic_cast<Circle*>(shapes.at(i)))
        {
			cout << "Circle radius: " << d->GetRadius() << endl;
        }
        cout << endl;
    }

    // FIXME: Getting memory leak! Delete all shapes.
	(*c).~Circle();
	(*r).~Rectangle();
    c = nullptr;
	r = nullptr;
    return 0;
}
