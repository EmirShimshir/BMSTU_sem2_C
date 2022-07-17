#!/bin/bash

this_path="./*.sh"
scripts_path="./func_tests/scripts/*.sh"

for file in $this_path $scripts_path ; do
	shellcheck "$file"
done
