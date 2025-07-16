#include "Measurement.h"

inline void TimeDuration::set(double value, UNITS::TimeUnits units) {
	//SECOND, MINUTE, HOUR, DAY, WEEK, YEAR, MILLISECOND, MICROSECOND, NANOSECOND
	switch (units) {
	case UNITS::s:
		time_in_s = value;
		break;
	case UNITS::min:
		time_in_s = value * 60;
		break;
	case UNITS::hr:
		time_in_s = value * 3600;
		break;
	case UNITS::day:
		time_in_s = value * (3600 * 24);
		break;
	case UNITS::week:
		time_in_s = value * (3600 * 24 * 7);
		break;
	case UNITS::yr:
		time_in_s = value * (3600 * 24 * 365.25);
		break;
	case UNITS::ms:
		time_in_s = value / 1000;
		break;
	case UNITS::us:
		time_in_s = value / 1000000;
		break;
	case UNITS::ns:
		time_in_s = value / 1000000000;
		break;
	}
}

inline double TimeDuration::value(UNITS::TimeUnits units) {
	switch (units) {
	case UNITS::s:
		return time_in_s;
	case UNITS::min:
		return time_in_s / 60;
		break;
	case UNITS::hr:
		return time_in_s / 3600;
		break;
	case UNITS::day:
		return time_in_s / (3600 * 24);
		break;
	case UNITS::week:
		return time_in_s / (3600 * 24 * 7);
		break;
	case UNITS::yr:
		return time_in_s / (3600 * 24 * 365.25);
		break;
	case UNITS::ms:
		return time_in_s * 1000;
		break;
	case UNITS::us:
		return time_in_s * 1000000;
		break;
	case UNITS::ns:
		return time_in_s * 1000000000;
		break;
	}
}

inline void Length::set(double value, UNITS::LengthUnits units) {
	switch (units) {
	case UNITS::m:
		length_in_m = value;
		break;
	case UNITS::cm:
		length_in_m = value / 100;
		break;
	case UNITS::mm:
		length_in_m = value / 1000;
		break;
	case UNITS::um:
		length_in_m = value / 1000000;
		break;
	case UNITS::km:
		length_in_m = value * 1000;
		break;
	case UNITS::in:
		set(value / 25.4, UNITS::mm);
		break;
	case UNITS::ft:
		set(value * 12, UNITS::in);
		break;
	case UNITS::mi:
		set(value * 5280, UNITS::ft);
		break;
	case UNITS::yd:
		set(value * 3, UNITS::ft);
		break;
	}
}

inline double Length::value(UNITS::LengthUnits units) {
	switch (units) {
	case UNITS::m:
		return length_in_m;
		break;
	case UNITS::cm:
		return (length_in_m * 100);
		break;
	case UNITS::mm:
		return (length_in_m * 1000);
		break;
	case UNITS::um:
		return (length_in_m * 1000000);
		break;
	case UNITS::km:
		return (length_in_m / 1000);
		break;
	case UNITS::in:
		return value(UNITS::mm) / 25.4;
		break;
	case UNITS::ft:
		return value(UNITS::in) / 12;
		break;
	case UNITS::mi:
		return value(UNITS::ft) / 5280;
		break;
	case UNITS::yd:
		return value(UNITS::ft) / 3;
		break;
	}

}

inline void Area::set(double value, UNITS::AreaUnits units) {
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
	//store as m^2
	switch (units) {
	case UNITS::m2:
		area_in_m2 = value;
		break;
	case UNITS::cm2:
		area_in_m2 = value / (100.0 * 100.0);
		break;
	case UNITS::mm2:
		area_in_m2 = value / 1000000.0;
		break;
	case UNITS::um2:
		area_in_m2 = value / 1000000000.0;
		break;
	case UNITS::km2:
		area_in_m2 = value * 1000000.0;
		break;
	case UNITS::in2:
		area_in_m2 = value * .00064516;
		break;
	case UNITS::ft2:
		area_in_m2 = value * .00064516 * 144;
		break;
	case UNITS::yd2:
		area_in_m2 = value * .00064516 * 144 * 9;
		break;
	case UNITS::mi2:
		area_in_m2 = value * .00064516 * 144 * 5280 * 5280;
		break;
	case UNITS::acre:
		area_in_m2 = value * .00064516 * 144 * 43560.0;
		break;
	case UNITS::hectare:
		area_in_m2 = 10000.0 * value;
		break;
	}
}

