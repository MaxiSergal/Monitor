// #include "UI/mainwindow.h"
// #include "datareader.h"

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine("qml/content/App.qml");

  // QApplication a(argc, argv);
  // MainWindow w;
  // w.show();
  // DataReader reader;
  // reader.loadFromFile();
  // reader.loadFromFile();

  return app.exec();
}
