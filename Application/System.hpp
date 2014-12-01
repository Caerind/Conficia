#ifndef APP_SYSTEM_HPP
#define APP_SYSTEM_HPP

#include "Window.hpp"
#include "ResourceManager.hpp"
#include "Clock.hpp"
#include "Log.hpp"
#include "Version.hpp"
#include "../Audio/MusicPlayer.hpp"
#include "../Audio/SoundPlayer.hpp"

namespace app
{

class System
{
    public:
        static void init(std::string const& appName = "");
        static void release();
        static System& instance();

        static std::string getAppName();
        static Window& getWindow();
        static ResourceManager& getResources();
        static Clock& getClock();
        static Log& getLog();
        static Version& getVersion();
        static MusicPlayer& getMusicPlayer();
        static SoundPlayer& getSoundPlayer();

    protected:
        System(std::string const& appName = "");

        static System* Instance;

        std::string mAppName;

        Window mWindow;
        ResourceManager mResources;
        Clock mClock;
        Log mLog;
        Version mVersion;
        MusicPlayer mMusics;
        SoundPlayer mSounds;
};

} // namespace app

#endif // APP_SYSTEM_HPP
