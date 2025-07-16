#pragma once

/*
MEASUREMENT LIBRARY
===================
v0.1

by Bryan Shortall
EngineerShorty@email.com

This library allows you to treat measurement data as measurements.
Operators have been properly overloaded to avoid incorrect combinations.
For example, measurements can only be added/subtracted from the same types of measurements.
Trying to add a Length to a Speed will cause a compile-time error.

Additionally, when measurements are multiplied or divided, they properly change types.
For example, dividing a Length by TimeDuration will give the answer as a Speed value.

MEASUREMENTS
------------

TimeDuration - SECOND, MINUTE, HOUR, DAY, WEEK, YEAR, MILLISECOND, MICROSECOND, NANOSECOND
Length - m, cm, mm, um, km, in, ft, yd, mi
Area - m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare


*/

#include "Angle.h"
class TimeDuration;
class Length;
class Area;
class Volume;
class Speed;
class Acceleration;
class Mass;
class Force;
class Pressure;
class Energy;
class Power;
class Density;
class Temperature;
class Voltage;
class Current;
class Capacitance;
class Resistance;
class RotationSpeed;
class Torque;

namespace UNITS {

	enum TimeUnits { s, min, hr, day, week, yr, ms, us, ns };
	enum LengthUnits { m, cm, mm, um, km, in, ft, yd, mi };
	enum AreaUnits { m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare };
	enum VolumeUnits { m3, cm3, mm3, km3, L, mL, in3, ft3, yd3, mi3, tsp, tbsp, cup, pint, quart, gallon, barrel };
	enum SpeedUnits { m_s, kph, mph, ft_s };
	enum AccelerationUnits { m_s2, kph_s, mph_s, ft_s2, G };
	enum MassUnits { gram, kg, lb, oz, tonne, ton };
	enum ForceUnits { N, lbf };
	enum PressureUnits { Pa, kPa, MPa, psi, mmHg, inH2O, bar, atm };
	enum EnergyUnits { J, kJ, MJ, kWh, hph, BTU, cal, kCal };
	enum PowerUnits { W, kW, MW, mW, hp, BTU_h };
	enum DensityUnits { kg_m3, g_cm3, lb_gal };
	enum TemperatureUnits { C, K, F, R };
	enum VoltageUnits { V, mV, kV, MV };
	enum CurrentUnits { A, mA, kA, MA };
	enum CapacitanceUnits { Farad, uF, mF, nF, pF };
	enum ResistanceUnits { Ohm, mOhm, kOhm, MOhm };
	enum RotationSpeedUnits { rpm, rev_s, rad_s, deg_s };
	enum TorqueUnits { Nm, inlb, ftlb };

}


struct YR_DAY_HR_MIN_SEC {
	int years;
	int days;
	int hours;
	int minutes;
	double seconds;
};

class TimeDuration {
	//s, min, hr, day, week, yr, ms, us, ns
public:
	TimeDuration() {
		time_in_s = 0;
	}
	TimeDuration(double val, UNITS::TimeUnits units) {
		set(val, units);
	}
	//s, min, hr, day, week, yr, ms, us, ns
	void set(double val, UNITS::TimeUnits units);
	//s, min, hr, day, week, yr, ms, us, ns
	double value(UNITS::TimeUnits units);
	YR_DAY_HR_MIN_SEC yr_day_hr_min_sec() {
		YR_DAY_HR_MIN_SEC output;
		double Remainder = time_in_s;
		TimeDuration year(1, UNITS::yr);
		output.years = Remainder / year.time_in_s;
		Remainder = Remainder - year.time_in_s * output.years;
		TimeDuration day(1, UNITS::day);
		output.days = Remainder / day.time_in_s;
		Remainder = Remainder - day.time_in_s * output.days;
		TimeDuration hour(1, UNITS::hr);
		output.hours = Remainder / hour.time_in_s;
		Remainder = Remainder - hour.time_in_s * output.hours;
		TimeDuration minute(1, UNITS::min);
		output.minutes = Remainder / minute.time_in_s;
		Remainder = Remainder - minute.time_in_s * output.minutes;
		output.seconds = Remainder;
		return output;
	}
	TimeDuration operator+ (TimeDuration time) {
		return TimeDuration(value(UNITS::s) + time.value(UNITS::s), UNITS::s);
	}
	TimeDuration operator- (TimeDuration time) {
		return TimeDuration(value(UNITS::s) - time.value(UNITS::s), UNITS::s);
	}
	TimeDuration operator* (double val) {
		return TimeDuration(value(UNITS::s) * val, UNITS::s);
	}
	TimeDuration operator/ (double val) {
		return TimeDuration(value(UNITS::s) / val, UNITS::s);
	}
	double operator/ (TimeDuration time) {
		return (value(UNITS::s) / time.value(UNITS::s));
	}
	bool operator> (TimeDuration time) {
		return (value(UNITS::s) > time.value(UNITS::s));
	}
	bool operator>= (TimeDuration time) {
		return (value(UNITS::s) >= time.value(UNITS::s));
	}
	bool operator< (TimeDuration time) {
		return (value(UNITS::s) < time.value(UNITS::s));
	}
	bool operator<= (TimeDuration time) {
		return (value(UNITS::s) <= time.value(UNITS::s));
	}
	bool operator== (TimeDuration time) {
		return (value(UNITS::s) == time.value(UNITS::s));
	}
	bool operator!= (TimeDuration time) {
		return (value(UNITS::s) != time.value(UNITS::s));
	}
	void operator= (TimeDuration time) {
		time_in_s = time.value(UNITS::s);
	}
	void operator+= (TimeDuration time) {
		time_in_s += time.value(UNITS::s);
	}
	void operator-= (TimeDuration time) {
		time_in_s -= time.value(UNITS::s);
	}

protected:
	double time_in_s;
};

	//m, cm, mm, um, km, in, ft, yd, mi
