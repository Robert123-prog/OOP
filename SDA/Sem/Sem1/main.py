from Bag import Bag
from Iterator import Iterator

b = Bag(4)
i = Iterator(b)

b.add(3)
b.add(2)
b.add(5)
b.add(2)



# print(i.getCurrent())
# i.next()
# print(i.getCurrent())
# i.next()
# print(i.getCurrent())
#
# b.rem(2)
# i.first()
#
# print(i.getCurrent())
# i.next()
# print(i.getCurrent())
# i.next()
# print(i.getCurrent())

assert b.size() == 4

assert b.search(1) == False
assert b.search(2) == True



assert b.nrOccurences(2) == 2


