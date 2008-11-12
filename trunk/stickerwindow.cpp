#include "stickerwindow.h"
#include <QDebug>

stickerWindow::stickerWindow(QWidget*)
{
    initTrayIcon();
}

void stickerWindow::initTrayIcon()
{
    trayIcon=new QSystemTrayIcon(*(new QIcon("qt_logo.png")), this);
    trayIcon->setToolTip(tr("Nokia StickIt"));
    //TODO: here setup the context menu and connect call back events
    trayIcon->show();
}

void stickerWindow::dressUp()
{
    //TODO: decorate the sticker window
}

void stickerWindow::mousePressEvent(QMouseEvent*)
{
    trayIcon->showMessage("from Mr. Naughty", "Hello I am naughty~", QSystemTrayIcon::Information, 2000);
    qDebug()<<trayIcon->geometry();
}

void stickerWindow::resizeEvent(QResizeEvent*)
{
    if(isMaximized())
        //TODO: here change to the full view, since when the user maximize the window, he/she tends to see more
        qDebug()<<"Change Window Now";
}