class Length {
public:
	Length() {
		length_in_m = 0;
	}
	//m, cm, mm, um, km, in, ft, yd, mi
	Length(double val, UNITS::LengthUnits units) {
		set(val, units);
	}
	//m, cm, mm, um, km, in, ft, yd, mi
	void set(double val, UNITS::LengthUnits units);
	//m, cm, mm, um, km, in, ft, yd, mi
	double value(UNITS::LengthUnits units);
	Length operator+ (Length length) {
		return Length(value(UNITS::m) + length.value(UNITS::m), UNITS::m);
	}
	Length operator- (Length length) {
		return Length(value(UNITS::m) - length.value(UNITS::m), UNITS::m);
	}
	Length operator/ (double val) {
		return Length(value(UNITS::m) / val, UNITS::m);
	}
	Length operator* (double val) {
		return Length(value(UNITS::m) * val, UNITS::m);
	}
	Area operator* (Length length) {
		return Area(value(UNITS::m) * length.value(UNITS::m), UNITS::m2);
	}
	Volume operator* (Area area) {
		return Volume(value(UNITS::m) * area.value(UNITS::m2), UNITS::m3);
	}
	Energy operator* (Force f) {
		return Energy(value(UNITS::m) * f.value(UNITS::N), UNITS::J);
	}
	double operator/ (Length length) {
		return (value(UNITS::m) / length.value(UNITS::m));
	}
	Speed operator/ (TimeDuration time) {
		double meters = value(UNITS::m);
		double secs = time.value(UNITS::s);
		return Speed(meters / secs, UNITS::m_s);
	}
	bool operator> (Length length) {
		return (value(UNITS::m) > length.value(UNITS::m));
	}
	bool operator>= (Length length) {
		return (value(UNITS::m) >= length.value(UNITS::m));
	}
	bool operator< (Length length) {
		return (value(UNITS::m) < length.value(UNITS::m));
	}
	bool operator<= (Length length) {
		return (value(UNITS::m) <= length.value(UNITS::m));
	}
	bool operator== (Length length) {
		return (value(UNITS::m) == length.value(UNITS::m));
	}
	bool operator!= (Length length) {
		return (value(UNITS::m) != length.value(UNITS::m));
	}
	void operator= (Length length) {
		length_in_m = length.value(UNITS::m);
	}
	void operator+= (Length length) {
		length_in_m += length.value(UNITS::m);
	}
	void operator-= (Length length) {
		length_in_m += length.value(UNITS::m);
	}
	bool operator++() {
		return (value(UNITS::m) > 0);
	}
	bool operator--() {
		return (value(UNITS::m) < 0);
	}
protected:
	double length_in_m;
};

class Area {
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
public:
	Area() {
		area_in_m2 = 0;
	}
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
	Area(double val, UNITS::AreaUnits units) {
		set(val, units);
	}
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
	void set(double val, UNITS::AreaUnits units);
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
	double value(UNITS::AreaUnits units);
	Area operator+ (Area area) {
		return Area(value(UNITS::m2) + area.value(UNITS::m2), UNITS::m2);
	}
	Area operator- (Area area) {
		return Area(value(UNITS::m2) - area.value(UNITS::m2), UNITS::m2);
	}
	Area operator* (double val) {
		return Area(value(UNITS::m2) * val, UNITS::m2);
	}
	Area operator/ (double val) {
		return Area(value(UNITS::m2) / val, UNITS::m2);
	}
	Volume operator* (Length length) {
		return Volume(value(UNITS::m2) * length.value(UNITS::m), UNITS::m3);
	}
	Length operator/ (Length length) {
		return Length(value(UNITS::m2) / length.value(UNITS::m), UNITS::m);
	}
	double operator/ (Area area) {
		return (value(UNITS::m2) / area.value(UNITS::m2));
	}
	bool operator> (Area area) {
		return (value(UNITS::m2) > area.value(UNITS::m2));
	}
	bool operator>= (Area area) {
		return (value(UNITS::m2) >= area.value(UNITS::m2));
	}
	bool operator< (Area area) {
		return (value(UNITS::m2) < area.value(UNITS::m2));
	}
	bool operator<= (Area area) {
		return (value(UNITS::m2) <= area.value(UNITS::m2));
	}
	bool operator== (Area area) {
		return (value(UNITS::m2) == area.value(UNITS::m2));
	}
	bool operator!= (Area area) {
		return (value(UNITS::m2) != area.value(UNITS::m2));
	}
protected:
	double area_in_m2;
};

