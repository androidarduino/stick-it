#include "stickerwindow.h"
#include <QDebug>
#include "localdiskstorage.h"

stickerWindow::stickerWindow(QWidget* parent):QTextEdit(parent)
{
    initTrayIcon();
    connect(this, SIGNAL(textChanged()), this, SLOT(updateText()));
    LocalDisk* disk=new LocalDisk("diskstorage.xml");
    storageList["disk"]=(StorageDevice*)disk;
    note=new Note();
}

void stickerWindow::initTrayIcon()
{
    trayIcon=new QSystemTrayIcon(*(new QIcon("qt_logo.png")), this);
    trayIcon->setToolTip(tr("Nokia StickIt"));
    //TODO: here setup the context menu and connect call back events
    trayIcon->show();
}

void stickerWindow::updateText()
{
    note->setContent(toPlainText());
}

void stickerWindow::dressUp()
{
    //TODO: decorate the sticker window
}

void stickerWindow::mousePressEvent(QMouseEvent* event)
{
    trayIcon->showMessage("from Mr. Naughty", "Hello I am naughty~", QSystemTrayIcon::Information, 2000);
    qDebug()<<trayIcon->geometry();
    QTextEdit::mousePressEvent(event);
}

void stickerWindow::resizeEvent(QResizeEvent* event)
{
    if(isMaximized())
        //TODO: here change to the full view, since when the user maximize the window, he/she tends to see more
        qDebug()<<"Change Window Now";
    QTextEdit::resizeEvent(event);
}

void stickerWindow::closeEvent(QCloseEvent* event)
{
    qDebug()<<"close event received";
    saveContent();
    QTextEdit::closeEvent(event);
}

void stickerWindow::saveContent()
{
    //TODO: according to the note type, automatically select the primary storage and save to the storage
    qDebug()<<"saving content on exiting...";
    LocalDisk* p=(LocalDisk*)storageList["disk"];
    p->saveNote(*note);
}
