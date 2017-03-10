#!/bin/bash

make re
./fillit tt/all > blah
diff blah valid_t
echo "Everything Fine!"
