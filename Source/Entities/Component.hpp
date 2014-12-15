#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <map>
#include <string>

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


#endif // COMPONENT_HPP
