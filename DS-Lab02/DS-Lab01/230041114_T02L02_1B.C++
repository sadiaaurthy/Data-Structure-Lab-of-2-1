#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string extractTagName(const string& tag) {
    string tagName = "";
    for (int i = 1; i < tag.length(); i++) {
        if (tag[i] == '>' || tag[i] == ' ') break;
        if (tag[i] != '/') tagName += tag[i];
    }
    return tagName;
}

bool isOpeningTag(const string& tag) {
    return tag[1] != '/';
}

string validateHTML(vector<string>& codes) {
    stack<pair<string, int>> tagStack; 
    
    for (int lineNum = 0; lineNum < codes.size(); lineNum++) {
        string line = codes[lineNum];
        
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '<') {
                int j = i;
                while (j < line.length() && line[j] != '>') j++;
                
                if (j < line.length()) {
                    string tag = line.substr(i, j - i + 1);
                    string tagName = extractTagName(tag);
                    
                    if (tagName.empty() || tag[tag.length()-2] == '/') {
                        i = j;
                        continue;
                    }
                    
                    if (isOpeningTag(tag)) {
                        tagStack.push({tagName, lineNum + 1});
                    } else {
                        if (tagStack.empty()) {
                            return "Error at line " + to_string(lineNum + 1);
                        }
                        
                        if (tagStack.top().first != tagName) {
                            return "Error at line " + to_string(lineNum + 1);
                        }
                        
                        tagStack.pop();
                    }
                    
                    i = j;
                }
            }
        }
    }
    
    if (!tagStack.empty()) {
        return "Error at line " + to_string(tagStack.top().second);
    }
    
    return "No error";
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    
    vector<string> codes;
    string line;
    
    while (getline(cin, line)) {
        if (line == "-1") {
            break;
        }
        codes.push_back(line);
    }
    
    string result = validateHTML(codes);
    cout << result << endl;
    
    return 0;
}