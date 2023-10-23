
#include "vecmath/vecmath.h"

#include "vecmath/matrix4.hpp"
#include "vecmath/vector3.hpp"

#include <memory>


namespace
{

vector3 ctype(const vecmath::vector3& v)
{
    return {v.x, v.y, v.z};
}

vecmath::vector3 cpptype(const vector3& v)
{
    return {v.x, v.y, v.z};
}
} // namespace

struct vecmath_matrix4
{
    std::unique_ptr<vecmath::matrix4> cpp_matrix;
};


vector3 vector3_add(vector3 v1, vector3 v2)
{
    return ctype(cpptype(v1) + cpptype(v2));
}

vector3 vector3_sub(vector3 v1, vector3 v2)
{
    return ctype(cpptype(v1) - cpptype(v2));
}

vector3 vector3_div(vector3 v1, vector3 v2)
{
    return ctype(cpptype(v1) / cpptype(v2));
}

vector3 vector3_mul(vector3 v1, vector3 v2)
{
    return ctype(cpptype(v1) * cpptype(v2));
}

vector3 vector3_apply_matrix4(vector3 v, vecmath_matrix4_t* m)
{
    return ctype(cpptype(v).apply_matrix4(*m->cpp_matrix));
}

vecmath_matrix4_t* matrix4_create()
{
    auto m = std::make_unique<vecmath_matrix4_t>();
    m->cpp_matrix = std::make_unique<vecmath::matrix4>();
    return m.release();
}

void matrix4_identity(vecmath_matrix4_t* m)
{
    m->cpp_matrix->identity();
}

void matrix4_copy(vecmath_matrix4_t* src, vecmath_matrix4_t* dst)
{
    dst->cpp_matrix->copy(*src->cpp_matrix);
}

void matrix4_set_position(vecmath_matrix4_t* m, float x, float y, float z)
{
    m->cpp_matrix->set_position(x, y, z);
}

void matrix4_make_rotation_x(vecmath_matrix4_t* m, float theta)
{
    m->cpp_matrix->make_rotation_x(theta);
}

void matrix4_make_rotation_y(vecmath_matrix4_t* m, float theta)
{
    m->cpp_matrix->make_rotation_y(theta);
}

void matrix4_make_rotation_z(vecmath_matrix4_t* m, float theta)
{
    m->cpp_matrix->make_rotation_z(theta);
}

const float* matrix4_data(vecmath_matrix4_t* m)
{
    return m->cpp_matrix->elements.data();
}

void matrix4_destroy(vecmath_matrix4_t* m)
{
    delete m;
}
