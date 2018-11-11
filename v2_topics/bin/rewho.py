#!/usr/bin/python3.5

import os
import re

f = os.popen('who', 'r')
for each_line in f:
    print(re.split(r'\s\s+|\t', each_line.rstrip()))
f.close()