#!/usr/bin/env python

from random import randrange, choice
from string import ascii_lowercase as lc
from sys import maxint
from time import ctime
import re

tlds = ('com', 'edu', 'net', 'org', 'gov')

data = []
for i in xrange(randrange(5, 11)):
    dtint = randrange(maxint) #choose a random val from range
    dtstr = ctime(dtint) #convert a time in secs
    llen = randrange(4, 8)
    login = ''.join(choice(lc) for j in range(llen))
    dlen = randrange(llen, 13)
    dom = ''.join(choice(lc) for j in xrange(dlen))
    print('%s::%s@%s.%s::%d-%d-%d'%(dtstr, login, 
        dom, choice(tlds), dtint, llen, dlen))
    data.append('%s::%s@%s.%s::%d-%d-%d'%(dtstr, login, 
        dom, choice(tlds), dtint, llen, dlen))

patt = r'^(Mon|Tue|Wed|Thu|Fri|Sat|Sun)'
patt = r'^(\w{3})'

for i in range(len(data)):
        m = re.match(patt, data[i])
        print(m.group())
