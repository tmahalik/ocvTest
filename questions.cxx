#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <memory>

using namespace std;

int fibR(int n)
{
    if(n <= 1)
        return n;
    return fibR(n-1) + fibR(n-2);
}

int fib(int n)
{
    int n1 = 0;
    int n2 =1;
    int n3 =0;
    cout << "fibonacci " << n << endl;
    cout << n1 << endl << n2 << endl;
    for(auto i = 2; i <= n; i++)
    {
        n3 = n1 + n2;
        cout << n3 << endl;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}

struct my_data
{
    int a;
    int b;
};



char* new_date(char* date,int n)
{
    // given date in this format:  mm/dd/yyyy
    // add n to the date and return the new data
    // 1. make a table with the number of days for 
    // each month
    struct my_data md;
    md.a =10;
    md.b = 30;
    char* delim = "/";
    int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    char*  tok = NULL;
    char* month = NULL;
    char* day = NULL;
    char* year = NULL;
    tok =  strtok(date,delim);
    month = tok;
    for(int i = 0;i<2;i++)  // parse the string
    {
        //printf(" %s \n",tok);
        if( i == 0)
            day  = strtok(NULL,delim);
        if(i = 1)
            year = strtok(NULL,delim); 
    }
    int di = atoi(day);
    di += n;

    sprintf(day,"%d",di);
    printf("%s %s %s \n",month,day,year);
}

struct Node
{
    Node* next = NULL;
    int data;
};

Node* makeList(int n)
{
    Node* nd = new Node;
    Node* head = nd;
    Node* curr = head;
    curr->data = 0;
    for(auto i=1; i<n;i++)
    {
        curr->next = new Node;
        curr->data = i;
        curr = curr->next;

    }
    return head;
}

void printList(Node *h)
{
    while(h != NULL)
    {
        cout << h->data << " list " << endl;
        h = h->next;
    }
}

Node *reverseList(Node* h)
{
    Node* curr = NULL;
    Node* next = NULL;
    Node* prev = NULL;
    curr = h;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

char* reverse(char* s)
{
    char *b = s;
    char* e = s + strlen(s)-1;
    char temp = ' ';
    cout << b << " " << e << endl;
    while(b <= e)
    {
        temp = *b;
        *b = *e;
        *e = temp;
        b++;
        e--;
        //cout << b << " " << e << endl;
    }
    cout << s << endl;;
}
int main(int argc,char** argv)
{
    int n = 35;
    // unique_ptr<int> upi = unique_ptr<int>(&n);
    // unique_ptr<int> upi1(std::move(upi));
    auto h = makeList(10);
    h = reverseList(h);
    printList(h);
    char s[] = "hello";
    cout << strlen(s) << endl;
    char* r = reverse(s);
    //cout << r << endl;
}