#pragma once 

#include <cmath>      // Funciones matemáticas estándar
#include <algorithm>  // Funciones como std::min y std::max

namespace EngineUtilities { 

/**
 * @brief Funciones matemáticas generales.
 */

// Valor absoluto
inline float abs(float value) { return std::abs(value); }

// Raíz cuadrada, cuadrado, cubo, potencia
inline float sqrt(float value) { return std::sqrt(value); }
inline float square(float value) { return value * value; }
inline float cube(float value) { return value * value * value; }
inline float power(float base, float exp) { return std::pow(base, exp); }

// Redondeo, piso, techo
inline float round(float value) { return std::round(value); }
inline float floor(float value) { return std::floor(value); }
inline float ceil(float value) { return std::ceil(value); }

// Módulo, exponencial, logaritmos
inline float mod(float a, float b) { return std::fmod(a, b); }
inline float exp(float value) { return std::exp(value); }
inline float log(float value) { return std::log(value); }
inline float log10(float value) { return std::log10(value); }

// Funciones trigonométricas
inline float sin(float angle) { return std::sin(angle); }
inline float cos(float angle) { return std::cos(angle); }
inline float tan(float angle) { return std::tan(angle); }

// Conversión de ángulos
inline float radians(float degrees) { return degrees * (3.14159265f / 180.0f); }
inline float degrees(float radians) { return radians * (180.0f / 3.14159265f); }

// Funciones geométricas
inline float circleArea(float radius) { return 3.14159265f * radius * radius; }
inline float circleCircumference(float radius) { return 2.0f * 3.14159265f * radius; }
inline float rectangleArea(float width, float height) { return width * height; }
inline float rectanglePerimeter(float width, float height) { return 2 * (width + height); }
inline float triangleArea(float base, float height) { return 0.5f * base * height; }
inline float distance(float x1, float y1, float x2, float y2) {
    return sqrt(square(x2 - x1) + square(y2 - y1));
}

// Interpolación lineal
inline float lerp(float a, float b, float t) { return a + t * (b - a); }

// Factorial
inline int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Comparación con margen de error
inline bool approxEqual(float a, float b, float epsilon = 1e-5f) {
    return std::fabs(a - b) < epsilon;
}

} // namespace EngineUtilities
