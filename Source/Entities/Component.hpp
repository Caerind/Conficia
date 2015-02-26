#ifndef CONFICIA_COMPONENT_HPP
#define CONFICIA_COMPONENT_HPP

#include <map>
#include <string>

namespace cf
{

class Component
{
    public:
        Component() {}
        ~Component() {}

        static std::string getType()
        {
            return "Component";
        }
};

typedef std::map<std::string,Component*> ComponentArray;

}

#endif // CONFICIA_COMPONENT_HPP
