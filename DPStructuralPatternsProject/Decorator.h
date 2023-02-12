#pragma once
#include <iostream>

using namespace std;

// Component
class IMessage
{
protected:
	string text;
	string from;
	string to;
public:
	IMessage() : IMessage("", "", "") {}

	IMessage(string text, string from, string to)
		: text{ text }, from{ from }, to{ to } {}
	
	virtual string& Text() { return text; }
	virtual string& From() { return from; }
	virtual string& To() { return to; }

	virtual void Send() = 0;
};

class EmailMessage : public IMessage
{
	string subject;
public:
	EmailMessage(string text, string from, string to, string subject)
		: IMessage(text, from, to), subject{ subject } {}

	string& Subject() { return subject; }

	void Send() override
	{
		cout << "Email message send from " << from
			<< "\n\tto " << to
			<< "\n\tsubject " << subject
			<< "\n\ttext " << text << "\n";
	}
};

class MessangerMessage : public IMessage
{
	string sticker;
public:
	MessangerMessage(string text, string from, string to, string sticker)
		: IMessage(text, from, to), sticker{ sticker } {}

	string& Sticker() { return sticker; }

	void Send() override
	{
		cout << "Messanger message send from " << from
			<< "\n\tto " << to
			<< "\n\ttext " << text
			<< "\n\tsticker " << sticker << "\n";
	}
};

class IMessageDecorator : public IMessage
{
protected:
	IMessage* message;
public:
	IMessageDecorator(IMessage* message) : message{ message } 
	{

	}
};

class FileMessage : public IMessageDecorator
{
	string file;
public:
	FileMessage(IMessage* message, string file)
		: IMessageDecorator(message), file{ file } {}
	void Send() override
	{
		message->Send();
		cout << "\twith file " << file << "\n";
	}
};

class ContactMessage : public IMessageDecorator
{
	string contact;
public:
	ContactMessage(IMessage* message, string contact)
		: IMessageDecorator(message), contact{ contact } {}
	void Send() override
	{
		message->Send();
		cout << "\twith contact " << contact << "\n";
	}
};