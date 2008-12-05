#ifndef LOCALDISK
#define LOCALDISK
#include "storagedevice.h"

class LocalDisk
{
    public:
        LocalDisk(QString fileName)
        {
            m_fileName=fileName;
            doc=new QDomDocument();
            QFile file(m_fileName);
            if (!file.open(QIODevice::ReadOnly))
                return;
            if(!doc->setContent(&file))
            {
                file.close();
                return;
            }
            notes=doc->elementsByTagName("note");
            file.close();
        }
        void saveNote(Note& note)
        {
            qDebug()<<"saving note";
            QDomElement newChild=doc->createElement("note");
            newChild.setAttribute("id", note.id.toString());
            newChild.appendChild(doc->createTextNode(note.toXML()));
            int p=findNote(note.id);
            if(p!=-1)
            {
                doc->documentElement().replaceChild(newChild, notes.item(p));
            }
            else
            {
                doc->documentElement().appendChild(newChild);
            }
            notes=doc->elementsByTagName("note");
            QFile file(m_fileName);
            if (!file.open(QIODevice::WriteOnly))
                return;
            QTextStream stream(&file);
            doc->save(stream,2);
            file.close();
        }
        Note* loadNote(QUuid id)
        {
            Note* note=new Note(id);
            int p=findNote(id);
            if(p==-1)
                return NULL;
            note->fromXML(notes.item(p).toElement().text());
        }
        QList<QUuid>& fullTextSearch(QString keyword)
        {
            QList<QUuid>* ids=new QList<QUuid>();
            for(int i=0;i<notes.count();i++)
            {
                if(notes.item(i).toElement().text().contains(keyword))
                    (*ids)<<notes.item(i).toElement().attribute("id");
            }
            return *ids;
        }
        ~LocalDisk()
        {
            delete doc;
        }
    private:
        QString m_fileName;
        QDomDocument* doc;
        QDomNodeList notes;
        int findNote(QUuid id)
        {
            for(int i=0;i<notes.count();i++)
            {
                if(notes.item(i).toElement().attribute("id")==id.toString())
                {
                    return i;
                }
            }
            return -1;
        }
};
#endif
