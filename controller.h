#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "UI/mainwindow.h"
#include "idatareader.h"

class Controller : public QObject
{
  Q_OBJECT

  public:
    Controller(IDataReader *reader, MainWindow *m_window);

  public slots:
    void updateData();

  private:
    IDataReader *reader;
    MainWindow  *m_window;
    QTimer       timer;

    void startTimer();
    void stopTimer();

    const size_t MS = 5000;
};

#endif // CONTROLLER_H
