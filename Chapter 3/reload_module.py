#!/usr/bin/env python3

import importlib
import script1

print(script1.x);
script1.x = "Hello";
print('x before reload: '+ script1.x +'\n');
importlib.reload(script1);
print('x after reload: '+ script1.x +'\n');
