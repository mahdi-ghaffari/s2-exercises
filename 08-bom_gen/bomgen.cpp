#include <iostream>
#include "rapidcsv.h"
#include <vector>
#include<bits/stdc++.h>

using namespace std;

struct part_t
{
    int num;
    string name;
    int count{0};
    vector<string>designators;
};

int main(int argc, char* argv[])
{
    rapidcsv::Document doc(argv[1]);

    vector<string> inCol1 = doc.GetColumn<string>("designator");
    vector<string> inCol2 = doc.GetColumn<string>("part");

    vector<part_t> list;

    int rowNo{0};
    for(auto i:inCol2)
    {        
        vector<part_t>::iterator it;
        it = find_if(list.begin(), list.end(), [i](const part_t&ls){return (ls.name == i);});    
        if(it==list.end())
        {
            part_t part;
            part.num = list.size() + 1;
            part.name = i;
            part.count++;
            part.designators.push_back(inCol1[rowNo]);
            list.push_back(part);
        }   
        else{
            it->count++;
            it->designators.push_back(inCol1[rowNo]);
        }
        rowNo++;
    }  

    ofstream file(argv[2]);

    file<<"num,part,count,designators\n";
    for(auto i:list)
    {        
        file<<i.num<<','<<i.name<<','<<i.count;
        for(auto d:i.designators)
            file<<','<<d;
        file<<'\n';
    }
    file.close();        
}

