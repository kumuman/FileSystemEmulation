#pragma once
// newwindow.h

#include <QtWidgets/QDialog>
#include "ui_fileSystemWrite.h"

class NewWindow : public QDialog
{
    Q_OBJECT

public slots:
    void writeInFile();
    void sizeSetting(QString size);

public:
    explicit NewWindow(QWidget* parent = nullptr);
    void readFile(QString filePath);
    QString filePath;
    ~NewWindow();

private:
    Ui::FileWrite ui;

    QPlainTextEdit* textEdit;
    QPushButton* pushButtonSave;
    QComboBox* comboBoxSize;


    void initialize();
    void showMessage();
};

