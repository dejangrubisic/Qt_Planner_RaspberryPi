#ifndef PLANNERCONTROLLER_H
#define PLANNERCONTROLLER_H

#include "planner.h"

#include <QObject>

class PlannerController : public QObject
{
    Q_OBJECT
public:
    explicit PlannerController(Planner *planner, QObject *parent = 0);

    PlannerEntry * createEntry();
    bool deleteEntry( PlannerEntry *entry );
signals:

public slots:

private:
    Planner *planner;
};

#endif // PLANNERCONTROLLER_H
