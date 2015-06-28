#include "frustum.h"

Plane::Plane() : normal(0.0f, 0.0f, 0.0f), distance(0.0f)
{
    
}

Plane::~Plane()
{
    
}

void Plane::setCoefficients(float x, float y, float z, float w)
{
    
    normal = Vector3(x, y, z);
    distance = w;
    
    float length = normal.length();
    
    normal.normalize();
    distance /= length;
    
}

float Plane::getDistance(Vector3 point) const
{
    
    return normal.dot(point) + distance;
    
}

Vector3 Plane::getMinimumExtent(Vector3 minimumExtent, Vector3 maximumExtent) const
{
    
    float x = normal.getX() >= 0.0f ? minimumExtent.getX() : maximumExtent.getX();
    float y = normal.getY() >= 0.0f ? minimumExtent.getY() : maximumExtent.getY();
    float z = normal.getZ() >= 0.0f ? minimumExtent.getZ() : maximumExtent.getZ();
    
    return Vector3(x, y, z);
    
}

Vector3 Plane::getMaximumExtent(Vector3 minimumExtent, Vector3 maximumExtent) const
{
    
    float x = normal.getX() >= 0.0f ? maximumExtent.getX() : minimumExtent.getX();
    float y = normal.getY() >= 0.0f ? maximumExtent.getY() : minimumExtent.getY();
    float z = normal.getZ() >= 0.0f ? maximumExtent.getZ() : minimumExtent.getZ();
    
    return Vector3(x, y, z);
    
}

Frustum::Frustum()
{
    
}

Frustum::~Frustum()
{
    
}

void Frustum::setProjectionMatrix(Matrix4 projectionMatrix)
{
    
    this->projectionMatrix = projectionMatrix;
    
}

void Frustum::setViewMatrix(Matrix4 viewMatrix)
{
    
    this->viewMatrix = viewMatrix;
    
}

void Frustum::calculateFrustum()
{
    
    Matrix4 pv = projectionMatrix * viewMatrix;
    
    float x;
    float y;
    float z;
    float w;
    
    x = pv.getValue(0, 0) + pv.getValue(0, 3);
    y = pv.getValue(1, 0) + pv.getValue(1, 3);
    z = pv.getValue(2, 0) + pv.getValue(2, 3);
    w = pv.getValue(3, 0) + pv.getValue(3, 3);
    
    planes[0].setCoefficients(x, y, z, w);
    
    x = -pv.getValue(0, 0) + pv.getValue(0, 3);
    y = -pv.getValue(1, 0) + pv.getValue(1, 3);
    z = -pv.getValue(2, 0) + pv.getValue(2, 3);
    w = -pv.getValue(3, 0) + pv.getValue(3, 3);
    
    planes[1].setCoefficients(x, y, z, w);
    
    x = pv.getValue(0, 1) + pv.getValue(0, 3);
    y = pv.getValue(1, 1) + pv.getValue(1, 3);
    z = pv.getValue(2, 1) + pv.getValue(2, 3);
    w = pv.getValue(3, 1) + pv.getValue(3, 3);
    
    planes[2].setCoefficients(x, y, z, w);
    
    x = -pv.getValue(0, 1) + pv.getValue(0, 3);
    y = -pv.getValue(1, 1) + pv.getValue(1, 3);
    z = -pv.getValue(2, 1) + pv.getValue(2, 3);
    w = -pv.getValue(3, 1) + pv.getValue(3, 3);
    
    planes[3].setCoefficients(x, y, z, w);
    
    x = pv.getValue(0, 2) + pv.getValue(0, 3);
    y = pv.getValue(1, 2) + pv.getValue(1, 3);
    z = pv.getValue(2, 2) + pv.getValue(2, 3);
    w = pv.getValue(3, 2) + pv.getValue(3, 3);
    
    planes[4].setCoefficients(x, y, z, w);
    
    x = -pv.getValue(0, 2) + pv.getValue(0, 3);
    y = -pv.getValue(1, 2) + pv.getValue(1, 3);
    z = -pv.getValue(2, 2) + pv.getValue(2, 3);
    w = -pv.getValue(3, 2) + pv.getValue(3, 3);
    
    planes[5].setCoefficients(x, y, z, w);
    
}

bool Frustum::isInViewFrustum(Vector3 center, float radius) const
{
    
    for(int i = 0; i < 6; i++)
    {
        
        if(planes[i].getDistance(center) < -radius)
        {
            
            return false;
            
        }
        
    }
    
    return true;
    
}

bool Frustum::isInViewFrustum(Vector3 minimumExtent, Vector3 maximumExtent) const
{
    
    for(int i = 0; i < 6; i++)
    {
        
        if(planes[i].getDistance(planes[i].getMaximumExtent(minimumExtent, maximumExtent)) < 0.0f)
        {
            
            return false;
            
        }
        
    }
    
    return true;
    
}
