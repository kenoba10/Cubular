#include "math3d.h"

Vector2::Vector2(float x, float y)
{

    this->x = x;
    this->y = y;

}

Vector2::~Vector2()
{

}

float Vector2::length() const
{

    return sqrt(x * x + y * y);

}

float Vector2::dot(Vector2 other) const
{

    return x * other.getX() + y * other.getY();

}

float Vector2::cross(Vector2 other) const
{

    return x * y - y * x;

}

void Vector2::normalize()
{

    float size = length();

    x /= size;
    y /= size;

}

Vector2 Vector2::normalized() const
{

    float size = length();

    return Vector2(x / size, y / size);

}

Vector2 Vector2::operator+(Vector2 other) const
{

    return Vector2(x + other.getX(), y + other.getY());

}

Vector2 Vector2::operator-(Vector2 other) const
{

    return Vector2(x - other.getX(), y - other.getY());

}

Vector2 Vector2::operator*(Vector2 other) const
{

    return Vector2(x * other.getX(), y * other.getY());

}

Vector2 Vector2::operator/(Vector2 other) const
{

    return Vector2(x / other.getX(), y / other.getY());

}

float Vector2::getX() const
{

    return x;

}

float Vector2::getY() const
{

    return y;

}

void Vector2::setX(float x)
{

    this->x = x;

}

void Vector2::setY(float y)
{

    this->y = y;

}

Vector3::Vector3(float x, float y, float z)
{

    this->x = x;
    this->y = y;
    this->z = z;

}

Vector3::~Vector3()
{

}

float Vector3::length() const
{

    return sqrt(x * x + y * y + z * z);

}

float Vector3::dot(Vector3 other) const
{

    return x * other.getX() + y * other.getY() + z * other.getZ();

}

Vector3 Vector3::cross(Vector3 other) const
{

    return Vector3(y * other.getZ() - z * other.getY(), z * other.getX() - x * other.getZ(), x * other.getY() - y * other.getX());

}

void Vector3::normalize()
{

    float size = length();

    x /= size;
    y /= size;
    z /= size;

}

Vector3 Vector3::normalized() const
{

    float size = length();

    return Vector3(x / size, y / size, z / size);

}

Vector3 Vector3::operator+(Vector3 other) const
{

    return Vector3(x + other.getX(), y + other.getY(), z + other.getZ());

}

Vector3 Vector3::operator-(Vector3 other) const
{

    return Vector3(x - other.getX(), y - other.getY(), z - other.getZ());

}

Vector3 Vector3::operator*(Vector3 other) const
{

    return Vector3(x * other.getX(), y * other.getY(), z * other.getZ());

}

Vector3 Vector3::operator/(Vector3 other) const
{

    return Vector3(x / other.getX(), y / other.getY(), z / other.getZ());

}

float Vector3::getX() const
{

    return x;

}

float Vector3::getY() const
{

    return y;

}

float Vector3::getZ() const
{

    return z;

}

void Vector3::setX(float x)
{

    this->x = x;

}

void Vector3::setY(float y)
{

    this->y = y;

}

void Vector3::setZ(float z)
{

    this->z = z;

}

Vector4::Vector4(float x, float y, float z, float w)
{

    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;

}

Vector4::~Vector4()
{

}

float Vector4::length() const
{

    return sqrt(x * x + y * y + z * z + w * w);

}

float Vector4::dot(Vector4 other) const
{

    return x * other.getX() + y * other.getY() + z * other.getZ() + w * other.getW();

}

void Vector4::normalize()
{

    float size = length();

    x /= size;
    y /= size;
    z /= size;
    w /= size;

}

Vector4 Vector4::normalized() const
{

    float size = length();

    return Vector4(x / size, y / size, z / size, w / size);

}

Vector4 Vector4::operator+(Vector4 other) const
{

    return Vector4(x + other.getX(), y + other.getY(), z + other.getZ(), w + other.getW());

}

Vector4 Vector4::operator-(Vector4 other) const
{

    return Vector4(x - other.getX(), y - other.getY(), z - other.getZ(), w - other.getW());

}

