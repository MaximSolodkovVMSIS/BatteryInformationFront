#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sleepButton_clicked();

    void on_hidernateButton_clicked();

    void on_exitButton_clicked();

    void checkFileUpdates();

private:
    Ui::MainWindow *ui;
    QString lastFileContent;
};
#endif // MAINWINDOW_H
