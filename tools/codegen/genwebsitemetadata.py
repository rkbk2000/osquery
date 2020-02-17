#!/usr/bin/env python3
"""
Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved

Generate a new website version metadata file based on a new release version

Usage:
    python tools/codegen/genwebsitemetadata.py --file=~/osquery-site/src/data/osquery_metadata.json
"""

#  Copyright (c) 2014-present, Facebook, Inc.
#  All rights reserved.
#
#  This source code is licensed in accordance with the terms specified in
#  the LICENSE file found in the root directory of this source tree.

import argparse
import io
import json
import sys

def main(argc, argv):
    parser = argparse.ArgumentParser(
        "Generate a new website version metadata file based on a new release")
    parser.add_argument("--file", help="Path to metadata file", required=True)
    parser.add_argument("--version", help="Version identifier", required=True)
    args = parser.parse_args()

    metadata = json.load(open(args.file))
    metadata["current_version"] = args.version
    metadata["all_versions"].append(args.version)
    with io.open(args.file, 'w', encoding='utf-8') as f:
        f.write(json.dumps(metadata, indent=2, separators=(',', ':')))

if __name__ == "__main__":
    main(len(sys.argv), sys.argv)
