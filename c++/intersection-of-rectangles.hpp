#include <iostream>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

ostream& operator<<(ostream& os, const Rectangle& rect)
{
    os  << "(leftX: " << rect.getLeftX() << ", bottomY: " << rect.getBottomY()
        << ", width: " << rect.getWidth() << ", height: " << rect.getHeight() << ")";
    return os;
}

Rectangle findRectangularOverlap(const Rectangle& rect1, const Rectangle& rect2)
{
    // calculate the overlap between the two rectangles
    

    return rect1;
}
