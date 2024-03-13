from Bag import Bag

class Iterator:
    def __init__(self, bag: Bag):
        self.bag = bag
        self.idx = 0

    def first(self):
        try:
            self.idx = 0
        except IndexError:
            print("Empty List!")


    def valid(self):
        return True if 0 <= self.idx <= self.bag.length - 1 else False

    def next(self):
        try:
            self.idx += 1
        except IndexError:
            print("Element has been removed")

    def getCurrent(self):
        try:
            return self.bag.elems[self.idx]

        except IndexError:
            print('No elem found')