Vector4 Vector4::operator*(Vector4 other) const
{

    return Vector4(x * other.getX(), y * other.getY(), z * other.getZ(), w * other.getW());

}

Vector4 Vector4::operator/(Vector4 other) const
{

    return Vector4(x / other.getX(), y / other.getY(), z / other.getZ(), w / other.getW());

}

float Vector4::getX() const
{

    return x;

}

float Vector4::getY() const
{

    return y;

}

float Vector4::getZ() const
{

    return z;

}

float Vector4::getW() const
{

    return w;

}

void Vector4::setX(float x)
{

    this->x = x;

}

void Vector4::setY(float y)
{

    this->y = y;

}

void Vector4::setZ(float z)
{

    this->z = z;

}

void Vector4::setW(float w)
{

    this->w = w;

}

Matrix3::Matrix3()
{

}

Matrix3::~Matrix3()
{

}

void Matrix3::createIdentity()
{

    values[0][0] = 1;
    values[0][1] = 0;
    values[0][2] = 0;

    values[1][0] = 0;
    values[1][1] = 1;
    values[1][2] = 0;

    values[2][0] = 0;
    values[2][1] = 0;
    values[2][2] = 1;

}

Matrix3 Matrix3::operator*(Matrix3 other) const
{

    Matrix3 result;

    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {

            result.setValue(i, j, values[i][0] * other.getValue(0, j) + values[i][1] * other.getValue(1, j) + values[i][2] * other.getValue(2, j));

        }

    }

    return result;

}

float* Matrix3::getValues() const
{

    static float vals[3 * 3];

    vals[0] = values[0][0];
    vals[1] = values[0][1];
    vals[2] = values[0][2];

    vals[3] = values[1][0];
    vals[4] = values[1][1];
    vals[5] = values[1][2];

    vals[6] = values[2][0];
    vals[7] = values[2][1];
    vals[8] = values[2][2];

    return vals;

}

float Matrix3::getValue(unsigned int x, unsigned int y) const
{

    return values[x][y];

}

void Matrix3::setValue(unsigned int x, unsigned int y, float value)
{

    values[x][y] = value;

}

Matrix4::Matrix4()
{

}

Matrix4::~Matrix4()
{

}

void Matrix4::createIdentity()
{

    values[0][0] = 1;
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = 0;

    values[1][0] = 0;
    values[1][1] = 1;
    values[1][2] = 0;
    values[1][3] = 0;

    values[2][0] = 0;
    values[2][1] = 0;
    values[2][2] = 1;
    values[2][3] = 0;

    values[3][0] = 0;
    values[3][1] = 0;
    values[3][2] = 0;
    values[3][3] = 1;

}

void Matrix4::createTranslation(Vector3 translation)
{

    values[0][0] = 1;
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = 0;

    values[1][0] = 0;
    values[1][1] = 1;
    values[1][2] = 0;
    values[1][3] = 0;

    values[2][0] = 0;
    values[2][1] = 0;
    values[2][2] = 1;
    values[2][3] = 0;

    values[3][0] = translation.getX();
    values[3][1] = translation.getY();
    values[3][2] = translation.getZ();
    values[3][3] = 1;

}

