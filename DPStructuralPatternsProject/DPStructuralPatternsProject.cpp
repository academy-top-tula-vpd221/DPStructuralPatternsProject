#include <iostream>
#include <vector>

using namespace std;

/*
#include "Adapter.h"
void AdapterExample()
{
    ISensor* sensor = new CelsiusSensor();
    std::cout << sensor->GetTemperature() << "\n";

    delete sensor;
    sensor = new FahrenheitAdapter(new FahrenheitSensor());
    std::cout << sensor->GetTemperature() << "\n";
}
*/

/*
#include "Bridge.h"
void BridgeExample()
{
    IProgrammer* programmer = new FreelanceProgrammer(new CppLanguage());
    programmer->Coding();
    programmer->SetMoney();
    std::cout << "\n";

    delete programmer;
    programmer = new CompanyProgrammer(new CSharpLanguage());
    programmer->Coding();
    programmer->SetMoney();
}
*/

/*
#include "Composite.h"
void CompositeExample()
{
    srand(time(nullptr));

    vector<IFactory*> factories;
    factories.push_back(new InfantryUnitFactory());
    factories.push_back(new ArcherUnitFactory());
    factories.push_back(new CavalryUnitFactory());


    Unit* falanga1 = new CompositeUnit("falanga 1");
    for (int i = 0; i < 10; i++)
        ((CompositeUnit*)falanga1)->AddUnit(factories[rand() % factories.size()]->CreateUnit());
    ((CompositeUnit*)falanga1)->AddUnit(factories[0]->CreateUnit());

    Unit* falanga2 = new CompositeUnit("falanga 2");
    for (int i = 0; i < 15; i++)
        ((CompositeUnit*)falanga2)->AddUnit(factories[rand() % factories.size()]->CreateUnit());
    ((CompositeUnit*)falanga2)->AddUnit(factories[0]->CreateUnit());
    ((CompositeUnit*)falanga2)->AddUnit(factories[2]->CreateUnit());

    Unit* legion1 = new CompositeUnit("legion 1");
    ((CompositeUnit*)legion1)->AddUnit(falanga1);
    ((CompositeUnit*)legion1)->AddUnit(falanga2);
    ((CompositeUnit*)legion1)->AddUnit(factories[2]->CreateUnit());

    cout << legion1->ToString();
}
*/

/*
#include "Decorator.h"
void DecoratorExample()
{
    IMessage* message = new MessangerMessage("Hello people!", "Foma", "Erema", "hello");
    message->Send();

    message = new FileMessage(message, "document.txt");
    message->Send();

    message = new ContactMessage(message, "Afonya 123-45-67");
    message->Send();

    message = new FileMessage(message, "report.docx");
    message->Send();
}
*/

/*
#include "Facade.h"
void FacadeExample()
{
    VisualStudioFacade* facade = new VisualStudioFacade(
        new TextEditor(),
        new Compiller(),
        new Debugger(),
        new Runtime());

    facade->Start();
    facade->Finish();
}
*/

#include "Flyweight.h"
void FlyweightExample()
{
    TankFactory* factory = new TankFactory();
    vector<TankContext*> tanks;

    for (int i = 0; i < 10; i++)
    {
        string name, color, texture;
        if (i % 2)
        {
            name = "Armata";
            color = "Gray";
            texture = "armata.jpg";
        }
        else
        {
            name = "T34";
            color = "Green";
            texture = "tankT34.jpg";
        }
        tanks.push_back(new TankContext(i + 1, i + 1, factory, name, color, texture));
    }

}

int main()
{
    
   
}
