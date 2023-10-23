//
// Created by alexd on 21.10.2023.
//

#ifndef CODEX_CIRCLE_H
#define CODEX_CIRCLE_H


#include "Curve3D.h"

class Circle : public Curve3D {
public:
    Circle(double r);

    Vector3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;

    double getRadius() const;

private:
    double m_radius;
};


#endif //CODEX_CIRCLE_H
