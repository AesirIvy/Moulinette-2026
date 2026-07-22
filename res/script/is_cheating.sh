#!/bin/bash
if [ $# -lt 2 ]; then
    echo "Usage: $0 <dir_path> [allowed_functions...]"
    exit 1
fi

dir_path="$1"
test_path="$2"
shift 2
allowed_list=("$@")

cd "$dir_path" || exit 1
cc -Wall -Wextra -Werror -I "$test_path" -c *.c

defined=$(nm *.o | awk 'NF>=3 && $2 != "U" {print $NF}' | sort -u)
undefined=$(nm *.o | awk '$1 == "U" {print $2}' | sort -u)

whitelist=$( (printf '%s\n' "${allowed_list[@]}"; echo "$defined") | sort -u )
blacklist=$(comm -23 <(echo "$undefined") <(echo "$whitelist"))

rm -f *.o
echo "$blacklist"
