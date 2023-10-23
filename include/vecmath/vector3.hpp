
#ifndef PYTHON_CPP_WRAPPER_VECTOR3_HPP
#define PYTHON_CPP_WRAPPER_VECTOR3_HPP

#include "matrix4.hpp"

namespace vecmath
{

class vector3
{

public:
    float x;
    float y;
    float z;

    vector3();

    vector3(float x, float y, float z);

    vector3 operator+(const vector3& other) const;
    vector3 operator-(const vector3& other) const;
    vector3 operator/(const vector3& other) const;
    vector3 operator*(const vector3& other) const;

    vector3 apply_matrix4(const matrix4& m);
};

} // namespace vecmath

#endif // PYTHON_CPP_WRAPPER_VECTOR3_HPP
