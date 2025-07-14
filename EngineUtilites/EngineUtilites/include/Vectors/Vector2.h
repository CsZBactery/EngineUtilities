#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

/**
 * @brief Representa un vector bidimensional.
 */
struct CVector2 {
    float x, y;

    CVector2() : x(0), y(0) {}
    CVector2(float x, float y) : x(x), y(y) {}

    CVector2 operator+(const CVector2& other) const {
        return CVector2(x + other.x, y + other.y);
    }

    CVector2 operator-(const CVector2& other) const {
        return CVector2(x - other.x, y - other.y);
    }

    CVector2 operator*(float scalar) const {
        return CVector2(x * scalar, y * scalar);
    }

    float dot(const CVector2& other) const {
        return x * other.x + y * other.y;
    }

    float magnitude() const {
        return sqrt(x * x + y * y);
    }

    CVector2 normalized() const {
        float mag = magnitude();
        return (mag != 0) ? (*this * (1.0f / mag)) : CVector2();
    }
};

} // namespace ZayasMath
