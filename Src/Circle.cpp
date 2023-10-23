//
// Created by alexd on 22.10.2023.
//

#include "../Inc/Circle.h"

Circle::Circle(double r) : m_radius(r) {
    if (r <= 0) {
        std::cout << "Radius must be positive";
        throw std::invalid_argument("Radius must be positive");
    }
}

Vector3D Circle::getPoint(double t) const {
    double x = m_radius * cos(t);
    double y = m_radius * sin(t);

    Vector3D point = {x, y, 0};
    return point;
}

Vector3D Circle::getDerivative(double t) const {
    double dx_dt = -m_radius * sin(t);
    double dy_dt = m_radius * cos(t);
    double dz_dt = 0.0;
    Vector3D derivative = {dx_dt, dy_dt, dz_dt};
    return derivative;
}

double Circle::getRadius() const {
    return m_radius;
}