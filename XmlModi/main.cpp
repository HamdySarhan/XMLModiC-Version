#include "XmlModi.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XmlModi w;
    w.show();
    return a.exec();
}
