////////////////////////////////////////////////////////////////////////////////
/// @brief Define a class named "Point", implement the following methods.
///        1. two private integer variables named "vertical" and "horizontal"
///        2. member variables are default to 0
///        3. "Set" public method with two parameters to reset member variables
///        4. "Move" public method with two parameters to move member variables
///        5. "Rotate" public method to change point's quadrant in clockwise
///        6. "RetrieveVertical" public method to return "x" of point
///        7. "RetrieveHorizontal" public method to return "y" of point
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "Point.h"
#include <iostream>

int main() {
    using namespace std;
    Point point;

    point.Set(0, 5);
    cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;

    point.Move(1, 2);
    cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
    for (int i = 0; i < 4; i++) {
        point.Rotate();
        cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl;
    }

    return 0;
}
