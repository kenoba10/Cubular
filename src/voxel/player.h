#ifndef PLAYER_H
#define PLAYER_H

class Player;

#define PLAYER_SPEED 10.0f / TICKS_PER_SECOND
#define MOUSE_SENSITIVITY 1.0f / TICKS_PER_SECOND

#include <algorithm>

#include "../core/window.h"
#include "../core/input.h"
#include "../core/math3d.h"
#include "world.h"
#include "chunk.h"

class Player
{

    public:
        Player(Window* window);
        ~Player();
        void update();
        Matrix4 getViewMatrix() const;
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
        Vector3 oldPosition;
        Vector3 position;
        Vector3 right;
        Vector3 up;
        Vector3 back;
        float pitch;
        float yaw;
        float roll;
        bool mouseLocked;

};

#endif // PLAYER_H
