/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 3 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// "multikit" Multicast Application Shell
// Copyright (c) 1996-2018, Live Networks, Inc.  All rights reserved
// "Group Endpoint Id"
// C++ header

#ifndef _GROUPEID_HH
#define _GROUPEID_HH

#ifndef _BOOLEAN_HH
#include "Boolean.hh"
#endif

#ifndef _NET_ADDRESS_HH
#include "NetAddress.hh"
#endif

class GroupEId {
public:
  GroupEId(LIVE_NET_ADDRESS_INADDR const& groupAddr,
	   portNumBits portNum, u_int8_t ttl);
      // used for a 'source-independent multicast' group
  GroupEId(LIVE_NET_ADDRESS_INADDR const& groupAddr,
	   LIVE_NET_ADDRESS_INADDR const& sourceFilterAddr,
	   portNumBits portNum);
      // used for a 'source-specific multicast' group

  LIVE_NET_ADDRESS_INADDR const& groupAddress() const { return fGroupAddress; }
  LIVE_NET_ADDRESS_INADDR const& sourceFilterAddress() const { return fSourceFilterAddress; }

  Boolean isSSM() const;

  portNumBits portNum() const { return fPortNum; }

  u_int8_t ttl() const { return fTTL; }

private:
  void init(LIVE_NET_ADDRESS_INADDR const& groupAddr,
	    LIVE_NET_ADDRESS_INADDR const& sourceFilterAddr,
	    portNumBits portNum,
	    u_int8_t ttl);

private:
  LIVE_NET_ADDRESS_INADDR fGroupAddress;
  LIVE_NET_ADDRESS_INADDR fSourceFilterAddress;
  portNumBits fPortNum; // in network byte order
  u_int8_t fTTL;
};

#endif
