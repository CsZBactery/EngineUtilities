#pragma once

#include "../Vectors/Vector3.h"
#include "../ZayasMathMath.h"

namespace ZayasMath {

  /**
   * @brief Representa una rotación en el espacio tridimensional mediante un cuaternión.
   */
  struct Quaternion {
    float x, y, z, w;

    /**
     * @brief Constructor por defecto. Cuaternión identidad.
     */
    Quaternion() : x(0), y(0), z(0), w(1) {}

    /**
     * @brief Constructor con componentes.
     * @param xVal Componente x
     * @param yVal Componente y
     * @param zVal Componente z
     * @param wVal Componente w
     */
    Quaternion(float xVal, float yVal, float zVal, float wVal)
      : x(xVal), y(yVal), z(zVal), w(wVal) {
    }

    /**
     * @brief Crea un cuaternión a partir de un eje y un ángulo en radianes.
     * @param axis Eje unitario de rotación.
     * @param angle Ángulo en radianes.
     * @return Cuaternión correspondiente.
     */
    static Quaternion fromAxisAngle(const CVector3& axis, float angle) {
      float halfAngle = angle * 0.5f;
      float s = sin(halfAngle);
      return Quaternion(
        axis.x * s,
        axis.y * s,
        axis.z * s,
        cos(halfAngle)
      );
    }

    /**
     * @brief Normaliza el cuaternión a unidad.
     * @return Cuaternión normalizado.
     */
    Quaternion normalized() const {
      float mag = sqrt(x * x + y * y + z * z + w * w);
      return (mag != 0) ? Quaternion(x / mag, y / mag, z / mag, w / mag) : Quaternion();
    }

    /**
     * @brief Inverso del cuaternión (asumiendo unidad).
     * @return Cuaternión inverso.
     */
    Quaternion inverse() const {
      return Quaternion(-x, -y, -z, w);  // solo para quaterniones unitarios
    }

    /**
     * @brief Multiplica este cuaternión por otro (rotación compuesta).
     * @param q Otro cuaternión.
     * @return Resultado de la multiplicación.
     */
    Quaternion operator*(const Quaternion& q) const {
      return Quaternion(
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y - x * q.z + y * q.w + z * q.x,
        w * q.z + x * q.y - y * q.x + z * q.w,
        w * q.w - x * q.x - y * q.y - z * q.z
      );
    }

    /**
     * @brief Rota un vector usando este cuaternión.
     * @param v Vector a rotar.
     * @return Vector rotado.
     */
    CVector3 rotate(const CVector3& v) const {
      Quaternion qv(v.x, v.y, v.z, 0);
      Quaternion result = (*this) * qv * this->inverse();
      return CVector3(result.x, result.y, result.z);
    }

    /**
     * @brief Interpolación lineal entre dos cuaterniones.
     * @param a Primer cuaternión.
     * @param b Segundo cuaternión.
     * @param t Factor de interpolación [0, 1].
     * @return Cuaternión interpolado.
     */
    static Quaternion lerp(const Quaternion& a, const Quaternion& b, float t) {
      return Quaternion(
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t,
        a.w + (b.w - a.w) * t
      ).normalized();
    }
  };

} // namespace ZayasMath
