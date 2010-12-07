#pragma once
/*
*  Author(s):
*  - Cedric Gestes <gestes@aldebaran-robotics.com>
*  - Chris  Kilner <ckilner@aldebaran-robotics.com>
*
*  Copyright (C) 2010 Aldebaran Robotics
*/


#ifndef _QI_MESSAGING_SRC_ADDRESS_MANAGER_HPP_
#define _QI_MESSAGING_SRC_ADDRESS_MANAGER_HPP_

#include <string>

namespace qi {
  namespace detail {
    class AddressManager {
    public:
      AddressManager();
      virtual ~AddressManager();

      void setMasterPort(int masterPort);
      int getMasterPort() const;
      int getNewPort(const std::string& machineID);

    protected:
      int _masterPort;
      int _nextFreePort;
    };
  }
}
#endif  // _QI_MESSAGING_SRC_ADDRESS_MANAGER_HPP_

