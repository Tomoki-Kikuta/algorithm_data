
class Queue():
    def __init__(self):
        self.top = -1
        self.lists = []
    def push(self,x):
        self.lists.append(x)
    def pop(self):
        self.top += 1
        return self.lists[self.top]

def main():
    input_list = [i for i in input().split()]
    queue = Queue()
    for i in range(len(input_list)):
        if input_list[i] == '+':
            number_1 = queue.pop()
            number_2 = queue.pop()
            queue.push(number_1+number_2)
        elif input_list[i] == '-':
            number_1 = queue.pop()
            number_2 = queue.pop()
            queue.push(number_1-number_2)
        elif input_list[i] == '*':
            number_1 = queue.pop()
            number_2 = queue.pop()
            queue.push(number_1 * number_2)
        else:
            queue.push(int(input_list[i]))
    print(queue.lists[-1])
        
if __name__ == "__main__":
    main()