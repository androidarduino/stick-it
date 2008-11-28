#include "note.h"

Note::Note(QUuid p_id)
{
    if(p_id==0)
        id=id.createUuid();
    else
	id=p_id;
}

void Note::setContent(QString text)
{
    content=text;
}

Note::~Note()
{

}

void Note::appendProperty(QString name, QString value)
{
    QDomElement property=doc.createElement(name);
    QDomText text=doc.createTextNode(value);
    property.appendChild(text);
    doc.documentElement().appendChild(property);
}

QString Note::toXML()
{
    doc.setContent(QString(""));
    QDomElement root=doc.createElement("note");
    doc.appendChild(root);
    appendProperty("uid", id.toString());
    appendProperty("dateCreated", dateCreated.toString("dd-MM-yy hh:mm:ss"));
    appendProperty("dateModified", dateCreated.toString("dd-MM-yy hh:mm:ss"));
    appendProperty("content", content);
    NoteLabel label;
    foreach(label, labels)
    {
        QDomElement element=doc.createElement("label");
        QDomText text=doc.createTextNode(label.serialize());
        element.appendChild(text);
        doc.documentElement().appendChild(element);
    }
    return doc.toString(2);
}

bool Note::fromXML(QString xml)
{
    doc.setContent(xml);
    labels.clear();
    QUuid newId(doc.elementsByTagName("uid").item(0).toElement().text());
    id=newId;
    dateCreated=QDateTime::fromString(doc.elementsByTagName("dateCreated").item(0).toElement().text());
    dateModified=QDateTime::fromString(doc.elementsByTagName("dateModified").item(0).toElement().text());
    content=doc.elementsByTagName("content").item(0).toElement().text();
    //now process the labels
    QDomNodeList nodeLabels=doc.elementsByTagName("label");
    for(int i=0;i<nodeLabels.count();i++)
    {
        //TODO: labels<<labelFactory::createLableFromElement(nodeLabels.item(i));
    }
    return true;
}

bool Note::addLabel(NoteLabel& label)
{
    labels<<label;
    return true;
}

bool Note::removeLabel(NoteLabel&)// label)
{
    //TODO: whether this is useful?
    return true;
}
