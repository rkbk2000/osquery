/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed in accordance with the terms specified in
 *  the LICENSE file found in the root directory of this source tree.
 */

// Sanity check integration test for keychain_acls
// Spec file: specs/darwin/keychain_acls.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class keychainAcls : public testing::Test {
 protected:
  void SetUp() override {
    setUpEnvironment();
  }
};

TEST_F(keychainAcls, test_sanity) {
  // TODO: This test takes too much time to run and may require some
  // additional permissions, which makes it flaky.

  // 1. Query data
  // auto const data = execute_query("select * from keychain_acls");
  // 2. Check size before validation
  // ASSERT_GE(data.size(), 0ul);
  // ASSERT_EQ(data.size(), 1ul);
  // ASSERT_EQ(data.size(), 0ul);
  // 3. Build validation map
  // See helper.h for avaialbe flags
  // Or use custom DataCheck object
  // ValidationMap row_map = {
  //      {"keychain_path", NormalType}
  //      {"authorizations", NormalType}
  //      {"path", NormalType}
  //      {"description", NormalType}
  //      {"label", NormalType}
  //}
  // 4. Perform validation
  // validate_rows(data, row_map);
}

} // namespace table_tests
} // namespace osquery
