#include "Application.hpp"

Application* Application::Instance = nullptr;

Application::Application()
{
    mAudio = new Audio();
    mClock = new Clock();
    mLang = new Lang();
    mLog = new Log();
    mResourceManager = new ResourceManager();
    mStateManager = new StateManager();
    mStatistics = new Statistics();
    mWindow = new Window();
    mData = new Data();

    if (Instance == nullptr)
    {
        Instance = this;
    }
}

Application& Application::instance()
{
    if (Instance == nullptr)
    {
        Instance = new Application();
    }
    return *Instance;
}

Audio& Application::getAudio()
{
    return *instance().mAudio;
}

Clock& Application::getClock()
{
    return *instance().mClock;
}

Lang& Application::getLang()
{
    return *instance().mLang;
}

Log& Application::getLog()
{
    return *instance().mLog;
}

ResourceManager& Application::getResources()
{
    return *instance().mResourceManager;
}

StateManager& Application::getStates()
{
    return *instance().mStateManager;
}

Statistics& Application::getStats()
{
    return *instance().mStatistics;
}

Window& Application::getWindow()
{
    return *instance().mWindow;
}

Data& Application::getData()
{
    return *instance().mData;
}

std::size_t Application::getMajor()
{
    return instance().mMajor;
}

std::size_t Application::getMinor()
{
    return instance().mMinor;
}

std::size_t Application::getPatch()
{
    return instance().mPatch;
}

std::string Application::getTitle()
{
    return instance().mTitle;
}

void Application::setAudio(Audio* audio)
{
    if (audio != nullptr)
        instance().mAudio = audio;
}

void Application::setClock(Clock* clock)
{
    if (clock != nullptr)
        instance().mClock = clock;
}

void Application::setLang(Lang* lang)
{
    if (lang != nullptr)
        instance().mLang = lang;
}

void Application::setLog(Log* log)
{
    if (log != nullptr)
        instance().mLog = log;
}

void Application::setResourceManager(ResourceManager* manager)
{
    if (manager != nullptr)
        instance().mResourceManager = manager;
}

void Application::setStatistics(Statistics* stats)
{
    if (stats != nullptr)
        instance().mStatistics = stats;
}

void Application::setWindow(Window* window)
{
    if (window != nullptr)
        instance().mWindow = window;
}

void Application::setData(Data* data)
{
    if (data != nullptr)
        instance().mData = data;
}

void Application::setMajor(std::size_t major)
{
    instance().mMajor = major;
}

void Application::setMinor(std::size_t minor)
{
    instance().mMinor = minor;
}

void Application::setPatch(std::size_t patch)
{
    instance().mPatch = patch;
}

void Application::setTitle(std::string title)
{
    instance().mTitle = title;
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	while (mWindow->isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			handleEvents();
			update(TimePerFrame);

			if (mStateManager->isEmpty())
                mWindow->close();

			std::cout << std::flush;
		}
		render();
	}
}

void Application::handleEvents()
{
    sf::Event event;
    while (mWindow->pollEvent(event))
    {
        mStateManager->handleEvent(event);

        if(event.type == sf::Event::Closed)
        {
            mWindow->close();
        }
    }
}

void Application::update(sf::Time dt)
{
    mStateManager->update(dt);
    mStatistics->update(dt);
    mAudio->update();
}

void Application::render()
{
    mWindow->clear();

    mStateManager->render();

    #ifdef DEBUG
    mStatistics->render();
    #endif

    mWindow->display();
}
