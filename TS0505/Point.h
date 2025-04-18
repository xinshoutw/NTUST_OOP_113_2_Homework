#ifndef POINT_H
#define POINT_H

class Point {

public:
    Point() = default;
    ~Point() = default;

    void Set(float x, float y);
    void Move(float dx, float dy);
    void Rotate();
    void Reflect();

    float GetHorizontal() const;
    float GetVertical() const;

private:
    float x;
    float y;
};

#endif // POINT_H
