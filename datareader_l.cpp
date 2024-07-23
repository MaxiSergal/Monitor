#include "datareader_l.h"
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QDebug>

DataReader_L::DataReader_L()
{

}

void DataReader_L::initStat()
{
  if(cpuinfo.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QByteArray contents = cpuinfo.readAll();
    QTextStream qts(&contents);

    size_t cores = 0;
    while(!qts.atEnd())
    {
      QString line = qts.readLine();
      QStringList parts = line.split(':');

      if(parts[0].trimmed() == "processor")
        cores++;
    }

    if(cores)
    {
      QVector<CoreStat*> vCores;
      for(int i = 0; i < cores; i++)
      {
        CoreStat *core = new CoreStat;

        vCores.push_back(core);
      }

      cpuStat.setCores(vCores);
    }

    cpuinfo.close();
  }
  // if(meminfo.open(QIODevice::ReadOnly | QIODevice::Text))
  // {
  //   QByteArray contents = meminfo.readAll();
  //   QTextStream qts(&contents);
  //   QMap<QString, size_t*>  memMap
  //       {
  //           {"MemTotal",   &memStat.MemTotal},
  //           {"MemFree",    &memStat.MemFree},
  //           {"Buffers",    &memStat.Buffers},
  //           {"Cached",     &memStat.Cached},
  //           {"SwapTotal",  &memStat.SwapTotal},
  //           {"SwapFree",   &memStat.SwapFree},
  //           {"Active",     &memStat.Active},
  //           {"Inactive",   &memStat.Inactive},
  //           {"SwapCached", &memStat.SwapCached}
  //       };

  //   while(!qts.atEnd())
  //   {
  //     QString line = qts.readLine();
  //     QStringList parts = line.split(':');

  //     QString key      = parts[0].trimmed();
  //     QString strValue = parts[1].trimmed();

  //     if(memMap.count(key))
  //       *memMap[key] = strValue.toUInt();
  //   }
  //   meminfo.close();
  // }
  // else
  //   qDebug() << "File meminfo not open";

  // QFile cpuinfo(path + "/cpuinfo");
  // if(cpuinfo.open(QIODevice::ReadOnly | QIODevice::Text))
  // {
  //   QByteArray contents = cpuinfo.readAll();
  //   QTextStream qts(&contents);

  //   if(cpuStat.isAllocated)
  //   {
  //     cpu_stat_t::core_stat_t *currentCore = cpuStat.headCore;
  //     while(!qts.atEnd())
  //     {
  //       size_t value = 0;
  //       QMap<QString, QString*> cpuMap
  //           {
  //               {"processor",   &currentCore->processor},
  //               {"vendor_id",   &currentCore->vendor_id},
  //               {"cpu family",  &currentCore->cpu_family},
  //               {"model",       &currentCore->model},
  //               {"model name",  &currentCore->model_name},
  //               {"stepping",    &currentCore->stepping},
  //               {"cpu MHz",     &currentCore->cpu_MHz},
  //               {"cache size",  &currentCore->cache_size},
  //               {"physical id", &currentCore->physical_id},
  //               {"siblings",    &currentCore->siblings},
  //               {"core id",     &currentCore->core_id},
  //               {"cpu cores",   &currentCore->cpu_cores}
  //           };

  //       QString line = qts.readLine();
  //       QStringList parts = line.split(':');
  //       if(parts.size() != 2)
  //       {
  //         currentCore = currentCore->next;
  //         continue;
  //       }

  //       QString key      = parts[0].trimmed();
  //       QString strValue = parts[1].trimmed();

  //       if(cpuMap.count(key))
  //         *cpuMap[key] = strValue;
  //     }
  //   }
  //   else
  //   {
  //     size_t value = 0;
  //     while(!qts.atEnd())
  //     {
  //       QString line = qts.readLine();
  //       line.remove(':');

  //       QTextStream linestream(&line);

  //       QString key;

  //       linestream >> key;
  //       if(key == "processor")
  //         linestream >> value;
  //     }
  //     if(value)
  //     {
  //       cpuStat.headCore = new cpu_stat_t::core_stat_t();
  //       cpu_stat_t::core_stat_t *currentCore = cpuStat.headCore;
  //       for(int i = 1; i < value+1; i++)
  //       {
  //         currentCore->next = new cpu_stat_t::core_stat_t();
  //         currentCore = currentCore->next;
  //       }
  //       cpuStat.isAllocated = true;

  //       currentCore = cpuStat.headCore;
  //       while(!qts.atEnd())
  //       {
  //         size_t value = 0;
  //         QMap<QString, QString*> cpuMap
  //             {
  //                 {"processor",   &currentCore->processor},
  //                 {"vendor_id",   &currentCore->vendor_id},
  //                 {"cpu family",  &currentCore->cpu_family},
  //                 {"model",       &currentCore->model},
  //                 {"model name",  &currentCore->model_name},
  //                 {"stepping",    &currentCore->stepping},
  //                 {"cpu MHz",     &currentCore->cpu_MHz},
  //                 {"cache size",  &currentCore->cache_size},
  //                 {"physical id", &currentCore->physical_id},
  //                 {"siblings",    &currentCore->siblings},
  //                 {"core id",     &currentCore->core_id},
  //                 {"cpu cores",   &currentCore->cpu_cores}
  //             };

  //         QString line = qts.readLine();
  //         QStringList parts = line.split(':');
  //         if(parts.size() != 2)
  //         {
  //           currentCore = currentCore->next;
  //           continue;
  //         }

  //         QString key      = parts[0].trimmed();
  //         QString strValue = parts[1].trimmed();

  //         if(cpuMap.count(key))
  //           *cpuMap[key] = strValue;
  //       }
  //     }
  //   }
  //   cpuinfo.close();
  // }
  // else
  //     qDebug() << "File cpuinfo not open";
}

  MemStat *DataReader_L::getMEMstat()
  {
    typedef void (MemStat::*MethodPtr)(size_t);

    if(meminfo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
     QByteArray contents = meminfo.readAll();
     QTextStream qts(&contents);

     QMap<QString, MethodPtr> memMap
         {
             {"MemTotal",   &MemStat::setMemTotal},
             {"MemFree",    &MemStat::setMemFree},
             {"Buffers",    &MemStat::setBuffers},
             {"Cached",     &MemStat::setCached},
             {"SwapTotal",  &MemStat::setSwapTotal},
             {"SwapFree",   &MemStat::setSwapFree},
             {"Active",     &MemStat::setActive},
             {"Inactive",   &MemStat::setInactive},
             {"SwapCached", &MemStat::setSwapCached}
         };

     while(!qts.atEnd())
     {
        QString line = qts.readLine();
        QStringList parts = line.split(':');

        QString key      = parts[0].trimmed();
        QString strValue = parts[1].trimmed();

        if(memMap.count(key))
        {
          MethodPtr method = memMap[key];
          size_t value = strValue.split(' ')[0].trimmed().toULongLong();
          (memStat.*method)(value);
        }
     }

     meminfo.close();
    }
    else
      PRINT("File meminfo not open")

    return &memStat;
  }

