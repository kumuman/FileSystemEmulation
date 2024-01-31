#include "filesystememulation.h"
#include <QtWidgets>
#include<fstream>
#include<cstdio>

using namespace std;

FileSystemEmulation::FileSystemEmulation(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initialize();
    ButtonConnected();
    
}

FileSystemEmulation::~FileSystemEmulation()
{
}

void FileSystemEmulation::initialize() {
    pushButton_Del = ui.pushButtonDel;
    pushButton_New = ui.pushButtonNew;
    pushButton_Read = ui.pushButtonReadWrite;
    newWindow = new NewWindow(this);
}

void FileSystemEmulation::ButtonConnected() {
    // 连接按钮的点击事件到槽函数
    bool connected = connect(pushButton_Del, SIGNAL(clicked()), this, SLOT(DeleteFiles()));
    connect(pushButton_New, SIGNAL(clicked()), this, SLOT(CreateFiles()));
    connect(pushButton_Read, SIGNAL(clicked()), this, SLOT(readWriteFiles()));
    qDebug() << "Connection status:" << connected;
}

void FileSystemEmulation::DeleteFiles() {
    qDebug() << "Connect to DeleteFiles";

    // 获取用户选择的文件路径
    QString filePath = QFileDialog::getOpenFileName(this, "选择要删除的文件", QDir::homePath(), "Text Files (*.txt);;All Files (*)");

    if (!filePath.isEmpty()) {
        qDebug() << "选择的文件：" << filePath;

        // 使用 QFile 删除文件
        QFile file(filePath);

        if (file.remove()) {
            qDebug() << "Delete File Successfully";
        }
        else {
            qDebug() << "Delete File Failed!";
        }
    }
}

void FileSystemEmulation::CreateFiles() {
    qDebug() << "Connect to CreateFiles";

    QString filePath = QFileDialog::getSaveFileName(this, "选择文件", QDir::homePath(), "Text Files (*.txt);;All Files (*)");

    if (!filePath.isEmpty()) {
        qDebug() << "选择的文件：" << filePath;

        // 使用 QFile 创建文件
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // 创建 QTextStream 对象，并关联到 QFile
            QTextStream out(&file);
            newWindow->readFile(filePath);
            newWindow->show();
            qDebug() << "Create File Successfully!";

            // 关闭文件
            file.close();
        }
        else {
            qDebug() << "Create File Failed!";
        }
    }
}

void FileSystemEmulation::readWriteFiles() {
    qDebug() << "Connect to ReadFiles";
    QString filePath = QFileDialog::getOpenFileName(this, "选择文件", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    if (!filePath.isEmpty()) {
        newWindow->readFile(filePath);
        newWindow->show();
    }
    else {
        // 用户取消了文件选择或发生了其他错误
        qDebug() << "选择文件操作已取消或发生错误。";
    }
}

