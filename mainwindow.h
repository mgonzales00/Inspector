#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <Windows.h>
#include <TlHelp32.h> //WinAPI Process API
#include "PE32.h"

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

    void on_actionToggleDarkMode_triggered();

private:
    Ui::MainWindow *ui;
    QString architecture;
    QString fileName; 
    bool darkModeOn = 1;
    PE32 pe32Image;

    void AddTableRow(QTableWidget* table, int row, int column, unsigned long long value, size_t offset, size_t size);
    void ParseImage32(LPVOID imageBase);   
    void ParseImage64(LPVOID imageBase);
    void DisplayImage32();
    void DisplayImage64();
    void DisplayDOSHeader();
    void DisplayNTHeaders();
    void DisplayFileHeader();
    void DisplayOptionalHeader();
    void DisplaySectionHeader();
    void DisplayDataDirectories();
    void DisplaySections();
    void DisplayImports();
    void SetDarkMode();
    void SetLightMode();
};
#endif // MAINWINDOW_H
