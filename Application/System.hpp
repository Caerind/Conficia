#ifndef APP_SYSTEM_HPP
#define APP_SYSTEM_HPP

#include "Window.hpp"
#include "ResourceManager.hpp"
#include "Clock.hpp"
#include "Log.hpp"
#include "Version.hpp"

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

    protected:
        System(std::string const& appName = "");

        static System* Instance;

        std::string mAppName;

        Window mWindow;
        ResourceManager mResources;
        Clock mClock;
        Log mLog;
        Version mVersion;
};

} // namespace app

#endif // APP_SYSTEM_HPP
