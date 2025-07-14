#pragma once

#include <ZayasMathMath.h>

namespace ZayasMath {

/**
 * @brief Representa un vector tridimensional.
 */
struct CVector3 {
    float x, y, z;

    CVector3() : x(0), y(0), z(0) {}
    CVector3(float x, float y, float z) : x(x), y(y), z(z) {}

    CVector3 operator+(const CVector3& other) const {
        return CVector3(x + other.x, y + other.y, z + other.z);
    }

    CVector3 operator-(const CVector3& other) const {
        return CVector3(x - other.x, y - other.y, z - other.z);
    }

    CVector3 operator*(float scalar) const {
        return CVector3(x * scalar, y * scalar, z * scalar);
    }

    float dot(const CVector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    CVector3 cross(const CVector3& other) const {
        return CVector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }

    CVector3 normalized() const {
        float mag = magnitude();
        return (mag != 0) ? (*this * (1.0f / mag)) : CVector3();
    }
};

} // namespace ZayasMath
