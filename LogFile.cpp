//
// Created by 裴沛东 on 2021/11/5.
//

#include <ctime>
#include "LogFile.h"
size_t LogFile::currentSize = 0;
size_t LogFile::logLines = 0;
size_t LogFile::fileNum = 0;

LogFile::LogFile(std::string filepath, std::string filename, std::size_t LogSaveDays, std::size_t LogFileSize):filepath(filepath),filename(filename),LogSaveDays(LogSaveDays),LogFileSize(LogFileSize) {
    fileName = filepath+filename+"_log"+std::to_string(fileNum)+".txt";
    std::cout<<"file name is "<<fileName<<std::endl;
    out = std::ofstream(fileName,std::ios_base::in|std::ios_base::trunc);
    fileStoreDays[time(0)] = fileName;
    std::thread(monitorFileTime());

}

LogFile::~LogFile() {
    if(out.is_open()) {
        out.close();
    }
}
bool LogFile::append(const std::string &strLog) {
    if(out.is_open()) {
        out<<strLog;
        logLines++;
        if(logLines > 1000) {
            currentSize = getFileSize();
            logLines = 0;
            if(currentSize > this->LogFileSize) {
                ++fileNum;
                fileName = filepath+filename+"_log"+std::to_string(fileNum)+".txt";
                if(out.is_open()) {
                    out.close();
                }
                out = std::ofstream(fileName,std::ios_base::in|std::ios_base::trunc);
                fileStoreDays[time(0)] = fileName;
            }
        }
    }else {
        return false;
    }
    return true;
}
size_t LogFile::getFileSize() {
    std::ifstream in(fileName.c_str());
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    in.close();
    return size;
}


void LogFile::setFileName(const std::string &filename) {
    this->filename = filename;
}

void LogFile::setFilePath(const std::string &filePath) {
    this->filepath = filePath;
}

void LogFile::setLogFileSize(size_t size) {
    this->LogFileSize = size;
}


void LogFile::setLogSaveDays(size_t days) {
    this->LogSaveDays = days;
}

void LogFile::setLogFileOption(const std::string &filepath, const std::string &filename, std::size_t LogSaveDays,
                               std::size_t LogFileSize) {
    setFilePath(filepath);
    setFileName(filename);
    setLogSaveDays(LogSaveDays);
    setLogFileSize(LogFileSize);
    fileName = filepath+filename+"_log"+std::to_string(fileNum)+".txt";
    if(out.is_open())
        out.close();
    out = std::ofstream(fileName,std::ios_base::in|std::ios_base::trunc);
    fileStoreDays[time(0)] = fileName;
}

void LogFile::monitorFileTime() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::minutes(24*60));
        time_t now = time(0);
        auto tmp = fileStoreDays.begin();
        while(tmp != fileStoreDays.end()) {
            if((now-tmp->first)/86400 > LogSaveDays) {
                remove(tmp->second.c_str());
                fileStoreDays.erase(tmp++);
            }else {
                tmp++;
            }

        }
    }

}