inline double Area::value(UNITS::AreaUnits units) {
	//m2, cm2, mm2, um2, km2, in2, ft2, yd2, mi2, acre, hectare
	//convert from m2
	switch (units) {
	case UNITS::m2:
		return area_in_m2;
		break;
	case UNITS::cm2:
		return area_in_m2 * (100.0 * 100.0);
		break;
	case UNITS::mm2:
		return area_in_m2 * 1000000.0;
		break;
	case UNITS::um2:
		return area_in_m2 * 1000000000.0;
		break;
	case UNITS::km2:
		return area_in_m2 / 1000000.0;
		break;
	case UNITS::in2:
		return area_in_m2 / .00064516;
		break;
	case UNITS::ft2:
		return area_in_m2 / (.00064516 * 144);
		break;
	case UNITS::yd2:
		return area_in_m2 / (.00064516 * 144 * 9);
		break;
	case UNITS::mi2:
		return area_in_m2 / (.00064516 * 144 * 5280 * 5280);
		break;
	case UNITS::acre:
		return area_in_m2 / (.00064516 * 144 * 43560.0);
		break;
	case UNITS::hectare:
		return area_in_m2 / 10000.0;
		break;
	}
}

inline void Volume::set(double value, UNITS::VolumeUnits units) {
	switch (units) {
	case UNITS::m3:
		volume_in_L = value * 1000.0;
		break;
	case UNITS::cm3:
		volume_in_L = value / 1000.0;
		break;
	case UNITS::mm3:
		volume_in_L = value / 1000000.0;
		break;
	case UNITS::km3:
		volume_in_L = value * 1000000.0;
		break;
	case UNITS::L:
		volume_in_L = value;
		break;
	case UNITS::mL:
		volume_in_L = value / 1000.0;
		break;
	case UNITS::in3:
		volume_in_L = value / 61.023744;
		break;
	case UNITS::ft3:
		set(value * 1728, UNITS::in3);
		break;
	case UNITS::yd3:
		set(value * 15552, UNITS::in3);
		break;
	case UNITS::mi3:
		set(value * 254358061056000, UNITS::in3);
		break;
	case UNITS::tsp:
		set(value / 96, UNITS::pint);
		break;
	case UNITS::tbsp:
		set(value / 32, UNITS::pint);
		break;
	case UNITS::cup:
		set(value / 2, UNITS::pint);
		break;
	case UNITS::pint:
		volume_in_L = value * .473176473;
		break;
	case UNITS::quart:
		set(value * 2, UNITS::pint);
		break;
	case UNITS::gallon:
		set(value * 8, UNITS::pint);
		break;
	case UNITS::barrel:
		set(value * 31.5, UNITS::gallon);
		break;
	}
}

inline double Volume::value(UNITS::VolumeUnits units) {
	switch (units) {
	case UNITS::m3:
		return volume_in_L / 1000.0;
		break;
	case UNITS::cm3:
		return volume_in_L * 1000.0;
		break;
	case UNITS::mm3:
		return volume_in_L * 1000000.0;
		break;
	case UNITS::km3:
		return volume_in_L / 1000000.0;
		break;
	case UNITS::L:
		return volume_in_L;
		break;
	case UNITS::mL:
		return volume_in_L * 1000.0;
		break;
	case UNITS::in3:
		return volume_in_L * 61.023744;
		break;
	case UNITS::ft3:
		return value(UNITS::in3) / 1728;
		break;
	case UNITS::yd3:
		return value(UNITS::in3) / 15552;
		break;
	case UNITS::mi3:
		return value(UNITS::in3) / 254358061056000.0;
		break;
	case UNITS::tsp:
		return value(UNITS::pint) * 96;
		break;
	case UNITS::tbsp:
		return value(UNITS::pint) * 32;
		break;
	case UNITS::cup:
		return value(UNITS::pint) * 2;
		break;
	case UNITS::pint:
		return volume_in_L / .473176473;
		break;
	case UNITS::quart:
		return value(UNITS::pint) / 2;
		break;
	case UNITS::gallon:
		return value(UNITS::pint) / 8;
		break;
	case UNITS::barrel:
		return value(UNITS::pint) / 31.5;
		break;
	}
}

