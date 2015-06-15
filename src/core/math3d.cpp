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
    
    return glm::length(glm::vec2(x, y));

}

float Vector2::dot(Vector2 other) const
{

    return glm::dot(glm::vec2(x, y), glm::vec2(other.getX(), other.getY()));

}

void Vector2::normalize()
{

    glm::vec2 vector = glm::normalize(glm::vec2(x, y));
    
    x = vector.x;
    y = vector.y;

}

Vector2 Vector2::normalized() const
{

    Vector2 vector(x, y);
    vector.normalize();
    
    return vector;

}

void Vector2::rotate(float angle)
{
    
    glm::vec2 vector = glm::rotate(glm::vec2(x, y), glm::radians(angle));
    
    x = vector.x;
    y = vector.y;
    
}

void Vector2::rotate(Quaternion rotation)
{
    
    glm::vec4 vector = glm::rotate(glm::quat(rotation.getValues().getW(), rotation.getValues().getX(), rotation.getValues().getY(), rotation.getValues().getZ()), glm::vec4(x, y, 0.0f, 0.0f));
    
    x = vector.x;
    y = vector.y;
    
}

Vector2 Vector2::operator+(Vector2 other) const
{

    glm::vec2 vector = glm::vec2(x, y) + glm::vec2(other.getX(), other.getY());
    
    return Vector2(vector.x, vector.y);

}

Vector2 Vector2::operator-(Vector2 other) const
{

    glm::vec2 vector = glm::vec2(x, y) - glm::vec2(other.getX(), other.getY());
    
    return Vector2(vector.x, vector.y);

}

Vector2 Vector2::operator*(Vector2 other) const
{

    glm::vec2 vector = glm::vec2(x, y) * glm::vec2(other.getX(), other.getY());
    
    return Vector2(vector.x, vector.y);

}

Vector2 Vector2::operator/(Vector2 other) const
{

    glm::vec2 vector = glm::vec2(x, y) / glm::vec2(other.getX(), other.getY());
    
    return Vector2(vector.x, vector.y);

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

    return glm::length(glm::vec3(x, y, z));

}

float Vector3::dot(Vector3 other) const
{

    return glm::dot(glm::vec3(x, y, z), glm::vec3(other.getX(), other.getY(), other.getZ()));

}

Vector3 Vector3::cross(Vector3 other) const
{

    glm::vec3 vector = glm::cross(glm::vec3(x, y, z), glm::vec3(other.getX(), other.getY(), other.getZ()));
    
    return Vector3(vector.x, vector.y, vector.z);

}

void Vector3::normalize()
{

    glm::vec3 vector = glm::normalize(glm::vec3(x, y, z));
    
    x = vector.x;
    y = vector.y;
    z = vector.z;

}

Vector3 Vector3::normalized() const
{

    Vector3 vector(x, y, z);
    vector.normalize();
    
    return vector;

}

void Vector3::rotate(float pitch, float yaw, float roll)
{
    
    glm::vec3 vector(x, y, z);
    
    vector = glm::rotateX(vector, glm::radians(pitch));
    vector = glm::rotateY(vector, glm::radians(yaw));
    vector = glm::rotateZ(vector, glm::radians(roll));
    
    x = vector.x;
    y = vector.y;
    z = vector.z;
    
}

void Vector3::rotate(Vector3 axis, float angle)
{
    
    glm::vec3 vector = glm::rotate(glm::vec3(x, y, z), glm::radians(angle), glm::vec3(axis.getX(), axis.getY(), axis.getZ()));
    
    x = vector.x;
    y = vector.y;
    z = vector.z;
    
}

void Vector3::rotate(Quaternion rotation)
{
    
    glm::vec4 vector = glm::rotate(glm::quat(rotation.getValues().getW(), rotation.getValues().getX(), rotation.getValues().getY(), rotation.getValues().getZ()), glm::vec4(x, y, z, 0.0f));
    
    x = vector.x;
    y = vector.y;
    z = vector.z;
    
}

Vector3 Vector3::operator+(Vector3 other) const
{

    glm::vec3 vector = glm::vec3(x, y, z) + glm::vec3(other.getX(), other.getY(), other.getZ());
    
    return Vector3(vector.x, vector.y, vector.z);

}

