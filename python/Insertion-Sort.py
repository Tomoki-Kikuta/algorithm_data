def print_format(N,input_list):
    for i in range(N):
        if i != N - 1:
            print(input_list[i],end=" ")
        else:
            print(input_list[i])
def insertion_sort(N,input_list):
    for i in range(1,N):
        print_format(N,input_list)
        v = input_list[i]
        j = i - 1
        while j>=0 and input_list[j] > v:
            input_list[j+1] = input_list[j]
            j -= 1
            input_list[j+1] = v
    return input_list

def main():
    N = int(input())
    input_list = [int(i) for i in input().split()]
    input_list = insertion_sort(N,input_list)
    print_format(N,input_list)

if __name__ == '__main__':
    main()