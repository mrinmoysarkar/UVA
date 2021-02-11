# python3


def max_pairwise_product(numbers):
    n = len(numbers)
    max1,max2 = numbers[0],numbers[1]
    for i in range(2,n):
        current_num = numbers[i]
        if current_num > max1 or current_num > max2:
            max1 = max(max1,max2)
            max2 = current_num


    return max1*max2


if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
