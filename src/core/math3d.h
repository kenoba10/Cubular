#ifndef MATH3D_H
#define MATH3D_H

struct Vector2;
struct Vector3;
struct Vector4;
struct Matrix3;
struct Matrix4;
struct Quaternion;

#include <math.h>

struct Vector2
{

    public:
        Vector2(float x, float y);
        ~Vector2();
        float length() const;
        float dot(Vector2 other) const;
        float cross(Vector2 other) const;
        void normalize();
        Vector2 normalized() const;
        Vector2 operator+(Vector2 other) const;
        Vector2 operator-(Vector2 other) const;
        Vector2 operator*(Vector2 other) const;
        Vector2 operator/(Vector2 other) const;
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);
    protected:
    private:
        float x;
        float y;

};

struct Vector3
{

    public:
        Vector3(float x, float y, float z);
        ~Vector3();
        float length() const;
        float dot(Vector3 other) const;
        Vector3 cross(Vector3 other) const;
        void normalize();
        Vector3 normalized() const;
        Vector3 operator+(Vector3 other) const;
        Vector3 operator-(Vector3 other) const;
        Vector3 operator*(Vector3 other) const;
        Vector3 operator/(Vector3 other) const;
        float getX() const;
        float getY() const;
        float getZ() const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);
    protected:
    private:
        float x;
        float y;
        float z;

};

struct Vector4
{

    public:
        Vector4(float x, float y, float z, float w);
        ~Vector4();
        float length() const;
        float dot(Vector4 other) const;
        void normalize();
        Vector4 normalized() const;
        Vector4 operator+(Vector4 other) const;
        Vector4 operator-(Vector4 other) const;
        Vector4 operator*(Vector4 other) const;
        Vector4 operator/(Vector4 other) const;
        float getX() const;
        float getY() const;
        float getZ() const;
        float getW() const;
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setW(float w);
    protected:
    private:
        float x;
        float y;
        float z;
        float w;

};

struct Matrix3
{

    public:
        Matrix3();
        ~Matrix3();
        void createIdentity();
        Matrix3 operator*(Matrix3 other) const;
        float* getValues() const;
        float getValue(unsigned int x, unsigned int y) const;
        void setValue(unsigned int x, unsigned int y, float value);
    protected:
    private:
        float values[3][3];

};

struct Matrix4
{

    public:
        Matrix4();
        ~Matrix4();
        void createIdentity();
        void createTranslation(Vector3 translation);
        void createRotation(Quaternion rotation);
        void createScale(Vector3 scale);
        void createOrthographic(float left, float right, float bottom, float top, float zNear, float zFar);
        void createPerspective(float fov, float aspect, float zNear, float zFar);
        Matrix4 operator*(Matrix4 other) const;
        float* getValues() const;
        float getValue(unsigned int x, unsigned int y) const;
        void setValue(unsigned int x, unsigned int y, float value);
    protected:
    private:
        float values[4][4];

};

struct Quaternion
{

    public:
        Quaternion(float x, float y, float z, float w);
        ~Quaternion();
        Quaternion conjugate() const;
        void normalize();
        Quaternion normalized() const;
        Quaternion rotate(Vector3 axis, float angle);
        Vector3 getLeft() const;
        Vector3 getRight() const;
        Vector3 getDown() const;
        Vector3 getUp() const;
        Vector3 getForward() const;
        Vector3 getBack() const;
        Matrix4 toRotationMatrix() const;
        Quaternion operator*(Vector3 other) const;
        Quaternion operator*(Quaternion other) const;
        Vector4 getValues() const;
    protected:
    private:
        float x;
        float y;
        float z;
        float w;

};

#endif // MATH3D_H
