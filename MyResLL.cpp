#include <iostream>
#include <ios>

using namespace std;

struct LinkListNode {
    int add;
    int data;
    int next;
};

struct StaticLinkList {
    LinkListNode* head;
    int last;
    int length;
public:
    StaticLinkList(int len){
        if (len <=0)
            cout << "XXXXx";
        else{
            this->head = new LinkListNode[len];
            last = 0;
            length = len;
        }
    }
    ~StaticLinkList(){delete[] head;}
    void insert(int add, int data, int next) {
        if(last >= 0 && last < length){
            this->head[last].add = add;
            this->head[last].data = data;
            this->head[last].next = next;
            last++;
        }
    }
    void listShow(int startPtr){
        if(startPtr == -1)
            return;
        else{
            int curindex = find(startPtr);
            cout << head[curindex].add << ' ' << head[curindex].data <<' '<< head[curindex].next <<endl;
            int nextPtr = head[curindex].next;

            listShow(nextPtr);
        }
    }

    void show(){
        for(int i= 0; i < last; ++i) {
            int a, d, n;
            cout << this->head[i].add << ' ' << this->head[i].data << ' ' <<this->head[i].next << endl;
        }
    }
    int find(int ptr) {
        for(int i= 0; i < last; ++i) {
            if (head[i].add == ptr)
                return i;
        }
        return -2;
    }
};
int main()
{
    int fristPtr, len, K;
    cin >> fristPtr >> len >> K;
    StaticLinkList sl(len);
    for(int i= 0; i < len; ++i) {
        int a, d, n;
        cin >> a >> d >> n;
        sl.insert(a, d, n);
    }
    // sl.init();
    // sl.show();
    sl.listShow(fristPtr);


    // int len = l1[1]; int K = l1[3];
    // StaticLinkList *sl = new StaticLinkList[len];
    // for (int i = 0; i < len; i++) {
    //     int x, y, z;
    //     cin >> x >> y >> z;
    //     sl->initList(x, y, z);
    // }
    // delete[] sl;
}
