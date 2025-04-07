#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <Windows.h>
#include <TlHelp32.h> //WinAPI Process API

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
    void on_actionOpenFile_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString architecture;
    QString fileName;

    void Debug(QString title, QString text);
    void ParseImage32(LPVOID imageBase);
    void ParseImage64(LPVOID imageBase);
};
#endif // MAINWINDOW_H
