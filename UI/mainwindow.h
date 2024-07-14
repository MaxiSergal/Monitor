#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>

class MainWindow : public QObject
{
  Q_OBJECT

  public:
    MainWindow(int argc, char *argv[]);
    int run();

  private:
    QGuiApplication app;
    QQmlApplicationEngine engine;
};
#endif // MAINWINDOW_H
