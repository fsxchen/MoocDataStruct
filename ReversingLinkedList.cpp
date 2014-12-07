#include <iostream>
using namespace std;

class List{
    typedef int T;
    struct Node {
        T data;
        Node* next;
        Node(const T& d=T()):data(d), next(NULL){}
    };
    Node* head;
    int len;
public:
    List():head(NULL),len(0){}
    int size() const {
        return len;
    }
    List& push_back(const T&d) {
        insert(d, size());
        return *this;
    }

    void push_front(const T& d) {
        insert(d, 0);
    }
    Node*& getptr(int pos){
        if(pos == 0) return head;
        Node* p = head;
        for(int i = 1; i < pos; i++) {
            p = p->next;
        }
        return p->next;
    }
    void insert(const T& d, int pos) {
        if (pos < 0 || pos > this->size()) pos = 0;
        Node*& pn = getptr(pos);
        Node* p = new Node(d);
        p->next = pn;
        pn = p;
        len++;
    }

    void travel() const {
        Node *p = head;
        while(p != NULL) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }
    void clear() {
        while(head != NULL) {
            Node* p = head->next;
            delete head;
            head = p;
        }
    }
    ~List() {
        clear();
    }
    void erase(int pos){
        if(pos < 0 || pos >= size()) return;
        Node*& pn = getptr(pos);
        Node* p = pn;
        pn = pn->next;
        delete p;
        this->len--;

    }
    void remove(const T& d) {
        int pos = -1;
        while((pos = find(d)) != -1)
            erase(pos);
    }

    int find(const T& d) const {
        Node *p = head;
        int pos = 0;
        while(p) {
            if(p->data == d) return pos;
            p = p->next; ++ pos;
        }
        return -1;
    }
    void set(int pos, const T& d) {
        if(pos < 0 || pos >= size()) return;
        getptr(pos)->data = d;
    }
    bool empty() const {return head==NULL;}
    const T& front() {if(empty()) throw "空"; return head->data;}
    T end()const {
        if(empty()) throw "空";
        Node *p = head;
        while(p->next != NULL){
            p = p->next;
        }
        return p->data;
    }
    void reverse() {
        Node *p = this->head;
        head = NULL;
        while(p != NULL) {
            push_front(p->data);
            p = p->next;
        }
    }

    void kReverse(int k) {
        int cnt = 0;
        Node *p = this->head;
        head = NULL;len = 0;
        while(p != NULL && cnt < k) {
            cout << p << endl;
            push_front(p->data);
            p = p->next;
            cnt++;
        }
        cout << p << endl;
        while(p != NULL) {
            push_back(p->data);
            p = p->next;
        }
    }
    void sort(int reverse=0) {
        Node* p = head;
        T tmp;
        while(p != NULL) {
            Node* q = p->next;
            while(q != NULL) {
                if(p->data > q->data) {
                    tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
};

int main() {
    List l;
    l.push_back(1).push_back(2).push_back(3).push_back(4).push_back(5).push_back(6);
    l.travel();
    l.kReverse(3);
    l.travel();
    return 0;
}