class Volume {
	//m3, cm3, mm3, km3, L, mL, in3, ft3, yd3, mi3, tsp, tbsp, cup, pint, quart, gallon, barrel
public:
	Volume() {
		volume_in_L = 0;
	}
	//m3, cm3, mm3, km3, L, mL, in3, ft3, yd3, mi3, tsp, tbsp, cup, pint, quart, gallon, barrel
	Volume(double val, UNITS::VolumeUnits units) {
		set(val, units);
	}
	//m3, cm3, mm3, km3, L, mL, in3, ft3, yd3, mi3, tsp, tbsp, cup, pint, quart, gallon, barrel
	void set(double val, UNITS::VolumeUnits units);
	//m3, cm3, mm3, km3, L, mL, in3, ft3, yd3, mi3, tsp, tbsp, cup, pint, quart, gallon, barrel
	double value(UNITS::VolumeUnits units);
	Volume operator+ (Volume volume) {
		return Volume(value(UNITS::L) + volume.value(UNITS::L), UNITS::L);
	}
	Volume operator- (Volume volume) {
		return Volume(value(UNITS::L) - volume.value(UNITS::L), UNITS::L);
	}
	Volume operator* (double factor) {
		return Volume(value(UNITS::L) * factor, UNITS::L);
	}
	Volume operator/ (double factor) {
		return Volume(value(UNITS::L) / factor, UNITS::L);
	}
	Area operator/ (Length length) {
		return Area(value(UNITS::L) / length.value(UNITS::m), UNITS::m2);
	}
	Length operator/ (Area area) {
		return Length(value(UNITS::L) / area.value(UNITS::m2), UNITS::m);
	}
	bool operator> (Volume vol) {
		return (value(UNITS::m3) > vol.value(UNITS::m3));
	}
	bool operator>= (Volume vol) {
		return (value(UNITS::m3) >= vol.value(UNITS::m3));
	}
	bool operator< (Volume vol) {
		return (value(UNITS::m3) < vol.value(UNITS::m3));
	}
	bool operator<= (Volume vol) {
		return (value(UNITS::m3) <= vol.value(UNITS::m3));
	}
	bool operator== (Volume vol) {
		return (value(UNITS::m3) == vol.value(UNITS::m3));
	}
	bool operator!= (Volume vol) {
		return (value(UNITS::m3) != vol.value(UNITS::m3));
	}
protected:
	double volume_in_L;
};

class Speed {
	//m_s, kph, mph, ft_s, G
public:
	Speed() {
		speed_in_m_s = 0;
	}
	//m_s, kph, mph, ft_s, G
	Speed(double val, UNITS::SpeedUnits units) {
		set(val, units);
	}
	//m_s, kph, mph, ft_s, G
	void set(double val, UNITS::SpeedUnits units);
	//m_s, kph, mph, ft_s, G
	double value(UNITS::SpeedUnits units);
	Speed operator+ (Speed speed) {
		return Speed(value(UNITS::m_s) + speed.value(UNITS::m_s), UNITS::m_s);
	}
	Speed operator- (Speed speed) {
		return Speed(value(UNITS::m_s) - speed.value(UNITS::m_s), UNITS::m_s);
	}
	Acceleration operator/ (TimeDuration time) {
		return Acceleration(value(UNITS::m_s) / time.value(UNITS::s), UNITS::m_s2);
	}
	Length operator* (TimeDuration time) {
		return Length(value(UNITS::m_s) * time.value(UNITS::s), UNITS::m);
	}
	Speed operator* (double val) {
		return Speed(value(UNITS::m_s) * val, UNITS::m_s);
	}
	Speed operator/ (double val) {
		return Speed(value(UNITS::m_s) / val, UNITS::m_s);
	}
	bool operator> (Speed speed) {
		return (value(UNITS::m_s) > speed.value(UNITS::m_s));
	}
	bool operator>= (Speed speed) {
		return (value(UNITS::m_s) >= speed.value(UNITS::m_s));
	}
	bool operator< (Speed speed) {
		return (value(UNITS::m_s) < speed.value(UNITS::m_s));
	}
	bool operator<= (Speed speed) {
		return (value(UNITS::m_s) <= speed.value(UNITS::m_s));
	}
	bool operator== (Speed speed) {
		return (value(UNITS::m_s) == speed.value(UNITS::m_s));
	}
	bool operator!= (Speed speed) {
		return (value(UNITS::m_s) != speed.value(UNITS::m_s));
	}
	bool operator++ () {
		return (value(UNITS::m_s) > 0);
	}
	bool operator-- () {
		return (value(UNITS::m_s) < 0);
	}
protected:
	double speed_in_m_s;
};

class Acceleration {
	// m_s2, kph_s, mph_s, ft_s2, G
public:
	Acceleration() {
		acceleration_in_m_s2 = 0;
	}
	// m_s2, kph_s, mph_s, ft_s2, G
	Acceleration(double value, UNITS::AccelerationUnits units) {
		set(value, units);
	}
	// m_s2, kph_s, mph_s, ft_s2, G
	void set(double value, UNITS::AccelerationUnits units);
	// m_s2, kph_s, mph_s, ft_s2, G
	double value(UNITS::AccelerationUnits units);
	Acceleration operator+ (Acceleration accel) {
		return Acceleration(value(UNITS::m_s2) + accel.value(UNITS::m_s2), UNITS::m_s2);
	}
	Acceleration operator- (Acceleration accel) {
		return Acceleration(value(UNITS::m_s2) - accel.value(UNITS::m_s2), UNITS::m_s2);
	}
	Acceleration operator* (double val) {
		return Acceleration(value(UNITS::m_s2) * val, UNITS::m_s2);
	}
	Acceleration operator/ (double val) {
		return Acceleration(value(UNITS::m_s2) / val, UNITS::m_s2);
	}
	Speed operator* (TimeDuration time) {
		return Speed(value(UNITS::m_s2) * time.value(UNITS::s), UNITS::m_s);
	}
	Force operator* (Mass mass) {
		return Force(value(UNITS::m_s2) * mass.value(UNITS::kg), UNITS::N);
	}
	bool operator> (Acceleration accel) {
		return (value(UNITS::m_s2) > accel.value(UNITS::m_s2));
	}
	bool operator>= (Acceleration accel) {
		return (value(UNITS::m_s2) >= accel.value(UNITS::m_s2));
	}
	bool operator< (Acceleration accel) {
		return (value(UNITS::m_s2) < accel.value(UNITS::m_s2));
	}
	bool operator<= (Acceleration accel) {
		return (value(UNITS::m_s2) <= accel.value(UNITS::m_s2));
	}
	bool operator== (Acceleration accel) {
		return (value(UNITS::m_s2) == accel.value(UNITS::m_s2));
	}
	bool operator!= (Acceleration accel) {
		return (value(UNITS::m_s2) != accel.value(UNITS::m_s2));
	}
	bool operator++() {
		return (value(UNITS::m_s2) > 0);
	}
	bool operator--() {
		return (value(UNITS::m_s2) < 0);
	}
protected:
	double acceleration_in_m_s2;
};

