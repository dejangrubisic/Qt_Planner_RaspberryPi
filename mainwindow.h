#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "plannercontroller.h"

#include <QMainWindow>
#include <QHash>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(PlannerController *controller, QWidget *parent = 0);
    ~MainWindow();

    void printOnCalendarPage( PlannerEntry *entry);

public slots:
    void selectDate();

    void createEntry();
    void deleteEntry();
    void editEntry();
    void saveEntry();
    void cancelEntry();
    void resetEntry();
    void checkAlarm();

private:
    Ui::MainWindow *ui;
    PlannerController *controller;

    QDate clickedDate;
    QHash<QDate, PlannerEntry*> entryMap;

    void setupConnections();
};

#endif // MAINWINDOW_H
