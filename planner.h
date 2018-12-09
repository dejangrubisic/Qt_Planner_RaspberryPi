#ifndef PLANNER_H
#define PLANNER_H

#include "plannerentry.h"

#include <QObject>
#include <QList>
class Planner : public QObject
{
    Q_OBJECT
public:
    typedef QList<PlannerEntry*> Enteries;

    explicit Planner(QObject *parent = 0);

    Enteries getEnteries() const;

    PlannerEntry* createEntry();
    bool deleteEntry( PlannerEntry *entry );

signals:

    void entryAdded( PlannerEntry *entry);
    void entryRemoved(PlannerEntry *entry );

public slots:

private:

    Enteries enteries;
};

#endif // PLANNER_H
