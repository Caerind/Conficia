#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>

class Log
{
    public:
        enum Type
        {
            INFO,
            WARNING,
            ERROR,
        };

        Log();
        ~Log();

        bool openFile(std::string const& filename);

        friend Log& operator << (Log& log, const Type type)
        {
            log.mType = type;
            return log;
        }

        friend Log& operator << (Log& log, std::string const& text)
        {
            if (log.mFile.is_open())
            {
                log.logTime();
                log.logType();
                log.logText(text);
                log.logText("\n");
            }
            return log;
        }

    protected:
        void logTime();
        void logType();
        void logText(std::string const& text);

    protected:
        std::ofstream mFile;
        Log::Type mType;
};

#endif // LOG_HPP
