#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Logger {
public:
    enum Level { INFO, WARNING, ERROR };

    static void SetLogFile(const std::string& filename) {
        logFilename() = filename;
    }

    static void Log(const std::string& message, Level level = INFO) {
        std::ofstream logFile(logFilename(), std::ios_base::app);
        if (logFile.is_open()) {
            logFile << CurrentDateTime() << " [" << LevelToString(level) << "] " << message << std::endl;
        }
    }

private:
    static std::string& logFilename() {
        static std::string filename = "log.txt";
        return filename;
    }

    static std::string CurrentDateTime() {
        std::ostringstream oss;
        std::time_t t = std::time(nullptr);
        std::tm tm;
#ifdef _WIN32
        localtime_s(&tm, &t);
#else
        tm = *std::localtime(&t);
#endif
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    static std::string LevelToString(Level level) {
        switch (level) {
            case INFO: return "INFO";
            case WARNING: return "WARNING";
            case ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }
};