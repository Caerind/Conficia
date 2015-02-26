#ifndef CONFICIA_CALLBACK_HPP
#define CONFICIA_CALLBACK_HPP

#include <functional>
#include <vector>

namespace cf
{

class Callback
{
    public:
        typedef std::function<void()> Function;

    public:
        Callback(std::size_t callbackCount);

        void setCallback(Function callback, std::size_t index = 0);

    protected:
        std::vector<Function> mCallbacks;
        bool mHoverDone; //Used by Button (see handleEvent())

};

}

#endif // CONFICIA_CALLBACK_HPP
