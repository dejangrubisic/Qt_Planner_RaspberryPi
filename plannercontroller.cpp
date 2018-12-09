#include "plannercontroller.h"

PlannerController::PlannerController(Planner *planner, QObject *parent) :
    QObject(parent),
    planner( planner)
{

}

PlannerEntry *PlannerController::createEntry()
{
    auto result = planner->createEntry();
    if( result != nullptr )
    {
        //result->setDate( date );
        QTime time;
        time.setHMS(0,0,0);
        result->setReminder(time);
        result->setReminder_activated( false );
        result->setStr_6_9("Add new activity...");
        result->setStr_9_12("Add new activity...");
        result->setStr_12_15("Add new activity...");
        result->setStr_15_18("Add new activity...");
        result->setStr_18_21("Add new activity...");
        result->setStr_21_24("Add new activity...");
    }
    return result;
}

bool PlannerController::deleteEntry(PlannerEntry *entry)
{
    return planner->deleteEntry( entry );
}
