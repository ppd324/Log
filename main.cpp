#include <iostream>
#include <ctime>
#include <thread>
#include "Logger.h"
using namespace Log;

int main() {
    initLogLevel();
    Logger::setLogFmtType(Logger::STRING);
    Logger::setLogMode(OUTPUT_CF);
    Logger::setLogFile("H:\\c++\\Log\\","test",7,1024*1024*100);
    LOG_DEBUG<<"hello world";
    LOG_TRACE<<7<<"jisdjfj"<<0.2154545;
    LOG_INFO<<"hello world"<<" 11 + "<<"20 = "<<11+20;
    LOG_ERROR<<"hejsfkfjks"<<" "<<78<<8989899988989;
    LOG_WARN<<"sffsfsfskjfk"<<-2154545<<" "<<8787878;
    thread t1([](){
        int i=0;
        while(i < 1000) {
            LOG_WARN<<"child thread id is:"<<this_thread::get_id()<<" "<<i;
            i++;
        }
    });
    int i=0;
    while(i < 1000) {
        LOG_WARN<<"main thread id is:"<<this_thread::get_id()<<" "<<i;
        i++;
    }
    t1.join();
    //LOG_FATAL<<"sfjkjksfjkf"<<"fsfkkskf"<<7888787878787;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
