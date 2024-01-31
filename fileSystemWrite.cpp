#include"fileSystemWrite.h"
#include <QtWidgets>

using namespace std;

NewWindow::NewWindow(QWidget* parent)
	:QDialog(parent) {
	ui.setupUi(this);
    initialize();
}
NewWindow::~NewWindow() {

}
void NewWindow::initialize() {
    comboBoxSize = ui.comboBoxSize;
    pushButtonSave = ui.pushButton_save;
    textEdit = ui.TextEdit;

    connect(pushButtonSave, SIGNAL(clicked()), this, SLOT(writeInFile()));
    connect(comboBoxSize, SIGNAL(currentTextChanged(const QString&)), this, SLOT(sizeSetting(const QString&)));
}
void NewWindow::readFile(QString filePath) {
    this->filePath = filePath;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        file.close();
        textEdit->setPlainText(content);
    }
    else {
        qDebug() << "Unable to open the file.";
    }
}

void NewWindow::writeInFile() {
    QString text = textEdit->toPlainText();
    QFile file(this->filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
    else {
        qDebug() << "Unable to open the file for writing.";
    }
    this->showMessage();
}

void NewWindow::showMessage() {
    QMessageBox messagebox;
    messagebox.information(this, "消息提示", "文件保存成功！", messagebox.Ok);
}

void NewWindow::sizeSetting(QString size) {
    qDebug() << "size" << size;
    QFont currentFont = textEdit->font();
    currentFont.setPointSize(size.toInt());
    textEdit->setFont(currentFont);
}
