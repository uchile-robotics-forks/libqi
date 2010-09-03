
#pragma once
/*
** $autogen
**
** Author(s):
**  - Chris Kilner <ckilner@aldebaran-robotics.com>
**  - Cedric Gestes <gestes@aldebaran-robotics.com>
**
** Copyright (C) 2010 Aldebaran Robotics
*/
#ifndef COMMON_CLIENT_NODE_HPP_
#define COMMON_CLIENT_NODE_HPP_

#include <string>
#include <memory>
#include <alcommon-ng/messaging/call_definition.hpp>
#include <alcommon-ng/messaging/result_definition.hpp>
#include <alcommon-ng/functor/functionsignature.hpp>

namespace AL {
  namespace Common {

    class ClientNodeImp;

    class ClientNode {
    public:
      ClientNode();

      ClientNode(const std::string& clientName,
        const std::string& masterAddress);

      virtual ~ClientNode();

      void callVoid(const std::string& methodName);

      template <typename RETURN_TYPE>
      RETURN_TYPE call(const std::string& methodName);

      template <typename P0>
      void callVoid(const std::string& methodName, const P0 &p0);

      template <typename RETURN_TYPE, typename P0>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0);

      template <typename P0, typename P1>
      void callVoid(const std::string& methodName, const P0 &p0, const P1 &p1);

      template <typename RETURN_TYPE, typename P0, typename P1>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0, const P1 &p1);

      template <typename P0, typename P1, typename P2>
      void callVoid(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2);

      template <typename RETURN_TYPE, typename P0, typename P1, typename P2>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2);

      template <typename P0, typename P1, typename P2, typename P3>
      void callVoid(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3);

      template <typename RETURN_TYPE, typename P0, typename P1, typename P2, typename P3>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3);

      template <typename P0, typename P1, typename P2, typename P3, typename P4>
      void callVoid(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);

      template <typename RETURN_TYPE, typename P0, typename P1, typename P2, typename P3, typename P4>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4);

      template <typename P0, typename P1, typename P2, typename P3, typename P4, typename P5>
      void callVoid(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);

      template <typename RETURN_TYPE, typename P0, typename P1, typename P2, typename P3, typename P4, typename P5>
      RETURN_TYPE call(const std::string& methodName, const P0 &p0, const P1 &p1, const P2 &p2, const P3 &p3, const P4 &p4, const P5 &p5);

    private:
      void xCall(const AL::Messaging::CallDefinition& callDef, AL::Messaging::ResultDefinition &result);
      std::auto_ptr<ClientNodeImp> fImp;
    };
  }
}

#include <alcommon-ng/common/client_node.hxx>
#endif  // COMMON_CLIENT_NODE_HPP_
