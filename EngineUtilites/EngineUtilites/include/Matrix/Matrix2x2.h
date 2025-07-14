#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Representa una matriz 2x2 con componentes flotantes.
   */
  struct Matrix2x2 {
    float m[2][2];  ///< Arreglo 2x2 de elementos

    /**
     * @brief Constructor por defecto. Inicializa a matriz identidad.
     */
    Matrix2x2() {
      m[0][0] = 1; m[0][1] = 0;
      m[1][0] = 0; m[1][1] = 1;
    }

    /**
     * @brief Constructor con valores individuales.
     */
    Matrix2x2(float a, float b, float c, float d) {
      m[0][0] = a; m[0][1] = b;
      m[1][0] = c; m[1][1] = d;
    }

    /**
     * @brief Acceso por fila y columna (lectura/escritura).
     */
    float& operator()(int row, int col) { return m[row][col]; }

    /**
     * @brief Acceso por fila y columna (solo lectura).
     */
    float operator()(int row, int col) const { return m[row][col]; }

    /**
     * @brief Suma dos matrices 2x2.
     */
    Matrix2x2 operator+(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
        m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
      );
    }

    /**
     * @brief Resta dos matrices 2x2.
     */
    Matrix2x2 operator-(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
        m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
      );
    }

    /**
     * @brief Multiplicación matriz * matriz.
     */
    Matrix2x2 operator*(const Matrix2x2& other) const {
      return Matrix2x2(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0], m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1],
        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0], m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1]
      );
    }

    /**
     * @brief Multiplicación por escalar.
     */
    Matrix2x2 operator*(float scalar) const {
      return Matrix2x2(
        m[0][0] * scalar, m[0][1] * scalar,
        m[1][0] * scalar, m[1][1] * scalar
      );
    }

    /**
     * @brief Determinante de la matriz.
     */
    float determinant() const {
      return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    /**
     * @brief Devuelve la transpuesta de la matriz.
     */
    Matrix2x2 transposed() const {
      return Matrix2x2(
        m[0][0], m[1][0],
        m[0][1], m[1][1]
      );
    }

    /**
     * @brief Devuelve la inversa de la matriz (si existe).
     */
    Matrix2x2 inverse() const {
      float det = determinant();
      if (det == 0) return Matrix2x2(); // matriz identidad si no se puede invertir
      float invDet = 1.0f / det;
      return Matrix2x2(
        m[1][1] * invDet, -m[0][1] * invDet,
        -m[1][0] * invDet, m[0][0] * invDet
      );
    }

    /**
     * @brief Crea y devuelve una matriz identidad.
     */
    static Matrix2x2 identity() {
      return Matrix2x2(1, 0, 0, 1);
    }
  };

} // namespace ZayasMath
