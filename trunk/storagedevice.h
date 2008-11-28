#ifndef STORAGE_H
#define STORAGE_H
#include <QList>
#include <QUuid>
#include "note.h"
#include <QDebug>

class StorageDevice
{
	public:
		StorageDevice(){};
		virtual void saveNote(Note& note)=0;
		virtual Note* loadNote(QUuid id)=0;
		virtual QList<QUuid>& fullTextSearch(QString keyword)=0;
                virtual ~StorageDevice(){}
};

#endif
