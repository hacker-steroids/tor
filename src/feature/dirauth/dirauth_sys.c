/* Copyright (c) 2001 Matej Pfajfar.
 * Copyright (c) 2001-2004, Roger Dingledine.
 * Copyright (c) 2004-2006, Roger Dingledine, Nick Mathewson.
 * Copyright (c) 2007-2019, The Tor Project, Inc. */
/* See LICENSE for licensing information */

#include "core/or/or.h"

#include "feature/dirauth/dirauth_sys.h"
#include "feature/dirauth/dirvote.h"
#include "feature/dirauth/dirauth_periodic.h"
#include "lib/subsys/subsys.h"

static int
subsys_dirauth_initialize(void)
{
  dirauth_register_periodic_events();
  return 0;
}

static void
subsys_dirauth_shutdown(void)
{
  dirvote_free_all();
}

const struct subsys_fns_t sys_dirauth = {
  .name = "dirauth",
  .supported = true,
  .level = 70,
  .initialize = subsys_dirauth_initialize,
  .shutdown = subsys_dirauth_shutdown,
};
