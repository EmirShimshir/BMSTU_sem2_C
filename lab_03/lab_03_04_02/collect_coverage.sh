#!/bin/bash

./testing.sh

echo ""
echo "gcov result:"
echo ""

gcov main.c
