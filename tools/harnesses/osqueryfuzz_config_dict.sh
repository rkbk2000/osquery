#!/usr/bin/env bash

#  Copyright (c) 2014-present, Facebook, Inc.
#  All rights reserved.
#
#  This source code is licensed in accordance with the terms specified in
#  the LICENSE file found in the root directory of this source tree.

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

function usage() {
  echo "${BASH_SOURCE[0]} destination-file"
}

function main() {
  if [[ $# < 1 ]]; then
    usage
    exit 1
  fi

  # dict format is keyword="value" or just "value" - so we need to make sure our output is quoted.

  egrep -h -R -o "HasMember\\(\"([^\"]+)\"\\)" ./  | sed 's/HasMember(//' | sed 's/)//' > tmp
  egrep -h -o -e "\"([^\"]+)\"" $SCRIPT_DIR/../tests/configs/*.conf >> tmp
  egrep -h -o -e "\"([^\"]+)\"" $SCRIPT_DIR/../../packs/*.conf >> tmp

  sort tmp | uniq > $1
  rm tmp
}

main $@
