#include "LinearProbing.h"
using namespace std;
int LinearProbing::binarySearch(vector<int> &sortedArray, int target) {
    int right = sortedArray.size() - 1;
    int mid=0;
    int left  = 0;
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
void LinearProbing::createAccount(std::string id, int count) {
    

        int hashvalue  = hash(id);
        Account A;
        A.balance = count;
        A.id = id;
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
        while(bankStorage1d[hashvalue].id!="****"&&bankStorage1d[hashvalue].id!="*****"){
            hashvalue++;
            while(hashvalue>=100000){
                hashvalue = 0;
            }
        }
        bankStorage1d[hashvalue] = A;
        NOA++;
        if (top.size()==0){
            top.push_back(count);
        }
        else{
            int i = binarySearch(top, count);
            top.insert(top.begin()+i, count);
            
        }
    
}


std::vector<int> LinearProbing::getTopK(int k){
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

int LinearProbing::getBalance(std::string id) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
    while(bankStorage1d[hashvalue].id!=id){
        if(bankStorage1d[hashvalue].id=="****"){
            return -1;
        }
        else{
            hashvalue++;
            if (hashvalue>=100000){
                hashvalue = 0;
            }
        }
        
    }
    return bankStorage1d[hashvalue].balance; // Placeholder return value
}

void LinearProbing::addTransaction(std::string id, int count) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
    while(bankStorage1d[hashvalue].id!=id){
        if(bankStorage1d[hashvalue].id=="****"){
            createAccount(id, count);
            
            return;
        }
        else{
            hashvalue++;
            if (hashvalue>=100000){
                hashvalue = 0;
            }
        }
}
    int i = binarySearch(top, bankStorage1d[hashvalue].balance);
    top.erase(top.begin()+i);
    bankStorage1d[hashvalue].balance += count;
    int j = binarySearch(top, bankStorage1d[hashvalue].balance);
    top.insert(top.begin()+j, bankStorage1d[hashvalue].balance);
    return;
}

bool LinearProbing::doesExist(std::string id) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
    while(bankStorage1d[hashvalue].id!=id){
        if(bankStorage1d[hashvalue].id=="****"){
            return false;
        }
        else{
            hashvalue++;
            if (hashvalue>=100000){
                hashvalue = 0;
            }
        }
        
    }
    return true;
}

bool LinearProbing::deleteAccount(std::string id) {
    int hashvalue  = hash(id);
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
    while(bankStorage1d[hashvalue].id!=id){
        if(bankStorage1d[hashvalue].id=="****"){
            return false;
        }
        else{
            hashvalue++;
            if (hashvalue>=100000){
                hashvalue = 0;
            }
        }
        
    }
    int i = binarySearch(top, bankStorage1d[hashvalue].balance);
    top.erase(top.begin()+i);
    bankStorage1d[hashvalue].id = "*****";
    bankStorage1d[hashvalue].balance = 0;
    NOA--;
    return true;
   
}
int LinearProbing::databaseSize() {
    return NOA; // Placeholder return value
}

int LinearProbing::hash(std::string id) {
   
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
        hashvalue -=100000;
    }
    
    return hashvalue; // Placeholder return value
}