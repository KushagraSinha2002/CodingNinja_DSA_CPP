#include <vector>
#include<climits>

/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/


class PriorityQueue {
    vector<int> pq;

    public :

    PriorityQueue() {

    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }

    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }

    }

    int removeMin() {
        // Complete this function
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        int ans=pq[0];
        int LI=pq.size()-1;
        pq[0]=pq[LI];
        pq.pop_back();
        int PI=0;
        int RCI=2*PI+1;
        int LCI=2*PI+2;
        while(LCI < pq.size())
        {
            int minIndex;
            if(pq[PI] > pq[LCI])
            {
                minIndex=LCI;
            }
            if(RCI < pq.size() && pq[PI] > pq[RCI])
            {
                minIndex=RCI;
            }
            if(RCI <pq.size())
            {
                if(pq[PI] > pq[LCI] && pq[PI] > pq[RCI])
                {
                    if(pq[LCI] > pq[RCI])
                    {
                        minIndex=RCI;
                    }
                    else
                    {
                        minIndex=LCI;
                    }
                }
            }
            if(PI==minIndex)
            {
                break;
            }
            int t=pq[PI];
            pq[PI]=pq[minIndex];
            pq[minIndex]=t;
            PI=minIndex;
            RCI=2*PI+1;
            LCI=2*PI+2;
        }        
        return ans;
    }

};


