
#include "LogHandler.hpp"

#define RESET "\033[0m"
#define BLACK "\033[30m" /* Black */
#define RED "\033[31m" /* Red */
#define GREEN "\033[32m" /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m" /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m" /* Cyan */
#define WHITE "\033[37m" /* White */
#define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
#define BOLDRED "\033[1m\033[31m" /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m" /* Bold White */

namespace log {
static auto g_start = std::chrono::steady_clock::now();

LogHandler& LogHandler::getInstance()
{
    static LogHandler sLogHandler;
    return sLogHandler;
}

LogHandler::LogHandler()
{
    std::cout << std::fixed << std::setprecision(9) << std::left;
}

LogHandler::~LogHandler()
{
}

void LogHandler::log(const eLogLevel& level, const std::string& prefix, const std::string& message)
{
    std::string color(WHITE);

    const std::chrono::duration<double> elapsedSeconds = std::chrono::steady_clock::now() - g_start;

    switch (level) {
    case eLogLevel::logVerbose:
    case eLogLevel::logDebug:
        color = RESET;
        break;
    case eLogLevel::logInfo:
        color = WHITE;
        break;
    case eLogLevel::logWarn:
        color = YELLOW;
        break;
    case eLogLevel::logError:
        color = RED;
        break;
    default:
        color = WHITE;
        break;
    }

    std::cout << color << elapsedSeconds.count() << ": " << prefix << message << RESET << "\n";
}

void LogHandler::logMethod(const std::string& methodName)
{
    const std::unique_ptr<LogStream> logStream
        = std::make_unique<LogStream>("", eLogLevel::logInfo);
    *logStream << methodName << "()";
}

void LogHandler::logMethod(const LogPrefix& pref, const std::string& methodName)
{
    const std::unique_ptr<LogStream> logStream
        = std::make_unique<LogStream>(pref.getPrefix(), eLogLevel::logInfo);
    *logStream << methodName << "()";
}

} // namespace log
