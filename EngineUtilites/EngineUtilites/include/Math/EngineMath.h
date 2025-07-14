#pragma once

#include "ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Calcula el área de un círculo.
   * @param radius Radio del círculo.
   * @return Área.
   */
  inline float circleArea(float radius) {
    return 3.14159265f * radius * radius;
  }

  /**
   * @brief Calcula la circunferencia de un círculo.
   * @param radius Radio del círculo.
   * @return Circunferencia.
   */
  inline float circleCircumference(float radius) {
    return 2.0f * 3.14159265f * radius;
  }

  /**
   * @brief Calcula el área de un rectángulo.
   * @param width Ancho del rectángulo.
   * @param height Altura del rectángulo.
   * @return Área.
   */
  inline float rectangleArea(float width, float height) {
    return width * height;
  }

  /**
   * @brief Calcula el perímetro de un rectángulo.
   * @param width Ancho.
   * @param height Altura.
   * @return Perímetro.
   */
  inline float rectanglePerimeter(float width, float height) {
    return 2 * (width + height);
  }

  /**
   * @brief Calcula el área de un triángulo.
   * @param base Base del triángulo.
   * @param height Altura.
   * @return Área.
   */
  inline float triangleArea(float base, float height) {
    return 0.5f * base * height;
  }

  /**
   * @brief Calcula la distancia entre dos puntos en 2D.
   */
  inline float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  }

  /**
   * @brief Devuelve el mayor entre dos valores.
   */
  inline float EMax(float a, float b) {
    return (a > b) ? a : b;
  }

  /**
   * @brief Devuelve el menor entre dos valores.
   */
  inline float EMin(float a, float b) {
    return (a < b) ? a : b;
  }

  /**
   * @brief Interpolación lineal entre dos valores.
   * @param a Valor inicial.
   * @param b Valor final.
   * @param t Factor de interpolación [0, 1].
   */
  inline float lerp(float a, float b, float t) {
    return a + t * (b - a);
  }

  /**
   * @brief Factorial de un número entero.
   */
  inline int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
  }

  /**
   * @brief Compara si dos valores flotantes son aproximadamente iguales.
   */
  inline bool approxEqual(float a, float b, float epsilon = 1e-5f) {
    return abs(a - b) < epsilon;
  }

} // namespace ZayasMath
