#ifndef DATAREADER_H
#define DATAREADER_H

#include <QString>

class DataReader
{

  struct mem_stat_t
  {
    size_t MemTotal;
    size_t MemFree;
    size_t Buffers;
    size_t Cached;
    size_t SwapTotal;
    size_t SwapFree;
    size_t Active;
    size_t Inactive;
    size_t SwapCached;
  } memStat;

  struct cpu_stat_t
  {
    struct core_stat_t
    {
      QString processor;
      QString vendor_id;
      QString cpu_family;
      QString model;
      QString model_name;
      QString stepping;
      QString cpu_MHz;
      QString cache_size;
      QString physical_id;
      QString siblings;
      QString core_id;
      QString cpu_cores;

      core_stat_t *next = nullptr;
    };

    core_stat_t *headCore = nullptr;
    bool isAllocated = false;

    ~cpu_stat_t()
    {
      while(headCore)
      {
        core_stat_t *tmpCore = headCore;
        headCore = headCore->next;
        delete tmpCore;
      }
    };

  } cpuStat;

  public:
    DataReader();
    void loadFromFile();

  private:
    QString path {"/proc"};

};

#endif // DATAREADER_H
