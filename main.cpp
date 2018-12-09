#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Planner planner;
    PlannerController controller( &planner );
    MainWindow w( &controller );

    w.show();

    return a.exec();
}