inline void Speed::set(double value, UNITS::SpeedUnits units) {
	switch (units) {
	case UNITS::m_s:
		speed_in_m_s = value;
		break;
	case UNITS::kph: 
		{
			double metersPerHour = value * 1000;
			double metersPerSecond = metersPerHour / 3600;
			speed_in_m_s = metersPerSecond;
		}
		break;
	case UNITS::mph: 
		{
			Length distanceInHr(value, UNITS::mi);
			double MetersPerHour = distanceInHr.value(UNITS::m);
			double MetersPerSecond = MetersPerHour / 3600;
			speed_in_m_s = MetersPerSecond;
		}	
		break;
	case UNITS::ft_s: 
		{
			Length distanceInSecond(value, UNITS::ft);
			speed_in_m_s = distanceInSecond.value(UNITS::m);
		}
		break;
	}
}

inline double Speed::value(UNITS::SpeedUnits units) {
	switch (units) {
	case UNITS::m_s:
		return speed_in_m_s;
		break;
	case UNITS::kph:
		return speed_in_m_s * 3600 / 1000;
		break;
	case UNITS::mph:
		{
			Length distanceInHr(speed_in_m_s * 3600, UNITS::m);
			return distanceInHr.value(UNITS::mi);
		}
		break;
	case UNITS::ft_s:
		{
			Length distanceInSecond(speed_in_m_s, UNITS::m);
			return distanceInSecond.value(UNITS::ft);
		}
	break;
	}
}

inline void Acceleration::set(double value, UNITS::AccelerationUnits units) {
	switch (units) {
	case UNITS::m_s2:
		acceleration_in_m_s2 = value;
		break;
	case UNITS::kph_s:
	{
		Speed increasePerSecond(value, UNITS::kph);
		acceleration_in_m_s2 = increasePerSecond.value(UNITS::m_s);
	}	break;
	case UNITS::mph_s:
	{
		Speed increasePerSecond(value, UNITS::mph);
		acceleration_in_m_s2 = increasePerSecond.value(UNITS::m_s);
	}	break;
	case UNITS::ft_s2:
		acceleration_in_m_s2 = value * .3048;
		break;
	case UNITS::G:
		acceleration_in_m_s2 = value * 9.80665;
		break;
	}
}

inline double Acceleration::value(UNITS::AccelerationUnits units) {
	switch (units) {
	case UNITS::m_s2:
		return acceleration_in_m_s2;
		break;
	case UNITS::kph_s:
	{
		Speed increasePerSecond(acceleration_in_m_s2, UNITS::m_s);
		return increasePerSecond.value(UNITS::kph);
	}	break;
	case UNITS::mph_s:
	{	
		Speed incPerSecond(acceleration_in_m_s2, UNITS::m_s);
		return incPerSecond.value(UNITS::mph);
	}	break;
	case UNITS::ft_s2:
		return acceleration_in_m_s2 / .3048;
		break;
	case UNITS::G:
		return acceleration_in_m_s2 / 9.80665;
		break;
	}
}

inline void Mass::set(double value, UNITS::MassUnits units) {
	switch (units) {
	case UNITS::gram:
		mass_in_kg = value / 1000;
		break;
	case UNITS::kg:
		mass_in_kg = value;
		break;
	case UNITS::lb:
		mass_in_kg = value * .45359237;
		break;
	case UNITS::oz:
		set(value / 16, UNITS::lb);
		break;
	case UNITS::tonne:
		mass_in_kg = value * 1000;
		break;
	case UNITS::ton:
		set(2000, UNITS::lb);
		break;
	}
}

