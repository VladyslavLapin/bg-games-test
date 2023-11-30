#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int find_diff(vector<int> &v)
{
    int diff = v[1] - v[0];
    if (v.size() == 2) return diff;
    
    vector<int> temp;
    bool find = true;
    int current_diff;

    for (int i = 0; i < v.size()-1; i++) {
        current_diff = v[i+1] - v[i];
        if (current_diff != diff) find = false;  
        temp.push_back(current_diff);
    }
 
    return find ? diff : find_diff(temp);
}

string add_element(vector<int> &v, int diff)
{
    stringstream result;
    int sz = v.size();
    int last = v[sz - 1];

    int curr_diff = v[1] - v[0];
    if (curr_diff != diff) {
        for (int i = 0; i < 3; i++) {
            last += curr_diff + diff * (sz - 1 + i);
            result << last;

            if (i != 2) result << ' ';
        }
    } else {
        result << last + diff << ' ' << last + diff * 2 << ' ' << last + diff * 3;
    }

    return result.str();
}

int main()
{
    string str; 
    getline(cin, str);
 
    stringstream lineStream(str);
    vector<int> numbers(istream_iterator<int>(lineStream), {});
    
    string res = add_element(numbers, find_diff(numbers));
    cout << res << endl;
    
    return 0;
}
