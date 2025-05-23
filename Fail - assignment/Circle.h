#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(float radius) { m_radius = radius; }
    ~Circle() {}

    float Area() override;

    void SetRadius(float radius) const { radius = radius; }
    float GetRadius() { return m_radius; }

private:
    float m_radius;
};

