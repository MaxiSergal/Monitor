#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>

class DataReader;
class MainWindow;

class Controller : public QObject
{
  Q_OBJECT
  public:
    Controller(DataReader *reader, MainWindow *m_window);

  public slots:
    void updateData() {};

  private:
    DataReader *reader;
    MainWindow *m_window;
    QTimer     *timer;
};

#endif // CONTROLLER_H
