#include <iostream>
#include <iomanip>
//#include "circleType.h"
//#include "rectangleType.h"

using namespace std;

class circleType {
public:
    void setRadius (double r){
        if (r >= 0)
            radius = r;
        else
            radius = 0;
    }
    double circleArea() const {
        return 3.1416 * radius * radius;
    }
    double circleCircumference() const {
        return 2 * 3.1416 * radius;
    }
    explicit circleType(double r = 0){
        setRadius(r);
        circleArea();
        circleCircumference();
    }
private:
    double radius{};
};

class rectangleType {
public:
    void setLength (double l){
        if (l >= 0)
            length = l;
        else
            length = 0;
    }
    void setWidth (double w){
        if (w >= 0)
            width = w;
        else
            width = 0;
    }
    double rectangleArea() const {
        return length * width;
    }
    double rectanglePerimeter() const {
        return 2 * (length + width);
    }
    explicit rectangleType(double l = 6.0, double w = 4.0) {
        setLength(l);
        setWidth(w);
        rectangleArea();
        rectanglePerimeter();
    }
private:
    double length{};
    double width{};
};

void showSelection(){
    cout << "*** Welcome to Calculation's Central ***" << endl;
    cout << "To select an option, enter " << endl;
    cout << "1. Calculate circle area " << endl;
    cout << "2. Calculate circle circumference " << endl;
    cout << "3. Calculate rectangle area " << endl;
    cout << "4. Calculate rectangle perimeter " << endl;
    cout << "5. Exit " << endl;
}

int main() {
    showSelection();
    circleType();
    rectangleType();

    int choice;
    double radius;
    double length;
    double width;

    circleType circle;
    rectangleType rectangle;

    cin >> choice;
    cout << fixed << showpoint << setprecision(2);

    while (choice != 5){
        switch (choice) {
            case 1:
                cout << "Enter a number for the radius of a circle: " << endl;
                cin >> radius;
                circle.setRadius(radius);
                cout << "The area of the circle is " << circle.circleArea() << endl;
                break;
            case 2:
                cout << "Enter a number for the radius of a circle: " << endl;
                cin >> radius;
                circle.setRadius(radius);
               cout << "The circumference of a circle is " << circle.circleCircumference() << endl;
               break;
            case 3:
                cout << "Enter a number for the length and width of a rectangle: " << endl;
                cin >> length >> width;
                rectangle.setLength(length);
                rectangle.setWidth(width);
                cout << "The area of a rectangle is " << rectangle.rectangleArea() << endl;
                break;
            case 4:
                cout << "Enter a number for the length and width of a rectangle: " << endl;
                cin >> length >> width;
                rectangle.setLength(length);
                rectangle.setWidth(width);
                cout << "The perimeter of a rectangle is " << rectangle.rectanglePerimeter()
                << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}



