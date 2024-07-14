#include "UI/mainwindow.h"
#include "datareader_l.h"


int main(int argc, char *argv[])
{
  MainWindow mainWindow(argc, argv);
  DataReader_L reader;
  // reader.initStat();
  // reader.updateStat();
  // reader.printMemStat();
  // reader.printCpuStat();

  return mainWindow.run();
}
