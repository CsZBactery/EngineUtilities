# EngineUtilities

Librería matemática personalizada en C++ diseñada para simulaciones gráficas y motores 2D/3D. Incluye únicamente archivos `.h`.

---

## Estructura del Proyecto

```
EngineUtilities/
├── Vectors/
│   ├── Vector2.h
│   ├── Vector3.h
│   └── Vector4.h
├── Matrices/
│   ├── Matrix2x2.h
│   ├── Matrix3x3.h
│   └── Matrix4x4.h
├── Rotations/
│   └── Quaternion.h
├── ZayasMathMath.h
├── EngineMath.h
├── main.cpp
└── README.md
```

## Namespace

Todas las clases y funciones están contenidas en el namespace:

```cpp
namespace ZayasMath
```

## Componentes

- Vectores: Vector2, Vector3, Vector4
- Matrices: Matrix2x2, Matrix3x3, Matrix4x4
- Rotaciones: Quaternion
- Módulo matemático: EngineMath
- Utilidades matemáticas fundamentales: ZayasMathMath

## Características

- Implementación 100% en headers.
- Ya no usa `<cmath>`, sino una librería matemática propia.
- Comentarios tipo Doxygen en todas las clases y funciones.
- Código organizado, modular y fácil de mantener.

## Compilación

Compatible con cualquier compilador moderno de C++:

```bash
g++ -std=c++17 main.cpp -o EngineTest
```

## Autor

Desarrollado por César Zayas como parte de un proyecto parcial de librería matemática para gráficos 2D.

