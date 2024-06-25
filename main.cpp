#include "UI/mainwindow.h"
#include <QApplication>
#include "datareader.h"

int main(/*int argc, char *argv[]*/)
{
  // QApplication a(argc, argv);
  // MainWindow w;
  // w.show();
  DataReader reader;
  reader.loadFromFile();
  reader.loadFromFile();

  return 0;
}
