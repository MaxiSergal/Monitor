#ifndef MEMSTAT_H
#define MEMSTAT_H

#include <QObject>

class MemStat : public QObject
{
  Q_OBJECT
  Q_PROPERTY(size_t memTotal READ memTotal WRITE setMemTotal NOTIFY memTotalChanged)
  Q_PROPERTY(size_t memFree READ memFree WRITE setMemFree NOTIFY memFreeChanged)
  Q_PROPERTY(size_t buffers READ buffers WRITE setBuffers NOTIFY buffersChanged)
  Q_PROPERTY(size_t cached READ cached WRITE setCached NOTIFY cachedChanged)
  Q_PROPERTY(size_t swapTotal READ swapTotal WRITE setSwapTotal NOTIFY swapTotalChanged)
  Q_PROPERTY(size_t swapFree READ swapFree WRITE setSwapFree NOTIFY swapFreeChanged)
  Q_PROPERTY(size_t active READ active WRITE setActive NOTIFY activeChanged)
  Q_PROPERTY(size_t inactive READ inactive WRITE setInactive NOTIFY inactiveChanged)
  Q_PROPERTY(size_t swapCached READ swapCached WRITE setSwapCached NOTIFY swapCachedChanged)

public:
  explicit MemStat(QObject *parent = nullptr) : QObject(parent) {}

  size_t memTotal() const { return m_memTotal; }
  void setMemTotal(size_t value) { if (m_memTotal != value) { m_memTotal = value; emit memTotalChanged(); } }

  size_t memFree() const { return m_memFree; }
  void setMemFree(size_t value) { if (m_memFree != value) { m_memFree = value; emit memFreeChanged(); } }

  size_t buffers() const { return m_buffers; }
  void setBuffers(size_t value) { if (m_buffers != value) { m_buffers = value; emit buffersChanged(); } }

  size_t cached() const { return m_cached; }
  void setCached(size_t value) { if (m_cached != value) { m_cached = value; emit cachedChanged(); } }

  size_t swapTotal() const { return m_swapTotal; }
  void setSwapTotal(size_t value) { if (m_swapTotal != value) { m_swapTotal = value; emit swapTotalChanged(); } }

  size_t swapFree() const { return m_swapFree; }
  void setSwapFree(size_t value) { if (m_swapFree != value) { m_swapFree = value; emit swapFreeChanged(); } }

  size_t active() const { return m_active; }
  void setActive(size_t value) { if (m_active != value) { m_active = value; emit activeChanged(); } }

  size_t inactive() const { return m_inactive; }
  void setInactive(size_t value) { if (m_inactive != value) { m_inactive = value; emit inactiveChanged(); } }

  size_t swapCached() const { return m_swapCached; }
  void setSwapCached(size_t value) { if (m_swapCached != value) { m_swapCached = value; emit swapCachedChanged(); } }

signals:
  void memTotalChanged();
  void memFreeChanged();
  void buffersChanged();
  void cachedChanged();
  void swapTotalChanged();
  void swapFreeChanged();
  void activeChanged();
  void inactiveChanged();
  void swapCachedChanged();

private:
  size_t m_memTotal = 0;
  size_t m_memFree = 0;
  size_t m_buffers = 0;
  size_t m_cached = 0;
  size_t m_swapTotal = 0;
  size_t m_swapFree = 0;
  size_t m_active = 0;
  size_t m_inactive = 0;
  size_t m_swapCached = 0;
};

#endif // MEMSTAT_H
