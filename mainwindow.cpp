#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QHashIterator>
#include <QColor>

MainWindow::MainWindow(PlannerController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller( controller )
{
    ui->setupUi(this);

    clickedDate = ( ui->calendar->selectedDate() ); //ovo bi trebao da bude na pocetku i current date

    setupConnections();
    ui->stackedWidget->setCurrentWidget( ui->calendarPage );
    ui->menuNew_Activities->setEnabled( true );

    //postavi pozadinu
/*    QPixmap bkgnd("/home/pi/Desktop/Planercopy/Planer/slikeCalendar/2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printOnCalendarPage(PlannerEntry *entry )
{
    ui->listWidget->clear();
    for(int i=0; i<6; i++)
    {
        switch(i)
        {
        case 0:    if(entry->getStr6_9() != "Add new activity...")
                   {
                        ui->listWidget->addItem("6h - 9h: ");
                        ui->listWidget->addItem( entry->getStr6_9() );
                   }
                   break;
        case 1:    if(entry->getStr9_12() != "Add new activity...")
                   {
                        ui->listWidget->addItem("9h - 12h: ");
                        ui->listWidget->addItem( entry->getStr9_12() );
                   }
                   break;
        case 2:    if(entry->getStr12_15() != "Add new activity...")
                   {
                        ui->listWidget->addItem("12h - 15h: ");
                        ui->listWidget->addItem( entry->getStr12_15() );
                   }
                   break;
        case 3:    if(entry->getStr15_18() != "Add new activity...")
                   {
                        ui->listWidget->addItem("15h - 18h: ");
                        ui->listWidget->addItem( entry->getStr15_18() );
                   }
                   break;
        case 4:    if(entry->getStr18_21() != "Add new activity...")
                   {
                        ui->listWidget->addItem("18h - 21h: ");
                        ui->listWidget->addItem( entry->getStr18_21() );
                   }
                   break;
        case 5:    if(entry->getStr21_24() != "Add new activity...")
                   {
                        ui->listWidget->addItem("21h - 24h: ");
                        ui->listWidget->addItem( entry->getStr21_24() );
                   }
                   break;
        }
    }
}

void MainWindow::selectDate()
{

    if(clickedDate != (ui->calendar->selectedDate() ) )
    {
        clickedDate = (ui->calendar->selectedDate() );


        //qDebug() << (ui->calendar->selectedDate().toString("dd.MM.yyyy") ) ;

        if( entryMap.contains(clickedDate) )
        {
            //qDebug() << clickedDate.toString("dd.MM.yyyy");

            printOnCalendarPage(entryMap.value(clickedDate));
        }
        else
        {
            ui->listWidget->clear();
        }
    }
}

void MainWindow::createEntry()
{
    auto entry = controller->createEntry();
    if( entry )
    {
        entry->setDate( clickedDate ); //sad i hash i entry imaju date al nema veze popravicu kasnije
        //ispis u listWidget treba da ide tak kad se klikne Save //
        //ui->listWidget->addItem( entry->getStr6_9() );

        ui->stackedWidget->setCurrentWidget( ui->activityPage );
        ui->menuNew_Activities->setEnabled( false );

        ui->text6_9->setPlainText( entry->getStr6_9() );
        ui->text9_12->setPlainText( entry->getStr9_12() );
        ui->text12_15->setPlainText( entry->getStr12_15() );
        ui->text15_18->setPlainText( entry->getStr15_18() );
        ui->text18_21->setPlainText( entry->getStr18_21() );
        ui->text21_24->setPlainText( entry->getStr21_24() );

        ui->alarm_chech_box->setChecked( entry->getReminder_activated() );
        ui->alarm_time->setTime(entry->getReminder() );


        entryMap.insert(clickedDate, entry);
    }
}

void MainWindow::deleteEntry()
{
    auto entry = entryMap.value( clickedDate );
    if(entry)
    {
        if(controller->deleteEntry(entry) )
        {
            entryMap.remove( clickedDate );
            ui->listWidget->clear();

            //obrisi okvir oko dana
            QTextCharFormat highLightDay;
            QColor color(252, 233, 79);
            highLightDay.setBackground(color);
            ui->calendar->setDateTextFormat(clickedDate, highLightDay);
        }
    }
}

void MainWindow::editEntry()
{
    auto entry = entryMap.value( clickedDate );
    if(entry)
    {
        ui->stackedWidget->setCurrentWidget( ui->activityPage );
        ui->menuNew_Activities->setEnabled( false );

        resetEntry();
    }
}

void MainWindow::saveEntry()
{
    auto entry = entryMap.value( clickedDate );
    if(entry)
    {
        entry->setStr_6_9( ui->text6_9->toPlainText() );
        entry->setStr_9_12( ui->text9_12->toPlainText() );
        entry->setStr_12_15( ui->text12_15->toPlainText() );
        entry->setStr_15_18( ui->text15_18->toPlainText() );
        entry->setStr_18_21( ui->text18_21->toPlainText() );
        entry->setStr_21_24( ui->text21_24->toPlainText() );

        entry->setReminder_activated( ui->alarm_chech_box->isChecked());
        entry->setReminder(ui->alarm_time->time() );

        printOnCalendarPage(entryMap.value(clickedDate));
        //qDebug() << "SAVE: alarm set, time: " << (ui->alarm_time->time());

        //Oznaci dan koji kliknes
        QTextCharFormat highLightDay;
        highLightDay.setBackground(Qt::yellow);
        ui->calendar->setDateTextFormat(clickedDate, highLightDay);

        cancelEntry();

    }

}

void MainWindow::cancelEntry()
{
    ui->stackedWidget->setCurrentWidget( ui->calendarPage );
    ui->menuNew_Activities->setEnabled( true );
}

void MainWindow::resetEntry()
{
    auto entry = entryMap.value( clickedDate );
    if(entry)
    {
        ui->text6_9->setPlainText( entry->getStr6_9() );
        ui->text9_12->setPlainText( entry->getStr9_12() );
        ui->text12_15->setPlainText( entry->getStr12_15() );
        ui->text15_18->setPlainText( entry->getStr15_18() );
        ui->text18_21->setPlainText( entry->getStr18_21() );
        ui->text21_24->setPlainText( entry->getStr21_24() );

        ui->alarm_chech_box->setChecked( entry->getReminder_activated() );
        ui->alarm_time->setTime(entry->getReminder() );

        //qDebug() << "alarm set, time: " << (ui->alarm_time->time());

    }
}

void MainWindow::checkAlarm()
{
    QHashIterator<QDate, PlannerEntry*> i(entryMap);
    i.toFront();
    //qDebug()<<"Current date = "<<QDateTime::currentDateTime().date()
    //       <<"time = "<< QDateTime::currentDateTime().time();
    //qDebug()<<"i.hasNext = "<< i.hasNext();

    while( i.hasNext() )
    {
        i.next();
        //qDebug()<<"My date = "<< i.value()->getDate()<<
        //          "My time = "<< i.value()->getReminder()<<
        //          "Remainder activated = "<< i.value()->getReminder_activated();

       if( i.value()->getDate() == QDateTime::currentDateTime().date() &&
            i.value()->getReminder_activated() == true )
            if( i.value()->getReminder().hour() == QDateTime::currentDateTime().time().hour() &&
                i.value()->getReminder().minute() == QDateTime::currentDateTime().time().minute() &&
                i.value()->getReminder().second() == QDateTime::currentDateTime().time().second() )
                QMessageBox::information(this,"","You have sheduled activity \n",QMessageBox::Ok );

    }

}

void MainWindow::setupConnections()
{
    //ko salje, signal, kome salje, slot
    connect( ui->calendar, SIGNAL(clicked(QDate)),
             this, SLOT(selectDate()) );

    connect( ui->actionAdd, &QAction::triggered,
             this, &MainWindow::createEntry );

    connect(ui->actionRemove, &QAction::triggered,
            this, &MainWindow::deleteEntry);

    connect(ui->actionEdit, &QAction::triggered,
            this, &MainWindow::editEntry );

    //Dugmici: Save, Cancel, Reset
    connect(ui->buttonBox->button( QDialogButtonBox::Save ), &QPushButton::clicked,
            this, &MainWindow::saveEntry);

    connect(ui->buttonBox->button( QDialogButtonBox::Cancel ), &QPushButton::clicked,
            this, &MainWindow::cancelEntry);

    connect(ui->buttonBox->button( QDialogButtonBox::Reset ), &QPushButton::clicked,
            this, &MainWindow::resetEntry);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout() ), this, SLOT(checkAlarm() ) );
    timer->start(1000);

    //QTimer::singleShot(1000, this, SLOT(checkAlarm));

}
