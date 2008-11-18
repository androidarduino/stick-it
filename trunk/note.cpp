#include "note.h"

Note::Note()
{
    id=id::createUuid();
}

Note::Note(QUuid p_id)
{
	id=p_id;
	//search the perminent storage for note with this id
}

Note::~Note()
{

}

void Note::appendProperty(QString name, QString value)
{
    QDomElement property=doc.createElement(name);
    QDomText text=doc.createTextNode(value);
    property.appendChild(text);
    doc.documentElement.appendChild(property);
}

QString Note::toXML()
{
    doc.setContent("");
    QDomElement root=doc.createElement("note");
    doc.appendChild(root);
    appendProperty("uid", id.toString());
    appendProperty("dateCreated", dateCreated.toString("dd-MM-yy hh:mm:ss"));
    appendProperty("dateModified", dateCreated.toString("dd-MM-yy hh:mm:ss"));
    appendProperty("content", content);
    NoteLabel label;
    foreach(label, labels)
    {
        doc.documentElement().appendChild(label.toElement());
    }
    return doc.toString(2);
}

bool fromXML(QString xml)
{
    doc.setContent(xml);
    labels.clear();
    QUuid newId(doc.elementsByTagName("uid").item(0));
    id=newId;
    dateCreated=QDateTime::fromString(doc.elementsByTagName("dateCreated").item(0));
    dateModified=QDateTime::fromString(doc.elementsByTagName("dateModified").item(0));
    content=doc.elementsByTagName("content").item(0);
    //now process the labels
    QDomNodeList nodeLabels=doc.elementsByTagName("label");
    for(int i=0;i<nodeLabels.count();i++)
    {
        labels<<labelFactory::createLableFromElement(nodeLabels.item(i));
    }
}

bool Note::addLabel(NoteLabel& label)
{
    labels<<label;
}

bool Note::removeLabel(NoteLabel& label)
{
    //TODO: whether this is useful?
}
