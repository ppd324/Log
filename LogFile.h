//
// Created by 裴沛东 on 2021/11/5.
//

#ifndef LOG_LOGFILE_H
#define LOG_LOGFILE_H
#include <string>

class LogFile {
public:
    LogFile(std::string filepath,std::string filename,std::size_t LogSaveDays,std::size_t LogFileSize);
    bool append(const std::string& strLog);

};


#endif //LOG_LOGFILE_H