Vector3 Vector3::operator-(Vector3 other) const
{

    glm::vec3 vector = glm::vec3(x, y, z) - glm::vec3(other.getX(), other.getY(), other.getZ());
    
    return Vector3(vector.x, vector.y, vector.z);

}

Vector3 Vector3::operator*(Vector3 other) const
{

    glm::vec3 vector = glm::vec3(x, y, z) * glm::vec3(other.getX(), other.getY(), other.getZ());
    
    return Vector3(vector.x, vector.y, vector.z);

}

Vector3 Vector3::operator/(Vector3 other) const
{

    glm::vec3 vector = glm::vec3(x, y, z) / glm::vec3(other.getX(), other.getY(), other.getZ());
    
    return Vector3(vector.x, vector.y, vector.z);

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

    return glm::length(glm::vec4(x, y, z, w));

}

float Vector4::dot(Vector4 other) const
{

    return glm::dot(glm::vec4(x, y, z, w), glm::vec4(other.getX(), other.getY(), other.getZ(), other.getW()));

}

void Vector4::normalize()
{

    glm::vec4 vector = glm::normalize(glm::vec4(x, y, z, w));
    
    x = vector.x;
    y = vector.y;
    z = vector.z;
    w = vector.w;

}

Vector4 Vector4::normalized() const
{

    Vector4 vector(x, y, z, w);
    vector.normalize();
    
    return vector;

}

Vector4 Vector4::operator+(Vector4 other) const
{

    glm::vec4 vector = glm::vec4(x, y, z, w) + glm::vec4(other.getX(), other.getY(), other.getZ(), other.getW());
    
    return Vector4(vector.x, vector.y, vector.z, vector.w);

}

Vector4 Vector4::operator-(Vector4 other) const
{

    glm::vec4 vector = glm::vec4(x, y, z, w) - glm::vec4(other.getX(), other.getY(), other.getZ(), other.getW());
    
    return Vector4(vector.x, vector.y, vector.z, vector.w);

}

Vector4 Vector4::operator*(Vector4 other) const
{

    glm::vec4 vector = glm::vec4(x, y, z, w) * glm::vec4(other.getX(), other.getY(), other.getZ(), other.getW());
    
    return Vector4(vector.x, vector.y, vector.z, vector.w);

}

Vector4 Vector4::operator/(Vector4 other) const
{

    glm::vec4 vector = glm::vec4(x, y, z, w) / glm::vec4(other.getX(), other.getY(), other.getZ(), other.getW());
    
    return Vector4(vector.x, vector.y, vector.z, vector.w);

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

    glm::mat3 matrix;
    
    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

Matrix3 Matrix3::operator*(Matrix3 other) const
{
    
    glm::mat3 matrix1;
    glm::mat3 matrix2;
    
    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {

            matrix1[i][j] = values[i][j];
            matrix2[i][j] = other.getValue(i, j);

        }

    }
    
    glm::mat3 matrix = matrix1 * matrix2;

    Matrix3 result;

    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {

            result.setValue(i, j, matrix[i][j]);

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

    glm::mat4 matrix(1.0f);
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

void Matrix4::createTranslation(Vector3 translation)
{

    glm::mat4 matrix = glm::translate(glm::mat4(1.0f), glm::vec3(translation.getX(), translation.getY(), translation.getZ()));
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

void Matrix4::createRotation(Vector3 axis, float angle)
{

    glm::mat4 matrix = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(axis.getX(), axis.getY(), axis.getZ()));
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

void Matrix4::createScale(Vector3 scale)
{

    glm::mat4 matrix = glm::scale(glm::mat4(1.0f), glm::vec3(scale.getX(), scale.getY(), scale.getZ()));
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

void Matrix4::createLookAt(Vector3 position, Vector3 target, Vector3 up)
{
    
    glm::mat4 matrix = glm::lookAt(glm::vec3(position.getX(), position.getY(), position.getZ()), glm::vec3(target.getX(), target.getY(), target.getZ()), glm::vec3(up.getX(), up.getY(), up.getZ()));
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }
    
}

void Matrix4::createOrthographic(float left, float right, float bottom, float top, float zNear, float zFar)
{

    glm::mat4 matrix = glm::ortho(left, right, bottom, top, zNear, zFar);
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

void Matrix4::createPerspective(float fov, float aspect, float zNear, float zFar)
{

    glm::mat4 matrix = glm::perspective(fov, aspect, zNear, zFar);
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            values[i][j] = matrix[i][j];

        }

    }

}

Matrix4 Matrix4::operator*(Matrix4 other) const
{

    glm::mat4 matrix1;
    glm::mat4 matrix2;
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            matrix1[i][j] = values[i][j];
            matrix2[i][j] = other.getValue(i, j);

        }

    }
    
    glm::mat4 matrix = matrix1 * matrix2;

    Matrix4 result;

    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            result.setValue(i, j, matrix[i][j]);

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

    glm::quat quaternion = glm::conjugate(glm::quat(w, x, y, z));
    
    return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);

}

