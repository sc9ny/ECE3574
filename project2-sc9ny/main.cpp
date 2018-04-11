#include "qinstrument.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *b = new QWidget;
    QInstrument qinstrument(b);

    qinstrument.show();

    return a.exec();
}
