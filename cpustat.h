#ifndef CPUSTAT_H
#define CPUSTAT_H

#include <QObject>
#include <QVector>

class CoreStat : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString processor READ processor WRITE setProcessor NOTIFY processorChanged)
  Q_PROPERTY(QString vendorId READ vendorId WRITE setVendorId NOTIFY vendorIdChanged)
  Q_PROPERTY(QString cpuFamily READ cpuFamily WRITE setCpuFamily NOTIFY cpuFamilyChanged)
  Q_PROPERTY(QString model READ model WRITE setModel NOTIFY modelChanged)
  Q_PROPERTY(QString modelName READ modelName WRITE setModelName NOTIFY modelNameChanged)
  Q_PROPERTY(QString stepping READ stepping WRITE setStepping NOTIFY steppingChanged)
  Q_PROPERTY(QString cpuMHz READ cpuMHz WRITE setCpuMHz NOTIFY cpuMHzChanged)
  Q_PROPERTY(QString cacheSize READ cacheSize WRITE setCacheSize NOTIFY cacheSizeChanged)
  Q_PROPERTY(QString physicalId READ physicalId WRITE setPhysicalId NOTIFY physicalIdChanged)
  Q_PROPERTY(QString siblings READ siblings WRITE setSiblings NOTIFY siblingsChanged)
  Q_PROPERTY(QString coreId READ coreId WRITE setCoreId NOTIFY coreIdChanged)
  Q_PROPERTY(QString cpuCores READ cpuCores WRITE setCpuCores NOTIFY cpuCoresChanged)

  public:
    explicit CoreStat(QObject *parent = nullptr) : QObject(parent) {}

    QString processor() const { return m_processor; }
    void setProcessor(const QString &value) { if (m_processor != value) { m_processor = value; emit processorChanged(); } }

    QString vendorId() const { return m_vendorId; }
    void setVendorId(const QString &value) { if (m_vendorId != value) { m_vendorId = value; emit vendorIdChanged(); } }

    QString cpuFamily() const { return m_cpuFamily; }
    void setCpuFamily(const QString &value) { if (m_cpuFamily != value) { m_cpuFamily = value; emit cpuFamilyChanged(); } }

    QString model() const { return m_model; }
    void setModel(const QString &value) { if (m_model != value) { m_model = value; emit modelChanged(); } }

    QString modelName() const { return m_modelName; }
    void setModelName(const QString &value) { if (m_modelName != value) { m_modelName = value; emit modelNameChanged(); } }

    QString stepping() const { return m_stepping; }
    void setStepping(const QString &value) { if (m_stepping != value) { m_stepping = value; emit steppingChanged(); } }

    QString cpuMHz() const { return m_cpuMHz; }
    void setCpuMHz(const QString &value) { if (m_cpuMHz != value) { m_cpuMHz = value; emit cpuMHzChanged(); } }

    QString cacheSize() const { return m_cacheSize; }
    void setCacheSize(const QString &value) { if (m_cacheSize != value) { m_cacheSize = value; emit cacheSizeChanged(); } }

    QString physicalId() const { return m_physicalId; }
    void setPhysicalId(const QString &value) { if (m_physicalId != value) { m_physicalId = value; emit physicalIdChanged(); } }

    QString siblings() const { return m_siblings; }
    void setSiblings(const QString &value) { if (m_siblings != value) { m_siblings = value; emit siblingsChanged(); } }

    QString coreId() const { return m_coreId; }
    void setCoreId(const QString &value) { if (m_coreId != value) { m_coreId = value; emit coreIdChanged(); } }

    QString cpuCores() const { return m_cpuCores; }
    void setCpuCores(const QString &value) { if (m_cpuCores != value) { m_cpuCores = value; emit cpuCoresChanged(); } }

  signals:
    void processorChanged();
    void vendorIdChanged();
    void cpuFamilyChanged();
    void modelChanged();
    void modelNameChanged();
    void steppingChanged();
    void cpuMHzChanged();
    void cacheSizeChanged();
    void physicalIdChanged();
    void siblingsChanged();
    void coreIdChanged();
    void cpuCoresChanged();

  private:
    QString m_processor;
    QString m_vendorId;
    QString m_cpuFamily;
    QString m_model;
    QString m_modelName;
    QString m_stepping;
    QString m_cpuMHz;
    QString m_cacheSize;
    QString m_physicalId;
    QString m_siblings;
    QString m_coreId;
    QString m_cpuCores;
};

class CpuStat : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QVector<CoreStat*> cores READ cores NOTIFY coresChanged)

  public:
    explicit CpuStat(QObject *parent = nullptr) : QObject(parent) {}

    QVector<CoreStat*> cores() const { return m_cores; }
    void setCores(const QVector<CoreStat*> &value)
    {
      if (m_cores != value)
      {
        m_cores = value;
        emit coresChanged();
      }
    }

    ~CpuStat()
    {
      for(auto &core : m_cores)
      {
        delete core;
      }
    }

  signals:
    void coresChanged();

  private:
    QVector<CoreStat*> m_cores;
};

#endif // CPUSTAT_H
