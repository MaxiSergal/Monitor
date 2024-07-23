#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <iostream>

struct mem_stat_t
{
  size_t MemTotal   = 0;
  size_t MemFree    = 0;
  size_t Buffers    = 0;
  size_t Cached     = 0;
  size_t SwapTotal  = 0;
  size_t SwapFree   = 0;
  size_t Active     = 0;
  size_t Inactive   = 0;
  size_t SwapCached = 0;

  friend std::ostream& operator<<(std::ostream &os, const mem_stat_t &stat)
  {
    os << "MemTotal: "   << stat.MemTotal  << '\n'
       << "MemFree: "    << stat.MemFree   << '\n'
       << "Buffers: "    << stat.Buffers   << '\n'
       << "Cached: "     << stat.Cached    << '\n'
       << "SwapTotal: "  << stat.SwapTotal << '\n'
       << "SwapFree: "   << stat.SwapFree  << '\n'
       << "Active: "     << stat.Active    << '\n'
       << "Inactive: "   << stat.Inactive  << '\n'
       << "SwapCached: " << stat.SwapCached;
    return os;
  }
};

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

  friend std::ostream& operator<<(std::ostream &os, const cpu_stat_t &stat)
  {
    cpu_stat_t::core_stat_t *current = stat.headCore;
    while(current)
    {
      os << "processor: "   << current->processor.toStdString()   << '\n'
         << "vendor_id: "   << current->vendor_id.toStdString()   << '\n'
         << "cpu_family: "  << current->cpu_family.toStdString()  << '\n'
         << "model: "       << current->model.toStdString()       << '\n'
         << "model_name: "  << current->model_name.toStdString()  << '\n'
         << "stepping: "    << current->stepping.toStdString()    << '\n'
         << "cpu_MHz: "     << current->cpu_MHz.toStdString()     << '\n'
         << "cache_size: "  << current->cache_size.toStdString()  << '\n'
         << "physical_id: " << current->physical_id.toStdString() << '\n'
         << "siblings: "    << current->siblings.toStdString()    << '\n'
         << "core_id: "     << current->core_id.toStdString()     << '\n'
         << "cpu_cores: "   << current->cpu_cores.toStdString()   << '\n';
      current = current->next;
    }

    return os;
  }
};

#endif // STRUCTS_H
