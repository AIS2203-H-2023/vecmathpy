
#ifndef PYTHON_CPP_WRAPPER_MATRIX4_HPP
#define PYTHON_CPP_WRAPPER_MATRIX4_HPP

#include <array>


namespace vecmath {

    class vector3; //forward reference

    class matrix4 {
    public:
        std::array<float, 16> elements{
                1.f, 0.f, 0.f, 0.f,
                0.f, 1.f, 0.f, 0.f,
                0.f, 0.f, 1.f, 0.f,
                0.f, 0.f, 0.f, 1.f};


        matrix4() = default;

        float &operator[](unsigned int index);

        matrix4 &set(float n11, float n12, float n13, float n14, float n21, float n22, float n23, float n24, float n31,
                     float n32, float n33, float n34, float n41, float n42, float n43, float n44);

        matrix4 &identity();

        matrix4& copy(const matrix4& m);

        matrix4 &set_position(const vector3 &v);

        matrix4 &set_position(float x, float y, float z);

        matrix4 &multiply(const matrix4 &m);

        matrix4 &multiply_matrices(const matrix4 &a, const matrix4 &b);

        matrix4 &make_translation(float x, float y, float z);

        matrix4 &make_rotation_x(float theta);

        matrix4 &make_rotation_y(float theta);

        matrix4 &make_rotation_z(float theta);

    };

}

#endif //PYTHON_CPP_WRAPPER_MATRIX4_HPP
