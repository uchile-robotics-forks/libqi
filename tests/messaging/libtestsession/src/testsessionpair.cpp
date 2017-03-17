/*
**
** Author(s):
**  - Pierre Roullon <proullon@aldebaran-robotics.com>
**
** Copyright (C) 2012 Aldebaran Robotics
*/

#include <qi/os.hpp>

#include <testsession/testsession.hpp>
#include <testsession/testsessionpair.hpp>

TestSessionPair::TestSessionPair(TestMode::Mode mode, const std::string sdUrl)
{
  qi::UrlVector endpoints;
  _sd = qi::makeSession();

  // #1 Get active mode.
  _mode = mode == TestMode::Mode_Default ? TestMode::getTestMode() : mode;

  // #2 Listen.
  if (_mode == TestMode::Mode_SSL)
  {
    _sd->setIdentity(qi::path::findData("qi", "server.key"),
                     qi::path::findData("qi", "server.crt"));
    _sd->listenStandalone("tcps://0.0.0.0:0");
    endpoints = _sd->endpoints();
  }
  else
  {
    if (_mode == TestMode::Mode_Gateway)
    {
      _sd->listenStandalone("tcp://0.0.0.0:0");
      _gw.reset(new qi::Gateway);
      _gw->attachToServiceDirectory(_sd->url()).value();
      _gw->listen(sdUrl);
      endpoints = _gw->endpoints();
    }
    else
    {
      _sd->listenStandalone(sdUrl);
      endpoints = _sd->endpoints();
    }
  }

  // #3 Get client and server sessions.
  _client.reset(new TestSession(endpoints[0].str(), false, _mode));
  _server.reset(new TestSession(endpoints[0].str(), true, _mode));
}

TestSessionPair::TestSessionPair(TestSessionPair &other)
{
  _sd = qi::makeSession();

  // #1 Get active mode.
  _mode = TestMode::getTestMode();

  // #2 Get client and server sessions using other pair service directory.
  _client.reset(new TestSession(other._sd->endpoints()[0].str(), false, _mode));
  _server.reset(new TestSession(other._sd->endpoints()[0].str(), true, _mode));
}

TestSessionPair::~TestSessionPair()
{
  _client.reset();
  _server.reset();
}

qi::SessionPtr TestSessionPair::client() const
{
  // #0 If activated test mode is 'Direct', cheat.
  if (_mode == TestMode::Mode_Direct)
    return _server->session();

  return _client->session();
}

qi::SessionPtr TestSessionPair::server() const
{
  return _server->session();
}

qi::SessionPtr TestSessionPair::sd() const
{
  return _sd;
}

std::vector<qi::Url> TestSessionPair::serviceDirectoryEndpoints() const
{
  return _sd->endpoints();
}

std::vector<qi::Url> TestSessionPair::gatewayEndpoints() const
{
  if (_gw)
    return _gw->endpoints();
  return std::vector<qi::Url>{};
}
