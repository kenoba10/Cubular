#include "player.h"

Player::Player(Window* window) : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f, 1.0f)
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

        position = position + rotation.getLeft();

    }

    if(window->getInput().getKey(KEY_D))
    {

        position = position + rotation.getRight();

    }

    if(window->getInput().getKey(KEY_LEFT_SHIFT))
    {

        position = position + Vector3(0.0f, -1.0f, 0.0f);

    }

    if(window->getInput().getKey(KEY_SPACE))
    {

        position = position + Vector3(0.0f, 1.0f, 0.0f);

    }

    if(window->getInput().getKey(KEY_W))
    {

        position = position + rotation.getForward();

    }

    if(window->getInput().getKey(KEY_S))
    {

        position = position + rotation.getBack();
        
    }
    
    Vector2 centerPosition(window->getWidth() / 2.0f, window->getHeight() / 2.0f);

    if(mouseLocked)
    {

        Vector2 deltaPosition(window->getInput().getMouseX() - centerPosition.getX(), window->getInput().getMouseY() - centerPosition.getY());

        bool rotateY = deltaPosition.getX() != 0.0f;
        bool rotateX = deltaPosition.getY() != 0.0f;

        if(rotateY)
        {

            rotation.rotate(Vector3(0.0f, 1.0f, 0.0f), deltaPosition.getX() * 0.25f);
        }
        
        if(rotateX)
        {

            rotation.rotate(rotation.getRight(), deltaPosition.getY() * 0.25f);

        }
        
        window->getInput().setMouseX(centerPosition.getX());
        window->getInput().setMouseY(centerPosition.getY());
        
    }
    
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

}

Matrix4 Player::getTransformation() const
{

    Matrix4 translationMatrix;
    translationMatrix.createTranslation(Vector3(-1.0f, -1.0f, -1.0f) * position);

    Matrix4 rotationMatrix = rotation.toRotationMatrix();

    return rotationMatrix * translationMatrix;

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
