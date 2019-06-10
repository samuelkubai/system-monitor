#include <string>
#include "ProcessParser.h"

using namespace std;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
private:
    string pid;
    string user;
    string cmd;
    string cpu;
    string mem;
    string upTime;

public:
    Process(string pid){
        this->pid = pid;
        this->user = ProcessParser::getProcUser(pid);
        this->cmd  = ProcessParser::getCmd(pid);
    }
    void setPid(int pid);
    string getPid()const;
    string getUser()const;
    string getCmd()const;
    int getCpu()const;
    int getMem()const;
    string getUpTime()const;
    string getProcess();
};

void Process::setPid(int pid){
    this->pid = pid;
}

string Process::getPid()const {
    return this->pid;
}

string Process::getUser()const {
    return this->user;
}

string Process::getCmd() const {
    return this->cmd;
}

int Process::getCpu() const {
    return this->cpu;
}

int Process::getMem() const {
    return this->mem;
}

string Process::getUpTime() const {
    return this->upTime;
}

string Process::getProcess() {
    if(!ProcessParser::isPidExisting(this->pid))
        return "";
    this->mem = ProcessParser::getVmSize(this->pid);
    this->upTime = ProcessParser::getProcUpTime(this->pid);
    this->cpu = ProcessParser::getCpuPercent(this->pid);

    return (this->pid + "   " + this->user + "   " + this->cpu +  "   " + this->mem +  "   " + this->upTime +  "   " + this->cmd); 
}