CpuStat *DataReader_L::getCPUstat()
{
  if(cpuinfo.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    typedef void (CoreStat::*MethodPtr)(size_t);

    QByteArray contents = cpuinfo.readAll();
    QTextStream qts(&contents);

    CoreStat *currentCore = cpuStat.headCore;
    while(!qts.atEnd())
    {
      size_t value = 0;
      QMap<QString, QString*> cpuMap
      {
          {"processor",   &currentCore->processor},
          {"vendor_id",   &currentCore->vendor_id},
          {"cpu family",  &currentCore->cpu_family},
          {"model",       &currentCore->model},
          {"model name",  &currentCore->model_name},
          {"stepping",    &currentCore->stepping},
          {"cpu MHz",     &currentCore->cpu_MHz},
          {"cache size",  &currentCore->cache_size},
          {"physical id", &currentCore->physical_id},
          {"siblings",    &currentCore->siblings},
          {"core id",     &currentCore->core_id},
          {"cpu cores",   &currentCore->cpu_cores}
      };

      QString line = qts.readLine();
      QStringList parts = line.split(':');
      if(parts.size() != 2)
      {
        currentCore = currentCore->next;
        continue;
      }

      QString key      = parts[0].trimmed();
      QString strValue = parts[1].trimmed();

      if(cpuMap.count(key))
        *cpuMap[key] = strValue;
    }

    cpuinfo.close();
  }
  else
    PRINT("File cpuinfo not open")

  return &cpuStat;
}
