#include <iostream>
#include "Vectors/Vector2.h"
#include "Vectors/Vector3.h"
#include "Vectors/Vector4.h"
#include "Rotations/Quaternion.h"
#include "../Matrix/Matrix2x2.h"               //#include "../Vectors/Vector3.h"
#include "../Matrix/Matrix3x3.h"
#include "../Matrix/Matrix4x4.h"
#include "ZayasMathMath.h"

using namespace ZayasMath;

int main() {
  std::cout << "==== ZAYAS MATH ENGINE TESTS ====\n\n";

  // Vector2
  CVector2 v2a(3, 4);
  CVector2 v2b(1, 2);
  CVector2 v2sum = v2a + v2b;
  std::cout << "Vector2 Sum: (" << v2sum.x << ", " << v2sum.y << ")\n";

  // Vector3
  CVector3 v3a(1, 0, 0);
  CVector3 v3b(0, 1, 0);
  CVector3 v3cross = v3a.cross(v3b);
  std::cout << "Vector3 Cross: (" << v3cross.x << ", " << v3cross.y << ", " << v3cross.z << ")\n";

  // Vector4
  CVector4 v4a(1, 2, 3, 1);
  CVector4 v4b(4, 5, 6, 1);
  CVector4 v4sum = v4a + v4b;
  std::cout << "Vector4 Sum: (" << v4sum.x << ", " << v4sum.y << ", " << v4sum.z << ", " << v4sum.w << ")\n";

  // Matrix2x2
  Matrix2x2 m2a(1, 2, 3, 4);
  Matrix2x2 m2b(2, 0, 1, 2);
  Matrix2x2 m2c = m2a * m2b;
  std::cout << "Matrix2x2 Product:\n";
  std::cout << m2c(0, 0) << " " << m2c(0, 1) << "\n";
  std::cout << m2c(1, 0) << " " << m2c(1, 1) << "\n";

  // Matrix3x3
  Matrix3x3 m3 = Matrix3x3::identity();
  Matrix3x3 m3scaled = m3 * 3.0f;
  std::cout << "Matrix3x3 Scaled by 3:\n";
  for (int i = 0; i < 3; ++i)
    std::cout << m3scaled(i, 0) << " " << m3scaled(i, 1) << " " << m3scaled(i, 2) << "\n";

  // Matrix4x4
  Matrix4x4 m4;
  m4.setScale(2.0f, 2.0f, 2.0f);
  CVector3 point(1, 1, 1);
  CVector3 transformed = m4.transformPoint(point);
  std::cout << "Matrix4x4 Scale Transform: (" << transformed.x << ", " << transformed.y << ", " << transformed.z << ")\n";

  // Quaternion
  Quaternion q = Quaternion::fromAxisAngle(CVector3(0, 1, 0), radians(90.0f));
  CVector3 rotated = q.rotate(CVector3(1, 0, 0));
  std::cout << "Quaternion Rotation: (" << rotated.x << ", " << rotated.y << ", " << rotated.z << ")\n";

  // EngineMath
  std::cout << "Circle area (r=5): " << circleArea(5.0f) << "\n";
  std::cout << "Triangle area (base=4, height=3): " << triangleArea(4.0f, 3.0f) << "\n";

  std::cout << "\n==== ALL TESTS COMPLETED ====\n";
  return 0;
}