void Matrix4::createRotation(Quaternion rotation)
{

    Vector3 right(1.0f - 2.0f * (rotation.getValues().getY() * rotation.getValues().getY() + rotation.getValues().getZ() * rotation.getValues().getZ()), 2.0f * (rotation.getValues().getX() * rotation.getValues().getY() - rotation.getValues().getW() * rotation.getValues().getZ()), 2.0f * (rotation.getValues().getX() * rotation.getValues().getZ() + rotation.getValues().getW() * rotation.getValues().getY()));
    Vector3 up(2.0f * (rotation.getValues().getX() * rotation.getValues().getY() + rotation.getValues().getW() * rotation.getValues().getZ()), 1.0f - 2.0f * (rotation.getValues().getX() * rotation.getValues().getX() + rotation.getValues().getZ() * rotation.getValues().getZ()), 2.0f * (rotation.getValues().getY() * rotation.getValues().getZ() - rotation.getValues().getW() * rotation.getValues().getX()));
    Vector3 forward(2.0f * (rotation.getValues().getX() * rotation.getValues().getZ() - rotation.getValues().getW() * rotation.getValues().getY()), 2.0f * (rotation.getValues().getY() * rotation.getValues().getZ() + rotation.getValues().getW() * rotation.getValues().getX()), 1.0f - 2.0f * (rotation.getValues().getX() * rotation.getValues().getX() + rotation.getValues().getY() * rotation.getValues().getY()));

    values[0][0] = right.getX();
    values[0][1] = up.getX();
    values[0][2] = forward.getX();
    values[0][3] = 0;

    values[1][0] = right.getY();
    values[1][1] = up.getY();
    values[1][2] = forward.getY();
    values[1][3] = 0;

    values[2][0] = right.getZ();
    values[2][1] = up.getZ();
    values[2][2] = forward.getZ();
    values[2][3] = 0;

    values[3][0] = 0;
    values[3][1] = 0;
    values[3][2] = 0;
    values[3][3] = 1;

}

void Matrix4::createScale(Vector3 scale)
{

    values[0][0] = scale.getX();
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = 0;

    values[1][0] = 0;
    values[1][1] = scale.getY();
    values[1][2] = 0;
    values[1][3] = 0;

    values[2][0] = 0;
    values[2][1] = 0;
    values[2][2] = scale.getZ();
    values[2][3] = 0;

    values[3][0] = 0;
    values[3][1] = 0;
    values[3][2] = 0;
    values[3][3] = 1;

}

void Matrix4::createOrthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{

    float width = right - left;
    float height = top - bottom;
    float depth = zFar - zNear;

    values[0][0] = 2.0f / width;
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = -(right + left) / width;

    values[1][0] = 0;
    values[1][1] = 2.0f / height;
    values[1][2] = 0;
    values[1][3] = -(top + bottom) / height;

    values[2][0] = 0;
    values[2][1] = 0;
    values[2][2] = -2.0f / depth;
    values[2][3] = -(zFar + zNear) / depth;

    values[3][0] = 0;
    values[3][1] = 0;
    values[3][2] = 0;
    values[3][3] = 1;

}

void Matrix4::createPerspective(float fov, float aspect, float zNear, float zFar)
{

    float bottom = -(zNear * tan(0.5f * fov));
    float top = -bottom;
    float left = bottom * aspect;
    float right = top * aspect;

    values[0][0] = (2.0f * zNear) / (right - left);
    values[0][1] = 0;
    values[0][2] = 0;
    values[0][3] = 0;

    values[1][0] = 0;
    values[1][1] = (2.0f * zNear) / (top - bottom);
    values[1][2] = 0;
    values[1][3] = 0;

    values[2][0] = (right + left) / (right - left);
    values[2][1] = (top + bottom) / (top - bottom);
    values[2][2] = -(zFar + zNear) / (zFar - zNear);
    values[2][3] = -1;

    values[3][0] = 0;
    values[3][1] = 0;
    values[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
    values[3][3] = 0;

}

Matrix4 Matrix4::operator*(Matrix4 other) const
{

    Matrix4 result;

    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            result.setValue(i, j, values[i][0] * other.getValue(0, j) + values[i][1] * other.getValue(1, j) + values[i][2] * other.getValue(2, j) + values[i][3] * other.getValue(3, j));

        }

    }

    return result;

}

float* Matrix4::getValues() const
{

    static float vals[4 * 4];

    vals[0] = values[0][0];
    vals[1] = values[0][1];
    vals[2] = values[0][2];
    vals[2] = values[0][3];

    vals[4] = values[1][0];
    vals[5] = values[1][1];
    vals[6] = values[1][2];
    vals[7] = values[1][3];

    vals[8] = values[2][0];
    vals[9] = values[2][1];
    vals[10] = values[2][2];
    vals[11] = values[2][3];

    vals[12] = values[3][0];
    vals[13] = values[3][1];
    vals[14] = values[3][2];
    vals[15] = values[3][3];

    return vals;

}

