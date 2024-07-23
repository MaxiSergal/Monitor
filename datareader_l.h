#ifndef DATAREADER_L_H
#define DATAREADER_L_H

#include "idatareader.h"
#include <QFile>

class DataReader_L : public IDataReader
{
  public:
    DataReader_L();

    // void printMemStat() { std::cout << memStat << std::endl; }
    // void printCpuStat() { std::cout << cpuStat << std::endl; }
    void initStat() override;

    MemStat *getMEMstat() override;
    CpuStat *getCPUstat() override;

  private:
    QString path {"/proc"};

    QFile meminfo  {path + "/meminfo"};
    QFile cpuinfo  {path + "/cpuinfo"};
    QFile diskinfo {};

};

#endif // DATAREADER_L_H
