
#include "vecmath/vector3.hpp"

using namespace vecmath;

vector3::vector3()
    : vector3(0, 0, 0)
{ }

vector3::vector3(float x, float y, float z)
    : x(x)
    , y(y)
    , z(z)
{ }

vector3 vector3::operator+(const vecmath::vector3& other) const
{
    return {x + other.x, y + other.y, z + other.z};
}

vector3 vector3::operator-(const vector3& other) const
{
    return {x - other.x, y - other.y, z - other.z};
}

vector3 vector3::operator/(const vector3& other) const
{
    return {x / other.x, y / other.y, z / other.z};
}

vector3 vector3::operator*(const vector3& other) const
{
    return {x * other.x, y * other.y, z * other.z};
}

vector3 vector3::apply_matrix4(const matrix4& m)
{

    const auto x_ = this->x, y_ = this->y, z_ = this->z;
    const auto& e = m.elements;

    const auto w = 1.0f / (e[3] * x + e[7] * y + e[11] * z + e[15]);

    this->x = (e[0] * x_ + e[4] * y_ + e[8] * z_ + e[12]) * w;
    this->y = (e[1] * x_ + e[5] * y_ + e[9] * z_ + e[13]) * w;
    this->z = (e[2] * x_ + e[6] * y_ + e[10] * z_ + e[14]) * w;

    return *this;
}
