#ifndef APP_LOG_HPP
#define APP_LOG_HPP

#include <fstream>

namespace app
{

class Log
{
    public:
        enum Type
        {
            INFO,
            WARNING,
            ERROR,
        };

        Log(std::string const& filename);
        ~Log();

        friend Log& operator << (Log& log, const Type type)
        {
            if (log.mFile.is_open())
            {
                switch (type)
                {
                    case Log::ERROR:
                        log.mFile << "[ERROR]: ";
                        break;

                    case Log::WARNING:
                        log.mFile << "[WARNING]: ";
                        break;

                    default:
                        log.mFile << "[INFO]: ";
                        break;
                }
            }
            return log;
        }

        friend Log& operator << (Log& log, std::string const& text)
        {
            if (log.mFile.is_open())
            {
                log.mFile << text << std::endl;
            }
            return log;
        }

    protected:
        std::ofstream mFile;
};

} // namespace app

#endif // APP_LOG_HPP
