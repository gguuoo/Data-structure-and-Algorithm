
#include <iostream>
#include <math.h>
using namespace std;

void swap(int &arr1, int &arr2)
{
    int temp = arr1;
    arr1 = arr2;
    arr2 = temp;
    
    return;
}
/*---------------------------------
 * 算法名称---------冒泡排序
 * 平均时间复杂度----O(n^2)
 * 最差时间复杂度----O(n^2)
 * 最优时间复杂度----O(n)
 * 所需辅助空间------O(1)
 * 稳定性-----------稳定
 ---------------------------------*/
void bubble_sort(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;
    
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j <len; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    
    return;
}

/*---------------------------------------
 * 算法名称---------选择排序
 * 当前值只和最小值交换，可以看做是冒泡排序的优化
 * 平均时间复杂度----O(n^2)
 * 最差时间复杂度----O(n^2)
 * 最优时间复杂度----O(n^2)
 * 所需辅助空间------O(1)
 * 稳定性-----------不稳定
 ---------------------------------------*/
void select_sort(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;
    
    for (int i = 0; i<len; i++)
    {
        int min_index = i;
        
        for (int j=i+1; j <len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        
        if (i != min_index)
        {
            swap(arr[i], arr[min_index]);
        }
    }
    
    return;
}

/*---------------------------------------
 * 算法名称---------插入排序
 * 平均时间复杂度----O(n^2)
 * 最差时间复杂度----O(n^2)
 * 最优时间复杂度----O(n)
 * 所需辅助空间------O(1)
 * 稳定性-----------稳定
 ---------------------------------------*/
void insert_sort(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;
    
    for (int i = 0; i<len; i++)
    {
        int j = i;
        int temp = arr[i];
        
        while (j > 0 && temp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        
        arr[j] = temp;
    }
    
    return;
}

/*---------------------------------------
 * 算法名称---------快速排序
 * 以最右边数为准
 * 平均时间复杂度----O(nlogn)
 * 最差时间复杂度----O(n^2)
 * 最优时间复杂度----O(nlogn)
 * 所需辅助空间------O(logn)
 * 稳定性-----------不稳定
 ---------------------------------------*/
int partition(int *arr, int left, int right)
{
    int index = left;
    int pivot_value = arr[right];
    
    for (int i = left;i <right; i++)
    {
        if (arr[i] <= pivot_value)
        {
            swap(arr[index], arr[i]);
            index++;
        }
    }
    
    swap(arr[right],arr[index]);
    return index;
}

void quick_sort(int *arr, int left, int right)
{
    if (left > right)
        return;
    int pivot = partition(arr, left, right);
    
    quick_sort(arr, left, pivot -1);
    quick_sort(arr, pivot + 1, right);
}

void sort(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;
    quick_sort(arr, 0, len -1);
    return;
}

/*---------------------------------------
 * 算法名称---------堆排序
 * 平均时间复杂度----O(nlogn)
 * 最差时间复杂度----O(nlogn)
 * 最优时间复杂度----O(nlogn)
 * 所需辅助空间------O(1)
 * 稳定性-----------不稳定
 ---------------------------------------*/
void max_heap_ify(int *arr, int index, int heap_size)
{
    int max = index;;
    int left = 2*index + 1;
    int right = 2 *index +2;
    
    if (left < heap_size && arr[max] < arr[left])
        max = left;
    
    if (right < heap_size && arr[max] < arr[right])
        max = right;
    
    if (max != index){
        swap(arr[max],arr[index]);
        index = max;
        max_heap_ify(arr, max, heap_size);
    }
    return;
}

void build_max_heap(int *arr, int len)
{
   int parent = floor((len-1)/2);
    int i;
    for (i=parent;i>=0;i--)
    {
        max_heap_ify(arr,i,len);
    }
    return;
}

void heap_sort(int *arr, int len)
{
    if (arr == nullptr || len <= 0)
        return;
    build_max_heap(arr,len);
    
    for (int i = len-1; i>=0;i--)
    {
        swap(arr[0], arr[i]);
        max_heap_ify(arr, 0,i);
    }
    return;
}
/*---------------------------------------
 * 算法名称---------希尔排序
 * 平均时间复杂度----O(n^1.3)
 * 最差时间复杂度----O(n^2)
 * 最优时间复杂度----O(n)
 * 所需辅助空间------O(1)
 * 稳定性-----------不稳定
 ---------------------------------------*/
void shell_sort(int *arr, int len)
{
    int gap = floor(len/2);
    
    while(gap > 0)
    {
        for (int i = gap; i<len;i++)
        {
            for (int j=i;j>0;j-=gap)
            {
                if (arr[j-gap] > arr[j])
                {
                    swap(arr[j-gap],arr[j]);
                }
                else
                {break;}
            }
        }
        gap = floor(gap /2);
    }
}

/*---------------------------------------
 * 算法名称---------归并排序
 * 平均时间复杂度----O(nlogn)
 * 最差时间复杂度----O(nlogn)
 * 最优时间复杂度----O(nlogn)
 * 所需辅助空间------O(n)
 * 稳定性-----------不稳定
 ---------------------------------------*/
void merge(int *arr, int left, int mid, int right)
{
    int len = right -left +1;
    int *temp = new int[len];
    int index = 0;
    int i = left;
    int j=mid+1;
    
    while (i <=mid && j <=right)
    {
        temp[index++] = arr[i] <arr[j]? arr[i++] :arr[j++];
    }
    while (i <=mid)
    {
        temp[index++] = arr[i++];
    }
    
    while(j<=right)
    {
        temp[index++]=arr[j++];
    }
    
    for (int k=0;k<len;k++)
    {
        arr[left++] = temp[k];
    }
}

void merge_sort_re(int *arr, int left, int right)//递归
{
    
    if (left == right)
        return;
    
    int mid = (left +right)/2;
    merge_sort_re(arr, left, mid);
    merge_sort_re(arr, mid+1, right);
    merge(arr,left,mid,right);
}

void merge_sort_ite(int *arr, int len)//迭代
{
    // 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
    for (int i=1;i<len;i*=2)// 子数组的大小i初始为1，每轮翻倍
    {
        int left =0;
        
        while(left+i<len)
        {
            int mid = left +i -1;
            int right  = mid +i <len ? mid + i :len-1;
            merge(arr, left,mid,right);
            left = right +1;
        }
    }
}

int main(int argc, const char * argv[]) {

    int arr[] = {3,2,5,7,4,0,6,1,9,8,11};
    int len = sizeof(arr)/sizeof(int);
    
    //bubble_sort(arr, len);
    //select_sort(arr, len);
    //insert_sort(arr,len);
    //sort(arr, len);
    //heap_sort(arr, len);
    //shell_sort(arr, len);
    //merge_sort_ite(arr,len);
    merge_sort_re(arr, 0,len-1);
    
    for (int i = 0; i <len; i++ )
        cout << arr[i] << endl;
    
    return 0;
}
