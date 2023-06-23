#include "Tutorial1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Tutorial1App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Tutorial1App::Tutorial1App(InputParameters parameters) : MooseApp(parameters)
{
  Tutorial1App::registerAll(_factory, _action_factory, _syntax);
}

Tutorial1App::~Tutorial1App() {}

void 
Tutorial1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<Tutorial1App>(f, af, s);
  Registry::registerObjectsTo(f, {"Tutorial1App"});
  Registry::registerActionsTo(af, {"Tutorial1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Tutorial1App::registerApps()
{
  registerApp(Tutorial1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Tutorial1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Tutorial1App::registerAll(f, af, s);
}
extern "C" void
Tutorial1App__registerApps()
{
  Tutorial1App::registerApps();
}
