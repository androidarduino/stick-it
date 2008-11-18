#ifndef STORAGE_H
#define STORAGE_H
#include <QList>
#include <QUuid>
#include "note.h"

class StorageDevice
{
	public:
		StorageDevice();
		virtual void saveNote(Note& note)=0;
		virtual Note& loadNote(QUuid id)=0;
		virtual QList<QUuid> fullTextSearch(QString keyword)=0;
};

#endif