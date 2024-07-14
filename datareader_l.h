#ifndef DATAREADER_L_H
#define DATAREADER_L_H

#include "datareader.h"
#include <QFile>

class DataReader_L : public DataReader
{
  public:
    DataReader_L();

    void printMemStat() { std::cout << memStat << std::endl; }
    void printCpuStat() { std::cout << cpuStat << std::endl; }
    void initStat() override;
    void updateStat() override;

  private:
    void updateMemStat();
    void updateCpuStat();

    QString path {"/proc"};

    QFile meminfo {path + "/meminfo"};
    QFile cpuinfo {path + "/cpuinfo"};
    QFile diskinfo {};

};

#endif // DATAREADER_L_H
