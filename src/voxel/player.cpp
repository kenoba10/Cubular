#include "player.h"

Player::Player(Window* window) : position(0, 0, 0), rotation(0, 0, 0, 1)
{

    this->window = window;

}

Player::~Player()
{

}

void Player::update()
{

    if(window->getInput().getKey(KEY_A))
    {

        position.setX(position.getX() + 0.5f);

    }

    if(window->getInput().getKey(KEY_D))
    {

        position.setX(position.getX() - 0.5f);

    }

    if(window->getInput().getKey(KEY_LEFT_SHIFT))
    {

        position.setY(position.getY() + 0.5f);

    }

    if(window->getInput().getKey(KEY_SPACE))
    {

        position.setY(position.getY() - 0.5f);

    }

    if(window->getInput().getKey(KEY_W))
    {

        position.setZ(position.getZ() + 0.5f);

    }

    if(window->getInput().getKey(KEY_S))
    {

        position.setZ(position.getZ() - 0.5f);

    }

    Vector2 centerPosition(window->getWidth() / 2.0f, window->getHeight() / 2.0f);

    if(window->getInput().getMouseButtonDown(MOUSEBUTTON_LEFT))
    {

        window->getInput().setMouseX(centerPosition.getX());
        window->getInput().setMouseY(centerPosition.getY());
        window->getInput().setCursor(false);
        mouseLocked = true;

    }

    if(window->getInput().getKeyDown(KEY_ESCAPE))
    {

        window->getInput().setMouseX(centerPosition.getX());
        window->getInput().setMouseY(centerPosition.getY());
        window->getInput().setCursor(true);
        mouseLocked = false;

    }

    if(mouseLocked)
    {

        Vector2 deltaPosition(window->getInput().getMouseX() - centerPosition.getX(), window->getInput().getMouseY() - centerPosition.getY());

        bool rotateY = deltaPosition.getX() != 0.0f;
        bool rotateX = deltaPosition.getY() != 0.0f;

        if(rotateY)
        {

            //Rotate Y-Axis
        }

        if(rotateX)
        {

            //Rotate X-Axis

        }

        window->getInput().setMouseX(centerPosition.getX());
        window->getInput().setMouseY(centerPosition.getY());

    }

}

Matrix4 Player::getTransformation() const
{

    Matrix4 translationMatrix;
    translationMatrix.createTranslation(position);

    Matrix4 rotationMatrix;
    rotationMatrix.createRotation(rotation);

    return translationMatrix * rotationMatrix;

}

int Player::getX() const
{

    return position.getX();

}

int Player::getY() const
{

    return position.getY();

}

int Player::getZ() const
{

    return position.getZ();

}

void Player::setX(int x)
{

    position.setX(x);

}

void Player::setY(int y)
{

    position.setY(y);

}

void Player::setZ(int z)
{

    position.setZ(z);

}
