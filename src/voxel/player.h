#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include "window.h"
#include "input.h"
#include "math3d.h"

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
        Quaternion rotation;
        bool mouseLocked;

};

#endif // PLAYER_H