inline double Mass::value(UNITS::MassUnits units) {
	switch (units) {
	case UNITS::gram:
		return mass_in_kg * 1000;
		break;
	case UNITS::kg:
		return mass_in_kg;
		break;
	case UNITS::lb:
		return mass_in_kg / .45359237;
		break;
	case UNITS::oz:
		return value(UNITS::lb) * 16;
		break;
	case UNITS::tonne:
		return mass_in_kg * 1000;
		break;
	case UNITS::ton:
		return value(UNITS::lb) * 2000;
		break;
	}
}

inline void Force::set(double value, UNITS::ForceUnits units) {
	switch (units) {
	case UNITS::N:
		force_in_N = value;
		break;
	case UNITS::lbf:
		force_in_N = value / .2248089431;
		break;
	}
}

inline double Force::value(UNITS::ForceUnits units) {
	switch (units) {
	case UNITS::N:
		return force_in_N;
		break;
	case UNITS::lbf:
		return force_in_N * .2248089431;
		break;
	}
}

inline void Pressure::set(double value, UNITS::PressureUnits units) {
	switch (units) {
	case UNITS::Pa:
		pressure_in_Pa = value;
		break;
	case UNITS::kPa:
		pressure_in_Pa = value * 1000;
		break;
	case UNITS::MPa:
		pressure_in_Pa = value * 1000000;
		break;
	case UNITS::psi:
		pressure_in_Pa = value * 6894.75729317;
		break;
	case UNITS::mmHg:
		pressure_in_Pa = value * 133.322387415;
		break;
	case UNITS::inH2O:
		pressure_in_Pa = value * 249.08891;
		break;
	case UNITS::bar:
		pressure_in_Pa = value * 100000;
		break;
	case UNITS::atm:
		pressure_in_Pa = value * 101325;
		break;
	}
}

inline double Pressure::value(UNITS::PressureUnits units) {
	switch (units) {
	case UNITS::Pa:
		return pressure_in_Pa;
		break;
	case UNITS::kPa:
		return pressure_in_Pa / 1000;
		break;
	case UNITS::MPa:
		return pressure_in_Pa / 1000000;
		break;
	case UNITS::psi:
		return pressure_in_Pa / 6894.75729317;
		break;
	case UNITS::mmHg:
		return pressure_in_Pa / 133.322387415;
		break;
	case UNITS::inH2O:
		return pressure_in_Pa / 249.08891;
		break;
	case UNITS::bar:
		return pressure_in_Pa / 100000;
		break;
	case UNITS::atm:
		return pressure_in_Pa / 101325;
		break;
	}
}


//C, K, F, R


//defaults to 0C

inline Temperature::Temperature() {
	set(0, UNITS::C);
}

inline Temperature::Temperature(double value, UNITS::TemperatureUnits units) {
	set(value, units);
}

//J, kJ, mJ, kWh, hph, BTU

inline void Energy::set(double val, UNITS::EnergyUnits units) {
	switch (units) {
	case UNITS::J:
		energy_in_J = val;
		break;
	case UNITS::kJ:
		energy_in_J = val * 1000;
		break;
	case UNITS::MJ:
		energy_in_J = val * 1000000;
		break;
	case UNITS::kWh:
		energy_in_J = val * 3600000;
		break;
	case UNITS::hph:
		energy_in_J = val * 2684519.5368856;
		break;
	case UNITS::BTU:
		energy_in_J = val * 1055.05585262;
		break;
	case UNITS::cal:
		energy_in_J = val * 4.184;
		break;
	case UNITS::kCal:
		energy_in_J = val * 4184;
		break;
	}
}

inline double Energy::value(UNITS::EnergyUnits units) {
	switch (units) {
	case UNITS::J:
		return energy_in_J;
		break;
	case UNITS::kJ:
		return energy_in_J / 1000;
		break;
	case UNITS::MJ:
		return energy_in_J / 1000000;
		break;
	case UNITS::kWh:
		return energy_in_J / 3600000;
		break;
	case UNITS::hph:
		return energy_in_J / 2684519.5368856;
		break;
	case UNITS::BTU:
		return energy_in_J / 1055.05585262;
		break;
	case UNITS::cal:
		return energy_in_J / 4.184;
		break;
	case UNITS::kCal:
		return energy_in_J / 4184;
		break;
	}
}

