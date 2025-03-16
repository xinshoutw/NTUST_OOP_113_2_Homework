////////////////////////////////////////////////////////////////////////////////
/// @brief A test program for Point class demonstrating operations like Set, Move, Rotate, Reflect and object copying
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/17
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "Point.h"
#include <iostream>

using namespace std;

int main(void) {
    Point point;
    point.Set(0, 5);
    cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
    point.Reflect();
    cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
    point.Move(1, 2);
    cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
    point.Rotate();
    cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
    Point copy = point;
    cout << "Copy point:" << endl;
    cout << copy.GetHorizontal() << " " << copy.GetVertical() << endl;
    return 0;
}
