#include "mainwindow.h"

MainWindow::MainWindow(int argc, char *argv[]) : app(argc, argv), engine()
{
  engine.load(QUrl(QStringLiteral("qml/content/App.qml")));
  if (engine.rootObjects().isEmpty())
    QCoreApplication::exit(-1);
}

int MainWindow::run()
{
  return app.exec();
}

void MainWindow::updateCPUusage(cpu_stat_t *cpuStat)
{

}

void MainWindow::updateMEMusage(mem_stat_t *memStat)
{

}

void MainWindow::updateDISKusage(/*disk_stat_t * diskStat*/)
{

}
