#include "QuadraticProbing.h"
using namespace std;
int QuadraticProbing::binarySearch(vector<int> &sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;
    int mid=0;
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

void QuadraticProbing::createAccount(std::string id, int count) {
   

        int hashvalue  = hash(id);
        Account A;
        A.balance = count;
        A.id = id;
        int i =1;
    if (hashvalue>=bankStorage1d.size()){
        Account h;
        h.balance = -1;
        h.id = "****";
        for(int i=0;i<=99999;i++){
            bankStorage1d.push_back(h);
        }
    }
        while(bankStorage1d[hashvalue].id!="****"&&bankStorage1d[hashvalue].id!="*****"){
            hashvalue+=i;
            while(hashvalue>=100000){
                hashvalue -= 100000;
            }
            i+=2;
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

std::vector<int> QuadraticProbing::getTopK(int k){
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
    


int QuadraticProbing::getBalance(std::string id) {
    int hashvalue  = hash(id);
    int i=1;
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
            hashvalue+=i;
            if (hashvalue>=100000){
                hashvalue -= 100000;
            }
            i+=2;
        }
        
    }
    return bankStorage1d[hashvalue].balance; // Placeholder return value
}

void QuadraticProbing::addTransaction(std::string id, int count) {
    int hashvalue  = hash(id);
    int i =1;
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
            hashvalue+=i;
            if (hashvalue>=100000){
                hashvalue -= 100000;
            }
            i+=2;
        }
    }
        int k = binarySearch(top, bankStorage1d[hashvalue].balance);
        top.erase(top.begin()+k);
        bankStorage1d[hashvalue].balance += count;
        int j = binarySearch(top, bankStorage1d[hashvalue].balance);
        top.insert(top.begin()+j, bankStorage1d[hashvalue].balance);
        return;
}

bool QuadraticProbing::doesExist(std::string id) {
    int hashvalue  = hash(id);
    int i=1;
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
            hashvalue+=i;
            if (hashvalue>=100000){
                hashvalue -= 100000;
            }
            i+=2;
        }
        
    }
    return true;
}

bool QuadraticProbing::deleteAccount(std::string id) {
    int hashvalue  = hash(id);
    int  i =1;
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
            hashvalue+=i;
            if (hashvalue>=100000){
                hashvalue -= 100000;
            }
            i+=2;
        }
        
    }
    int j = binarySearch(top, bankStorage1d[hashvalue].balance);
    top.erase(top.begin()+j);
    bankStorage1d[hashvalue].id = "*****";
    bankStorage1d[hashvalue].balance = -1;
    NOA--;
    return true;
}
int QuadraticProbing::databaseSize() {
    return NOA; // Placeholder return value
}

int QuadraticProbing::hash(std::string id) {

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