class Mass {
	//gram, kg, lb, oz, tonne, ton
public:
	Mass() {
		mass_in_kg = 0;
	}
	//gram, kg, lb, oz, tonne, ton
	Mass(double value, UNITS::MassUnits units) {
		set(value, units);
	}
	//gram, kg, lb, oz, tonne, ton
	void set(double value, UNITS::MassUnits units);
	//gram, kg, lb, oz, tonne, ton
	double value(UNITS::MassUnits units);
	Mass operator+ (Mass mass) {
		return Mass(value(UNITS::kg) + mass.value(UNITS::kg), UNITS::kg);
	}
	Mass operator- (Mass mass) {
		return Mass(value(UNITS::kg) - mass.value(UNITS::kg), UNITS::kg);
	}
	Mass operator* (double val) {
		return Mass(value(UNITS::kg) * val, UNITS::kg);
	}
	Mass operator/ (double val) {
		return Mass(value(UNITS::kg) / val, UNITS::kg);
	}
	Force operator* (Acceleration accel) {
		return Force(value(UNITS::kg) * accel.value(UNITS::m_s2), UNITS::N);
	}
	Density operator/ (Volume vol) {
		return Density(value(UNITS::kg) / vol.value(UNITS::m3), UNITS::kg_m3);
	}
	bool operator> (Mass mass) {
		return (value(UNITS::kg) > mass.value(UNITS::kg));
	}
	bool operator>= (Mass mass) {
		return (value(UNITS::kg) >= mass.value(UNITS::kg));
	}
	bool operator< (Mass mass) {
		return (value(UNITS::kg) < mass.value(UNITS::kg));
	}
	bool operator<= (Mass mass) {
		return (value(UNITS::kg) <= mass.value(UNITS::kg));
	}
	bool operator== (Mass mass) {
		return (value(UNITS::kg) == mass.value(UNITS::kg));
	}
	bool operator!= (Mass mass) {
		return (value(UNITS::kg) != mass.value(UNITS::kg));
	}
protected:
	double mass_in_kg;
};

class Force {
	//N, lbf
public:
	Force() {
		force_in_N = 0;
	}
	//N, lbf
	Force(double value, UNITS::ForceUnits units) {
		set(value, units);
	}
	//N, lbf
	void set(double value, UNITS::ForceUnits units);
	//N, lbf
	double value(UNITS::ForceUnits units);
	Force operator+ (Force force) {
		return Force(value(UNITS::N) + force.value(UNITS::N), UNITS::N);
	}
	Force operator- (Force force) {
		return Force(value(UNITS::N) - force.value(UNITS::N), UNITS::N);
	}
	Force operator* (double val) {
		return Force(value(UNITS::N) * val, UNITS::N);
	}
	Force operator/ (double val) {
		return Force(value(UNITS::N) / val, UNITS::N);
	}
	Energy operator* (Length distance) {
		return Energy(value(UNITS::N) + distance.value(UNITS::m), UNITS::J);
	}
	Acceleration operator/ (Mass mass) {
		return Acceleration(value(UNITS::N) / mass.value(UNITS::kg), UNITS::m_s2);
	}
	Mass operator/ (Acceleration accel) {
		return Mass(value(UNITS::N) / accel.value(UNITS::m_s2), UNITS::kg);
	}
	Pressure operator/ (Area area) {
		return Pressure(value(UNITS::N) / area.value(UNITS::m2), UNITS::Pa);
	}
	bool operator> (Force force) {
		return (value(UNITS::N) > force.value(UNITS::N));
	}
	bool operator>= (Force force) {
		return (value(UNITS::N) >= force.value(UNITS::N));
	}
	bool operator< (Force force) {
		return (value(UNITS::N) < force.value(UNITS::N));
	}
	bool operator<= (Force force) {
		return (value(UNITS::N) <= force.value(UNITS::N));
	}
	bool operator== (Force force) {
		return (value(UNITS::N) == force.value(UNITS::N));
	}
	bool operator!= (Force force) {
		return (value(UNITS::N) != force.value(UNITS::N));
	}
	bool operator++() {
		return (value(UNITS::N) > 0);
	}
	bool operator--() {
		return (value(UNITS::N) < 0);
	}
protected:
	double force_in_N;
};

class Pressure {
	//Pa, kPa, MPa, psi, mmHg, inH2O, bar, atm
public:
	Pressure() {
		pressure_in_Pa = 0;
	}
	//Pa, kPa, MPa, psi, mmHg, inH2O, bar, atm
	Pressure(double value, UNITS::PressureUnits units) {
		set(value, units);
	}
	//Pa, kPa, MPa, psi, mmHg, inH2O, bar, atm
	void set(double value, UNITS::PressureUnits units);
	//Pa, kPa, MPa, psi, mmHg, inH2O, bar, atm
	double value(UNITS::PressureUnits units);
	Pressure operator+ (Pressure pressure) {
		return Pressure(value(UNITS::Pa) + pressure.value(UNITS::Pa), UNITS::Pa);
	}
	Pressure operator- (Pressure pressure) {
		return Pressure(value(UNITS::Pa) - pressure.value(UNITS::Pa), UNITS::Pa);
	}
	Pressure operator* (double val) {
		return Pressure(value(UNITS::Pa) * val, UNITS::Pa);
	}
	Pressure operator/ (double val) {
		return Pressure(value(UNITS::Pa) / val, UNITS::Pa);
	}
	Force operator* (Area area) {
		return Force(area.value(UNITS::m2) * value(UNITS::Pa), UNITS::N);
	}
	bool operator> (Pressure press) {
		return (value(UNITS::Pa) > press.value(UNITS::Pa));
	}
	bool operator>= (Pressure press) {
		return (value(UNITS::Pa) >= press.value(UNITS::Pa));
	}
	bool operator< (Pressure press) {
		return (value(UNITS::Pa) < press.value(UNITS::Pa));
	}
	bool operator<= (Pressure press) {
		return (value(UNITS::Pa) <= press.value(UNITS::Pa));
	}
	bool operator== (Pressure press) {
		return (value(UNITS::Pa) == press.value(UNITS::Pa));
	}
	bool operator!= (Pressure press) {
		return (value(UNITS::Pa) != press.value(UNITS::Pa));
	}
	bool operator++() {
		return (value(UNITS::Pa) > 0);
	}
	bool operator--() {
		return (value(UNITS::Pa) < 0);
	}
protected:
	double pressure_in_Pa;
};

