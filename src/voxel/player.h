#ifndef PLAYER_H
#define PLAYER_H

class Player;

#define PLAYER_SPEED 10.0f / TICKS_PER_SECOND
#define MOUSE_SENSITIVITY 1.0f / TICKS_PER_SECOND

#include <algorithm>

#include "../core/window.h"
#include "../core/input.h"
#include "../core/math3d.h"
#include "../physics/frustum.h"

class Player
{

    public:
        Player(Window* window);
        ~Player();
        void update();
        void updateFrustum(float fov, float aspect, float zNear, float zFar);
        Matrix4 getViewMatrix() const;
        Frustum& getFrustum();
        int getOldX() const;
        int getOldY() const;
        int getOldZ() const;
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
    protected:
    private:
        Window* window;
        Frustum frustum;
        Vector3 oldPosition;
        Vector3 position;
        Quaternion rotation;
        float pitch;
        float yaw;
        float roll;
        bool mouseLocked;

};

#endif // PLAYER_H
