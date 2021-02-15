#include "MacawApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MacawApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MacawApp::MacawApp(InputParameters parameters) : MooseApp(parameters)
{
  MacawApp::registerAll(_factory, _action_factory, _syntax);
}

MacawApp::~MacawApp() {}

void
MacawApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MacawApp"});
  Registry::registerActionsTo(af, {"MacawApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MacawApp::registerApps()
{
  registerApp(MacawApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MacawApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MacawApp::registerAll(f, af, s);
}
extern "C" void
MacawApp__registerApps()
{
  MacawApp::registerApps();
}
