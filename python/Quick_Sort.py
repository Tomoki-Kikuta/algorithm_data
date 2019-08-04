class Quick_Sort():
    def __init__(self, N, input_number_list):
        self.N = N
        self.number_list = input_number_list
        
    def quick_sort(self, start, standard):
        if start < standard:
            wall = self.partition(start, standard)
            self.quick_sort(start, wall-1)
            self.quick_sort(wall+1, standard)

    def partition(self, start, standard):
        wall = start - 1 
        for i in range(start,standard):
            if self.number_list[i] < self.number_list[standard]:
                wall += 1
                temp = self.number_list[wall]
                self.number_list[wall] = self.number_list[i]
                self.number_list[i] = temp
        temp = self.number_list[wall+1]
        self.number_list[wall+1] =self.number_list[standard]
        self.number_list[standard] = temp
        return wall + 1

def print_number_list(number_list, N):
    for i in range(N):
        if i != N - 1:
            print(number_list[i],end=' ')
        else:
            print(number_list[i])

def main():
    N = int(input())
    input_number_list = list()
    for i in range(N):
        a = int(input())
        input_number_list.append(a)
    sort = Quick_Sort(N, input_number_list)
    sort.quick_sort(0,N-1)
    print_number_list(sort.number_list, N)

if __name__ == "__main__":
    main()