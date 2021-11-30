//
// Created by 裴沛东 on 2021/11/5.
//

#ifndef LOG_LOGFILE_H
#define LOG_LOGFILE_H
#include <string>
#include <fstream>
#include <cstdio>
#include <unordered_map>
#include <thread>
#include <iostream>

class LogFile {
public:
    LogFile(std::string filepath,std::string filename,std::size_t LogSaveDays,std::size_t LogFileSize);
    ~LogFile();
    bool append(const std::string& strLog);
    size_t getFileSize();
    void setFileName(const std::string& filename);
    void setFilePath(const std::string& filePath);
    void setLogFileSize(size_t size);
    void setLogSaveDays(size_t days);
    void setLogFileOption(const std::string &filepath,const std::string &filename,std::size_t LogSaveDays,std::size_t LogFileSize);
    void getCurrentDays();
    void monitorFileTime();
private:
    std::ofstream out;
    std::string filename;
    std::string filepath;
    std::string fileName;
    size_t LogFileSize;
    size_t LogSaveDays;
    static size_t currentSize;
    static size_t logLines;
    static size_t fileNum;
    std::unordered_map<time_t,std::string> fileStoreDays;

};


#endif //LOG_LOGFILE_H
