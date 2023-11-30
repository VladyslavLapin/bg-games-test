#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void decrypt(const string& key, const string& str)
{ 
    map<char, string> m;

    for (auto ch : key) {
        m[ch] = "";
    }
    
    int j = 0;
    bool isDigraph = true;
    for (int i = 0; i < str.size(); i++) {
        if (j == key.size()) j = 0;

        string temp = m[key[j]];
        if (isDigraph) {
            temp.append(1, str[i]);
            if(isalpha(str[i+1])){
                temp.append(1, str[i + 1]);
            }
            i++;
            isDigraph = false;
        } else {
            temp.append(1, str[i]);
            isDigraph = true;
        }
        m[key[j]] = temp;
        
        j++;
    }
    
    for (auto& [key, value] : m) {
        cout << value ;
    }
    cout<<endl;
}

int main()
{
    string line;
    while (std::getline(std::cin, line))
    {
        stringstream lineStream(line);
        string key, str;
        lineStream >> key >> str;
        decrypt(key, str);
    } 
    
    return 0;
}
