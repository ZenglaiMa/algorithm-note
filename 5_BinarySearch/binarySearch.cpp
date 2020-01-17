
// 1. 在长度为len的递增序列中查找元素x, 返回x的下标, 不存在返回-1.
int binarySearch(int arr[], int len, int x) {
    int mid, left = 0, right = len - 1; // 注意left和right的初值
    while(left <= right) { // 注意循环条件为 left <= right
        mid = (left + right) / 2;
        // mid = left + (right - left) / 2; 与mid = (left + right) / 2; 等价, 防止溢出(当二分上界超过对应数据类型的一半时).
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1; // 不存在返回-1
}

// 2. 在长度为len的递增序列中查找元素x, 返回第一个大于等于x的元素的位置.
//    如果序列中不存在元素x, 那么假设序列中存在元素x, 返回x应该在的位置.
int lower_bound(int arr[], int len, int x) {
    int mid, left = 0, right = len; // 注意left和right的初值
    while(left < right) { // 注意循环条件为 left < right
        mid = (left + right) / 2;
        if(arr[mid] >= x)
            right = mid;
        else
            left = mid + 1;
    }

    return left; // 当left==right时跳出循环, 因此 return left 和 return right等价.
}

// 3. 在长度为len的递增序列中查找元素x, 返回第一个大于x的元素的位置.
//    如果序列中不存在元素x, 那么假设序列中存在元素x, 返回x应该在的位置.
int upper_bound(int arr[], int len, int x) {
    int mid, left = 0, right = len; // 注意left和right的初值
    while(left < right) { // 注意循环条件为 left < right
        mid = (left + right) / 2;
        if(arr[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }

    return left; // 当left==right时跳出循环, 因此 return left 和 return right等价.
}