void Quaternion::normalize()
{

    glm::quat quaternion = glm::normalize(glm::quat(w, x, y, z));
    
    x = quaternion.x;
    y = quaternion.y;
    z = quaternion.z;
    w = quaternion.w;

}

Quaternion Quaternion::normalized() const
{

    Quaternion quaternion(x, y, z, w);
    quaternion.normalize();
    
    return quaternion;

}

void Quaternion::rotate(Vector3 axis, float angle)
{
    
    glm::quat quaternion = glm::rotate(glm::quat(w, x, y, z), glm::radians(angle), glm::vec3(axis.getX(), axis.getY(), axis.getZ()));
    
    x = quaternion.x;
    y = quaternion.y;
    z = quaternion.z;
    w = quaternion.w;
    
    normalize();

}

Vector3 Quaternion::getLeft() const
{
    
    return Vector3(-1.0f * (1.0f - 2.0f * (y * y + z * z)), -1.0f * (2.0f * (x * y - w * z)), -1.0f * (2.0f * (x * z + w * y))).normalized();

}

Vector3 Quaternion::getRight() const
{

    return Vector3(1.0f - 2.0f * (y * y + z * z), 2.0f * (x * y - w * z), 2.0f * (x * z + w * y)).normalized();

}

Vector3 Quaternion::getDown() const
{

    return Vector3(-1.0f * (2.0f * (x * y + w * z)), -1.0f * (1.0f - 2.0f * (x * x + z * z)), -1.0f * (2.0f * (y * z - w * x))).normalized();

}

Vector3 Quaternion::getUp() const
{

    return Vector3(2.0f * (x * y + w * z), 1.0f - 2.0f * (x * x + z * z), 2.0f * (y * z - w * x)).normalized();

}

Vector3 Quaternion::getForward() const
{

    return Vector3(-1.0f * (2.0f * (x * z - w * y)), -1.0f * (2.0f * (y * z + w * x)), -1.0f * (1.0f - 2.0f * (x * x + y * y))).normalized();

}

Vector3 Quaternion::getBack() const
{

    return Vector3(2.0f * (x * z - w * y), 2.0f * (y * z + w * x), 1.0f - 2.0f * (x * x + y * y)).normalized();

}

Matrix4 Quaternion::toRotationMatrix() const
{

    glm::mat4 matrix = glm::mat4_cast(glm::quat(w, x, y, z));
    
    Matrix4 result;
    
    for(int i = 0; i < 4; i++)
    {

        for(int j = 0; j < 4; j++)
        {

            result.setValue(i, j, matrix[i][j]);

        }

    }

    return result;

}

Quaternion Quaternion::operator*(Vector3 other) const
{
    
    glm::quat quaternion1(w, x, y, z);
    glm::quat quaternion2(0.0f, other.getX(), other.getY(), other.getZ());
    
    glm::quat quaternion = quaternion1 * quaternion2;

    return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);

}

Quaternion Quaternion::operator*(Quaternion other) const
{

    glm::quat quaternion1(w, x, y, z);
    glm::quat quaternion2(other.getValues().getW(), other.getValues().getX(), other.getValues().getY(), other.getValues().getZ());
    
    glm::quat quaternion = quaternion1 * quaternion2;

    return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);

}

Vector4 Quaternion::getValues() const
{

    return Vector4(x, y, z, w);

}

void Quaternion::clear()
{
    
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 1.0f;
    
}
