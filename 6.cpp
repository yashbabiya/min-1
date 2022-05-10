#include <bits/stdc++.h>
using namespace std;

int findInTransactions(set<set<int>> trns, set<int> tt)
{
    int count = 0;
    for (auto e = trns.begin(); e != trns.end(); e++)
    {
        set<int> s = *e;
        if (includes(s.begin(), s.end(), tt.begin(), tt.end()))
            count++;
    }
    return count;
}
void printSetNum(set<set<int>> kk, set<set<int>> trns,int n)
{
    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        set<int> temp1 = *i;
        if(temp1.size()==n)
        {for (auto j = temp1.begin(); j != temp1.end(); j++)
        {
            cout << *j << " ";
        }
        cout << "Counts : " << findInTransactions(trns, temp1) << endl;}
    }
}
void printSetMan(set<int> s){
    cout<<"{ ";
    for(auto i = s.begin(); i != s.end(); i++ ){
        cout<<*i<<" ";
    }
    cout<<"}";
}
void printSet(set<set<int>> kk, set<set<int>> trns)
{
    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        set<int> temp1 = *i;
        for (auto j = temp1.begin(); j != temp1.end(); j++)
        {
            cout << *j << " ";
        }
        cout << "Counts : " << findInTransactions(trns, temp1) << endl;
    }
}
void reduse(set<set<int>> trns, set<set<int>> &kk, int support, int len)
{
     
    for (auto i = kk.begin(); i != kk.end(); i++)
    {
       
        set<int> temp = *i;
        if (temp.size() == len)
        {
            int sp = findInTransactions(trns, temp);

            if (sp < support)
            {
                cout<<"Punning : ";
                printSetMan(*i);
                cout<<" Erased"<<endl;
                kk.erase(i);
            }
        }
    }
     
      cout<<endl;
}



void findPermutations(set<set<int>> trns, set<set<int>> &s, int k)
{
    set<set<int>> kk;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        set<int> temp = *i;
        if (temp.size() == k - 1)
        {
            kk.insert(temp);
        }
    }
    if (kk.size() == 0)
        return;
    for (auto i = kk.begin(); i != kk.end(); i++)
    {
        for (auto j = kk.begin(); j != kk.end(); j++)
        {
            cout<<"Joining : ";
            set<int> temp1 = *i;
            set<int> temp2 = *j;
            set<int> hh;
            merge(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(hh, hh.begin()));
            printSetMan(temp1);
            cout<<"and";
            printSetMan(temp2);

            cout<<"Counts : "<<findInTransactions(trns,hh);
            if (hh.size() == k)
            {    
                s.insert(hh);
                
                cout<<" accepted";
            }
            

            cout<<endl;
        }
    }
}
int main()
{
    int n;
    cout << "How many Transaction you want to insert : ";
    cin >> n;
    vector<vector<int>> t;
    set<set<int>> ff;
    set<set<int>> trans;
    map<set<int>, int> mp;
    for (int i = 0; i < n; i++)

    {
        int k;
        cout << "How many data you want you to insert in transaction no " << i + 1 << " : ";
        cin >> k;
        cout << "Enter elements : ";
        vector<int> vv;
        set<int> vvv;
        for (int j = 0; j < k; j++)
        {
            int l;
            cin >> l;
            vvv.insert(l);
            set<int> c;
            c.insert(l);
            ff.insert(c);
            mp[c]++;
        }
        trans.insert(vvv);
        t.push_back(vv);
    }

cout << "Transactions : "<<endl;
    for(auto i=trans.begin();i != trans.end();i++){
        set<int> tmp = *i;
        for(auto j=tmp.begin();j != tmp.end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    int ll = ff.size();

    int cl = 0;
    int spll = 2;
    int support;
    cout << "Enter mininmum support : ";
    // support=2;
    cin >> support;
    reduse(trans, ff,support, 1);
    printSetNum(ff, trans,1);
    while (ll != cl)
    {
        cl = ll;
        findPermutations(trans, ff, spll);
        reduse(trans, ff,support, spll);
         printSetNum(ff, trans,spll);
        spll++;
        ll = ff.size();
    }
    // printSet(ff, trans);
    return 0;
}
