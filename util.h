#ifndef UTIL
#define UTIL
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

// Classic helper function
class Util {

public:
    static std::string convertToTime(long int input_seconds);
    static std::string getProgressBar(std::string percent);
    static std::ifstream getStream(std::string path);
    static vector<string> splitByWhiteSpace(string stringToSplit);
};

std::vector<std::string> Util::splitByWhiteSpace(std::string stringToSplit){
       istringstream buf(stringToSplit);
       istream_iterator<string> beg(buf),end;
       return std::vector<std::string>(beg,end);
}

std::string Util::convertToTime(long int input_seconds) {
    long minutes = input_seconds / 60;
    long hours = minutes / 60;
    long seconds = int(input_seconds%60);
    minutes = int(minutes%60);
    std::string result = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
    return result;
}

// constructing string for given percentage
// 50 bars is uniformly stretched 0 - 100 %
// meaning: every 2% is one bar(|)
std::string Util::getProgressBar(std::string percent) {
    std::string result = "0%% ";
    int _size= 50;
    int  boundaries;

    try {
        boundaries = (stof(percent)/100)*_size;
    } catch (...){
        boundaries = 0;
    }

    for(int i=0;i<_size;i++){
        if(i<=boundaries){
            result +="|";
        }
        else{
            result +=" ";
        }
    }

    result +=" " + percent.substr(0,5) + " /100%%";

    return result;
}

// wrapper for creating streams
std::ifstream Util::getStream(std::string path){
    std::ifstream stream(path);
    if (!stream || !stream.is_open()){
        stream.close();
        throw std::runtime_error("Non - existing PID");
    }
    return stream;
}
#endif