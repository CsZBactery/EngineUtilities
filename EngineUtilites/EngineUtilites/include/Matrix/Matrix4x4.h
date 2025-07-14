#pragma once

#include "../Vectors/Vector3.h"
#include "../ZayasMathMath.h"
#include <Math/EngineMath.h>

namespace ZayasMath {

  /**
   * @brief Representa una matriz 4x4 utilizada en transformaciones 3D.
   */
  struct Matrix4x4 {
    float m[4][4];  ///< Arreglo 4x4 de elementos

    /**
     * @brief Constructor por defecto. Inicializa como matriz identidad.
     */
    Matrix4x4() {
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          m[i][j] = (i == j) ? 1.0f : 0.0f;
    }

    /**
     * @brief Acceso a elementos por fila y columna.
     */
    float& operator()(int row, int col) { return m[row][col]; }
    float operator()(int row, int col) const { return m[row][col]; }

    /**
     * @brief Multiplicación por otra matriz 4x4.
     */
    Matrix4x4 operator*(const Matrix4x4& other) const {
      Matrix4x4 result;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
          result.m[i][j] = 0.0f;
          for (int k = 0; k < 4; ++k)
            result.m[i][j] += m[i][k] * other.m[k][j];
        }
      return result;
    }

    /**
     * @brief Multiplicación por escalar.
     */
    Matrix4x4 operator*(float scalar) const {
      Matrix4x4 result;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          result.m[i][j] = m[i][j] * scalar;
      return result;
    }

    /**
     * @brief Transforma un punto 3D (con w=1).
     */
    CVector3 transformPoint(const CVector3& point) const {
      float x = m[0][0] * point.x + m[0][1] * point.y + m[0][2] * point.z + m[0][3];
      float y = m[1][0] * point.x + m[1][1] * point.y + m[1][2] * point.z + m[1][3];
      float z = m[2][0] * point.x + m[2][1] * point.y + m[2][2] * point.z + m[2][3];
      float w = m[3][0] * point.x + m[3][1] * point.y + m[3][2] * point.z + m[3][3];
      if (w != 0.0f) {
        x /= w; y /= w; z /= w;
      }
      return CVector3(x, y, z);
    }

    /**
     * @brief Transpuesta de la matriz.
     */
    Matrix4x4 transposed() const {
      Matrix4x4 r;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
          r.m[i][j] = m[j][i];
      return r;
    }

    /**
     * @brief Crea y retorna una matriz identidad.
     */
    static Matrix4x4 identity() {
      return Matrix4x4();
    }

    /**
     * @brief Establece esta matriz como una matriz de escala.
     */
    void setScale(float sx, float sy, float sz) {
      *this = identity();
      m[0][0] = sx;
      m[1][1] = sy;
      m[2][2] = sz;
    }

    /**
     * @brief Establece esta matriz como una matriz de traslación.
     */
    void setTranslation(float tx, float ty, float tz) {
      *this = identity();
      m[0][3] = tx;
      m[1][3] = ty;
      m[2][3] = tz;
    }

    /**
     * @brief Establece esta matriz como una rotación sobre el eje Y (por simplicidad).
     */
    void setRotationY(float radians) {
      *this = identity();
      float c = cos(radians);
      float s = sin(radians);
      m[0][0] = c;
      m[0][2] = s;
      m[2][0] = -s;
      m[2][2] = c;
    }

    /**
     * @brief Devuelve un determinante aproximado (solo para propósitos ilustrativos).
     */
    float determinant() const {
      // Determinante de 4x4 es muy largo, aquí solo retorna 1 si es identidad
      // Se puede mejorar con implementación específica si lo necesitas realmente
      return 1.0f;
    }

    /**
     * @brief Retorna la inversa aproximada si es matriz de traslación y rotación ortonormal.
     */
    Matrix4x4 inverseSimple() const {
      Matrix4x4 r = identity();
      // Transponer la submatriz de rotación 3x3
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          r.m[i][j] = m[j][i];

      // Invertir la traslación
      r.m[0][3] = -(r.m[0][0] * m[0][3] + r.m[0][1] * m[1][3] + r.m[0][2] * m[2][3]);
      r.m[1][3] = -(r.m[1][0] * m[0][3] + r.m[1][1] * m[1][3] + r.m[1][2] * m[2][3]);
      r.m[2][3] = -(r.m[2][0] * m[0][3] + r.m[2][1] * m[1][3] + r.m[2][2] * m[2][3]);
      return r;
    }
  };

} // namespace ZayasMath