//W, kW, MW, mW, hp, BTU_h


//W, kW, MW, mW, hp, BTU_h

inline Power::Power(double val, UNITS::PowerUnits units) {
	set(val, units);
}

inline void Power::set(double val, UNITS::PowerUnits units) {
	switch (units) {
	case UNITS::W:
		power_in_W = val;
		break;
	case UNITS::kW:
		power_in_W = val * 1000;
		break;
	case UNITS::MW:
		power_in_W = val * 1000000;
		break;
	case UNITS::mW:
		power_in_W = val / 1000;
		break;
	case UNITS::hp:
		power_in_W = val * 745.699872;
		break;
	case UNITS::BTU_h:
		power_in_W = val / 3.41;
		break;
	}
}

//W, kW, MW, mW, cal, kCal, hp, BTU_h

inline double Power::value(UNITS::PowerUnits units) {
	switch (units) {
	case UNITS::W:
		return power_in_W;
		break;
	case UNITS::kW:
		return power_in_W / 1000;
		break;
	case UNITS::MW:
		return power_in_W / 1000000;
		break;
	case UNITS::mW:
		return power_in_W * 1000;
		break;
	case UNITS::hp:
		return power_in_W / 745.699872;
		break;
	case UNITS::BTU_h:
		return power_in_W * 3.41;
		break;
	}

}

//kg_m3, g_cm3, lb_gal

inline void Density::set(double val, UNITS::DensityUnits units) {
	switch (units) {
	case UNITS::kg_m3:
		density_relative_to_water = val / 1000;
		break;
	case UNITS::g_cm3:
		density_relative_to_water = val;
		break;
	case UNITS::lb_gal:
		density_relative_to_water = val * 8.34540445;
		break;
	}
}

//kg_m3, g_cm3, lb_gal

inline double Density::value(UNITS::DensityUnits units) {
	switch (units) {
	case UNITS::kg_m3:
		return density_relative_to_water * 1000;
		break;
	case UNITS::g_cm3:
		return density_relative_to_water;
		break;
	case UNITS::lb_gal:
		return density_relative_to_water / 8.34540445;
		break;
	}

}

inline void Current::set(double val, UNITS::CurrentUnits units) {
	switch (units) {
	case UNITS::A:
		current_in_A = val;
		break;
	case UNITS::kA:
		current_in_A = val * 1000;
		break;
	case UNITS::mA:
		current_in_A = val / 1000;
		break;
	case UNITS::MA:
		current_in_A = val * 1000000;
		break;
	}
}

inline double Current::value(UNITS::CurrentUnits units) {
	switch (units) {
	case UNITS::A:
		return current_in_A;
		break;
	case UNITS::kA:
		return current_in_A / 1000;
		break;
	case UNITS::mA:
		return current_in_A * 1000;
		break;
	case UNITS::MA:
		return current_in_A / 1000000;
		break;
	}
}

inline void Voltage::set(double val, UNITS::VoltageUnits units) {
	switch (units) {
	case UNITS::V:
		voltage_in_V = val;
		break;
	case UNITS::mV:
		voltage_in_V = val / 1000;
		break;
	case UNITS::kV:
		voltage_in_V = val * 1000;
		break;
	case UNITS::MV:
		voltage_in_V = val * 1000000;
		break;
	}
}

inline double Voltage::value(UNITS::VoltageUnits units) {
	switch (units) {
	case UNITS::V:
		return voltage_in_V;
		break;
	case UNITS::mV:
		return voltage_in_V * 1000;
		break;
	case UNITS::kV:
		return voltage_in_V / 1000;
		break;
	case UNITS::MV:
		return voltage_in_V / 1000000;
		break;
	}
}

