#include "System.hpp"

namespace app
{

System* System::Instance = new System();

System::System(std::string const& appName)
: mAppName(appName)
, mLog("system.log")
{
}

void System::init(std::string const& appName)
{
    Instance = new System(appName);
}

void System::release()
{
    Instance = nullptr;
}

System& System::instance()
{
    if (Instance == nullptr)
    {
        init();
    }
    return *Instance;
}

std::string System::getAppName()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mAppName;
}

Window& System::getWindow()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mWindow;
}

ResourceManager& System::getResources()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mResources;
}

Clock& System::getClock()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mClock;
}

Log& System::getLog()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mLog;
}

Version& System::getVersion()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mVersion;
}

MusicPlayer& System::getMusicPlayer()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mMusics;
}

SoundPlayer& System::getSoundPlayer()
{
    if (Instance == nullptr)
    {
        init();
    }
    return instance().mSounds;
}

} // namespace app
