#ifndef SGUI_CALLBACK_HPP
#define SGUI_CALLBACK_HPP

#include <functional>
#include <vector>

namespace SGUI
{

class Callback
{
    public:
        typedef std::function<void()> Function;

    public:
        Callback(size_t callbackCount);

        void setCallback(Function callback, size_t index = 0);

    protected:
        std::vector<Function> mCallbacks;
        bool mHoverDone; //Used by Button (see handleEvent())

};

}

#endif // SGUI_CALLBACK_HPP
