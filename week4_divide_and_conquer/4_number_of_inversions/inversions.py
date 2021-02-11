# Uses python3
import sys

def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 1:
        return number_of_inversions
    ave = (left + right) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave, right)
    #write your code here
    for i in range(left,right):
        b[i] = a[i]
    helperLeft = left
    helperRight = ave
    current = left
    for i in range(left,right):
        if helperLeft<ave and helperRight<right:
            if b[helperLeft]>b[helperRight]:
                a[i] = b[helperRight]
                helperRight += 1
                number_of_inversions += (ave-helperLeft)
            else:
                a[i] = b[helperLeft]
                helperLeft +=1
        elif helperLeft<ave:
            a[i] = b[helperLeft]
            helperLeft+=1
        elif helperRight<right:
            a[i] = b[helperRight]
            helperRight += 1

    #while helperLeft<ave and helperRight<right:
    #    if b[helperLeft]>b[helperRight]:
    #        a[current]=b[helperRight]
    #        helperRight+=1
    #        number_of_inversions += 1
    #    else:
    #        a[current]=b[helperLeft]
    #        helperLeft += 1
    #    current+=1
    #if helperLeft<ave:
    #    remain = ave-helperLeft
    #    a[current:current+remain]=b[helperLeft:helperLeft+remain]        
    #    number_of_inversions+=(remain-1)*(right-ave)
        #print(remain,right-ave)
    #print(number_of_inversions)
    return number_of_inversions

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    aa = [a[0]]
    for i in a:
        if aa[-1] != i:
            aa.append(i)
    #b = n * [0]
    a=aa
    b=len(a)*[0]
    print(get_number_of_inversions(a, b, 0, len(a)))
    #print(a)
