/*
  Copyright (C) 2007 National Institute For Space Research (INPE) - Brazil.

  This file is part of TerraMA2 - a free and open source computational
  platform for analysis, monitoring, and alert of geo-environmental extremes.

  TerraMA2 is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License,
  or (at your option) any later version.

  TerraMA2 is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with TerraMA2. See LICENSE. If not, write to
  TerraMA2 Team at <terrama2-team@dpi.inpe.br>.
*/

/*!
  \file terrama2/services/analysis/core/grid/zonal/Operator.hpp

  \brief Contains grid zonal analysis operators.

  \author Paulo R. M. Oliveira
*/


#ifndef __TERRAMA2_SERVICES_ANALYSIS_CORE_GRID_ZONAL_OPERATOR_HPP__
#define __TERRAMA2_SERVICES_ANALYSIS_CORE_GRID_ZONAL_OPERATOR_HPP__

// TerraMA2
#include "../../Analysis.hpp"
#include "../../utility/Utils.hpp"
#include "../../BufferMemory.hpp"

// STL
#include <string>


namespace terrama2
{
  namespace services
  {
    namespace analysis
    {
      namespace core
      {
        namespace grid
        {
          namespace zonal
          {

            /*!
              \brief Implementation of grid zonal operator.

              In case of an error or no data available it will return NAN(Not A Number).

              \param statisticOperation The statistic operation chosen by the user.
              \param dataSeriesName DataSeries name.
              \param dateFilter Time filter for the data.

              \return A double value with the result.
            */
            TMANALYSISEXPORT double operatorImpl(terrama2::services::analysis::core::StatisticOperation statisticOperation,
                                const std::string& dataSeriesName,
                                const size_t band,
                                terrama2::services::analysis::core::Buffer buffer,
                                std::function<bool(double)> removeCondition = nullptr);

            TMANALYSISEXPORT double operatorImpl(terrama2::services::analysis::core::StatisticOperation statisticOperation,
                                const std::string& dataSeriesName,
                                const terrama2::core::Filter& filter,
                                const size_t band,
                                terrama2::services::analysis::core::Buffer buffer,
                                terrama2::services::analysis::core::MonitoredObjectContextPtr context,
                                OperatorCache cache,
                                std::function<bool(double)> removeCondition = nullptr);

            /*!
              \brief Calculates the number of pixels inside the monitored object.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.

              \return A int value with the result.
            */
            TMANALYSISEXPORT double count(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            TMANALYSISEXPORT double countByValue(const std::string& dataSeriesName, const double value, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());
            TMANALYSISEXPORT double countByRange(const std::string& dataSeriesName, const double begin, const double end, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the sum of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.

              \return A double value with the result.
            */
            TMANALYSISEXPORT double sum(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the mean of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.
              \param dateFilter Time filter for the data.

              \return A double value with the result.
            */
            TMANALYSISEXPORT double mean(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the min of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.


              \return A double value with the result.
            */
            TMANALYSISEXPORT double min(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the max of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.
              \param attribute Which DCP attribute will be used.
              \param dcpId Identifier of DCP dataset.
              \param buffer Buffer to be used in the monitored object.


              \return A double value with the result.
            */
            TMANALYSISEXPORT double max(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the median of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.


              \return A double value with the result.
            */
            TMANALYSISEXPORT double median(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the standard deviation of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.

              \return A double value with the result.
            */
            TMANALYSISEXPORT double standardDeviation(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

            /*!
              \brief Calculates the variance of zonal grid data.

              In case of an error or no data available it will return NAN(Not A Number).

              \param dataSeriesName DataSeries name.

              \return A double value with the result.
            */
            TMANALYSISEXPORT double variance(const std::string& dataSeriesName, const size_t band = 0, terrama2::services::analysis::core::Buffer buffer = Buffer());

          } /* zonal */
        }   // end namespace grid
      }     // end namespace core
    }       // end namespace analysis
  }         // end namespace services
}           // end namespace terrama2

#endif // __TERRAMA2_SERVICES_ANALYSIS_CORE_GRID_OPERATOR_HPP__
