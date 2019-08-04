class MergeSort():
    def __init__(self, N, number_list):
        self.N = N
        self.number_list = number_list
        self.count = 0

    def merge(self, left, mid, right):
        left_number = mid - left
        right_number = right - mid
        left_number_element = list()
        right_number_element = list()
        for i in range(left_number):
            left_number_element.append(self.number_list[left + i])
        for i in range(right_number):
            right_number_element.append(self.number_list[mid + i])
        left_number_element.append(1<<21)
        right_number_element.append(1<<21)
        r=0
        l=0
        for k in range(left,right):
            self.count += 1
            if right_number_element[r] <= left_number_element[l]:
                self.number_list[k] = right_number_element[r] 
                r += 1
            else:
                self.number_list[k] = left_number_element[l]
                l += 1 

    def merge_sort(self, left, right):
        if left + 1 < right:
            mid = int((left + right) / 2)
            self.merge_sort(left,mid)
            self.merge_sort(mid,right)
            self.merge(left,mid,right)

def print_number_list(number_list, count, N):
    for i in range(N):
        if i != N - 1:
            print(number_list[i],end=' ')
        else:
            print(number_list[i])
    print(count)

def main():
    N = int(input())
    number_list = [int(i) for i in input().split()]
    sort = MergeSort(N,number_list)
    sort.merge_sort(0,N)
    print_number_list(sort.number_list, sort.count, N)

if __name__ == "__main__":
    main()