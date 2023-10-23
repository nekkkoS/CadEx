//
// Created by alexd on 21.10.2023.
//

#ifndef CODEX_ELLIPSE_H
#define CODEX_ELLIPSE_H


#include "Curve3D.h"


class Ellipse : public Curve3D {
public:
    Ellipse(double rx, double ry);

    Vector3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;

private:
    double m_radiusX;
    double m_radiusY;
};


#endif //CODEX_ELLIPSE_H
