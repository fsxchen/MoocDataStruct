#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

struct LinkListNode {
    int add;
    int data;
    int next;
    friend ostream& operator<<(ostream& o, const LinkListNode& node) {
        if (node.next == -1) o << setfill('0') <<setw(5) << node.add << ' ' << node.data << ' ' << node.next << endl;
        else o << setfill('0') <<setw(5) << node.add << ' ' << node.data << ' ' << setw(5) <<node.next << endl;
        return o;
    }
};

struct StaticLinkList {
    LinkListNode* head;
    int last;
    int length;
public:
    StaticLinkList(int len){
        this->head = new LinkListNode[len];
        last = 0;
        length = len;
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

    void sortList(int startPtr) {
        for (int i = 0; i < length; ++ i) {
            int realindex = find(startPtr);
            if (realindex != -1){
                if (i != realindex)
                    swap(head[i], head[realindex]);
                startPtr = head[i].next;
            }
        }
    }

    void kReverList(int K) {
        int num = length / K;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < K/2; j ++) {
                swap(head[j + (i*K)], head[K -1 - j + (i*K)]);
            }
        }
        for (int i = 0; i < length; ++ i) {
            if (i != length - 1){
                head[i].next = head[i + 1].add;
            }
            else
                head[i].next = -1;
            }
    }

    void show(){
        for(int i = 0; i < last; ++i)
            cout << head[i];
    }

    int find(int ptr) {
        for(int i= 0; i < last; ++i) {
            if (head[i].add == ptr)
                return i;
        }
        return -1;
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

    sl.sortList(fristPtr);
    if(0 < K && K <= len)
        sl.kReverList(K);
    sl.show();
}
