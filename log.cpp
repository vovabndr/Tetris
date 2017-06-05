#include "log.h"

#include <fstream>
#include <ctime>
#include <sstream>
#include <iostream>

std::ofstream Log::fout;
Log* Log::instance;

Log::~Log() {
    fout.close();
    delete instance;
}

Log& Log::getInstance() {
    if(!instance)     {
        instance = new Log();

        initialize();
    }
    return *instance;
}

void Log::initialize() {
    fout.open("sveta_log.dat", std::ios::out | std::ios::app);
    if (!fout) {
        std::cout << "can't open log file" << std::endl;
    }
}

void Log::i(std::string flag, std::string message) {
    if (fout) {
        time_t now = time(0);
        struct tm *tm = localtime(&now);

        std::stringstream ss;
        ss << tm->tm_mday << ".";
        ss << tm->tm_mon + 1 << ".";
        ss << tm->tm_year + 1900 << " ";
        ss << tm->tm_hour << ":";
        ss << tm->tm_min << ":";
        ss << tm->tm_sec;

        std::string timestamp = ss.str();

        fout << timestamp + " " + flag + " | " + message + '\n';
    }
}
