#pragma once
#include <iostream>

class ILanguage
{
public:
	virtual void Build() = 0;
	virtual void Execute() = 0;
};

class IProgrammer
{
protected:
	ILanguage* language;
public:
	IProgrammer(ILanguage* language) : language{ language } {}
	
	// set get
	ILanguage*& Language() { return language; }

	virtual void Coding()
	{
		language->Build();
		language->Execute();
	}
	virtual void SetMoney() = 0;
};

class CompanyProgrammer : public IProgrammer
{
public:
	CompanyProgrammer(ILanguage* language) : IProgrammer(language) {}
	void SetMoney() override
	{
		std::cout << "Set money in last day of month\n";
	}
};

class FreelanceProgrammer : public IProgrammer
{
public:
	FreelanceProgrammer(ILanguage* language) : IProgrammer(language) {}
	void SetMoney() override
	{
		std::cout << "Set money with finish project\n";
	}
};

class CppLanguage : public ILanguage
{
public:
	void Build() override
	{
		std::cout << "compiling with cpp compiler in binary cod\n";
	}
	void Execute() override
	{
		std::cout << "execute program with operation system\n";
	}
};

class CSharpLanguage : public ILanguage
{
public:
	void Build() override
	{
		std::cout << "compiling with compiler Roslin in CIL code\n";
	}
	void Execute() override
	{
		std::cout << "execute program with paltform .Net\n";
		std::cout << "JIT compiler make bynary code\n";
		std::cout << "CLR work\n";
	}
};


