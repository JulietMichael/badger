#include "BadgerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<BadgerApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

BadgerApp::BadgerApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BadgerApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BadgerApp::associateSyntax(_syntax, _action_factory);
}

BadgerApp::~BadgerApp()
{
}

// External entry point for dynamic application loading
extern "C" void BadgerApp__registerApps() { BadgerApp::registerApps(); }
void
BadgerApp::registerApps()
{
  registerApp(BadgerApp);
}

// External entry point for dynamic object registration
extern "C" void BadgerApp__registerObjects(Factory & factory) { BadgerApp::registerObjects(factory); }
void
BadgerApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BadgerApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BadgerApp::associateSyntax(syntax, action_factory); }
void
BadgerApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
