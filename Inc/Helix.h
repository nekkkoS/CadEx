//
// Created by alexd on 21.10.2023.
//

#ifndef CODEX_HELIX_H
#define CODEX_HELIX_H


#include "Curve3D.h"

class Helix : public Curve3D {
public:
    Helix(double r, double s);

    Vector3D getPoint(double t) const override;

    Vector3D getDerivative(double t) const override;

private:
    double m_radius;
    double m_step;
};


#endif //CODEX_HELIX_H