float Matrix4::getValue(unsigned int x, unsigned int y) const
{

    return values[x][y];

}

void Matrix4::setValue(unsigned int x, unsigned int y, float value)
{

    values[x][y] = value;

}

Quaternion::Quaternion(float x, float y, float z, float w)
{

    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;

}

Quaternion::~Quaternion()
{

}

Quaternion Quaternion::conjugate() const
{

    return Quaternion(-x, -y, -z, w);

}

void Quaternion::normalize()
{

    float size = getValues().length();

    x /= size;
    y /= size;
    z /= size;
    w /= size;

}

Quaternion Quaternion::normalized() const
{

    float size = getValues().length();

    return Quaternion(x / size, y / size, z / size, w / size);

}

void Quaternion::rotate(Vector3 axis, float angle)
{

    float sinHalfAngle = sin(angle / 2);
    float cosHalfAngle = cos(angle / 2);

    Quaternion rotated = (*this) * Quaternion(axis.getX() * sinHalfAngle, axis.getY() * sinHalfAngle, axis.getZ() * sinHalfAngle, cosHalfAngle);

    *this = *this * rotated;

}

Vector3 Quaternion::getLeft() const
{

    Quaternion left = (*this) * this->conjugate() * Vector3(-1.0f, 0.0f, 0.0f);

    return Vector3(left.getValues().getX(), left.getValues().getY(), left.getValues().getZ()).normalized();

}

Vector3 Quaternion::getRight() const
{

    Quaternion right = (*this) * this->conjugate() * Vector3(1.0f, 0.0f, 0.0f);

    return Vector3(right.getValues().getX(), right.getValues().getY(), right.getValues().getZ()).normalized();

}

Vector3 Quaternion::getDown() const
{

    Quaternion down = (*this) * this->conjugate() * Vector3(0.0f, -1.0f, 0.0f);

    return Vector3(down.getValues().getX(), down.getValues().getY(), down.getValues().getZ()).normalized();

}

Vector3 Quaternion::getUp() const
{

    Quaternion up = (*this) * this->conjugate() * Vector3(0.0f, 1.0f, 0.0f);

    return Vector3(up.getValues().getX(), up.getValues().getY(), up.getValues().getZ()).normalized();

}

Vector3 Quaternion::getForward() const
{

    Quaternion forward = (*this) * this->conjugate() * Vector3(0.0f, 0.0f, -1.0f);

    return Vector3(forward.getValues().getX(), forward.getValues().getY(), forward.getValues().getZ()).normalized();

}

Vector3 Quaternion::getBack() const
{

    Quaternion back = (*this) * this->conjugate() * Vector3(0.0f, 0.0f, 1.0f);

    return Vector3(back.getValues().getX(), back.getValues().getY(), back.getValues().getZ()).normalized();

}

Matrix4 Quaternion::toRotationMatrix() const
{

    Matrix4 result;

    result.createRotation(*this);

    return result;

}

Quaternion Quaternion::operator*(Vector3 other) const
{

    float x_ = w * other.getX() + y * other.getZ() - z * other.getY();
    float y_ = w * other.getY() + z * other.getX() - x * other.getZ();
    float z_ = w * other.getZ() + x * other.getY() - y * other.getX();
    float w_ = -x * other.getX() - y * other.getY() - z * other.getZ();

    return Quaternion(x_, y_, z_, w_);

}

Quaternion Quaternion::operator*(Quaternion other) const
{

    Vector4 r = other.getValues();

    float x_ = x * r.getW() + w * r.getX() + y * r.getZ() - z * r.getY();
    float y_ = y * r.getW() + w * r.getY() + z * r.getX() - x * r.getZ();
    float z_ = z * r.getW() + w * r.getZ() + x * r.getY() - y * r.getX();
    float w_ = w * r.getW() - x * r.getX() - y * r.getY() - z * r.getZ();

    return Quaternion(x_, y_, z_, w_);

}

Vector4 Quaternion::getValues() const
{

    return Vector4(x, y, z, w);

}
