/*------------------------------GPL---------------------------------------//
// This file is part of ADCIRCModules.
//
// (c) 2015-2019 Zachary Cobell
//
// ADCIRCModules is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ADCIRCModules is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ADCIRCModules.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------*/
#ifndef ADCIRC_OUTPUTFILES_H
#define ADCIRC_OUTPUTFILES_H

#include <vector>

#include "OutputMetadata.h"

using namespace Adcirc::Output;

static const std::vector<OutputMetadata> c_outputMetadata = {
    OutputMetadata("sigmat", "water column vertically varying density",
                   "water_density_vertically_varying", "kg/m^3",
                   OutputMetadata::defaultConvention(), "salinity",
                   "water column vertically varying salinity",
                   "water_salinity_vertically_varying", "psu",
                   OutputMetadata::defaultConvention(), "temperature",
                   "water column vertically varying temperature",
                   "water_temperature_vertically_varying", "Celsius",
                   OutputMetadata::defaultConvention()),
    OutputMetadata(
        "u-vel3D", "water column vertically varying east/west velocity",
        "eastward_water_velocity_vertically_varying", "m/s", "east", "v-vel3D",
        "water column vertically varying north/south velocity",
        "northward_water_velocity_vertically_varying", "m/s", "north",
        "w-vel3D", "water column vertically varying up/down velocity",
        "upward_water_velocity_vertically_varying", "m/s", "up", false, true),
    OutputMetadata("q20",
                   "water column vertically varying turbulent kinetic energy",
                   "turbulent_kinetic_energy_vertically_varying", "m s-2",
                   OutputMetadata::defaultConvention(), "l",
                   "water column vertically varying mixing length",
                   "water_mixing_length_vertically_varying", "m",
                   OutputMetadata::defaultConvention(), "ev",
                   "water column vertically varying eddy viscosity",
                   "water_eddy_viscosity_vertically_varying", "m^2/s",
                   OutputMetadata::defaultConvention(), false, false),
    OutputMetadata("qsurfkp1", "sea surface temperature at the k+1 time level",
                   "future sea surface temperature", "Celsius",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("zeta", "water surface elevation above geoid",
                   "sea_surface_height_above_geoid", "m",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("tau0", "primitive weighting in continuity equation",
                   "primitive_weighting_in_continuity_equation", "1",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("zeta_max", "'maximum water surface elevation",
                   "maximum_sea_surface_height_above_geoid", "m",
                   OutputMetadata::defaultConvention(), "time_of_zeta_max",
                   "time of maximum water surface elevation above geoid",
                   "time_of_maximum_sea_surface_height_above_geoid", "sec",
                   OutputMetadata::defaultConvention(), true, false),
    OutputMetadata("u-vel",
                   "water column vertically averaged east/west velocity",
                   "eastward_water_velocity", "m/s", "east", "v-vel",
                   "water column vertically averaged north/south velocity",
                   "northward_water_velocity", "m/s", "north", false, true),
    OutputMetadata("vel_max",
                   "maximum water column vertically averaged velocity",
                   "maximum_water_velocity", "m/s",
                   OutputMetadata::defaultConvention(), "time_of_vel_max",
                   "time of maximum water column vertically averaged velocity",
                   "time_of_maximum_water_velocity", "sec",
                   OutputMetadata::defaultConvention(), true, false),
    OutputMetadata("winddrag", "wind drag coefficient at sea level",
                   "wind drag coefficient", "unitless",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("pressure", "air pressure at sea level",
                   "air_pressure_at_sea_level", "mH20",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("pressure_min", "minimum air pressure at sea level",
                   "minimum_air_pressure_at_sea_level", "mH20",
                   OutputMetadata::defaultConvention(), "time_of_pressure_min",
                   "time of minimum air pressure at sea level",
                   "time_of_minimum_air_pressure_at_sea_level", "sec",
                   OutputMetadata::defaultConvention(), true, false),
    OutputMetadata("windx", "e/w wind velocity", "eastward_wind", "m/s", "east",
                   "windy", "'n/s wind velocity", "northward_wind", "m/s",
                   "north", false, true),
    OutputMetadata("wind_max", "maximum wind velocity", "maximum_wind", "m/s",
                   OutputMetadata::defaultConvention(), "time_of_wind_max",
                   "time of maximum wind velocity", "time_of_maximum_wind",
                   "sec", OutputMetadata::defaultConvention(), true, false),
    OutputMetadata("radstress_max", "maximum radiation stress gradient",
                   "maximum_radiation_stress", "m-2 s-2",
                   OutputMetadata::defaultConvention(), "time_of_radstress_max",
                   "time of maximum radiation stress gradient",
                   "time_of_maximum_radiation_stress", "sec",
                   OutputMetadata::defaultConvention(), true, false),
    OutputMetadata("weir_dz", "elevation change in weir boundary condition",
                   "weir_elevation_change", "m",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("radstress_x", "radiation stress gradient x component",
                   "radiation_stress_gradient_x", "m-2 s-2", "east",
                   "radstress_y", "radiation stress gradient y component",
                   "radiation_stress_gradient_y", "m-2 s-2", "north", false,
                   true),
    OutputMetadata("swan_HS", "significant wave height",
                   "sea_surface_wave_significant_height", "m",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("swan_HS_max", "maximum significant wave height",
                   "maximum_sea_surface_wave_significant_height", "m",
                   OutputMetadata::defaultConvention(), true),
    OutputMetadata("swan_DIR", "mean wave direction",
                   "sea_surface_wave_to_direction", "degrees",
                   "degrees_CW_from_East"),
    OutputMetadata("swan_DIR_max", "maximum mean wave direction",
                   "maximum_sea_surface_wave_to_direction", "degrees",
                   "degrees_CW_from_East", true),
    OutputMetadata("swan_TM01", "mean absolute wave period",
                   "sea_surface_wave_mean_period_from_variance_spectral_"
                   "density_first_frequency_moment",
                   "s", OutputMetadata::defaultConvention()),
    OutputMetadata("swan_TM01_max", "maximum TM01 mean wave period",
                   "maximum_sea_surface_wave_mean_period_from_variance_"
                   "spectral_density_first_frequency_moment",
                   "s", OutputMetadata::defaultConvention(), true),
    OutputMetadata(
        "swan_TPS", "smoothed peak period",
        "sea_surface_wave_period_at_variance_spectral_density_maximum", "s",
        OutputMetadata::defaultConvention()),
    OutputMetadata(
        "swan_TPS_max", "maximum smoothed peak period",
        "maximum_sea_surface_wave_period_at_variance_spectral_density_maximum",
        "s", OutputMetadata::defaultConvention(), true),
    OutputMetadata("swan_windx", "e/w wind velocity", "eastward_wind", "m/s",
                   "east", "swan_windy", "n/s wind velocity", "northward_wind",
                   "m/s", "north"),
    OutputMetadata("swan_wind_max", "maximum wind velocity", "maximum_wind",
                   "m/s", OutputMetadata::defaultConvention(), true),
    OutputMetadata("swan_TM02", "mean absoloute zero crossing period",
                   "sea_surface_wave_mean_period_from_variance_spectral_"
                   "density_second_frequency_moment",
                   "s", OutputMetadata::defaultConvention()),
    OutputMetadata("swan_TM02_max", "maximum TM02 mean wave period",
                   "maximum_sea_surface_wave_mean_period_from_variance_"
                   "spectral_density_second_frequency_moment",
                   "s", OutputMetadata::defaultConvention(), true),
    OutputMetadata("swan_TMM10", "mean absolute wave period",
                   "sea_surface_wave_mean_period_from_variance_spectral_"
                   "density_inverse_frequency_moment",
                   "s", OutputMetadata::defaultConvention()),
    OutputMetadata("swan_TMM10_max", "maximum TMM10 mean wave period",
                   "maximum_sea_surface_wave_mean_period_from_variance_"
                   "spectral_density_inverse_frequency_moment",
                   "s", OutputMetadata::defaultConvention(), true),
    OutputMetadata("inun_time", "total time of inundation beyond the threshold",
                   "total_time_of_inundation_beyond_the_threshold", "s",
                   OutputMetadata::defaultConvention(), "onset_inun_time",
                   "time of onset of inundation beyond the threshold",
                   "time_of_onset_of_inundation_beyond_the_threshold", "s",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("inun_max", "maximum water inundation depth",
                   "maximum_water_inundation_depth", "m",
                   OutputMetadata::defaultConvention(), "time_of_inun_max",
                   "time of maximum water inundation depth",
                   "time_of_maximum_water_inundation_depth", "s",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("initiallydry", "dry nodes at cold start", "initially_dry",
                   "none", OutputMetadata::defaultConvention()),
    OutputMetadata(
        "endrisinginun", "'rising inundation at the end of the simulation",
        "end_rising_inundation", "none", OutputMetadata::defaultConvention()),
    OutputMetadata("everdried", "ever dried", "ever_dried", "none",
                   OutputMetadata::defaultConvention(), "time_of_everdried",
                   "time of most recent drying occurrence",
                   "time_of_most_recent_drying_occurrence", "s",
                   OutputMetadata::defaultConvention()),
    OutputMetadata("offset", "water surface offset above dynamic water level",
                   "sea_surface_offset_above_dynamic_water_level", "m",
                   OutputMetadata::defaultConvention())};

#endif  // ADCIRC_OUTPUTFILES_H
