// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2016-2017 BXC developers
// Copyright (c) 2017-2019 UltraNote developers 
// Copyright (c) 2019 Avengers developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "StdOutputStream.h"

namespace Common {

StdOutputStream::StdOutputStream(std::ostream& out) : out(out) {
}

size_t StdOutputStream::writeSome(const void* data, size_t size) {
  out.write(static_cast<const char*>(data), size);
  if (out.bad()) {
    return 0;
  }

  return size;
}

}
