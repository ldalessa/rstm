/**
 *  Copyright (C) 2011
 *  University of Rochester Department of Computer Science
 *    and
 *  Lehigh University Department of Computer Science and Engineering
 *
 * License: Modified BSD
 *          Please see the file LICENSE.RSTM for licensing information
 */

/**
 * OrecLazy is the name for the oreclazy algorithm when instantiated with no
 * CM.  Virtually all of the code is in the oreclazy.hpp file, but we need to
 * instantiate in order to use the "HyperAggressiveCM", which is nops on all
 * transaction boundaries.
 */

#include "oreclazy.hpp"
#include "cm.hpp"

namespace stm
{
  /**
   * Instantiate rollback with the appropriate CM for this TM algorithm
   */
  scope_t* rollback(TX* tx)
  {
      return rollback_generic<HyperAggressiveCM>(tx);
  }

  /**
   * Instantiate tm_begin with the appropriate CM for this TM algorithm
   */
  void tm_begin(scope_t* scope)
  {
      tm_begin_generic<HyperAggressiveCM>(scope);
  }

  /**
   * Instantiate tm_end with the appropriate CM for this TM algorithm
   */
  void tm_end()
  {
      tm_end_generic<HyperAggressiveCM>();
  }

  /**
   *  For querying to get the current algorithm name
   */
  const char* tm_getalgname() { return "OrecLazy"; }

}