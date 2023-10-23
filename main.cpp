#include <iostream>
#include <vector>
#include <algorithm>
#include "Inc/Curve3D.h"
#include "Inc/Circle.h"
#include "Inc/Ellipse.h"
#include "Inc/Helix.h"

int main() {
    const double angle = PI / 4;

    std::vector<std::unique_ptr<Curve3D>> curves;

    curves.emplace_back(std::make_unique<Circle>(0.9));
    curves.emplace_back(std::make_unique<Ellipse>(9.0, 4.0));
    curves.emplace_back(std::make_unique<Helix>(5.0, 3.0));
    curves.emplace_back(std::make_unique<Circle>(20.0));
    curves.emplace_back(std::make_unique<Ellipse>(7.0, 8.0));
    curves.emplace_back(std::make_unique<Helix>(10.0, 2.0));
    curves.emplace_back(std::make_unique<Circle>(13.0));

    for (const auto& curve : curves) {
        Vector3D point = curve->getPoint(angle);
        Vector3D derivative = curve->getDerivative(angle);

        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
        std::cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << std::endl;
        std::cout << std::endl;
    }

    std::vector<Curve3D*> circleContainer;

    for (const auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve.get())) {
            circleContainer.push_back(curve.get());
        }
    }

    std::sort(circleContainer.begin(), circleContainer.end(), [](const Curve3D* a, const Curve3D* b) {
        const auto* circleA = dynamic_cast<const Circle*>(a);
        const auto* circleB = dynamic_cast<const Circle*>(b);

        return circleA->getRadius() < circleB->getRadius();
    });

    for (const Curve3D* circle : circleContainer) {
        const auto* circleObj = dynamic_cast<const Circle*>(circle);
        if (circleObj) {
            std::cout << "Radius: " << circleObj->getRadius() << std::endl;
        }
    }

    // Подсчет радиусов (можно и многопоточности добавить)
    double totalRadiusSum = 0.0;

    for (const Curve3D* circle : circleContainer) {
        const auto* circleObj = dynamic_cast<const Circle*>(circle);
        if (circleObj) {
            totalRadiusSum += circleObj->getRadius();
        }
    }

    std::cout << "Total Radius Sum: " << totalRadiusSum << std::endl;


    return 0;
}

