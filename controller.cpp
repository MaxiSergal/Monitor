#include "controller.h"

Controller::Controller(IDataReader *reader, MainWindow *m_window) : reader(reader), m_window(m_window)
{
  connect(&timer, &QTimer::timeout, this, &Controller::updateData);
  reader->initStat();

  startTimer();
}

void Controller::updateData()
{
  m_window->updateCPUusage(reader->getCPUstat());
  m_window->updateMEMusage(reader->getMEMstat());
  m_window->updateDISKusage(/*reader->getDISKstat()*/);
}

void Controller::startTimer()
{
  timer.start(MS);
  updateData();
}

void Controller::stopTimer()
{
  timer.stop();
}
