#include "planner.h"

Planner::Planner(QObject *parent) : QObject(parent)
{

}

Planner::Enteries Planner::getEnteries() const
{
    return enteries;
}

PlannerEntry *Planner::createEntry()
{
    auto result = new PlannerEntry( this ); //this - parent od PlannerEntry sto je Planner i kad se Planner obrise svi child se brisu

    if( result != nullptr)
    {
        enteries.append( result );
        emit entryAdded( result );
    }
    return result;
}

bool Planner::deleteEntry(PlannerEntry *entry)
{
    if(enteries.contains( entry ))
    {
        emit entryRemoved( entry );
        enteries.removeOne( entry );
        delete entry;

        return true;
    }

    return false;
}
