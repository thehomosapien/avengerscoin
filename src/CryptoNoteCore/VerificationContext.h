// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2016-2017 BXC developers
// Copyright (c) 2017-2019 UltraNote developers 
// Copyright (c) 2019 Avengers developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once
namespace CryptoNote
{
  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
  struct tx_verification_context
  {
    bool m_should_be_relayed;
    bool m_verifivation_failed; //bad tx, should drop connection
    bool m_verifivation_impossible; //the transaction is related with an alternative blockchain
    bool m_added_to_pool; 
    bool m_tx_fee_too_small;
  };

  struct block_verification_context
  {
    bool m_added_to_main_chain;
    bool m_verifivation_failed; //bad block, should drop connection
    bool m_marked_as_orphaned;
    bool m_already_exists;
    bool m_switched_to_alt_chain;
  };
}
