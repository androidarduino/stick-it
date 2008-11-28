#ifndef STICKERWINDOW
#define STICKERWINDOW
#include <QtGui>
#include <QSystemTrayIcon>
#include "note.h"
#include "storagedevice.h"

class stickerWindow : public QTextEdit
{
    Q_OBJECT
    public:
        stickerWindow(QWidget* parent=0);
    protected:
        void mousePressEvent(QMouseEvent* event);//temp here for testing, don't know whether we need it in the future
        void resizeEvent(QResizeEvent* event);//swich the windows when maximized
        void closeEvent(QCloseEvent * event);//save changes when exiting
    private:
        void initTrayIcon();//set the tray icon and its context menu things
        void dressUp();//decorate the window
    private slots:
        void saveContent();//save the contents in the sticker
        void updateText();
    private:
        QSystemTrayIcon * trayIcon;
        Note* note;
        QMap<QString, StorageDevice*> storageList;
        //TODO: void analyzeText();
};

#endif //STICKERWINDOW
