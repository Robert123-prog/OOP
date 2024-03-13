
class Bag:
    def __init__(self, length):
        self.length = length
        self.elems =[]

    def add(self, el):
        if len(self.elems) < self.length:
            self.elems.append(el)


    def rem(self, el):
        self.elems.remove(el) if el in self.elems else False

    def search(self, el):
        return True if el in self.elems else False

    def size(self):
        return len(self.elems)

    def nrOccurences(self, elem_to_search):
        if self.search(elem_to_search):
            cnt = 0
            for elem in self.elems:
                if elem == elem_to_search:
                    cnt += 1

        else:
            return False

        return cnt if cnt > 0 else False

