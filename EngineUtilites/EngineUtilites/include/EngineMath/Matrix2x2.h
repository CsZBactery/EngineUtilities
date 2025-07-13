#pragma once
#include <cmath>

namespace EngineUtilities {

/**
 * @brief Representa una matriz 2x2 y sus operaciones.
 */
struct Matrix2x2 {
    float m[2][2];

    Matrix2x2() {
        m[0][0] = m[1][1] = 1.0f;
        m[0][1] = m[1][0] = 0.0f;
    }

    Matrix2x2(float a, float b, float c, float d) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    float determinant() const {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    Matrix2x2 transpose() const {
        return Matrix2x2(
            m[0][0], m[1][0],
            m[0][1], m[1][1]
        );
    }

    Matrix2x2 inverse() const {
        float det = determinant();
        if (det == 0.0f) return Matrix2x2();
        float invDet = 1.0f / det;
        return Matrix2x2(
            m[1][1] * invDet, -m[0][1] * invDet,
            -m[1][0] * invDet, m[0][0] * invDet
        );
    }
};

} // namespace EngineUtilities
