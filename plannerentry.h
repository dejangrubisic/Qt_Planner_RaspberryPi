#ifndef PLANNERENTRY_H
#define PLANNERENTRY_H

#include <QObject>
#include <QString>
#include <QTime>
#include <QDate>
#include <QDebug>

class PlannerEntry : public QObject
{
    Q_OBJECT
    //ime getter metod-isto ime kao i Property, setter metod, signal ==> sluzi za
    Q_PROPERTY(QString getStr6_9 READ getStr6_9 WRITE setStr_6_9 NOTIFY str_6_9Changed)
    Q_PROPERTY(QString getStr9_12 READ getStr9_12 WRITE setStr_9_12 NOTIFY str_9_12Changed)
    Q_PROPERTY(QString getStr12_15 READ getStr12_15 WRITE setStr_12_15 NOTIFY str_12_15Changed)
    Q_PROPERTY(QString getStr15_18 READ getStr15_18 WRITE setStr_15_18 NOTIFY str_15_18Changed)
    Q_PROPERTY(QString getStr18_21 READ getStr18_21 WRITE setStr_18_21 NOTIFY str_18_21Changed)
    Q_PROPERTY(QString getStr21_24 READ getStr21_24 WRITE setStr_21_24 NOTIFY str_21_24Changed)
    Q_PROPERTY(QTime getReminder READ getReminder WRITE setReminder NOTIFY reminderChanged)
    Q_PROPERTY(bool getReminder_activated READ getReminder_activated WRITE setReminder_activated NOTIFY reminder_activatedChanged)
    Q_PROPERTY(QDate getDate READ getDate WRITE setDate NOTIFY DateChanged)
public:
    explicit PlannerEntry(QObject *parent = 0);
    ~PlannerEntry();

    QString getStr6_9() const;
    void setStr_6_9(const QString &value);

    QString getStr9_12() const;
    void setStr_9_12(const QString &value);

    QString getStr12_15() const;
    void setStr_12_15(const QString &value);

    QString getStr15_18() const;
    void setStr_15_18(const QString &value);

    QString getStr18_21() const;
    void setStr_18_21(const QString &value);

    QString getStr21_24() const;
    void setStr_21_24(const QString &value);

    QDate getDate() const;
    void setDate(const QDate &value);

    QTime getReminder() const;
    void setReminder(const QTime &value);

    bool getReminder_activated() const;
    void setReminder_activated(bool value);

signals:
    void DateChanged();
    void reminderChanged();
    void reminder_activatedChanged();

    void str_6_9Changed();
    void str_9_12Changed();
    void str_12_15Changed();
    void str_15_18Changed();
    void str_18_21Changed();
    void str_21_24Changed();

public slots:

private:
    QString str_6_9;
    QString str_9_12;
    QString str_12_15;
    QString str_15_18;
    QString str_18_21;
    QString str_21_24;

    QDate date;
    QTime reminder;
    bool reminder_activated;
};

#endif // PLANNERENTRY_H
