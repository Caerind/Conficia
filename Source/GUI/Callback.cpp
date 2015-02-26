#include "Callback.hpp"

namespace cf
{

////////////////////////////////////////////////////////////
Callback::Callback(std::size_t callbackCount) : mCallbacks(callbackCount), mHoverDone(false)
{
}

////////////////////////////////////////////////////////////
void Callback::setCallback(Function callback, std::size_t index)
{
    if(index >= mCallbacks.size())
        index = 0;
    mCallbacks[index] = callback;
}

}

