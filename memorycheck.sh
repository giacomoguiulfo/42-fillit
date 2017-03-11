#!/bin/bash
make quicktest &> output
cat output | grep -E 'Exec|FAIL'
