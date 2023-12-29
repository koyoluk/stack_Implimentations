
#include "Comp.h"

using namespace std;
int Comp::binarySearch( vector<int> &sortedArray, int target) {
    int right = sortedArray.size() - 1;
    int mid=0;
    int left = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (sortedArray[mid] == target) {
            return mid; // Element found at index 'mid'
        } else if (sortedArray[mid] < target) {
            left = mid + 1; // Adjust the left boundary
        } else {
            right = mid - 1; // Adjust the right boundary
        }
    }
    return left;
}
void Comp::createAccount(std::string id, int count) {
    
        
        int hashvalue  = hash(id);
        
        Account A;
        A.balance = count;
        A.id = id;
    if (hashvalue>=bankStorage2d.size()){
        vector<Account> B;
        Account h;
        h.balance = -1;
        B.push_back(h);
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage2d.push_back(B);
        }
    }
        int i =1;
        bankStorage2d[hashvalue].push_back(A);
        NOA++;
        if (top.size()==0){
            top.push_back(count);
        }
        else{
            int i = binarySearch(top, count);
            top.insert(top.begin()+i, count);
            
        }
    
}

std::vector<int> Comp::getTopK(int k){
    int l= top.size();
    vector<int>lol;
    if(k<l){
    for(int i = 0; i<k;i++){
        lol.push_back(top[top.size()-i-1]);
        }
        return lol; // Placeholder return value
}
else{
    for(int i = 0; i<k && i<l;i++){
        lol.push_back(top[top.size()-i-1]);
        }
        return lol; // Placeholder return value
    
}
}

int Comp::getBalance(std::string id) {
    int hashvalue  = hash(id);
    
    int i =bankStorage2d[hashvalue].size();
    if (hashvalue>=bankStorage2d.size()){
        vector<Account> B;
        Account h;
        h.balance = -1;
        B.push_back(h);
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage2d.push_back(B);
        }
    }
    
    while(bankStorage2d[hashvalue][i-1].id!=id){
        if(bankStorage2d[hashvalue][i-1].id=="****"){
            return -1;
        }
        else{
            i-=1;
        }
        
    }
    return bankStorage2d[hashvalue][i-1].balance; // Placeholder return value
}

void Comp::addTransaction(std::string id, int count) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage2d.size()){
        vector<Account> B;
        Account h;
        h.balance = -1;
        B.push_back(h);
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage2d.push_back(B);
        }
    }
    int i =bankStorage2d[hashvalue].size();
    while(bankStorage2d[hashvalue][i-1].id!=id){
        if(bankStorage2d[hashvalue][i-1].id=="****"){
            createAccount(id, count);
            
            return;
        }
        else{
            i-=1;
        }
}
    int k = binarySearch(top, bankStorage2d[hashvalue][i-1].balance);
    top.erase(top.begin()+k);
    bankStorage2d[hashvalue][i-1].balance += count;
    int j = binarySearch(top, bankStorage2d[hashvalue][i-1].balance);
    top.insert(top.begin()+j, bankStorage2d[hashvalue][i-1].balance);
    return;
}

bool Comp::doesExist(std::string id) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage2d.size()){
        vector<Account> B;
        Account h;
        h.balance = -1;
        B.push_back(h);
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage2d.push_back(B);
        }
    }
    int i =bankStorage2d[hashvalue].size();
    while(bankStorage2d[hashvalue][i-1].id!=id){
        if(bankStorage2d[hashvalue][i-1].id=="****"){
            return false;
        }
        else{
            
            i-=1;
        }
        
    }
    return true;
}

bool Comp::deleteAccount(std::string id) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage2d.size()){
        vector<Account> B;
        Account h;
        h.balance = -1;
        B.push_back(h);
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage2d.push_back(B);
        }
    }
    int i =bankStorage2d[hashvalue].size();
    while(bankStorage2d[hashvalue][i-1].id!=id){
        if(bankStorage2d[hashvalue][i-1].id=="****"){
            return false;
        }
        else{
            
            i-=1;
        }
        
    }
    int j = binarySearch(top, bankStorage2d[hashvalue][i-1].balance);
    top.erase(top.begin()+j);
    bankStorage2d[hashvalue].erase(bankStorage2d[hashvalue].begin()+i-1);
    NOA--;
    return true;
}
int Comp::databaseSize() {
    if(NOA<=100000){
        return NOA; // Placeholder return value
    }
    else {
        return -1;
    }
}

int Comp::hash(std::string id) {
    
    int l = id.size();
    int code[l];
    for(int i = 0;i<l;i++){
        code[i] = id[i];
    }
    long hashvalue=0;
    for(int i = 0; i<l;i++){
        hashvalue += (code[i])*(i+1)*code[i]*(i+7);
    }
    int sum = 0;
    for(int i = 0; i<l;i++){
        sum += code[i];
    }
    hashvalue += sum;
    if(hashvalue<0){
        hashvalue*=-1;
    }
    
    while(hashvalue>=100000){
        hashvalue -=100001;
    }
    
    return hashvalue; // Placeholder return value
}