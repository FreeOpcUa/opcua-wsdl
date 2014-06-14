/// @author Alexander Rykovanov 2013
/// @email rykovanov.as@gmail.com
/// @brief Class which implements Discovery service over soap.
/// @license GNU LGPL
///
/// Distributed under the GNU LGPL License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/lgpl.html)
///

#pragma once

#include <soapBasicHttpBinding_USCOREIDiscoveryEndpointService.h>

#include <opc/ua/server.h>

namespace OpcUa
{
  namespace Soap
  {
    class DiscoveryService : public BasicHttpBinding_USCOREIDiscoveryEndpointService
    {
      typedef BasicHttpBinding_USCOREIDiscoveryEndpointService ParentType;
    public:
      DiscoveryService(OpcUa::Remote::Server::SharedPtr computer, bool debug)
        : Server(computer)
        , Debug(debug)
      {
      }

      DiscoveryService(OpcUa::Remote::Server::SharedPtr computer, bool debug, struct soap& s)
        : ParentType(s)
        , Server(computer)
        , Debug(debug)
      {
      }

      DiscoveryService(OpcUa::Remote::Server::SharedPtr computer, bool debug, soap_mode iomode)
        : ParentType(iomode)
        , Server(computer)
        , Debug(debug)
      {
      }

      DiscoveryService(OpcUa::Remote::Server::SharedPtr computer, bool debug, soap_mode imode, soap_mode omode)
        : ParentType(imode, omode)
        , Server(computer)
        , Debug(debug)
      {
      }

      virtual BasicHttpBinding_USCOREIDiscoveryEndpointService *copy();
      virtual int FindServers(ns3__FindServersRequest *ns3__FindServersRequest_, ns3__FindServersResponse *ns3__FindServersResponse_);
      virtual int GetEndpoints(ns3__GetEndpointsRequest *ns3__GetEndpointsRequest_, ns3__GetEndpointsResponse *ns3__GetEndpointsResponse_);

    private:
      OpcUa::Remote::Server::SharedPtr Server;
      bool Debug;
    };
  }
}
