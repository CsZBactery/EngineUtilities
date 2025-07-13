#pragma once
namespace EngineUtilities {
struct Matrix3x3 {
    float m[3][3];
    Matrix3x3() {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                m[i][j] = (i == j) ? 1.0f : 0.0f;
    }
};
}