//Nm, inlb, ftlb
inline void Torque::set(double val, UNITS::TorqueUnits units) {
	switch (units) {
	case UNITS::Nm:
		torque_in_Nm = val;
		break;
	case UNITS::inlb:
		torque_in_Nm = val / 8.85074576737892;
		break;
	case UNITS::ftlb:
		torque_in_Nm = val / (12 * 8.85074576737892);
		break;
	}
}

//Nm, inlb, ftlb
inline double Torque::value(UNITS::TorqueUnits units) {
	switch (units) {
	case UNITS::Nm:
		return torque_in_Nm;
		break;
	case UNITS::inlb:
		return torque_in_Nm * 8.85074576737892;
		break;
	case UNITS::ftlb:
		return torque_in_Nm * (12 * 8.85074576737892);
		break;
	}
}

//rpm, rev_s, rad_s
inline void RotationSpeed::set(double val, UNITS::RotationSpeedUnits units) {
	switch (units) {
	case (UNITS::rpm):
		rotationSpeed_in_rpm = val;
		break;
	case(UNITS::rev_s):
		rotationSpeed_in_rpm = val / 60;
		break;
	case(UNITS::rad_s):
		rotationSpeed_in_rpm = val / (6.28 * 60);
		break;
	case(UNITS::deg_s):
		rotationSpeed_in_rpm = val / (360 * 60);
		break;
	}
}

//rpm, rev_s, rad_s
inline double RotationSpeed::value(UNITS::RotationSpeedUnits units) {
	switch (units) {
	case (UNITS::rpm):
		return rotationSpeed_in_rpm;
		break;
	case(UNITS::rev_s):
		return rotationSpeed_in_rpm * 60;
		break;
	case(UNITS::rad_s):
		return rotationSpeed_in_rpm * (6.28 * 60);
		break;
	case(UNITS::deg_s):
		return rotationSpeed_in_rpm * (360 * 60);
		break;
	}
}

inline void Capacitance::set(double val, UNITS::CapacitanceUnits units) {
	switch (units) {
	case(UNITS::Farad):
		capacitance_in_Farad = val;
		break;
	case(UNITS::mF):
		capacitance_in_Farad = val * 0.001;
		break;
	case(UNITS::uF):
		capacitance_in_Farad = val * 0.000001;
		break;
	case(UNITS::nF):
		capacitance_in_Farad = val * 0.000000001;
		break;
	case(UNITS::pF):
		capacitance_in_Farad = val * 0.000000000001;
		break;
	}
}

inline double Capacitance::value(UNITS::CapacitanceUnits units) {
	switch (units) {
	case(UNITS::Farad):
		return capacitance_in_Farad;
		break;
	case(UNITS::mF):
		return capacitance_in_Farad * 1000;
		break;
	case(UNITS::uF):
		return capacitance_in_Farad * 1000000;
		break;
	case(UNITS::nF):
		return capacitance_in_Farad * 1000000000;
		break;
	case(UNITS::pF):
		return capacitance_in_Farad * 1000000000000;
		break;
	}
}

// Ohm, mOhm, kOhm, MOhm
inline void Resistance::set(double val, UNITS::ResistanceUnits units) {
	switch (units) {
	case(UNITS::Ohm):
		resistance_in_Ohm = val;
		break;
	case(UNITS::mOhm):
		resistance_in_Ohm = val * .001;
		break;
	case(UNITS::kOhm):
		resistance_in_Ohm = val * 1000;
		break;
	case(UNITS::MOhm):
		resistance_in_Ohm = val * 1000000;
		break;
	}
}

//Ohm, mOhm, kOhm, MOhm
inline double Resistance::value(UNITS::ResistanceUnits units) {
	switch (units) {
	case(UNITS::Ohm):
		return resistance_in_Ohm;
		break;
	case(UNITS::mOhm):
		return resistance_in_Ohm * 1000;
		break;
	case(UNITS::kOhm):
		return resistance_in_Ohm * .001;
		break;
	case(UNITS::MOhm):
		return resistance_in_Ohm * .000001;
		break;
	}

}
