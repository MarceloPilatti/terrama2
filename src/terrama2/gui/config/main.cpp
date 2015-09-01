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
  \file terrama2/gui/config/main.cpp

  \brief Main routine for TerraMA2 Config GUI.

  \author Evandro Delatin
  \author Raphael Willian da Costa
*/

// TerraMA2
#include "ConfigApp.hpp"

// TerraLib
#include <terralib/common/TerraLib.h>

// Qt
#include <QApplication>

int main(int argc, char* argv[])
{
// initialize Qt
  QApplication app(argc, argv);

// initialize TerraLib
  TerraLib::getInstance().initialize();

  ConfigApp capp;

  capp.init();
  
  capp.showMaximized();

  int retval = app.exec();


// finalize TerraLib
  TerraLib::getInstance().finalize();
  
  return retval;
}
