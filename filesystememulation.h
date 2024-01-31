#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_filesystememulation.h"
#include "fileSystemWrite.h"

class FileSystemEmulation : public QMainWindow
{
    Q_OBJECT

public:
    FileSystemEmulation(QWidget *parent = nullptr);
    ~FileSystemEmulation();

public slots:
    void DeleteFiles();
    void CreateFiles();
    void readWriteFiles();


private:
    Ui::FileSystemEmulationClass ui;

    NewWindow* newWindow;
    QPushButton* pushButton_New;
    QPushButton* pushButton_Del;
    QPushButton* pushButton_Read;

    void initialize();
    void ButtonConnected();
    
};
