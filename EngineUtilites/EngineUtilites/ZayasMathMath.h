#pragma once

namespace ZayasMath {

  // ====================================================
  // Funciones básicas
  // ====================================================

  inline float abs(float value) {
    return (value < 0) ? -value : value;
  }

  inline float square(float value) {
    return value * value;
  }

  inline float cube(float value) {
    return value * value * value;
  }

  inline float power(float base, int exponent) {
    float result = 1.0f;
    bool negative = (exponent < 0);
    if (negative) exponent = -exponent;
    for (int i = 0; i < exponent; ++i)
      result *= base;
    return negative ? 1.0f / result : result;
  }

  // ====================================================
  // Funciones de redondeo
  // ====================================================

  inline float floor(float value) {
    int i = static_cast<int>(value);
    return (value < 0 && value != i) ? i - 1 : i;
  }

  inline float ceil(float value) {
    int i = static_cast<int>(value);
    return (value > 0 && value != i) ? i + 1 : i;
  }

  inline float round(float value) {
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
  }

  inline float mod(float a, float b) {
    int div = static_cast<int>(a / b);
    return a - b * div;
  }

  // ====================================================
  // Raíz cuadrada (Método de Newton-Raphson)
  // ====================================================

  inline float sqrt(float number) {
    if (number <= 0) return 0;
    float x = number;
    float last = 0;
    const float epsilon = 1e-5f;
    while (abs(x - last) > epsilon) {
      last = x;
      x = 0.5f * (x + number / x);
    }
    return x;
  }

  // ====================================================
  // Exponencial y logaritmo (aproximaciones básicas)
  // ====================================================

  inline float exp(float x) {
    float sum = 1.0f;
    float term = 1.0f;
    for (int i = 1; i < 20; ++i) {
      term *= x / i;
      sum += term;
    }
    return sum;
  }

  inline float log(float x) {
    if (x <= 0) return 0;
    float y = (x - 1) / (x + 1);
    float y2 = y * y;
    float result = 0;
    for (int i = 1; i < 20; i += 2)
      result += (1.0f / i) * power(y, i);
    return 2.0f * result;
  }

  inline float log10(float x) {
    return log(x) / 2.30258509f; // log(10)
  }

  // ====================================================
  // Trigonometría: sin, cos, tan (Taylor series)
  // ====================================================

  inline float radians(float degrees) {
    return degrees * (3.14159265f / 180.0f);
  }

  inline float degrees(float radians) {
    return radians * (180.0f / 3.14159265f);
  }

  inline float sin(float x) {
    float x2 = x * x;
    float result = x;
    result -= (x2 * x) / 6;
    result += (x2 * x2 * x) / 120;
    result -= (x2 * x2 * x2 * x) / 5040;
    return result;
  }

  inline float cos(float x) {
    float x2 = x * x;
    float result = 1;
    result -= x2 / 2;
    result += (x2 * x2) / 24;
    result -= (x2 * x2 * x2) / 720;
    return result;
  }

  inline float tan(float x) {
    return sin(x) / cos(x);
  }

  // ====================================================
  // Trigonometría inversa (aproximaciones)
  // ====================================================

  inline float asin(float x) {
    float x3 = x * x * x;
    float x5 = x3 * x * x;
    return x + (x3 / 6.0f) + (3.0f * x5 / 40.0f);
  }

  inline float acos(float x) {
    return (3.14159265f / 2) - asin(x);
  }

  inline float atan(float x) {
    return x - (x * x * x) / 3 + (x * x * x * x * x) / 5;
  }

  // ====================================================
  // Funciones hiperbólicas (serie de Taylor)
  // ====================================================

  inline float sinh(float x) {
    return (exp(x) - exp(-x)) / 2.0f;
  }

  inline float cosh(float x) {
    return (exp(x) + exp(-x)) / 2.0f;
  }

  inline float tanh(float x) {
    return sinh(x) / cosh(x);
  }

} // namespace ZayasMath
