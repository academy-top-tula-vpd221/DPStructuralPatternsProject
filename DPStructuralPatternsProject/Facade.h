#pragma once
#include <iostream>

using namespace std;

class TextEditor
{
public:
	void Create(string& code)
	{
		code = "noname.cpp";
		cout << "write code to " << code << "\n";
	}
	string Save(string code)
	{
		code = "prog.cpp";
		cout << "save code " << code << "\n";
		return code;
	}
};
class Compiller
{
public:
	string Compile(string& code)
	{
		cout << "compile code to execute file " <<  code + ".exe\n";
		return code + ".exe";
	}
};
class Debugger
{
public:
	void Step(string& code)
	{
		cout << "step by step execute prog " << code << "\n";
		code = "prog_debugg.cpp";
	}
	string Save(string& code)
	{
		cout << "save debugging code " << code << "\n";
		return code;
	}
};
class Runtime
{
public:
	void Execute(string& app)
	{
		cout << "execute app " << app << "\n";
	}
	int Finish(string& app)
	{
		cout << "Finish app " << app << "\n";
		return 0;
	}
};

class VisualStudioFacade
{
	TextEditor* editor;
	Compiller* compiller;
	Debugger* debugger;
	Runtime* runtime;

	string code;
	string app;
public:
	VisualStudioFacade(TextEditor* editor, Compiller* compiller, Debugger* debugger, Runtime* runtime)
		: editor{ editor },
		compiller{ compiller },
		debugger{ debugger },
		runtime{ runtime } {}

	void Start()
	{
		editor->Create(code);
		code = editor->Save(code);
		app = compiller->Compile(code);
		debugger->Step(code);
		debugger->Save(code);
		app = compiller->Compile(code);
		runtime->Execute(app);
	}

	void Finish()
	{
		int code = runtime->Finish(app);
		cout << "error code: " << code << "\n";
	}

};


