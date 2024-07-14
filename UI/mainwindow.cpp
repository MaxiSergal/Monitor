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
