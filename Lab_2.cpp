#include <iostream>
#include <iomanip>
//#include "circleType.h"
//#include "rectangleType.h"
//#include "shapesType.h"

using namespace std;

class circleType {

public:

    double operator+(circleType &);

    void setRadius(double r) {
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

    explicit circleType(double r = 0) {
        setRadius(r);
        circleArea();
        circleCircumference();
    }

private:
    double radius{};
};

double circleType::operator+(circleType &circle) {
    return circle.circleArea() + circle.circleArea();
}

class rectangleType {
public:
    double operator+(rectangleType &);

    void setLength(double l) {
        if (l >= 0)
            length = l;
        else
            length = 0;
    }

    void setWidth(double w) {
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

double rectangleType::operator+(rectangleType &rectangle) {
    return rectangle.rectangleArea() + rectangle.rectangleArea();
}

class shapesType : circleType, rectangleType {
    bool operator>(shapesType &) const;

};

bool shapesType::operator>(shapesType &circle) const {
    return (circle.circleArea() > rectangleArea()) || (rectangleArea() > circle.circleArea());
}


void showSelection() {
    cout << "*** Welcome to Calculation's Central ***" << endl;
    cout << "To select an option, enter " << endl;
    cout << "1. Calculate circle area " << endl;
    cout << "2. Calculate circle circumference " << endl;
    cout << "3. Calculate rectangle area " << endl;
    cout << "4. Calculate rectangle perimeter " << endl;
    cout << "5. Calculate two circle area's  " << endl;
    cout << "6. Calculate two rectangle area's " << endl;
    cout << "7. Compare the area of a circle and rectangle " << endl;
    cout << "8. Exit " << endl;
}

int main() {
    showSelection();
    circleType();
    rectangleType();
    shapesType();

    circleType circle1, circle2;
    circleType compareCircle;
    rectangleType rectangle1, rectangle2;
    rectangleType compareRectangle;

    int choice;
    double radius, radius2;
    double length, length2;
    double width, width2;

    circleType circle;
    rectangleType rectangle;

    cin >> choice;
    cout << fixed << showpoint << setprecision(2);

    while (choice != 8) {
        switch (choice) {
            case 1:
                cout << "Enter a number for the radius of a circle: " << endl;
                cin >> radius;
                circle.setRadius(radius);
                cout << endl;
                cout << "The area of the circle is " << circle.circleArea() << "." << endl;
                cout << endl;
                break;
            case 2:
                cout << "Enter a number for the radius of a circle: " << endl;
                cin >> radius;
                circle.setRadius(radius);
                cout << endl;
                cout << "The circumference of a circle is " << circle.circleCircumference() << "."
                     << endl;
                cout << endl;
                break;
            case 3:
                cout << "Enter a number for the length and width of a rectangle: " << endl;
                cin >> length >> width;
                rectangle.setLength(length);
                rectangle.setWidth(width);
                cout << endl;
                cout << "The area of a rectangle is " << rectangle.rectangleArea() << "."
                     << endl;
                cout << endl;
                break;
            case 4:
                cout << "Enter a number for the length and width of a rectangle: " << endl;
                cin >> length >> width;
                rectangle.setLength(length);
                rectangle.setWidth(width);
                cout << endl;
                cout << "The perimeter of a rectangle is " << rectangle.rectanglePerimeter() << "."
                     << endl;
                cout << endl;
                break;
            case 5:
                cout << "Enter two numbers for two circles: " << endl;
                cin >> radius >> radius2;
                circle1.setRadius(radius);
                circle2.setRadius(radius2);
                cout << endl;
                cout << "The sum of the area for two circle's is " << circle1 + circle2 << "."
                     << endl;
                cout << endl;
                break;
            case 6:
                cout << "Enter two numbers for the length and width, and "
                        "another two numbers for the length and width for two rectangle's: " << endl;
                cin >> length >> width >> length2 >> width2;
                rectangle1.setLength(length);
                rectangle1.setWidth(width);
                rectangle2.setLength(length2);
                rectangle2.setWidth(width2);
                cout << endl;
                cout << "The sum of the area for two rectangle's is "
                     << rectangle1 + rectangle2 << "." << endl;
                cout << endl;
                break;
            case 7:
                cout << "Enter a number for the radius of a circle to compare which area is larger: "
                     << endl;
                cin >> radius;
                compareCircle.setRadius(radius);
                cout << endl;

                cout << "Enter a number for both the length and width for the area of a "
                        "rectangle to compare which is larger:" << endl;
                cin >> length >> width;
                rectangle.setLength(length);
                rectangle.setWidth(width);
                cout << endl;

                compareCircle.circleArea();
                compareRectangle.rectangleArea();

                if (compareCircle.circleArea() > compareRectangle.rectangleArea()) {
                    cout << "The area of the circle is " << compareCircle.circleArea() <<
                         ", and it's area is larger than the area of a rectangle that's "
                         << compareRectangle.rectangleArea() << "." << endl;
                    cout << endl;
                } else if (compareRectangle.rectangleArea() > compareCircle.circleArea()) {
                    cout << "The area of the rectangle is " << compareRectangle.rectangleArea()
                         << ", and it's area is larger than the area of a circle that's "
                         << compareCircle.circleArea() << "." << endl;
                    cout << endl;
                }
                break;
            default:
                cout << "Invalid option." << endl;
        }
        showSelection();
        cin >> choice;
    }
    return 0;
}



