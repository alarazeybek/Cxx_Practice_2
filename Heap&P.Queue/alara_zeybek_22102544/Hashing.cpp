//
// Created by DELL on 25.04.2024.
//

#include "Hashing.h"

LinkedList::LinkedList() {
    root = nullptr;
}
LinkedList::LinkedList(LinkedList& l){
    Node* temp = l.root;
    while(temp != nullptr){
        addNode(temp->item);
        temp = temp->next;
    }
}
LinkedList::~LinkedList() { //ItemType'ı releaselemedi !! sadece list için kullanilan node alanını bosalatti
    while(root != nullptr){
        Node* temp = root;
        root = root->next;
        delete temp;
    }
}
bool LinkedList::addNode(string i) {
    if(searchNode(i) == nullptr){
        Node* temp = new Node(i);   //new kullanıldı
        temp->next = root;
        root = temp;
        return true;
    }
    else{
        cout<<i<<" is already in the list.\n";
        return false;
    }
}

bool LinkedList::deleteNode(string i) {
    if(root != nullptr ) {
        if ((root->item) == i) {     // want-to-delete item is root
            Node *temp1 = root->next;
            delete root;
            root = temp1;
            return true;
        }
        Node *temp = root;
        while (temp->next != nullptr) {
            if ((temp->next->item) == i) {
                Node *temptemp = temp->next->next;
                delete temp->next;
                temp->next = temptemp;
                return true;
            }
            temp = temp->next;
        }
        cout << i << " does not exist in the list.\n";
    }
    return false;
}
Node* LinkedList::searchNode(string i) {
    if(root != nullptr) {
        Node *temp = root;
        while (temp != nullptr) {
            if ((temp->item) == i) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return nullptr;
}
void LinkedList::printLinkedList() {
    Node* temp = root;
    while(temp != nullptr){
        //cout<<temp->item<<" , ";
        temp = temp->next;
    }
    //cout<<endl;
}
bool LinkedList::isEmpty(){
    return root == nullptr;
}
Node* LinkedList::getRootItem(){
    return root;
}

Hashing::Hashing() {
    bucket = new LinkedList[tablesize];
}

Hashing::~Hashing() {
    delete[] bucket;
}

int Hashing::hash(string s) const {
    int hashVal = 0;
    for (char c : s) {
        hashVal = (hashVal *3  + c) % tablesize; // Adjusting the hashtable size
    }
    return hashVal;
}

bool Hashing::addNewItem(string s) {
    int index = hash(s);
    return bucket[index].addNode(s);
}

bool Hashing::deleteNewItem(string s) {
    int i = hash(s);
    return bucket[i].deleteNode(s);
}
string Hashing::findItemInTable(string s){
    int index = hash(s);
    Node* temp = bucket[index].searchNode(s);
    if(temp == nullptr){
        return "";
    }
    return temp->item;
}

void Hashing::printTable() {
    int index = 0;
    for (int i = 0; i < tablesize; i++)
    {
        //cout<<"Index "<< i <<" element: " ;
        bucket[i].printLinkedList();
    }
}

string Hashing::f(string prefix, string suffix) {
    string combined = prefix + "|" + suffix;
    int hashVal = hash(combined);
    Node* current = bucket[hashVal].getRootItem(); // Get the root of the linked list at the hashed index
    while (current != nullptr) {
        if (current->item == combined) {
            return current->item;
        }
        current = current->next;
    }
    return ""; // Return -1 if the combined prefix and suffix is not found
}


void Hashing::WordFilter(string* words, int size) {
    for (int i = 0; i < size; i++) {
        string word = words[i];
        addNewItem(word);
    }
}
int Hashing::searchCollision(string* words, int size){
    int collision = 0;
    for (int i = 0; i < size; i++) {
        string word = words[i];
        for (int j = 1; j < word.size(); j++) { //O(character_num_of_a_word)
            string prefix = word.substr(0, j);
            int pre_index = hash(prefix);
            if(!bucket[pre_index].isEmpty() ){
                //cout<<prefix<<" - "<<pre_index<<endl;
                collision++;
            }
        }
        for (int k = 1; k < word.size(); k++) { //O(character_num_of_a_word)
            string suffix = word.substr(k, word.size());
            int suffix_index = hash(suffix);
            if (!bucket[suffix_index].isEmpty()) {
                //cout<<suffix<<" - "<<suffix_index<<endl;
                collision++;
            }
        }
    } // Overall O(total character number)
    return collision;
}

