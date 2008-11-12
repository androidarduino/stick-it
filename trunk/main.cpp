#include <QApplication>
#include "stickerwindow.h"

int main(int argc, char** argv)
{
    QApplication stickIt(argc, argv);
    stickerWindow win;
    win.show();
    return stickIt.exec();
}
