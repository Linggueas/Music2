#include "Music2.h"
#include <QtWidgets/QApplication>
#include"../addMusic/addMusic.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Music2 window;
    window.show();
    return app.exec();
}
