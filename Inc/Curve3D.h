//
// Created by alexd on 21.10.2023.
//

#ifndef CODEX_CURVE3D_H
#define CODEX_CURVE3D_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


const double PI = 3.14159265358979323846;

struct Vector3D {
    double x;
    double y;
    double z;
};

class Curve3D {
public:
    virtual ~Curve3D() = default;

    virtual Vector3D getPoint(double t) const = 0;

    virtual Vector3D getDerivative(double t) const = 0;


};


#endif //CODEX_CURVE3D_H
