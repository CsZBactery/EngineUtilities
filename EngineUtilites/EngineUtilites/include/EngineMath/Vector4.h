#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Representa un vector de 4 dimensiones con componentes flotantes.
   */
  struct CVector4 {
    float x, y, z, w;

    /**
     * @brief Constructor por defecto. Inicializa a (0, 0, 0, 0).
     */
    CVector4() : x(0), y(0), z(0), w(0) {}

    /**
     * @brief Constructor con valores iniciales.
     * @param xVal Componente X
     * @param yVal Componente Y
     * @param zVal Componente Z
     * @param wVal Componente W
     */
    CVector4(float xVal, float yVal, float zVal, float wVal)
      : x(xVal), y(yVal), z(zVal), w(wVal) {
    }

    /**
     * @brief Suma componente a componente con otro vector.
     * @param other Otro vector.
     * @return Vector resultante.
     */
    CVector4 operator+(const CVector4& other) const {
      return CVector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    /**
     * @brief Resta componente a componente con otro vector.
     * @param other Otro vector.
     * @return Vector resultante.
     */
    CVector4 operator-(const CVector4& other) const {
      return CVector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    /**
     * @brief Multiplicación por escalar.
     * @param scalar Escalar.
     * @return Vector escalado.
     */
    CVector4 operator*(float scalar) const {
      return CVector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    /**
     * @brief Producto punto con otro vector.
     * @param other Otro vector.
     * @return Valor escalar del producto punto.
     */
    float dot(const CVector4& other) const {
      return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    /**
     * @brief Magnitud del vector.
     * @return Valor de magnitud.
     */
    float magnitude() const {
      return sqrt(x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Normaliza el vector a magnitud 1.
     * @return Vector normalizado.
     */
    CVector4 normalized() const {
      float mag = magnitude();
      return (mag != 0) ? CVector4(x / mag, y / mag, z / mag, w / mag) : CVector4();
    }

    /**
     * @brief Compara si dos vectores son aproximadamente iguales.
     * @param other Otro vector.
     * @param epsilon Margen de error permitido.
     * @return true si son casi iguales.
     */
    bool approxEqual(const CVector4& other, float epsilon = 1e-5f) const {
      return ::ZayasMath::approxEqual(x, other.x, epsilon) &&
        ::ZayasMath::approxEqual(y, other.y, epsilon) &&
        ::ZayasMath::approxEqual(z, other.z, epsilon) &&
        ::ZayasMath::approxEqual(w, other.w, epsilon);
    }
  };

} // namespace ZayasMath
