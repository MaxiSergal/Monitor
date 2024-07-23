#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "structs.h"

class MainWindow : public QObject
{
  Q_OBJECT

  public:
    MainWindow(int argc, char *argv[]);
    int run();

    void updateCPUusage(cpu_stat_t *cpuStat);
    void updateMEMusage(mem_stat_t *memStat);
    void updateDISKusage(/*disk_stat_t * diskStat*/);

  private:
    QGuiApplication app;
    QQmlApplicationEngine engine;

};
#endif // MAINWINDOW_H
