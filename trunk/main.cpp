#include <QApplication>
#include "stickerwindow.h"

int main(int argc, char** argv)
{
    QApplication stickIt(argc, argv);
    stickerWindow win;
    win.show();
/*    Note note;
    note.setContent("Hello note.");
    qDebug()<<note.toXML();
    */
    return stickIt.exec();
}
