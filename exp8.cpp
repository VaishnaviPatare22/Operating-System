#include <iostream>
#include <cmath>

using namespace std;

void sortArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void FCFS(int arr[], int head, int n)
{
    int seek_count = 0;
    int cur_head = head;
    for (int i = 0; i < n; i++) {
        seek_count += abs(arr[i] - cur_head);
        cur_head = arr[i];
    }
    cout << "FCFS Total seek operations: " << seek_count << endl;
}

void SSTF(int arr[], int head, int n)
{
    int seek_count = 0;
    int visited = {0};
    int cur_head = head;
    for (int i = 0; i < n; i++) {
        int min = 1000000, index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs(arr[j] - cur_head) < min) {
                min = abs(arr[j] - cur_head);
                index = j;
            }
        }
        visited[index] = 1;
        seek_count += min;
        cur_head = arr[index];
    }
    cout << "SSTF Total seek operations: " << seek_count << endl;
}

void SCAN(int arr[], int head, int n, int disk_size)
{
    int seek_count = 0;
    int temp, m = 0;
    for(int i = 0; i < n; i++) temp[m++] = arr[i];
    temp[m++] = 0;
    sortArray(temp, m);
    int pos;
    for(int i = 0; i < m; i++) {
        if(temp[i] > head) {
            pos = i;
            break;
        }
    }
    seek_count += abs((disk_size - 1) - head);
    seek_count += abs((disk_size - 1) - temp);
    cout << "SCAN Total seek operations: " << seek_count << endl;
}

void CSCAN(int arr[], int head, int n, int disk_size)
{
    int temp;
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    sortArray(temp, n);
    int pos;
    for(int i = 0; i < n; i++) {
        if(temp[i] > head) {
            pos = i;
            break;
        }
    }
    int seek_count = abs((disk_size - 1) - head) + (disk_size - 1) + temp[pos-1];
    cout << "C-SCAN Total seek operations: " << seek_count << endl;
}

void LOOK(int arr[], int head, int n)
{
    int temp;
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    sortArray(temp, n);
    int min = temp;
    int max = temp[n-1];
    int seek_count = abs(max - head) + abs(max - min);
    cout << "LOOK Total seek operations: " << seek_count << endl;
}

void CLOOK(int arr[], int head, int n)
{
    int temp;
    for(int i = 0; i < n; i++) temp[i] = arr[i];
    sortArray(temp, n);
    int pos;
    for(int i = 0; i < n; i++) {
        if(temp[i] > head) {
            pos = i;
            break;
        }
    }
    int seek_count = abs(temp[n-1] - head) + abs(temp[n-1] - temp) + abs(temp - temp[pos-1]);
    cout << "C-LOOK Total seek operations: " << seek_count << endl;
}

int main()
{
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = 8;
    int head = 53;
    int disk_size = 200;

    FCFS(arr, head, n);
    SSTF(arr, head, n);
    SCAN(arr, head, n, disk_size);
    CSCAN(arr, head, n, disk_size);
    LOOK(arr, head, n);
    CLOOK(arr, head, n);

    return 0;
}