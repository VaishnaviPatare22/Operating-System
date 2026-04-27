#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;
void FIFO(int pages[], int n, int capacity){
    queue<int> q; 
    unordered_set<int> s; 
    int faults = 0;
    for(int i = 0; i < n; i++){
        if(s.find(pages[i]) == s.end()){
            if(q.size() == capacity){
                int val = q.front(); 
                q.pop(); 
                s.erase(val); 
            }
            q.push(pages[i]); 
            s.insert(pages[i]);
            faults++;
        }
    }

    cout << "FIFO Page Faults = " << faults << endl;
}

void LRU(int pages[], int n, int capacity){
    vector<int> q; 
    int faults = 0;

    for(int i = 0; i < n; i++){
        int found = 0;

        for(int j = 0; j < q.size(); j++){
            if(q[j] == pages[i]){
                found = 1;

                q.erase(q.begin() + j);

                q.push_back(pages[i]);
                break;
            }
        }
        if(!found){ 
            if(q.size() == capacity)
                q.erase(q.begin());

            q.push_back(pages[i]);
            faults++;
        }
    }
    cout << "LRU Page Faults = " << faults << endl;
}


bool isPresent(vector<int> &frame, int page){
    for(int x : frame)
        if(x == page)
            return true;
    return false;
}

void Optimal(int pages[], int n, int capacity){
    vector<int> frame;
    int faults = 0;

    for(int i = 0; i < n; i++){
        if(!isPresent(frame, pages[i])){
            if(frame.size() < capacity){
                frame.push_back(pages[i]);
            }
            else{
                int index = -1, farthest = i;
                for(int j = 0; j < frame.size(); j++){
                    int k;
                    for(k = i + 1; k < n; k++){
                        if(frame[j] == pages[k])
                            break;
                    }

                    if(k > farthest){
                        farthest = k;
                        index = j;
                    }
                }

                if(index == -1)
                    index = 0;

                frame[index] = pages[i]; 
            }
            faults++;
        }
    }
    cout << "Optimal Page Faults = " << faults << endl;
}


int main(){
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 3;

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}