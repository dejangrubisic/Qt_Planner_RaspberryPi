#include "plannerentry.h"

PlannerEntry::PlannerEntry(QObject *parent) : QObject(parent)
{

}

PlannerEntry::~PlannerEntry()
{

}

QString PlannerEntry::getStr6_9() const
{
    return str_6_9;
}

void PlannerEntry::setStr_6_9(const QString &value)
{
    if(str_6_9 != value)
    {
        str_6_9 = value;
        emit str_6_9Changed();
    }

}

QString PlannerEntry::getStr9_12() const
{
    return str_9_12;
}

void PlannerEntry::setStr_9_12(const QString &value)
{
    if(str_9_12 != value)
    {
        str_9_12 = value;
        emit str_9_12Changed();
    }
}

QString PlannerEntry::getStr12_15() const
{
    return str_12_15;
}

void PlannerEntry::setStr_12_15(const QString &value)
{
    if(str_12_15 != value)
    {
        str_12_15 = value;
        emit str_12_15Changed();
    }
}

QString PlannerEntry::getStr15_18() const
{
    return str_15_18;
}

void PlannerEntry::setStr_15_18(const QString &value)
{
    if(str_15_18 != value)
    {
        str_15_18 = value;
        emit str_15_18Changed();
    }
}

QString PlannerEntry::getStr18_21() const
{
    return str_18_21;
}

void PlannerEntry::setStr_18_21(const QString &value)
{
    if(str_18_21 != value)
    {
        str_18_21 = value;
        emit str_18_21Changed();
    }
}

QString PlannerEntry::getStr21_24() const
{
    return str_21_24;
}

void PlannerEntry::setStr_21_24(const QString &value)
{
    if(str_21_24 != value)
    {
        str_21_24 = value;
        emit str_21_24Changed();
    }
}

QDate PlannerEntry::getDate() const
{
    return date;
}

void PlannerEntry::setDate(const QDate &value)
{
    if(date != value)
    {
        date = value;
        emit DateChanged();
    }

}

QTime PlannerEntry::getReminder() const
{
    return reminder;
}

void PlannerEntry::setReminder(const QTime &value)
{
    if(reminder != value)
    {
        reminder = value;
        emit reminderChanged();
    }

}

bool PlannerEntry::getReminder_activated() const
{
    return reminder_activated;
}

void PlannerEntry::setReminder_activated(bool value)
{
    if(reminder_activated != value)
    {
        reminder_activated = value;
        emit reminder_activatedChanged();
    }

}


