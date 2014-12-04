#include "Callback.hpp"

namespace SGUI
{

////////////////////////////////////////////////////////////
Callback::Callback(size_t callbackCount) : mCallbacks(callbackCount), mHoverDone(false)
{
}

////////////////////////////////////////////////////////////
void Callback::setCallback(Function callback, size_t index)
{
    if(index >= mCallbacks.size())
        index = 0;
    mCallbacks[index] = callback;
}

} // namespace SGUI

