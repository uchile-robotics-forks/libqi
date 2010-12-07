#pragma once
/*
*  Author(s):
*  - Chris  Kilner <ckilner@aldebaran-robotics.com>
*  - Cedric Gestes <gestes@aldebaran-robotics.com>
*
*  Copyright (C) 2010 Aldebaran Robotics
*/


#ifndef _QI_TRANSPORT_TRANSPORT_MESSAGE_HANDLER_HPP_
#define _QI_TRANSPORT_TRANSPORT_MESSAGE_HANDLER_HPP_

# include <qi/transport/buffer.hpp>

namespace qi {
  namespace transport {

    class TransportMessageHandler {
    public:
      /// <summary> Generic message handler. </summary>
      /// <param name="requestMessage"> The request </param>
      /// <param name="responseMessage"> The reply </param>
      virtual void messageHandler(qi::transport::Buffer& requestMessage,
                                  qi::transport::Buffer& responseMessage) = 0;
    };
  }
}

#endif  // _QI_TRANSPORT_TRANSPORT_MESSAGE_HANDLER_HPP_
