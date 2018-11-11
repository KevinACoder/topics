#!/usr/bin/python3.5
import re

def matchto(key, s):
    m = re.match(key, s)
    print('[try to match (', s, ') to (', key, ')]')
    if m is not None:
        print(m.group())
    else:
        print('no match result')
    return m

def searchin(key, s):
    m = re.search(key, s)
    print('[try to search (', s, ') with (', key, ')]')
    if m is not None:
        print(m.group())
    else:
        print('no search result')
    return m

def extract(key, s, num):
    m = matchto(key, s)
    for i in range(1, num+1):
        print('<group', i, '>', m.group(i))

def searchall(key, s):
    res = re.findall(key, s)
    for i in res:
        print(i)

def searchall2(key, s):
    for g in re.finditer(key, s, re.I):
        print(g)

def replace(key, to, s):
    m = re.subn(key, to, s)
    print(m[1], 'place replaced')
    print(m[0])

def splitby(key, s):
    m = re.split(key, s)
    print('split into', len(m), 'parts')
    #print(type(m))
    for g in m:
        print(g)

def findby(key, s):
    m = re.findall(key, s)
    print('find', len(m), 'item(s)')
    for g in m:
        print(g)

#match check from the first word
matchto('foo', 'foo')
matchto('foo', 'seafood')

#search to end to find first occurrance
searchin('foo', 'seafood')
matchto('bat|bet|bit', 'bet')#match any of
matchto('.end', 'bend')#'.' match any char
matchto('[cr][23]', 'c3')
matchto('3\.14', '3.14')
#+(1~N), ?(0~1), *(0~N)
matchto('\w+@(\w+\.)?\w+\.com', 'kev@paofu.com')
matchto('\w+@(\w+\.)*\w+\.com', 'kev@paofu.gy.zhu.com')
matchto('\w+-\d+', 'abc-123')

extract('(\w+)-(\d+)', 'abc-123', 2)
matchto('^the', 'the end')

searchall2('car', 'carry the barcardi to the car')

replace('x', 'Mr. Zhu', 'attn: x\n Dear x\n')
replace('x', 'Mr. Zhu', 'attn: s\n Dear s\n')
replace(r'(\d{1,2})/(\d{1,2})/(\d{2}|\d{4})',r'\2/\1/\3', '2/20/91')

splitby(':', 's1:s2:s3')

data = (
    'mountain view, ca 94040',
    'sunyvale, ca',
    'los altos, 94023',
    'cupertino 95014',
    'palo alto ca'
)

for datum in data:
    splitby(', |(?= (?:\d{5}|[a-z]{2}))', datum)

findby(r'(?i)yes', 'yes? Yes. YES !!!')
findby(r'(?im)(th)', """
    this line is the first, \n
    another line, \n
    that line \n
    it's the best \n
    """)
