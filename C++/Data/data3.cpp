#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Rule{
    vector<string> customerId;
    vector<string> product;
    vector<string> senderId;
    vector<string> country;
    vector<string> vpc;
    string content;
    vector<string> supplierId;
    int priority;
};

vector<Rule> Rules;

unordered_map<string,vector<Rule>> RuleAssign;

struct ruleFinal{
    vector<string> supplierId;
    string content;
    int priority;
};
void assignRule(const vector<Rule>& Rules, unordered_map<string , vector<Rule>> &RuleAssign);
void printRuleAssign(const unordered_map<string,vector<Rule>> &RuleAssign);

int main(){
    //{{"22286-1","22286-2"},{"PRD001","PRD002"},{"9988779988","8899775566"},{"IND","BZ"},{"11-11-12","12-12-12"},"cancel",{"22288-1"},1}
    Rules = {{{"22286-1","22286-2"},{},{},{"IND","BZ"},{},"cancel",{"22288-1"},1},
            {{"22286-1","22286-2"},{},{},{},{"11-11-12","12-12-12"},"cancel",{"22288-1"},5},
            {{"22286-1","22286-2"},{},{"9988779988","8899775566"},{},{"11-11-12","12-12-12"},"cancel",{"22288-1"},4},
            {{"22286-1","22286-2"},{},{"9988779988","8899775566"},{},{"11-11-12","12-12-12"},"cancel",{"22288-1"},3},
            {{},{"PRD001","PRD002"},{},{},{"11-11-12","12-12-12"},"cancel",{"22288-1"},7},
            {{},{"PRD001","PRD002"},{},{"IND","BZ"},{},"cancel",{"22288-1"},6},
            {{"22286-3","22286-2"},{},{"9988779988","8899775566"},{"IND","BZ"},{"11-11-12","12-12-12"},"cancel",{"22288-1"},2},
            {{"22286-3","22286-2"},{},{"9988779988","8899775566"},{"IND","BZ"},{"11-11-12","12-12-12"},"cancel",{"22288-1"},0}};
    assignRule(Rules,RuleAssign);
    printRuleAssign(RuleAssign);
    vector<string> msgData = {"22286-1","PRD001","9988779988","IND","14-14-14","Hi cancel cancel"};
    
    return (0);
}
//8777655210 - kausik
// paromita
void assignRule(const vector<Rule>& Rules, unordered_map<string , vector<Rule>> &RuleAssign){
    for (auto &r : Rules)
    {
        if(!r.customerId.empty()){
            for(auto& c : r.customerId){
                cout << "Customet  iD = " << c << endl;
                RuleAssign[c].push_back(r);
            }
        }
        else{
            for(auto& p : r.product){
                cout << "Product  iD = " << p << endl;
                RuleAssign[p].push_back(r);
            }
        }        
    }
}
/* 2595
2124 */


void printRuleAssign(const unordered_map<string,vector<Rule>> &RuleAssign){
    cout << "Size of the rule = " << RuleAssign.size() << endl;
    for (auto i: RuleAssign){
        cout << "--------------- Key = " << i.first << " -----------------" << endl;
        for (auto d : i.second){
            cout << "Customer ID [" ;
            for(auto j : d.customerId){
                cout << j << " ";
            }
            cout << "] Product [" ;
            for(auto j : d.product){
                cout << j << " ";
            }
            cout << "] SenderId [" ;
            for(auto j : d.senderId){
                cout << j << " ";
            }
            cout << "] Country [" ;
            for(auto j : d.country){
                cout << j << " ";
            }
            cout << "] Vpc [" ;
            for(auto j : d.vpc){
                cout << j << " ";
            }
            cout << "] Content [" ;
                cout << d.content << " ";
            cout << "] SupplierId [" ;
            for(auto j : d.supplierId){
                cout << j << " ";
            }
            cout << "] priority [" ;
                cout << d.priority << "]" << endl;



        }
        cout << endl << endl ;
    }
}






