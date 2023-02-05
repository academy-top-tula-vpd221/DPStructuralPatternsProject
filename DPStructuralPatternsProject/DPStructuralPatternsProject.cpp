#include <iostream>


#include "Adapter.h"


int main()
{
    ISensor* sensor = new CelsiusSensor();
    std::cout << sensor->GetTemperature() << "\n";

    delete sensor;
    sensor = new FahrenheitAdapter(new FahrenheitSensor());
    std::cout << sensor->GetTemperature() << "\n";
}