class Energy {
	//J, kJ, mJ, kWh, hph, BTU, cal, kCal
public:
	Energy() {
		energy_in_J = 0;
	}
	//J, kJ, mJ, kWh, hph, BTU, cal, kCal
	Energy(double val, UNITS::EnergyUnits units) {
		set(val, units);
	}
	//J, kJ, mJ, kWh, hph, BTU, cal, kCal
	void set(double val, UNITS::EnergyUnits units);
	double value(UNITS::EnergyUnits units);
	Energy operator+ (Energy energy) {
		return Energy(value(UNITS::J) + energy.value(UNITS::J), UNITS::J);
	}
	Energy operator- (Energy energy) {
		return Energy(value(UNITS::J) - energy.value(UNITS::J), UNITS::J);
	}
	Energy operator* (double val) {
		return Energy(value(UNITS::J) * val, UNITS::J);
	}
	Energy operator/ (double val) {
		return Energy(value(UNITS::J) / val, UNITS::J);
	}
	Power operator/ (TimeDuration time) {
		return Power(value(UNITS::J) / time.value(UNITS::s), UNITS::W);
	}
	Force operator/ (Length distance) {
		return Force(value(UNITS::J) / distance.value(UNITS::m), UNITS::N);
	}
	Length operator/ (Force force) {
		return Length(value(UNITS::J) / force.value(UNITS::N), UNITS::m);
	}
	Pressure operator/ (Volume vol) {
		return Pressure(value(UNITS::J) / vol.value(UNITS::m3), UNITS::Pa);
	}
	Volume operator/ (Pressure p) {
		return Volume(value(UNITS::J) / p.value(UNITS::Pa), UNITS::m3);
	}
	void operator= (Torque torque) {
		set(torque.value(UNITS::Nm), UNITS::J);
	}
	bool operator> (Energy energy) {
		return (value(UNITS::J) > energy.value(UNITS::J));
	}
	bool operator>= (Energy energy) {
		return (value(UNITS::J) > energy.value(UNITS::J));
	}
	bool operator< (Energy energy) {
		return (value(UNITS::J) < energy.value(UNITS::J));
	}
	bool operator<= (Energy energy) {
		return (value(UNITS::J) <= energy.value(UNITS::J));
	}
	bool operator== (Energy energy) {
		return (value(UNITS::J) == energy.value(UNITS::J));
	}
	bool operator!= (Energy energy) {
		return (value(UNITS::J) != energy.value(UNITS::J));
	}
	operator Torque() {
		return Torque(value(UNITS::J), UNITS::Nm);
	}
protected:
	double energy_in_J;
};

class Power {
	//W, kW, MW, mW, hp, BTU_h
public:
	Power() {
		power_in_W = 0;
	}
	//W, kW, MW, mW, hp, BTU_h
	Power(double val, UNITS::PowerUnits units);
	//W, kW, MW, mW, hp, BTU_h
	void set(double val, UNITS::PowerUnits units);
	//W, kW, MW, mW, cal, kCal, hp, BTU_h
	double value(UNITS::PowerUnits units);
	Power operator+ (Power energy) {
		return Power(value(UNITS::W) + energy.value(UNITS::W), UNITS::W);
	}
	Power operator- (Power energy) {
		return Power(value(UNITS::W) - energy.value(UNITS::W), UNITS::W);
	}
	Power operator* (double val) {
		return Power(value(UNITS::W) * val, UNITS::W);
	}
	Power operator/ (double val) {
		return Power(value(UNITS::W) / val, UNITS::W);
	}
	Energy operator* (TimeDuration time) {
		return Energy(value(UNITS::W) * time.value(UNITS::s), UNITS::J);
	}
	Voltage operator/ (Current current) {
		return Voltage(value(UNITS::W) / current.value(UNITS::A), UNITS::V);
	}
	Current operator/ (Voltage volts) {
		return Current(value(UNITS::W) / volts.value(UNITS::V), UNITS::A);
	}
	Speed operator/ (Force force) {
		return Speed(value(UNITS::W) / force.value(UNITS::N), UNITS::m_s);
	}
	Force operator/ (Speed velocity) {
		return Force(value(UNITS::W) / velocity.value(UNITS::m_s), UNITS::N);
	}
	bool operator> (Power energy) {
		return (value(UNITS::W) > energy.value(UNITS::W));
	}
	bool operator>= (Power energy) {
		return (value(UNITS::W) > energy.value(UNITS::W));
	}
	bool operator< (Power energy) {
		return (value(UNITS::W) < energy.value(UNITS::W));
	}
	bool operator<= (Power energy) {
		return (value(UNITS::W) <= energy.value(UNITS::W));
	}
	bool operator== (Power energy) {
		return (value(UNITS::W) == energy.value(UNITS::W));
	}
	bool operator!= (Power energy) {
		return (value(UNITS::W) != energy.value(UNITS::W));
	}
protected:
	double power_in_W;
};

