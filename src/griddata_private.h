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
#ifndef ADCMOD_GRIDDATAPRIVATE_H
#define ADCMOD_GRIDDATAPRIVATE_H

#include <cmath>
#include <memory>
#include <string>
#include <utility>
#include "adcmap.h"
#include "constants.h"
#include "interpolationmethods.h"
#include "mesh.h"
#include "rasterdata.h"

namespace Adcirc {
namespace Private {

using Point = std::pair<double, double>;

class GriddataPrivate {
 public:
  GriddataPrivate();

  GriddataPrivate(const std::vector<double> &x, const std::vector<double> &y,
                  std::vector<double> resolution, const std::string &rasterFile,
                  int epsgQuery, int epsgRaster);

  GriddataPrivate(Adcirc::Geometry::Mesh *mesh, const std::string &rasterFile,
                  int epsgRaster);

  std::string rasterFile() const;
  void setRasterFile(const std::string &rasterFile);

  void readLookupTable(const std::string &lookupTableFile);

  std::vector<int> interpolationFlags() const;
  void setInterpolationFlags(const std::vector<int> &interpolationFlags);
  void setInterpolationFlags(int interpolationFlag);
  int interpolationFlag(size_t index);
  void setInterpolationFlag(size_t index, int flag);

  std::vector<double> filterSizes() const;
  void setFilterSizes(const std::vector<double> &filterSize);
  void setFilterSizes(double &filterSize);
  double filterSize(size_t index);
  void setFilterSize(size_t index, double filterSize);

  double defaultValue() const;
  void setDefaultValue(double defaultValue);

  std::vector<double> computeValuesFromRaster(bool useLookupTable = false);
  std::vector<std::vector<double>> computeDirectionalWindReduction(
      bool useLookupTable = false);

  int epsg() const;
  void setEpsg(int epsg);

  bool showProgressBar() const;
  void setShowProgressBar(bool showProgressBar);

  double rasterMultiplier() const;
  void setRasterMultiplier(double rasterMultiplier);

  bool rasterInMemory() const;
  void setRasterInMemory(bool rasterInMemory);

  static constexpr double windRadius() { return 10000.0; }
  static constexpr double windSigma() { return 6.0; }

  double datumShift() const;
  void setDatumShift(double datumShift);

  double thresholdValue() const;
  void setThresholdValue(double thresholdValue);

  Interpolation::Threshold thresholdMethod() const;
  void setThresholdMethod(const Interpolation::Threshold &thresholdMethod);

  std::vector<double> extents() const;

 private:
  bool getKeyValue(unsigned short key, double &value);

  double calculatePoint(Point &p, double searchRadius, double gsMultiplier,
                        Interpolation::Method method);
  double calculateAverage(Point &p, double w);
  double calculateNearest(Point &p, double w);
  double calculateHighest(Point &p, double w);
  double calculateOutsideStandardDeviation(Point &p, double w, int n);
  double calculateBilskieAveraging(Point &p, double w, double gsMultiplier);
  double calculateInverseDistanceWeighted(Point &p, double w);
  double calculateInverseDistanceWeightedNPoints(Point &p, double n);
  double calculateAverageNearestN(Point &p, double n);

  double calculatePointFromLookup(Point &p, double w, double gsMultiplier,
                                  Interpolation::Method method);
  double calculateAverageFromLookup(Point &p, double w);
  double calculateNearestFromLookup(Point &p, double w);
  double calculateHighestFromLookup(Point &p, double w);
  double calculateOutsideStandardDeviationFromLookup(Point &p, double w, int n);
  double calculateBilskieAveragingFromLookup(Point &p, double w,
                                             double gsMultiplier);
  double calculateInverseDistanceWeightedFromLookup(Point &p, double w);
  double calculateInverseDistanceWeightedNPointsFromLookup(Point &p, double n);
  double calculateAverageNearestNFromLookup(Point &p, double n);

  double (GriddataPrivate::*m_calculatePointPtr)(Point &p, double w,
                                                 double gsMultiplier,
                                                 Interpolation::Method method);

  std::vector<double> (GriddataPrivate::*m_calculateDwindPtr)(Point &p);

  bool calculateBilskieRadius(double meshSize, double rasterCellSize,
                              double &radius);

  template <typename T>
  bool pixelDataInRadius(Point &p, double radius, std::vector<double> &x,
                         std::vector<double> &y, std::vector<T> &z,
                         std::vector<bool> &valid);

  template <typename T>
  void thresholdData(std::vector<T> &z, std::vector<bool> &v);

  std::vector<double> calculateDirectionalWindFromRaster(Point &p);
  std::vector<double> calculateDirectionalWindFromLookup(Point &p);

  bool computeWindDirectionAndWeight(Point &p, double x, double y, double &w,
                                     int &dir);

  void computeWeightedDirectionalWindValues(std::vector<double> &weight,
                                            std::vector<double> &wind,
                                            double nearWeight);

  short windDirection(short i, short j);

  void checkMatchingCoorindateSystems();
  void checkRasterOpen();
  void assignDirectionalWindReductionFunctionPointer(bool useLookupTable);
  void assignInterpolationFunctionPointer(bool useLookupTable);
  double calculateExpansionLevelForPoints(size_t n);

  std::vector<Point> meshToQueryPoints(Adcirc::Geometry::Mesh *m);

  Adcirc::adcmap<unsigned short, double> m_lookup;
  Interpolation::Threshold m_thresholdMethod;

  std::unique_ptr<Adcirc::Raster::Rasterdata> m_raster;

  std::vector<Point> m_queryLocations;
  std::vector<double> m_filterSize;
  std::vector<double> m_queryResolution;
  std::vector<int> m_interpolationFlags;

  std::string m_rasterFile;

  int m_inputEpsg;
  int m_epsg;

  double m_defaultValue;
  double m_rasterMultiplier;
  double m_datumShift;
  double m_thresholdValue;

  bool m_showProgressBar;
  bool m_rasterInMemory;
};

}  // namespace Private
}  // namespace Adcirc

#endif  // ADCMOD_GRIDDATAPRIVATE_H
