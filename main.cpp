#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool desccmp(char a, char b)
{
    return a>b;
}
// Complete the biggerIsGreater function below.
string biggerIsGreater(string w)
{
    if(w.size()==1)
    {
        return "no answer";
    }
    //Check if all we need to do is just swap the last 2 elements
    if(w[w.size()-1]>w[w.size()-2])
    {
        swap(w[w.size()-1],w[w.size()-2]);
        return w;
    }
    //If the string is already sorted in descending order --> nothing can be done
    string q = w;
    sort(q.begin(), q.end(), desccmp);
    if(q==w)
    {
        return "no answer";
    }
    char a;
    string e;
    for(int i=w.size()-2; i>0; --i)
    {
        a = w[i-1];
        e = w;
        sort(e.begin()+i, e.end()); //sort remaining letters in asc order
        auto it = upper_bound(e.begin()+i, e.end(), a); //Find the smallest element largar than w[0]
        if (it != e.end())
        {
            e[i-1] = *it; //swap w[0] and the next bigger element
            *it = a;
            sort(e.begin()+i, e.end()); //sort remaining letters in asc order
            return e;
        }

    }

    return "no answer";
}

int main()
{
    string a = "b";
    //cout<<("a"<"b")<<endl;
    //cout << "Hello world!" << endl;
    string result = biggerIsGreater(a);
    cout<<result;
    return 0;
}