class Density {
	//kg_m3, g_cm3, lb_gal
public:
	Density() {
		density_relative_to_water = 0;
	}
	//kg_m3, g_cm3, lb_gal
	Density(double val, UNITS::DensityUnits units) {
		set(val, units);
	}
	//kg_m3, g_cm3, lb_gal
	void set(double val, UNITS::DensityUnits units);
	//kg_m3, g_cm3, lb_gal
	double value(UNITS::DensityUnits units);
	Density operator+ (Density energy) {
		return Density(value(UNITS::kg_m3) + energy.value(UNITS::kg_m3), UNITS::kg_m3);
	}
	Density operator- (Density energy) {
		return Density(value(UNITS::kg_m3) - energy.value(UNITS::kg_m3), UNITS::kg_m3);
	}
	Density operator* (double val) {
		return Density(value(UNITS::kg_m3) * val, UNITS::kg_m3);
	}
	Density operator/ (double val) {
		return Density(value(UNITS::kg_m3) / val, UNITS::kg_m3);
	}
	Mass operator* (Volume vol) {
		return Mass(value(UNITS::g_cm3) * vol.value(UNITS::cm3), UNITS::gram);
	}
	bool operator> (Density energy) {
		return (value(UNITS::kg_m3) > energy.value(UNITS::kg_m3));
	}
	bool operator>= (Density energy) {
		return (value(UNITS::kg_m3) > energy.value(UNITS::kg_m3));
	}
	bool operator< (Density energy) {
		return (value(UNITS::kg_m3) < energy.value(UNITS::kg_m3));
	}
	bool operator<= (Density energy) {
		return (value(UNITS::kg_m3) <= energy.value(UNITS::kg_m3));
	}
	bool operator== (Density energy) {
		return (value(UNITS::kg_m3) == energy.value(UNITS::kg_m3));
	}
	bool operator!= (Density energy) {
		return (value(UNITS::kg_m3) != energy.value(UNITS::kg_m3));
	}
protected:
	double density_relative_to_water;
};

class Temperature {
	//C, K, F, R
public:
	//defaults to 0C
	Temperature();
	//C, K, F, R
	Temperature(double value, UNITS::TemperatureUnits units);
	//C, K, F, R
	void set(double value, UNITS::TemperatureUnits units) {
		switch (units) {
		case UNITS::C:
			temperature_in_K = value + 273.15;
			break;
		case UNITS::K:
			temperature_in_K = value;
			break;
		case UNITS::F:
			temperature_in_K = (value + 459.67) / 1.8;
			break;
		case UNITS::R:
			temperature_in_K = value / 1.8;
			break;
		}
	}
	//C, K, F, R
	double value(UNITS::TemperatureUnits units) {
		switch (units) {
		case UNITS::C:
			return temperature_in_K - 273.15;
			break;
		case UNITS::K:
			return temperature_in_K;
			break;
		case UNITS::F:
			return temperature_in_K * 1.8 - 459.67;
			break;
		case UNITS::R:
			return temperature_in_K * 1.8;
			break;
		}
	}
	Temperature operator+ (Temperature temp) {
		return Temperature(value(UNITS::K) + temp.value(UNITS::K), UNITS::K);
	}
	Temperature operator- (Temperature temp) {
		return Temperature(value(UNITS::K) - temp.value(UNITS::K), UNITS::K);
	}
	bool operator> (Temperature temp) {
		return (value(UNITS::K) > temp.value(UNITS::K));
	}
	bool operator>= (Temperature temp) {
		return (value(UNITS::K) >= temp.value(UNITS::K));
	}
	bool operator< (Temperature temp) {
		return (value(UNITS::K) < temp.value(UNITS::K));
	}
	bool operator<= (Temperature temp) {
		return (value(UNITS::K) <= temp.value(UNITS::K));
	}
	bool operator== (Temperature temp) {
		return (value(UNITS::K) == temp.value(UNITS::K));
	}
	bool operator!= (Temperature temp) {
		return (value(UNITS::K) != temp.value(UNITS::K));
	}
protected:
	double temperature_in_K;
};

class Voltage {
public:
	Voltage() {
		voltage_in_V = 0;
	}
	//value in Volts
	Voltage(double val) {
		set(val, UNITS::V);
	}
	//V, mV, kV, MV		
	Voltage(double val, UNITS::VoltageUnits units) {
		set(val, units);
	}
	//V, mV, kV, MV
	void set(double val, UNITS::VoltageUnits units);
	//V, mV, kV, MV
	double value(UNITS::VoltageUnits units);
	//value in Volts
	double value() {
		return value(UNITS::V);
	}
	Voltage operator+(Voltage v) {
		return Voltage(value(UNITS::V) + v.value(UNITS::V), UNITS::V);
	}
	Voltage operator-(Voltage v) {
		return Voltage(value(UNITS::V) - v.value(UNITS::V), UNITS::V);
	}
	Voltage operator* (double val) {
		return Voltage(value(UNITS::V) * val, UNITS::V);
	}
	Voltage operator/ (double val) {
		return Voltage(value(UNITS::V) / val, UNITS::V);
	}
	Power operator* (Current c) {
		return Power(value(UNITS::V) * c.value(UNITS::A), UNITS::W);
	}
	Resistance operator/ (Current c) {
		return Resistance(value(UNITS::V) / c.value(UNITS::A), UNITS::Ohm);
	}
	bool operator> (Voltage v) {
		return (value(UNITS::V) > v.value(UNITS::V));
	}
	bool operator>= (Voltage v) {
		return (value(UNITS::V) >= v.value(UNITS::V));
	}
	bool operator< (Voltage v) {
		return (value(UNITS::V) < v.value(UNITS::V));
	}
	bool operator<= (Voltage v) {
		return (value(UNITS::V) <= v.value(UNITS::V));
	}
	bool operator== (Voltage v) {
		return (value(UNITS::V) == v.value(UNITS::V));
	}
	bool operator!= (Voltage v) {
		return (value(UNITS::V) != v.value(UNITS::V));
	}
	bool operator++() {
		return (value(UNITS::V) > 0);
	}
	bool operator--() {
		return (value(UNITS::V) < 0);
	}
protected:
	double voltage_in_V;
};

