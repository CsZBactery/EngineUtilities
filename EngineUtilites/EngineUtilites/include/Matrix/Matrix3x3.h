#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Representa una matriz 3x3 de componentes flotantes.
   */
  struct Matrix3x3 {
    float m[3][3]; ///< Arreglo 3x3 de elementos

    /**
     * @brief Constructor por defecto. Inicializa a identidad.
     */
    Matrix3x3() {
      m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
      m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
      m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
    }

    /**
     * @brief Constructor con 9 valores en orden fila-por-fila.
     */
    Matrix3x3(float a, float b, float c,
      float d, float e, float f,
      float g, float h, float i) {
      m[0][0] = a; m[0][1] = b; m[0][2] = c;
      m[1][0] = d; m[1][1] = e; m[1][2] = f;
      m[2][0] = g; m[2][1] = h; m[2][2] = i;
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
     * @brief Multiplicación por escalar.
     */
    Matrix3x3 operator*(float scalar) const {
      Matrix3x3 result;
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          result.m[i][j] = m[i][j] * scalar;
      return result;
    }

    /**
     * @brief Multiplicación por otra matriz 3x3.
     */
    Matrix3x3 operator*(const Matrix3x3& other) const {
      Matrix3x3 result;
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
          result.m[i][j] = 0;
          for (int k = 0; k < 3; ++k)
            result.m[i][j] += m[i][k] * other.m[k][j];
        }
      return result;
    }

    /**
     * @brief Transpuesta de la matriz.
     */
    Matrix3x3 transposed() const {
      return Matrix3x3(
        m[0][0], m[1][0], m[2][0],
        m[0][1], m[1][1], m[2][1],
        m[0][2], m[1][2], m[2][2]
      );
    }

    /**
     * @brief Determinante de la matriz 3x3.
     */
    float determinant() const {
      return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
        m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
        m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    /**
     * @brief Inversa de la matriz 3x3.
     */
    Matrix3x3 inverse() const {
      float det = determinant();
      if (det == 0) return Matrix3x3(); // Retorna identidad si no se puede invertir

      float invDet = 1.0f / det;
      Matrix3x3 r;

      r.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) * invDet;
      r.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invDet;
      r.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invDet;

      r.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invDet;
      r.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invDet;
      r.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * invDet;

      r.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * invDet;
      r.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * invDet;
      r.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * invDet;

      return r;
    }

    /**
     * @brief Crea y devuelve la matriz identidad 3x3.
     */
    static Matrix3x3 identity() {
      return Matrix3x3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
      );
    }
  };

} // namespace ZayasMath
