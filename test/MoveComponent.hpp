#ifndef MOVECOMPONENT_HPP
#define MOVECOMPONENT_HPP

#include "../Source/Entities/Component.hpp"

class MoveComponent : public cf::Component
{
    public:
        MoveComponent() {}

        static std::string getType()
        {
            return "MoveComponent";
        }

        void setSpeed(float speed)
        {
            mSpeed = speed;
        }

        float getSpeed()
        {
            return mSpeed;
        }

    protected:
        float mSpeed;
};

#endif // MOVECOMPONENT_HPP
