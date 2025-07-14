#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

/**
 * @brief Representa un vector en 4 dimensiones.
 */
struct CVector4 {
    float x, y, z, w;

    CVector4() : x(0), y(0), z(0), w(0) {}
    CVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    CVector4 operator+(const CVector4& other) const {
        return CVector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    CVector4 operator-(const CVector4& other) const {
        return CVector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    CVector4 operator*(float scalar) const {
        return CVector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    float dot(const CVector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    float magnitude() const {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    CVector4 normalized() const {
        float mag = magnitude();
        return (mag != 0) ? (*this * (1.0f / mag)) : CVector4();
    }
};

} // namespace ZayasMath
