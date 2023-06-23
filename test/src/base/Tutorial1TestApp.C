//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "Tutorial1TestApp.h"
#include "Tutorial1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
Tutorial1TestApp::validParams()
{
  InputParameters params = Tutorial1App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Tutorial1TestApp::Tutorial1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  Tutorial1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

Tutorial1TestApp::~Tutorial1TestApp() {}

void
Tutorial1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  Tutorial1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"Tutorial1TestApp"});
    Registry::registerActionsTo(af, {"Tutorial1TestApp"});
  }
}

void
Tutorial1TestApp::registerApps()
{
  registerApp(Tutorial1App);
  registerApp(Tutorial1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
Tutorial1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Tutorial1TestApp::registerAll(f, af, s);
}
extern "C" void
Tutorial1TestApp__registerApps()
{
  Tutorial1TestApp::registerApps();
}
