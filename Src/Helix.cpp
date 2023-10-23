//
// Created by alexd on 22.10.2023.
//

#include "../Inc/Helix.h"

Helix::Helix(double r, double s) : m_radius(r), m_step(s)  {
    if (r <= 0) {
        std::cout << "Radius must be positive";
        throw std::invalid_argument("Радиус должен быть положительным.");
    }
}

Vector3D Helix::getPoint(double t) const {
    double x = m_radius * cos(t);
    double y = m_radius * sin(t);
    double z = m_step * t;

    Vector3D point = {x, y, z};
    return point;
}

Vector3D Helix::getDerivative(double t) const {
    double dx_dt = -m_radius * sin(t);
    double dy_dt = m_radius * cos(t);
    double dz_dt = m_step;

    Vector3D derivative = {dx_dt, dy_dt, dz_dt};
    return derivative;
}