class Current {
public:
	Current() {
		current_in_A = 0;
	}
	//current in Amps
	Current(double val) {
		set(val, UNITS::A);
	}
	//A, mA, kA, MA
	Current(double val, UNITS::CurrentUnits units) {
		set(val, units);
	}
	//A, mA, kA, MA
	void set(double val, UNITS::CurrentUnits units);
	//current in Amps
	void set(double val) {
		set(val, UNITS::A);
	}
	//A, mA, kA, MA
	double value(UNITS::CurrentUnits units);
	//current in Amps
	double value() {
		return current_in_A;
	}
	Current operator+(Current c) {
		return Current(value(UNITS::A) + c.value(UNITS::A), UNITS::A);
	}
	Current operator-(Current c) {
		return Current(value(UNITS::A) - c.value(UNITS::A), UNITS::A);
	}
	Current operator*(double val) {
		return Current(value(UNITS::A) * val, UNITS::A);
	}
	Current operator/(double val) {
		return Current(value(UNITS::A) / val, UNITS::A);
	}
	Power operator* (Voltage v) {
		return Power(value(UNITS::A) * v.value(UNITS::V), UNITS::W);
	}
	bool operator> (Current c) {
		return (value(UNITS::A) > c.value(UNITS::A));
	}
	bool operator>= (Current c) {
		return (value(UNITS::A) >= c.value(UNITS::A));
	}
	bool operator< (Current c) {
		return (value(UNITS::A) < c.value(UNITS::A));
	}
	bool operator<= (Current c) {
		return (value(UNITS::A) <= c.value(UNITS::A));
	}
	bool operator== (Current c) {
		return (value(UNITS::A) == c.value(UNITS::A));
	}
	bool operator!= (Current c) {
		return (value(UNITS::A) != c.value(UNITS::A));
	}
	bool operator++() {
		return (value(UNITS::A) > 0);
	}
	bool operator--() {
		return (value(UNITS::A) < 0);
	}
protected:
	double current_in_A;
};

class Torque {
public:
	Torque() {
		torque_in_Nm = 0;
	}
	//Nm, inlb, ftlb
	Torque(double val, UNITS::TorqueUnits units) {
		set(val, units);
	}
	//Nm, inlb, ftlb
	void set(double val, UNITS::TorqueUnits units);
	//Nm, inlb, ftlb
	double value(UNITS::TorqueUnits units);
	Torque operator+ (Torque t) {
		return Torque(value(UNITS::Nm) + t.value(UNITS::Nm), UNITS::Nm);
	}
	Torque operator- (Torque t) {
		return Torque(value(UNITS::Nm) - t.value(UNITS::Nm), UNITS::Nm);
	}
	Torque operator* (double val) {
		return Torque(value(UNITS::Nm) * val, UNITS::Nm);
	}
	Torque operator/ (double val) {
		return Torque(value(UNITS::Nm) / val, UNITS::Nm);
	}
	Length operator/ (Force f) {
		return Length(value(UNITS::Nm) / f.value(UNITS::N), UNITS::m);
	}
	Force operator/ (Length l) {
		return Force(value(UNITS::Nm) / l.value(UNITS::m), UNITS::N);
	}
	/*Power operator* (RotationSpeed speed) {
		Power myPower = Power(value(UNITS::Nm) * speed.value(UNITS::rev_s) * 6.28318530718, UNITS::W);
		return myPower;
			//Power(value(UNITS::Nm) * speed.value(UNITS::rev_s) * 6.28318530718, UNITS::W);
	}*/
	bool operator> (Torque t) {
		return (value(UNITS::Nm) > t.value(UNITS::Nm));
	}
	bool operator>= (Torque t) {
		return (value(UNITS::Nm) > t.value(UNITS::Nm));
	}
	bool operator< (Torque t) {
		return (value(UNITS::Nm) > t.value(UNITS::Nm));
	}
	bool operator<= (Torque t) {
		return (value(UNITS::Nm) <= t.value(UNITS::Nm));
	}
	bool operator== (Torque t) {
		return (value(UNITS::Nm) == t.value(UNITS::Nm));
	}
	bool operator!= (Torque t) {
		return (value(UNITS::Nm) != t.value(UNITS::Nm));
	}
	bool operator++() {
		return (value(UNITS::Nm) > 0);
	}
	bool operator--() {
		return (value(UNITS::Nm) < 0);
	}
	operator Energy() {
		return Energy(value(UNITS::Nm), UNITS::J);
	}
protected:
	double torque_in_Nm;
};

