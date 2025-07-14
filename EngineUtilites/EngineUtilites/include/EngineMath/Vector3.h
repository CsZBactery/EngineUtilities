#pragma once

#include "../ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Representa un vector tridimensional con componentes flotantes.
   */
  struct CVector3 {
    float x, y, z;

    /**
     * @brief Constructor por defecto. Inicializa a (0, 0, 0).
     */
    CVector3() : x(0), y(0), z(0) {}

    /**
     * @brief Constructor con componentes específicas.
     * @param xVal Componente X
     * @param yVal Componente Y
     * @param zVal Componente Z
     */
    CVector3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    /**
     * @brief Suma dos vectores componente a componente.
     * @param other El otro vector.
     * @return Resultado de la suma.
     */
    CVector3 operator+(const CVector3& other) const {
      return CVector3(x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Resta dos vectores componente a componente.
     * @param other El otro vector.
     * @return Resultado de la resta.
     */
    CVector3 operator-(const CVector3& other) const {
      return CVector3(x - other.x, y - other.y, z - other.z);
    }

    /**
     * @brief Multiplica el vector por un escalar.
     * @param scalar Valor escalar.
     * @return Vector escalado.
     */
    CVector3 operator*(float scalar) const {
      return CVector3(x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Producto punto entre este vector y otro.
     * @param other Otro vector.
     * @return Valor escalar del producto punto.
     */
    float dot(const CVector3& other) const {
      return x * other.x + y * other.y + z * other.z;
    }

    /**
     * @brief Producto cruzado entre este vector y otro.
     * @param other Otro vector.
     * @return Vector perpendicular resultante.
     */
    CVector3 cross(const CVector3& other) const {
      return CVector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
      );
    }

    /**
     * @brief Magnitud (longitud) del vector.
     * @return Valor de magnitud.
     */
    float magnitude() const {
      return sqrt(x * x + y * y + z * z);  // Usa sqrt de tu librería ZayasMathMath
    }

    /**
     * @brief Normaliza el vector a magnitud 1.
     * @return Vector normalizado (unitario).
     */
    CVector3 normalized() const {
      float mag = magnitude();
      return (mag != 0) ? CVector3(x / mag, y / mag, z / mag) : CVector3();
    }

    /**
     * @brief Compara si dos vectores son aproximadamente iguales.
     * @param other El otro vector.
     * @param epsilon Margen de error permitido.
     * @return true si son casi iguales.
     */
    bool approxEqual(const CVector3& other, float epsilon = 1e-5f) const {
      return ::ZayasMath::approxEqual(x, other.x, epsilon) &&
        ::ZayasMath::approxEqual(y, other.y, epsilon) &&
        ::ZayasMath::approxEqual(z, other.z, epsilon);
    }
  };

} // namespace ZayasMath
