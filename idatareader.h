#ifndef IDATAREADER_H
#define IDATAREADER_H
#define DEBUG

#ifdef DEBUG
#include <QDebug>
#define WATCH(x)   qDebug() << (#x) << "=" << (x);
#define PRINT(str) qDebug() << str;
#endif

#include "memstat.h"
#include "cpustat.h"

class IDataReader
{
  public:
    CpuStat cpuStat;
    MemStat memStat;

    virtual MemStat *getMEMstat() = 0;
    virtual CpuStat *getCPUstat() = 0;
    virtual void initStat() = 0;

};

#endif // IDATAREADER_H
