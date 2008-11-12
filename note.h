#include <QString>
#include <QDateTime>
#include <QList>
#include <QDebug>
#include <QDomDocument>
#include <QDomElement>

class NoteLabel
{
	public:
		NoteLabel(){}
		virtual QString serialize()
                {
                    QDebug()<<"note label serilized";
                }
	private:
		QString labelType;
};

/*
class IdeaNoteLabel: public NoteLabel
{
	public:
		IdeaNoteLabel():labelType(tr("IDEA"));
		virtual QString serialize();
	private:
		int importance;
};

class QuestionNoteLabel: public NoteLabel
{
	public:
		QuestionNoteLabel():labelType(tr("QUESTION"));
		virtual QString serialize();
		setAnswer(QString answer);
	private:
		QDateTime resolveDeadline;
		QString answer;
};

class TaskNoteLabel: public NoteLabel
{
	public:
		TaskNoteLabel():labelType(tr("TASK"));
		virtual QString serialize();
	private:
		QDateTime deadline;
};

class EventNoteLabel: public NoteLabel
{
	public:
		EventNoteLabel():labelType(tr("EVENT"));
		virtual QString serialize();
	private:
		QDateTime start;
		QDateTime end;
};

class InvitationNoteLabel: public NoteLabel
{
	public:
		InvitationNoteLabel():labelType(tr("INVITATION"));
		virtual QString serialize();
	private:
		QString extraNotes;
		QString format;
};

class ReminderNoteLabel: public NoteLabel
{
	public:
		ReminderNoteLabel():labelType(tr("REMINDER"));
		virtual QString serialize();
	private:
		QDateTime reminderTime;
		int snoozeInterval;
		int snoozeCount;
		QString repeatType;
};

class NewsNoteLabel: public NoteLabel
{
	public:
		NewsNoteLabel():labelType(tr("NEWS"));
		virtual QString serialize();
	private:
		QString source;
                QDateTime date;
                QString reference;
};

class MessageNoteLabel: public NoteLabel
{
	public:
		MessageNoteLabel():labelType(tr("MESSAGE"));
		virtual QString serialize();
	private:
		QString from;
                QDateTime date;
};
*/

class Note
{
	public:
		QUuid id;//global note id
                static Board * board;//the board that the sticker can be put on
		Note(long noteId=0);//constructor
		~Note();//destructor
		QString toXML();//convert this instance to a xml document
		bool fromXML(QString xml);//construct the instance from xml stream
                bool addLabel(NoteLabel& label);
                bool removeLabel(NoteLabel& label);
	private:
		QDateTime dateCreated;//date created
		QDateTime dateModified;//last modified
		QString content;//contents of the note
		QList<NoteLabel> labels;//labels attached to the note
                QDomDocument doc;
                void appendProperty(QString name, QString value);
};
