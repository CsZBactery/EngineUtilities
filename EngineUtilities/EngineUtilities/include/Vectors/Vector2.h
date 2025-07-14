#pragma once


#include "../ZayasMathMath.h"
#include <Vectors/Vector2.h>

namespace ZayasMath {

  /**
   * @brief Representa un vector bidimensional con componentes flotantes.
   */
  struct CVector2 {
    float x, y;

    /**
     * @brief Constructor por defecto. Inicializa x e y en 0.
     */
    CVector2() : x(0), y(0) {}

    /**
     * @brief Constructor con parámetros.
     * @param xVal Valor de la componente x.
     * @param yVal Valor de la componente y.
     */
    CVector2(float xVal, float yVal) : x(xVal), y(yVal) {}

    /**
     * @brief Suma componente a componente con otro vector.
     * @param other Otro vector a sumar.
     * @return Resultado de la suma.
     */
    CVector2 operator+(const CVector2& other) const {
      return CVector2(x + other.x, y + other.y);
    }

    /**
     * @brief Resta componente a componente con otro vector.
     * @param other Otro vector a restar.
     * @return Resultado de la resta.
     */
    CVector2 operator-(const CVector2& other) const {
      return CVector2(x - other.x, y - other.y);
    }

    /**
     * @brief Multiplicación por escalar.
     * @param scalar Escalar por el cual multiplicar.
     * @return Vector escalado.
     */
    CVector2 operator*(float scalar) const {
      return CVector2(x * scalar, y * scalar);
    }

    /**
     * @brief Producto punto entre este vector y otro.
     * @param other Otro vector.
     * @return Resultado escalar del producto punto.
     */
    float dot(const CVector2& other) const {
      return x * other.x + y * other.y;
    }

    /**
     * @brief Magnitud (longitud) del vector.
     * @return Valor de magnitud.
     */
    float magnitude() const {
      return sqrt(x * x + y * y);  // Usa sqrt de tu librería ZayasMathMath.h
    }

    /**
     * @brief Devuelve una versión normalizada (de magnitud 1) del vector.
     * @return Vector unitario.
     */
    CVector2 normalized() const {
      float mag = magnitude();
      return (mag != 0) ? CVector2(x / mag, y / mag) : CVector2();
    }

    /**
     * @brief Compara este vector con otro dentro de un margen de error.
     * @param other Otro vector.
     * @param epsilon Margen permitido.
     * @return true si son aproximadamente iguales.
     */
    bool approxEqual(const CVector2& other, float epsilon = 1e-5f) const {
      return ::ZayasMath::approxEqual(x, other.x, epsilon) &&
        ::ZayasMath::approxEqual(y, other.y, epsilon);
    }
  };

} // namespace ZayasMath
