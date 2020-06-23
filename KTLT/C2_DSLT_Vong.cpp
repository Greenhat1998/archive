#include <iostream>
using namespace std;
struct List{
    int data;
    struct List *next;
};
typedef struct List *node;
int length;
node tail=NULL;
node make(int X) 
{
    node tmp=(node)malloc(sizeof(node));
    tmp->data=X;
    tmp->next=NULL;
    return tmp;
}
void insert_first(node &tail, int X) 
{
    node tmp=make(X);
    if (tail == NULL) 
	{
        tail = tmp;
        tmp->next=tmp;
    }
	else {
        tmp->next=tail->next;
        tail->next=tmp;
    }
    length++;
}
void insert_last(node &tail, int X) 
{
    insert_first(tail,X);
    tail=tail->next;
}
void insert(node &tail, int X, int pos) // danh so tu 1...
{
    if (pos<1 || pos>length+1) cout<<"Vi tri loi!\n";
    else if (tail==NULL || pos==1)	insert_first(tail,X);
    else{
	node tmp=make(X);
	node q=tail;
	for(int i=1;i!=pos;i++)	q=q->next;
        tmp->next = q->next;
        q->next=tmp;
        if (pos==length+1) tail=tmp;
    }
}
node del(node &tail, int pos)
{
    node prev=tail;
    if (pos<1 || pos>length) cout<<"Vi tri loi!\n";
    else if (length==1)	tail=NULL;
    else {
        node tmp=tail->next;
        for(int i=1;i<pos;i++) 
	{
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=tmp->next;
        if (tmp==tail) tail=prev;
        free(tmp);
    }
    length--;
}
void input(node &tail)
{
    int n, X;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
	cin>>X;
	insert_last(tail,X);
    }
}
void output(node tail) 
{
    node tmp=tail;
    if (tail!=NULL)
    	do {
            tmp=tmp->next;
            cout<<tmp->data<<' ';
    	} while (tmp!=tail);
}
int main()
{
    input(tail);
    output(tail);
    cout<<'\n'<<length;
    return 0;
}
