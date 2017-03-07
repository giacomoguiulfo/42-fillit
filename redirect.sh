#!/bin/bash
make testverbose &> output
cat output | grep -E 'Exec|FAIL'
