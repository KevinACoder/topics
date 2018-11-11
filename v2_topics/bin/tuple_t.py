#!/usr/bin/env python3

dim  = (200, 50)
for d in dim:
    print(d)

#dim[0] = 201 #cannot assign new value
dim = (400, 100, 100) #can reassign tuple
print(dim)

for i in range(len(dim)):
    if dim[i] > 120:
        print(dim[i])
    if i > 0 and dim[i] == dim[i-1]:
        print('duplicate element', dim[i])

brand = ['audi', 'honda', 'toyota', 'Audi', 'hONda']
brand.sort()
print(brand)
for i in range(len(brand)):
    if i > 0 and brand[i].lower() == brand[i-1].lower():
            print('duplicate item ', brand[i])

name = 'hondaw'
if name in brand:
    print(name, 'in list')
if name not in brand:
    print(name, 'not in list')

if len(brand) < 10 and len(brand) > 4:
    print('less than 10')
elif len(brand) < 4:
    print('betwee 4 and 10')
else:
    print('other cases')