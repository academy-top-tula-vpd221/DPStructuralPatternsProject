#pragma once
#include <iostream>

class ISensor
{
public:
	virtual double GetTemperature() = 0;
};

class CelsiusSensor : public ISensor
{
public:
	double GetTemperature() override
	{
		return 36.6;
	}
};

class FahrenheitSensor
{
public:
	double GetFahrenheitTemperature()
	{
		return 40;
	}
};

class FahrenheitAdapter : public ISensor
{
	FahrenheitSensor* sensor;
public:
	FahrenheitAdapter(FahrenheitSensor* sensor) : sensor{ sensor } {}
	double GetTemperature() override
	{
		return (sensor->GetFahrenheitTemperature() - 32.0) * 5.0 / 9.0;
	}
};

