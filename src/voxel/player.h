#ifndef PLAYER_H
#define PLAYER_H

class Player;

#define PLAYER_SPEED 0.25f
#define MOUSE_SENSITIVITY 0.05f

#include <algorithm>

#include "../core/window.h"
#include "../core/input.h"
#include "../core/math3d.h"

class Player
{

    public:
        Player(Window* window);
        ~Player();
        void update();
        Matrix4 getTransformation() const;
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int x);
        void setY(int y);
        void setZ(int z);
    protected:
    private:
        Window* window;
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
