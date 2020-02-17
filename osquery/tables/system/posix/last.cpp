/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed in accordance with the terms specified in
 *  the LICENSE file found in the root directory of this source tree.
 */

#include <utmpx.h>

#include <osquery/core.h>
#include <osquery/tables.h>

namespace osquery {
namespace tables {

namespace impl {

void genLastAccessForRow(const utmpx& ut, QueryData& results) {
  if (ut.ut_type == USER_PROCESS || ut.ut_type == DEAD_PROCESS) {
    Row r;
    r["username"] = TEXT(ut.ut_user);
    r["tty"] = TEXT(ut.ut_line);
    r["pid"] = INTEGER(ut.ut_pid);
    r["type"] = INTEGER(ut.ut_type);
    r["time"] = INTEGER(ut.ut_tv.tv_sec);
    r["host"] = TEXT(ut.ut_host);
    results.push_back(r);
  }
}

} // namespace impl

QueryData genLastAccess(QueryContext& context) {
  QueryData results;
  struct utmpx* ut;
#ifdef __APPLE__
  setutxent_wtmp(0); // 0 = reverse chronological order

  while ((ut = getutxent_wtmp()) != nullptr) {
#else

#ifndef __FreeBSD__
  utmpxname(_PATH_WTMP);
#endif
  setutxent();

  while ((ut = getutxent()) != nullptr) {
#endif
    impl::genLastAccessForRow(*ut, results);
  }

#ifdef __APPLE__
  endutxent_wtmp();
#else
  endutxent();
#endif
  return results;
}
}
}
