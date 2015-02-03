#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>
#include <string>

#include "Audio.hpp"
#include "Clock.hpp"
#include "Lang.hpp"
#include "Log.hpp"
#include "ResourceManager.hpp"
#include "StateManager.hpp"
#include "Statistics.hpp"
#include "Window.hpp"
#include "Data.hpp"

class Application
{
    public:
        Application();

        static Application& instance();

        static Audio& getAudio();
        static Clock& getClock();
        static Lang& getLang();
        static Log& getLog();
        static ResourceManager& getResources();
        static StateManager& getStates();
        static Statistics& getStats();
        static Window& getWindow();
        static Data& getData();

        static std::size_t getMajor();
        static std::size_t getMinor();
        static std::size_t getPatch();
        static std::string getTitle();

        static void setAudio(Audio* audio);
        static void setClock(Clock* clock);
        static void setLang(Lang* lang);
        static void setLog(Log* log);
        static void setResourceManager(ResourceManager* manager);
        static void setStateManager(StateManager* manager);
        static void setStatistics(Statistics* stats);
        static void setWindow(Window* window);
        static void setData(Data* data);

        static void setMajor(std::size_t major);
        static void setMinor(std::size_t minor);
        static void setPatch(std::size_t patch);
        static void setTitle(std::string title);



        void run();

    protected:
        void handleEvents();
        void update(sf::Time dt);
        void render();

    protected:
        static Application* Instance;

        Audio* mAudio;
        Clock* mClock;
        Lang* mLang;
        Log* mLog;
        ResourceManager* mResourceManager;
        StateManager* mStateManager;
        Statistics* mStatistics;
        Window* mWindow;
        Data* mData;

        std::size_t mMajor;
        std::size_t mMinor;
        std::size_t mPatch;
        std::string mTitle;
};

#endif // APPLICATION_HPP
