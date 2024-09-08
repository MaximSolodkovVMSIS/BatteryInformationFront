#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <windows.h>
#include <powrprof.h>
#include <QTimer>
#include <QFile>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fileDisplayTextEdit->setReadOnly(true);

    lastFileContent = "";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkFileUpdates);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkFileUpdates() {
    QString filePath = "D:/AStydy/IiYVMqt/battery_info.txt";
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();

        if(fileContent != lastFileContent) {
            lastFileContent = fileContent;

            ui->fileDisplayTextEdit->setPlainText(fileContent);
        }
    }
    else {
        ui->fileDisplayTextEdit->setPlainText("Failed to open file");
    }
}

void MainWindow::on_sleepButton_clicked()
{
    SetSuspendState(FALSE, FALSE, FALSE);
}

void MainWindow::on_hidernateButton_clicked()
{
    SetSuspendState(TRUE, FALSE, FALSE);
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}
