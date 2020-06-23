#include <iostream>
using namespace std;
struct List{
    int data;
    List *next;
};
typedef struct List *node;
int length=0;
node head=NULL;
node make(int X)
{
    node tmp = (node)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->data = X;
    return tmp;
}
void insert_first(node &head, int X)
{
    node tmp = make(X);
    if (head == NULL)	head = tmp;
    else{
        tmp->next = head;
        head = tmp;
    }
    length++;
}
void insert_last(node &head, int X)
{
    node tmp = make(X);
    if (head == NULL)	head = tmp;
    else{
        node q = head;
        while (q->next != NULL)	q = q->next;
        q->next = tmp;
    }
    length++;
}
void insert(node &head, int X, int p)
{
	if (p == 0 || head == NULL)	insert_first(head, X);
    else{
        int k = 1;
        node q = head;
        while (q != NULL && k != p)
		{
            q = q->next;
            k++;
        }
        if (k != p)
		{
			cout<<"Vi tri ngoai danh sach. Phan tu se duoc them vao cuoi danh sach!\n";
            insert_last(head, X);
        }
		else{
            node tmp = make(X);
            tmp->next = q->next;
            q->next = tmp;
            length++;
        }
    }
}
void del_first(node &head)
{
    if (head == NULL)	cout<<"Danh sach rong\n";
    else head = head->next, length--;
}
void del_last(node &head)
{
	if (head == NULL || head->next == NULL)	del_first(head);
	else{
	    node q = head;
	    while (q->next->next != NULL)	q = q->next;
    	q->next = q->next->next;
    	length--;
    }
}
void del(node &head, int p)
{
    if (p == 0 || head == NULL || head->next == NULL)	del_first(head);
    else{
        int k = 1;
        node q = head;
        while (q->next->next != NULL && k != p)
		{
            q = q->next;
            k++;
        }
        if (k != p)
		{
			cout<<"Vi tri xoa ngoai danh sach. Xoa phan tu cuoi cung trong danh sach\n";
            del_last(head);
        }
		else q->next = q->next->next, length--;
    }
}
int get(node head, int p)
{
    int k = 0;
    node q = head;
    while (q->next != NULL && k != p)
	{
        k++;
        q = q->next;
    }
    return q->data;
}
void input(node &head)
{
    int n, X;
    cin>>n;
    for(int i=0;i<n;i++)
	{
        cin>>X;
        insert_last(head, X);
    }
}
void output(node head)
{
	for(node q = head; q != NULL; q = q->next)	cout<<q->data<<' ';
	cout<<'\n';
}
int search(node head, int X)
{
	int p = 0;
    for(node q = head; q != NULL; q = q->next)
        if (q->data == X)	return p;
        else p++;
    return -1;
}
int main()
{
	input(head);
	output(head);
	del(head,3);
	output(head);
	int x;
	cin>>x;
	cout<<search(head,x);
	return 0;
}
