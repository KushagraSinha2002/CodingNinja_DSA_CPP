
/***************
 * Following is the main function that er are using internally
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
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
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
*******************/
#include<vector>
#include<climits>
class PriorityQueue {
    // Complete this class
    vector<int> pq;
    public:
    PriorityQueue()
    {
        
    }
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    void insert(int element)
    {
        pq.push_back(element);
        int CI=pq.size()-1;
        while(CI > 0)
        {
        int PI=(CI-1)/2;
        if(pq[PI] < pq[CI])
        {
            int t=pq[PI];
            pq[PI]=pq[CI];
            pq[CI]=t;
        }
        else
        {
            break;
        }
        CI=PI;
        }
    }
    int getMax()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }
        return pq[0];
    }
    int removeMax()
    {
        if(isEmpty())
        {
            return INT_MIN;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int PI=0;
        int LCI=2*PI+1;
        int RCI=2*PI+2;
        while(LCI < pq.size())
        {
            int maxIndex;
            if(pq[PI] < pq[LCI])
            {
                maxIndex=LCI;
            }
            if(pq.size() > RCI && pq[PI] < pq[RCI])
            {
                maxIndex=RCI;
            }
            if(pq.size() > RCI)
            {
                if(pq[PI] < pq[LCI] && pq[PI] < pq[RCI])
                {
                    if(pq[RCI] > pq[LCI])
                    {
                        maxIndex=RCI;
                    }
                    else
                    {
                        maxIndex=LCI;
                    }
                }
            }
            if(maxIndex==PI)
            {
                break;
            }
            int t=pq[PI];
            pq[PI]=pq[maxIndex];
            pq[maxIndex]=t;
            PI=maxIndex;
            LCI=2*PI+1;
            RCI=2*PI+2;
        }
        return ans;
    }  
};