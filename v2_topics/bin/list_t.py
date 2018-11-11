#!/usr/bin/env python3

bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print("last item: ", bicycles[-1])

print('[list]....')
#for i in range(len(bicycles)):
#    print(bicycles[i])
#    bicycles[i] = '[' + bicycles[i] + "]"

#add new item
bicycles.append('honda')
bicycles.insert(0, 'yamaha')
#del item
del bicycles[2]
print(bicycles.pop(3), 'deleted')
bicycles.append('redline')
if bicycles.count('redline') > 0:
    bicycles.remove('redline')

print('[list]....')
for bicycle in bicycles:
    print(bicycle)

print('sort list....')
print(bicycles)
#bicycles.sort(reverse=True) #sort in desc order
print(sorted(bicycles, reverse=True))#temp sort

for i in range(1, 6):
    print(i)

nums = list(range(2,11,2))
print(nums, "min:", min(nums), "max:", max(nums), 
    "sum:", sum(nums))

#create a list in expression
squares = [i**2 for i in range(1,11)]
print("squares ", squares[:])
#splice
print(squares[:4]) #0..4
print(squares[4:]) #4-..-1
print(squares[-3:]) #last 3 items

sq_copy = squares#point to the same list
sq = squares[:]#copy items to a new list
print(sq_copy)
squares.append(12)
print(sq_copy)