class RotationSpeed {
public:
	RotationSpeed() {
		rotationSpeed_in_rpm = 0;
	}
	//rpm, rev_s, rad_s
	RotationSpeed(double val, UNITS::RotationSpeedUnits units) {
		set(val, units);
	}
	//rpm, rev_s, rad_s
	void set(double val, UNITS::RotationSpeedUnits units);
	//rpm, rev_s, rad_s
	double value(UNITS::RotationSpeedUnits units);
	RotationSpeed operator+(RotationSpeed spd) {
		return RotationSpeed(value(UNITS::rpm) + spd.value(UNITS::rpm), UNITS::rpm);
	}
	RotationSpeed operator-(RotationSpeed spd) {
		return RotationSpeed(value(UNITS::rpm) - spd.value(UNITS::rpm), UNITS::rpm);
	}
	RotationSpeed operator*(double val) {
		return RotationSpeed(value(UNITS::rpm) * val, UNITS::rpm);
	}
	RotationSpeed operator/(double val) {
		return RotationSpeed(value(UNITS::rpm) / val, UNITS::rpm);
	}
	Power operator*(Torque torque) {
		double RPM = value(UNITS::rpm);
		if (RPM < 0) {
			RPM = -RPM;;
		}
		double t = torque.value(UNITS::Nm);
		if (torque--) {
			t = -t;
		}
		return Power(RPM * t, UNITS::W);
	}
	Angle operator*(TimeDuration time) {
		return Angle(value(UNITS::rpm) * time.value(UNITS::min), REVOLUTIONS);
	}
	bool operator> (RotationSpeed speed) {
		return (value(UNITS::rpm) > speed.value(UNITS::rpm));
	}
	bool operator>= (RotationSpeed speed) {
		return (value(UNITS::rpm) >= speed.value(UNITS::rpm));
	}
	bool operator< (RotationSpeed speed) {
		return (value(UNITS::rpm) < speed.value(UNITS::rpm));
	}
	bool operator<= (RotationSpeed speed) {
		return (value(UNITS::rpm) <= speed.value(UNITS::rpm));
	}
	bool operator== (RotationSpeed speed) {
		return (value(UNITS::rpm) == speed.value(UNITS::rpm));
	}
	bool operator!= (RotationSpeed speed) {
		return (value(UNITS::rpm) != speed.value(UNITS::rpm));
	}
	bool operator++() {
		return (value(UNITS::rpm) > 0);
	}
	bool operator--() {
		return (value(UNITS::rpm) < 0);
	}

protected:
	double rotationSpeed_in_rpm;
};

class Resistance {
public:
	Resistance() {
		resistance_in_Ohm = 0;
	}
	//Ohm, mOhm, kOhm, MOhm
	Resistance(double val, UNITS::ResistanceUnits units) {
		set(val, units);
	}
	Resistance(double val) {
		set(val, UNITS::Ohm);
	}
	//Ohm, mOhm, kOhm, MOhm
	void set(double val, UNITS::ResistanceUnits units);
	//Ohm, mOhm, kOhm, MOhm
	double value(UNITS::ResistanceUnits units);
	Resistance operator+(Resistance R) {
		return Resistance(value(UNITS::Ohm) + R.value(UNITS::Ohm), UNITS::Ohm);
	}
	Resistance operator-(Resistance R) {
		return Resistance(value(UNITS::Ohm) - R.value(UNITS::Ohm), UNITS::Ohm);
	}
	Resistance operator*(double val) {
		return Resistance(value(UNITS::Ohm) * val, UNITS::Ohm);
	}
	Resistance operator/(double val) {
		return Resistance(value(UNITS::Ohm) / val, UNITS::Ohm);
	}
	Voltage operator*(Current c) {
		return Voltage(value(UNITS::Ohm) * c.value(UNITS::A), UNITS::V);
	}
	bool operator>(Resistance R) {
		return (value(UNITS::Ohm) > R.value(UNITS::Ohm));
	}
	bool operator>=(Resistance R) {
		return (value(UNITS::Ohm) >= R.value(UNITS::Ohm));
	}
	bool operator<(Resistance R) {
		return (value(UNITS::Ohm) < R.value(UNITS::Ohm));
	}
	bool operator<=(Resistance R) {
		return (value(UNITS::Ohm) <= R.value(UNITS::Ohm));
	}
	bool operator==(Resistance R) {
		return (value(UNITS::Ohm) == R.value(UNITS::Ohm));
	}
	bool operator!=(Resistance R) {
		return (value(UNITS::Ohm) != R.value(UNITS::Ohm));
	}
protected:
	double resistance_in_Ohm;
};

class Capacitance {
public:
	Capacitance() {
		capacitance_in_Farad = 0;
	}
	//Farad, uF, mF, nF, pF
	Capacitance(double val, UNITS::CapacitanceUnits units) {
		set(val, units);
	}
	Capacitance(double val) {
		set(val, UNITS::Farad);
	}
	//Farad, uF, mF, nF, pF
	void set(double val, UNITS::CapacitanceUnits units);
	//Farad, uF, mF, nF, pF
	double value(UNITS::CapacitanceUnits units);
	Capacitance operator+(Capacitance cap) {
		return Capacitance(value(UNITS::Farad) + cap.value(UNITS::Farad), UNITS::Farad);
	}
	Capacitance operator-(Capacitance cap) {
		return Capacitance(value(UNITS::Farad) - cap.value(UNITS::Farad), UNITS::Farad);
	}
	Capacitance operator*(double val) {
		return Capacitance(value(UNITS::Farad) * val, UNITS::Farad);
	}
	Capacitance operator/(double val) {
		return Capacitance(value(UNITS::Farad) / val, UNITS::Farad);
	}
	bool operator>(Capacitance cap) {
		return (value(UNITS::Farad) > cap.value(UNITS::Farad));
	}
	bool operator>=(Capacitance cap) {
		return (value(UNITS::Farad) >= cap.value(UNITS::Farad));
	}
	bool operator< (Capacitance cap) {
		return (value(UNITS::Farad) < cap.value(UNITS::Farad));
	}
	bool operator<=(Capacitance cap) {
		return (value(UNITS::Farad) <= cap.value(UNITS::Farad));
	}
	bool operator==(Capacitance cap) {
		return (value(UNITS::Farad) == cap.value(UNITS::Farad));
	}
	bool operator!=(Capacitance cap) {
		return (value(UNITS::Farad) != cap.value(UNITS::Farad));
	}
protected:
	double capacitance_in_Farad;
};
