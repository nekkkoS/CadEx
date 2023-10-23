//
// Created by alexd on 22.10.2023.
//

#include "../Inc/Ellipse.h"

Ellipse::Ellipse(double rx, double ry) : m_radiusX(rx), m_radiusY(ry) {
    if (rx <= 0 || ry <= 0) {
        std::cout << "Radii must be positive";
        throw std::invalid_argument("Радиусы должны быть положительными.");
    }
}

Vector3D Ellipse::getPoint(double t) const {
    double x = m_radiusX * cos(t);
    double y = m_radiusY * sin(t);
    double z = 0.0;

    Vector3D point = {x, y, z};
    return point;
}

Vector3D Ellipse::getDerivative(double t) const {
    double dx_dt = -m_radiusX * sin(t);
    double dy_dt = m_radiusY * cos(t);
    double dz_dt = 0.0;

    Vector3D derivative = {dx_dt, dy_dt, dz_dt};
    return derivative;
}