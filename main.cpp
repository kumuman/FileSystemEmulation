#include "filesystememulation.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileSystemEmulation w;
    w.show();
    return a.exec();
}
