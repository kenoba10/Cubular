#include "player.h"

Player::Player(Window* window) : oldPosition(0.0f, 0.0f, 0.0f), position(0.0f, 0.0f, 0.0f), right(1.0f, 0.0f, 0.0f), up(0.0f, 1.0f, 0.0f), back(0.0f, 0.0f, 1.0f)
{

    this->window = window;
    
    pitch = 0.0f;
    yaw = 0.0f;
    roll = 0.0f;
    
    mouseLocked = false;

}

Player::~Player()
{

}

void Player::update()
{
    
    oldPosition = position;

    if(window->getInput().getKey(KEY_A))
    {

        position = position - right * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);

    }

    if(window->getInput().getKey(KEY_D))
    {

        position = position + right * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);

    }

    if(window->getInput().getKey(KEY_LEFT_SHIFT))
    {

        position = position - up * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);

    }

    if(window->getInput().getKey(KEY_SPACE))
    {

        position = position + up * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);

    }

    if(window->getInput().getKey(KEY_W))
    {

        position = position - back * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);

    }

    if(window->getInput().getKey(KEY_S))
    {

        position = position + back * Vector3(PLAYER_SPEED, PLAYER_SPEED, PLAYER_SPEED);
        
    }
    
    Vector2 centerPosition(window->getWidth() / 2.0f, window->getHeight() / 2.0f);

    if(mouseLocked)
    {

        Vector2 deltaPosition(window->getInput().getMouseX() - centerPosition.getX(), window->getInput().getMouseY() - centerPosition.getY());

        bool rotateY = deltaPosition.getX() != 0.0f;
        bool rotateX = deltaPosition.getY() != 0.0f;

        if(rotateY)
        {

            yaw = yaw + deltaPosition.getX() * MOUSE_SENSITIVITY;
        }
        
        if(rotateX)
        {

            
            pitch = std::min(std::max(pitch + deltaPosition.getY() * MOUSE_SENSITIVITY, -89.0f), 89.0f);

        }
        
        if(rotateY || rotateX)
        {
            
            Vector3 forward(0.0f, 0.0f, -1.0f);
            
            right = forward.cross(Vector3(0.0f, 1.0f, 0.0f)).normalized();
            
            forward.rotate(right, pitch);
            forward.rotate(Vector3(0.0f, 1.0f, 0.0f), yaw);
            
            right = forward.cross(Vector3(0.0f, 1.0f, 0.0f)).normalized();
            
            back = Vector3(-forward.getX(), -forward.getY(), -forward.getZ()).normalized();
            up = forward.cross(right).normalized();
            right = forward.cross(up).normalized();
            
            window->getInput().setMouseX(centerPosition.getX());
            window->getInput().setMouseY(centerPosition.getY());
            
        }
        
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

Matrix4 Player::getViewMatrix() const
{
    
    Matrix4 viewMatrix;
    viewMatrix.createLookAt(position, position - back, up);

    return viewMatrix;

}

int Player::getOldX() const
{

    return oldPosition.getX();

}

int Player::getOldY() const
{

    return oldPosition.getY();

}

int Player::getOldZ() const
{

    return oldPosition.getZ();

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
