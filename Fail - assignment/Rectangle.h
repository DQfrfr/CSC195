#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(float width, float height) {
        m_width = width;
        m_height = height;
    }

    float Area() override;

private:
    float m_width;
    float m_height;
};

