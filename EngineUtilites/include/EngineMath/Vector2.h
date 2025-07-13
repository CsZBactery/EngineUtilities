#pragma once 

#include <cmath>      // Para operaciones matemáticas 
#include <iostream>   

namespace EngineUtilities { // Namespace del motor de utilidades matemáticas

/**
 * @brief Representa un vector bidimensional.
 */
struct Vector2 {
    float x, y; // Componentes X e Y del vector

    // Constructor por defecto que inicializa en (0,0)
    Vector2() : x(0), y(0) {}

    // Constructor que recibe valores específicos
    Vector2(float x, float y) : x(x), y(y) {}

    // Suma de vectores componente a componente
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // Resta de vectores componente a componente
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // Multiplicacion  entre dos vectores
    float dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    // Longitud del vector
    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // Devuelve al vector
    Vector2 normalized() const {
        float mag = magnitude();
        return mag != 0 ? Vector2(x / mag, y / mag) : Vector2(); // Vector (0,0) 
    }

    // Multiplicacion por escalar
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }
};

} // namespace EngineUtilities
