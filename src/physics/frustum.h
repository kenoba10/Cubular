#ifndef FRUSTUM_H
#define FRUSTUM_H

struct Plane;
class Frustum;

#include <array>

#include "../core/math3d.h"

struct Plane
{
    
    public:
        Plane();
        ~Plane();
        void setCoefficients(float x, float y, float z, float w);
        float getDistance(Vector3 point) const;
        Vector3 getMinimumExtent(Vector3 minimumExtent, Vector3 maximumExtent) const;
        Vector3 getMaximumExtent(Vector3 minimumExtent, Vector3 maximumExtent) const;
    protected:
    private:
        Vector3 normal;
        float distance;
    
};

class Frustum
{
    
    public:
        Frustum();
        ~Frustum();
        void setProjectionMatrix(Matrix4 projectionMatrix);
        void setViewMatrix(Matrix4 viewMatrix);
        void calculateFrustum();
        bool isInViewFrustum(Vector3 center, float radius) const;
        bool isInViewFrustum(Vector3 minimumExtent, Vector3 maximumExtent) const;
    protected:
    private:
        Matrix4 projectionMatrix;
        Matrix4 viewMatrix;
        std::array<Plane, 6> planes;
    
};

#endif // FRUSTUM_H
